
#ifndef INC_TRANSFORMSNUMBERSTOSPACES_H
#define INC_TRANSFORMSNUMBERSTOSPACES_H

#include "../string_.h"

void transformsNumbersToSpaces(char *s) {

    char *readPtr = stringBuffer;
    copy(s, getEndOfString(s) + 1, stringBuffer);

    while (*readPtr != '\0') {
        if (isdigit(*readPtr)) {
            for (int i = 0; i < *readPtr - '0'; i++) {
                *s = ' ';
                s++;
            }
        } else {
            *s = *readPtr;
            s++;
        }
        readPtr++;
    }

    *s = '\0';
}

void test_transformsNumbersToSpaces_isEmpty() {
    char s[] = "";
    transformsNumbersToSpaces(s);
    ASSERT_STRING("", s);
}

void test_transformsNumbersToSpaces_oneNumber() {
    char s[] = "3";
    transformsNumbersToSpaces(s);
    ASSERT_STRING("   ", s);
}

void test_transformsNumbersToSpaces_NumbersAndSymbols() {
    char s[] = "3gg3ff";
    transformsNumbersToSpaces(s);
    ASSERT_STRING("   gg   ff", s);
}

void test_transformsNumbersToSpaces() {
    test_transformsNumbersToSpaces_isEmpty();
    test_transformsNumbersToSpaces_oneNumber();
    test_transformsNumbersToSpaces_NumbersAndSymbols();
}

#endif
