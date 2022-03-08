#ifndef INC_REVERSESWORDORDER_H
#define INC_REVERSESWORDORDER_H

#include "../string_.h"

void reversesWordOrder(char *s) {
    char *end = copy(s, getEndOfString(s), stringBuffer);
    char *begin = s;
    char *beginSearch = end - 1;
    WordDescriptor word;

    while (getWordReverse(beginSearch, stringBuffer - 1, &word)) {
        begin = copy(word.begin, word.end, begin);
        *begin++ = ' ';

        char *startNextWord = beginSearch - word.end + word.begin - 1;
        beginSearch = findNonSpaceReverse(startNextWord, stringBuffer - 1);
    }

    while (!isspace(*begin))
        begin--;

    *begin = '\0';
}

void test_reversesWordOrder_isEmpty() {
    char s[] = "";
    reversesWordOrder(s);
    ASSERT_STRING("", s);
}

void test_reversesWordOrder_hasOneWord() {
    char s[] = "danil";
    reversesWordOrder(s);
    ASSERT_STRING("danil", s);
}

void test_reversesWordOrder_hasSeveralWords() {
    char s[] = "danil eryomin";
    reversesWordOrder(s);
    ASSERT_STRING("eryomin danil", s);
}

void test_reversesWordOrder_hasSeveralWordsAndSpaceInEnd() {
    char s[] = "danil eryomin ";
    reversesWordOrder(s);
    ASSERT_STRING("eryomin danil", s);
}

void test_reversesWordOrder() {
    test_reversesWordOrder_isEmpty();
    test_reversesWordOrder_hasOneWord();
    test_reversesWordOrder_hasSeveralWords();
    test_reversesWordOrder_hasSeveralWordsAndSpaceInEnd();
}

#endif
