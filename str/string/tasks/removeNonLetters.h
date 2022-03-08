#ifndef INC_REMOVENONLETTERS_H
#define INC_REMOVENONLETTERS_H

#include "../string_.h"

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_isEmptyString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_hasOneSpace() {
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_notHasSpaces() {
    char s[] = "vk";
    removeNonLetters(s);
    ASSERT_STRING("vk", s);
}

void test_removeNonLetters_hasSpaces() {
    char s[] = "  v   k   ";
    removeNonLetters(s);
    ASSERT_STRING("vk", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_hasSpaces();
    test_removeNonLetters_notHasSpaces();
    test_removeNonLetters_isEmptyString();
    test_removeNonLetters_hasOneSpace();
}

#endif
