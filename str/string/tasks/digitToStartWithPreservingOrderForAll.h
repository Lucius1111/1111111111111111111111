#ifndef INC_DIGITTOSTART_H
#define INC_DIGITTOSTART_H

#include "../string_.h"

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithPreservingOrder(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer);
    char *recPosition = copyIf(stringBuffer, endStringBuffer,
                               word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithPreservingOrderForAll(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;
    while (getWord(beginSearch,
                   &word)) {

        digitToStartWithPreservingOrder(word);

        beginSearch = word.end;
    }
}

void test_digitToStartWithPreservingOrderForAll_notHasDigits() {
    char s[] = "ABC  FCF";
    digitToStartWithPreservingOrderForAll(s);
    ASSERT_STRING("ABC  FCF", s);
}

void test_digitToStartWithPreservingOrderForAll_HasDigitsInBeginning() {
    char s[] = "123ABC  122FCF";
    digitToStartWithPreservingOrderForAll(s);
    ASSERT_STRING("123ABC  122FCF", s);
}

void test_digitToStartWithPreservingOrderForAll_HasDigitsInEnd() {
    char s[] = "ABC123  FCF122";
    digitToStartWithPreservingOrderForAll(s);
    ASSERT_STRING("123ABC  122FCF", s);
}

void test_digitToStartWithPreservingOrderForAll_chaoticPosition() {
    char s[] = "AB2C123  122FC1F122";
    digitToStartWithPreservingOrderForAll(s);
    ASSERT_STRING("2123ABC  1221122FCF", s);
}

void test_digitToStartWithPreservingOrderForAll(){
    test_digitToStartWithPreservingOrderForAll_notHasDigits();
    test_digitToStartWithPreservingOrderForAll_HasDigitsInBeginning();
    test_digitToStartWithPreservingOrderForAll_HasDigitsInEnd();
    test_digitToStartWithPreservingOrderForAll_chaoticPosition();
}

#endif
