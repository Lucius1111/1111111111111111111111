#ifndef INC_PRINTREVERSEWORDSONEBYONETOSTRING_H
#define INC_PRINTREVERSEWORDSONEBYONETOSTRING_H

#include "../string_.h"

void printReverseWordsOneByOneToString(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&bag, stringBuffer);

    char *begin = s;
    for (int i = 0; i < bag.size; i++) {
        begin = copyReverse(bag.words[i].end - 1, bag.words[i].begin - 1, begin);
        *begin++ = ' ';
    }
    if (begin != s)
        begin--;

    *begin = '\0';
}

void test_printReverseWordsOneByOneToString_isEmpty() {
    char s[] = "";
    printReverseWordsOneByOneToString(s);
    ASSERT_STRING("", s);
}

void test_printReverseWordsOneByOneToString_oneWord() {
    char s[] = "Danil";
    printReverseWordsOneByOneToString(s);
    ASSERT_STRING("linaD", s);
}

void test_printReverseWordsOneByOneToString_setOfWords() {
    char s[] = "Danil Eryomin 123";
    printReverseWordsOneByOneToString(s);
    ASSERT_STRING("linaD nimoyrE 321", s);
}

void test_printReverseWordsOneByOneToString() {
    test_printReverseWordsOneByOneToString_isEmpty();
    test_printReverseWordsOneByOneToString_oneWord();
    test_printReverseWordsOneByOneToString_setOfWords();
}

#endif
