#ifndef INC_TRANSFORMSALLWORDSW1TOW2_H
#define INC_TRANSFORMSALLWORDSW1TOW2_H

#include "../string_.h"

void transformsAllWordsW1toW2(char *source, char *w1, char *w2) {
    size_t sizeW1 = strlen_(w1);
    size_t sizeW2 = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + sizeW1};
    WordDescriptor word2 = {w2, w2 + sizeW2};
    WordDescriptor desiredWord;
    char *recPtr = source;
    char *readPtr;

    if (sizeW1 >= sizeW2) {
        readPtr = source;
    } else {
        *(copy(source, getEndOfString(source), stringBuffer)) = '\0';
        readPtr = stringBuffer;
    }

    while (*readPtr != '\0') {
        getWord(readPtr, &desiredWord);
        size_t sizeDesiredWord = desiredWord.end - desiredWord.begin;
        if (areWordsEqual(word1, desiredWord) == 0) {
            copy(word2.begin, word2.end, recPtr);
            recPtr += sizeW2;
            readPtr += sizeW1;
        } else {
            copy(desiredWord.begin, desiredWord.end, recPtr);
            recPtr += sizeDesiredWord;
            readPtr += sizeDesiredWord;
        }
        recPtr++;
        readPtr++;
    }
    *recPtr = '\0';
}

void test_transformsAllWordsW1toW2_onlyOneDesiredWord() {
    char s[] = "gg";
    char w1[] = "gg";
    char w2[] = "ff";
    transformsAllWordsW1toW2(s, w1, w2);
    ASSERT_STRING("ff", s);
}

void test_transformsAllWordsW1toW2_hasDesiredWordAndW2MoreW1_() {
    char s[MAX_STRING_SIZE] = "gg";
    char w1[] = "gg";
    char w2[] = "fff";
    transformsAllWordsW1toW2(s, w1, w2);
    ASSERT_STRING("fff", s);
}

void test_transformsAllWordsW1toW2_hasOnlyDesiredWords() {
    char s[] = "gg gg gg";
    char w1[] = "gg";
    char w2[] = "ff";
    transformsAllWordsW1toW2(s, w1, w2);
    ASSERT_STRING("ff ff ff", s);
}

void test_transformsAllWordsW1toW2_hasDesiredAndOtherWords() {
    char s[] = "ff gg gff";
    char w1[] = "gg";
    char w2[] = "ff";
    transformsAllWordsW1toW2(s, w1, w2);
    ASSERT_STRING("ff ff gff", s);
}

void test_transformsAllWordsW1toW2_hasDesiredAndOtherWordThatIncludeDesiredWord() {
    char s[] = "ffggff gg";
    char w1[] = "gg";
    char w2[] = "ff";
    transformsAllWordsW1toW2(s, w1, w2);
    ASSERT_STRING("ffggff ff", s);
}



void test_transformsAllWordsW1toW2() {
    test_transformsAllWordsW1toW2_onlyOneDesiredWord();
    test_transformsAllWordsW1toW2_hasOnlyDesiredWords();
    test_transformsAllWordsW1toW2_hasDesiredAndOtherWords();
    test_transformsAllWordsW1toW2_hasDesiredAndOtherWordThatIncludeDesiredWord();
    test_transformsAllWordsW1toW2_hasDesiredWordAndW2MoreW1_();
}

#endif
