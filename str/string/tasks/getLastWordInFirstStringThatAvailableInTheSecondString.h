#ifndef INC_GETLASTWORDINFIRSTSTRINGTHATAVAILABLEINTHESECONDSTRING_H
#define INC_GETLASTWORDINFIRSTSTRINGTHATAVAILABLEINTHESECONDSTRING_H

#include "../string_.h"

WordDescriptor getLastWordInFirstStringThatAvailableInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&bag, s1);
    getBagOfWords(&bag2, s2);
    WordDescriptor word = {NULL, NULL};

    for (size_t i = 0; i < bag.size; i++)
        for (size_t j = 0; j < bag2.size; j++)
            if (areWordsEqual(bag.words[i], bag2.words[j]) == 0) {
                word = bag.words[i];
            }

    return word;
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringIsEmpty() {
    char s1[] = "";
    char s2[] = "123 456";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_secondStringIsEmpty() {
    char s1[] = "123 456";
    char s2[] = "";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_bothStringsAreEmpty() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasWordFromSecondString() {
    char s1[] = "123 456 789";
    char s2[] = "123 234 567";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("123", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasNotWordFromSecondString() {
    char s1[] = "567 456 789";
    char s2[] = "123 234";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasWordsFromSecondString() {
    char s1[] = "123 456 234";
    char s2[] = "123 234";
    WordDescriptor word = getLastWordInFirstStringThatAvailableInTheSecondString(s1, s2);
    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("234", res);
}

void test_getLastWordInFirstStringThatAvailableInTheSecondString() {
    test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringIsEmpty();
    test_getLastWordInFirstStringThatAvailableInTheSecondString_secondStringIsEmpty();
    test_getLastWordInFirstStringThatAvailableInTheSecondString_bothStringsAreEmpty();
    test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasWordFromSecondString();
    test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasNotWordFromSecondString();
    test_getLastWordInFirstStringThatAvailableInTheSecondString_firstStringHasWordsFromSecondString();
}

#endif
