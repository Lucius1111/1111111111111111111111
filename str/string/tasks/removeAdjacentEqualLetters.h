#ifndef INC_REMOVEADJACENTEQUALLETTERS_H
#define INC_REMOVEADJACENTEQUALLETTERS_H

#include "../string_.h"

void removeAdjacentEqualLetters(char *s) {
    char *begin = s + 1;
    char *next = begin;
    char buffer = *s;
    while (*next != '\0') {
        if (buffer != *next) {
            *begin = *next;
            begin++;
            buffer = *next;
        }
        next++;
    }
    *begin = '\0';
}

void test_removeAdjacentEqualLetters_hasSameSymbols() {
    char s[] = " vvv k";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" v k", s);
}

void test_removeAdjacentEqualLetters_notHasSameSymbols() {
    char s[] = " v k";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" v k", s);
}

void test_removeAdjacentEqualLetters_isEmptyString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters_hasOneSymbols() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters(){
    test_removeAdjacentEqualLetters_hasSameSymbols();
    test_removeAdjacentEqualLetters_notHasSameSymbols();
    test_removeAdjacentEqualLetters_isEmptyString();
    test_removeAdjacentEqualLetters_hasOneSymbols();
};

#endif
