#ifndef INC_HASEQUALWORDS_H
#define INC_HASEQUALWORDS_H

#include "../string_.h"

bool hasEqualWords(char *s) {
    getBagOfWords(&bag, s);

    for (size_t i = 0; i < bag.size; i++)
        for (size_t j = i + 1; j < bag.size; j++)
            if (areWordsEqual(bag.words[i], bag.words[j]) == 0)
                return true;

    return false;
}

void test_hasEqualWords_isEmpty() {
    char s[] = "";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_hasOneWord() {
    char s[] = "123";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_hasNotEqualWords() {
    char s[] = "123 456 789";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_hasEqualWords() {
    char s[] = "123 456 123 789";
    assert(hasEqualWords(s));
}

void test_hasEqualWords() {
    test_hasEqualWords_isEmpty();
    test_hasEqualWords_hasOneWord();
    test_hasEqualWords_hasNotEqualWords();
    test_hasEqualWords_hasEqualWords();
}

#endif
