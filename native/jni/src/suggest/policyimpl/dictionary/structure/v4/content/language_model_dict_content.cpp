/*
 * Copyright (C) 2014, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "suggest/policyimpl/dictionary/structure/v4/content/language_model_dict_content.h"

namespace latinime {

bool LanguageModelDictContent::save(FILE *const file) const {
    return mTrieMap.save(file);
}

bool LanguageModelDictContent::runGC(
        const TerminalPositionLookupTable::TerminalIdMap *const terminalIdMap,
        const LanguageModelDictContent *const originalContent,
        int *const outNgramCount) {
    return runGCInner(terminalIdMap, originalContent->mTrieMap.getEntriesInRootLevel(),
            0 /* nextLevelBitmapEntryIndex */, outNgramCount);
}

ProbabilityEntry LanguageModelDictContent::getProbabilityEntry(
        const WordIdArrayView prevWordIds, const int wordId) const {
    if (!prevWordIds.empty()) {
        // TODO: Read n-gram entry.
        return ProbabilityEntry();
    }
    const TrieMap::Result result = mTrieMap.getRoot(wordId);
    if (!result.mIsValid) {
        // Not found.
        return ProbabilityEntry();
    }
    return ProbabilityEntry::decode(result.mValue, mHasHistoricalInfo);
}

bool LanguageModelDictContent::setProbabilityEntry(const WordIdArrayView prevWordIds,
        const int terminalId, const ProbabilityEntry *const probabilityEntry) {
    if (!prevWordIds.empty()) {
        // TODO: Add n-gram entry.
        return false;
    }
    return mTrieMap.putRoot(terminalId, probabilityEntry->encode(mHasHistoricalInfo));
}


bool LanguageModelDictContent::runGCInner(
        const TerminalPositionLookupTable::TerminalIdMap *const terminalIdMap,
        const TrieMap::TrieMapRange trieMapRange,
        const int nextLevelBitmapEntryIndex, int *const outNgramCount) {
    for (auto &entry : trieMapRange) {
        const auto it = terminalIdMap->find(entry.key());
        if (it == terminalIdMap->end() || it->second == Ver4DictConstants::NOT_A_TERMINAL_ID) {
            // The word has been removed.
            continue;
        }
        if (!mTrieMap.put(it->second, entry.value(), nextLevelBitmapEntryIndex)) {
            return false;
        }
        if (outNgramCount) {
            *outNgramCount += 1;
        }
        if (entry.hasNextLevelMap()) {
            if (!runGCInner(terminalIdMap, entry.getEntriesInNextLevel(),
                    mTrieMap.getNextLevelBitmapEntryIndex(it->second, nextLevelBitmapEntryIndex),
                    outNgramCount)) {
                return false;
            }
        }
    }
    return true;
}

} // namespace latinime
