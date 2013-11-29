/*
 * Copyright (C) 2013, The Android Open Source Project
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

#ifndef LATINIME_VER4_DICT_CONSTANTS_H
#define LATINIME_VER4_DICT_CONSTANTS_H

#include "defines.h"

namespace latinime {

// Note that there are corresponding definitions in FormatSpec.java.
class Ver4DictConstants {
 public:
    static const char *const TRIE_FILE_EXTENSION;
    static const char *const FREQ_FILE_EXTENSION;
    static const char *const TERMINAL_ADDRESS_TABLE_FILE_EXTENSION;
    static const char *const BIGRAM_FILE_EXTENSION;
    static const char *const BIGRAM_LOOKUP_TABLE_FILE_EXTENSION;
    static const char *const BIGRAM_CONTENT_TABLE_FILE_EXTENSION;
    static const char *const SHORTCUT_FILE_EXTENSION;
    static const char *const SHORTCUT_LOOKUP_TABLE_FILE_EXTENSION;
    static const char *const SHORTCUT_CONTENT_TABLE_FILE_EXTENSION;

    static const int MAX_DICTIONARY_SIZE;
    static const int MAX_DICT_EXTENDED_REGION_SIZE;

    static const int NOT_A_TERMINAL_ID;
    static const int NOT_A_TIME_STAMP;
    static const int PROBABILITY_SIZE;
    static const int FLAGS_IN_PROBABILITY_FILE_SIZE;
    static const int TERMINAL_ADDRESS_TABLE_ADDRESS_SIZE;
    static const int NOT_A_TERMINAL_ADDRESS;
    static const int TERMINAL_ID_FIELD_SIZE;
    static const int TIME_STAMP_FIELD_SIZE;
    static const int WORD_LEVEL_FIELD_SIZE;
    static const int WORD_COUNT_FIELD_SIZE;

    static const int BIGRAM_ADDRESS_TABLE_BLOCK_SIZE;
    static const int BIGRAM_ADDRESS_TABLE_DATA_SIZE;
    static const int SHORTCUT_ADDRESS_TABLE_BLOCK_SIZE;
    static const int SHORTCUT_ADDRESS_TABLE_DATA_SIZE;

    static const int BIGRAM_FLAGS_FIELD_SIZE;
    static const int BIGRAM_TARGET_TERMINAL_ID_FIELD_SIZE;
    static const int INVALID_BIGRAM_TARGET_TERMINAL_ID;
    static const int BIGRAM_PROBABILITY_MASK;
    static const int BIGRAM_HAS_NEXT_MASK;
    // Used when bigram list has time stamp.
    static const int BIGRAM_LARGE_PROBABILITY_FIELD_SIZE;

    static const int SHORTCUT_FLAGS_FIELD_SIZE;

 private:
    DISALLOW_IMPLICIT_CONSTRUCTORS(Ver4DictConstants);
};
} // namespace latinime
#endif /* LATINIME_VER4_DICT_CONSTANTS_H */