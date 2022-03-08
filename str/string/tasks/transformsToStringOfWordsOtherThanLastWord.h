#ifndef INC_TRANSFORMSTOSTRINGOFWORDSOTHERTHANLASTWORD_H
#define INC_TRANSFORMSTOSTRINGOFWORDSOTHERTHANLASTWORD_H

#include "../string_.h"

void transformsToStringOfWordsOtherThanLastWord(char *s) {
    char *begin = s;
    char *beginCopy = s;
    WordDescriptor desiredWord;
    WordDescriptor word;

    getWordReverse(getEndOfString(s), s - 1, &desiredWord);

    while (getWord(begin, &word)) {
        if (areWordsEqual(word, desiredWord) != 0) {
            beginCopy = copy(word.begin, word.end, beginCopy);
            *beginCopy++ = ' ';
        }
        begin = word.end;
    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}


void test_transformsToStringOfWordsOtherThanLastWord_isEmpty() {
    char s[] = "";
    transformsToStringOfWordsOtherThanLastWord(s);
    ASSERT_STRING("", s);
}

void test_transformsToStringOfWordsOtherThanLastWord_hasOneWord() {
    char s[] = "ff";
    transformsToStringOfWordsOtherThanLastWord(s);
    ASSERT_STRING("", s);
}

void test_transformsToStringOfWordsOtherThanLastWord_hasEqualWordWithLast() {
    char s[] = "ff gg   ff";
    transformsToStringOfWordsOtherThanLastWord(s);
    ASSERT_STRING("gg", s);
}

void test_transformsToStringOfWordsOtherThanLastWord_hasOnlyLastWords() {
    char s[] = "ff ff    ff ff";
    transformsToStringOfWordsOtherThanLastWord(s);
    ASSERT_STRING("", s);
}

void test_transformsToStringOfWordsOtherThanLastWord() {
    test_transformsToStringOfWordsOtherThanLastWord_isEmpty();
    test_transformsToStringOfWordsOtherThanLastWord_hasOneWord();
    test_transformsToStringOfWordsOtherThanLastWord_hasEqualWordWithLast();
    test_transformsToStringOfWordsOtherThanLastWord_hasOnlyLastWords();
}


#endif
