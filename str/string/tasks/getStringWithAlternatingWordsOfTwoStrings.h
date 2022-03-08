#ifndef INC_GETSTRINGWITHALTERNATINGWORDSOFTWOSTRINGS_H
#define INC_GETSTRINGWITHALTERNATINGWORDSOFTWOSTRINGS_H

#include "../string_.h"

void getStringWithAlternatingWordsOfTwoStrings(char *s, char *s1, char *s2) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *begin = s, *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            begin = copy(word1.begin, word1.end, begin);
            *begin++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            begin = copy(word2.begin, word2.end, begin);
            *begin++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (begin != s)
        begin--;
    *begin = '\0';
}

void test_getStringWithAlternatingWordsOfTwoStrings_twoEmptyStrings() {
    char s[MAX_STRING_SIZE];
    char s1[] = "";
    char s2[] = "";
    getStringWithAlternatingWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("", s);
}

void test_getStringWithAlternatingWordsOfTwoStrings_twoStringsWithOneWord() {
    char s[MAX_STRING_SIZE];
    char s1[] = "danil";
    char s2[] = "eryomin";
    getStringWithAlternatingWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("danil eryomin", s);
}

void test_getStringWithAlternatingWordsOfTwoStrings_twoStringsWithMoreOneWords() {
    char s[MAX_STRING_SIZE];
    char s1[] = "danil 123";
    char s2[] = "eryomin  456";
    getStringWithAlternatingWordsOfTwoStrings(s, s1, s2);
    ASSERT_STRING("danil eryomin 123 456", s);

}

void test_getStringWithAlternatingWordsOfTwoStrings() {
    test_getStringWithAlternatingWordsOfTwoStrings_twoEmptyStrings();
    test_getStringWithAlternatingWordsOfTwoStrings_twoStringsWithOneWord();
    test_getStringWithAlternatingWordsOfTwoStrings_twoStringsWithMoreOneWords();
}

#endif
