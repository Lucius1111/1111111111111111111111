#ifndef INC_HASPAIROFWORDTHATMADEOFTHESAMELETTERS_H
#define INC_HASPAIROFWORDTHATMADEOFTHESAMELETTERS_H

#include "../string_.h"

int cmp(void *a, void *b) {
    return *(char *) a - *(char *) b;
}

bool hasPairOfWordThatMadeOfTheSameLetters(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&bag, stringBuffer);

    for (size_t i = 0; i < bag.size; i++)
        qsort(bag.words[i].begin, bag.words[i].end - bag.words[i].begin, sizeof(char), cmp);

    return hasEqualWords(stringBuffer);
}

void test_hasPairOfWordThatMadeOfTheSameLetterschar_isEmpty() {
    char s[] = "";
    assert(!hasPairOfWordThatMadeOfTheSameLetters(s));
}

void test_hasPairOfWordThatMadeOfTheSameLetterschar_hasOneWord() {
    char s[] = "danil";
    assert(!hasPairOfWordThatMadeOfTheSameLetters(s));
}

void test_hasPairOfWordThatMadeOfTheSameLetters_hasPairOfWordThatMadeOfTheSameLetters() {
    char s[] = "danil danil";
    assert(hasPairOfWordThatMadeOfTheSameLetters(s));
}

void hasPairOfWordThatMadeOfTheSameLetters_hasNotPairOfWordThatMadeOfTheSameLetters() {
    char s[] = "danil eryomin";
    assert(!hasPairOfWordThatMadeOfTheSameLetters(s));
}

void hasPairOfWordThatMadeOfTheSameLetters_hasPairOfWordThatMadeOfTheSameLettersAndAnotherWords() {
    char s[] = "danil eryomin danil";
    assert(hasPairOfWordThatMadeOfTheSameLetters(s));
}

void test_hasPairOfWordThatMadeOfTheSameLetters() {
    test_hasPairOfWordThatMadeOfTheSameLetterschar_isEmpty();
    test_hasPairOfWordThatMadeOfTheSameLetterschar_hasOneWord();
    test_hasPairOfWordThatMadeOfTheSameLetters_hasPairOfWordThatMadeOfTheSameLetters();
    hasPairOfWordThatMadeOfTheSameLetters_hasNotPairOfWordThatMadeOfTheSameLetters();
    hasPairOfWordThatMadeOfTheSameLetters_hasPairOfWordThatMadeOfTheSameLettersAndAnotherWords();

}


#endif
