#ifndef INC_ISLEXIGRAPHICALLYORDEREDSTRING_H
#define INC_ISLEXIGRAPHICALLYORDEREDSTRING_H

#include "../string_.h"

bool isLexigraphicallyOrderedString(char *s) {
    WordDescriptor currentWord;
    if (!getWord(s, &currentWord))
        return true;

    WordDescriptor pastWord = currentWord;
    s = pastWord.end;

    while (getWord(s, &currentWord)) {
        if (areWordsEqual(currentWord, pastWord) < 0)
            return false;

        pastWord = currentWord;
        s = currentWord.end;
    }
    return true;
}

void test_isLexigraphicallyOrderedString_isEmptyString() {
    char s[] = "";
    assert(isLexigraphicallyOrderedString(s));
}

void test_isLexigraphicallyOrderedString_isLexigraphicallyOrderedString() {
    char s[] = "a b c d";
    assert(isLexigraphicallyOrderedString(s));
}

void test_isLexigraphicallyOrderedString_isNonLexigraphicallyOrderedString() {
    char s[] = "a d c e";
    assert(!isLexigraphicallyOrderedString(s));
}

void test_isLexigraphicallyOrderedString_isLexigraphicallyOrderedStringWithRepeatingWords() {
    char s[] = "a b b d";
    assert(isLexigraphicallyOrderedString(s));
}


void test_isLexigraphicallyOrderedString() {
    test_isLexigraphicallyOrderedString_isEmptyString();
    test_isLexigraphicallyOrderedString_isLexigraphicallyOrderedString();
    test_isLexigraphicallyOrderedString_isNonLexigraphicallyOrderedString();
    test_isLexigraphicallyOrderedString_isLexigraphicallyOrderedStringWithRepeatingWords();
}

#endif
