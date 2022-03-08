#ifndef INC_COUNTOFPOLINDROMES_H
#define INC_COUNTOFPOLINDROMES_H

#include "../string_.h"

bool isPalindrome(char *begin, char *end) {
    end--;

    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }

    return true;
}

int countOfPalindromes(char *s) {
    char *begin = findNonSpace(s);
    char *end = getEndOfString(s);
    char *commaPos = find(begin, end, ',');
    int countOfPalindromes = 0;
    WordDescriptor word;

    if (*begin == '\0')
        countOfPalindromes--;

    while (*commaPos != '\0') {
        word.begin = findNonSpace(begin);
        word.end = commaPos;

        countOfPalindromes += isPalindrome(word.begin, word.end);
        begin = commaPos + 1;
        commaPos = find(begin, end, ',');
    }

    getWord(begin, &word);
    countOfPalindromes += isPalindrome(word.begin, word.end);

    return countOfPalindromes;
}

void test_countOfPalindromes_isEmpty() {
    char s[] = "";
    assert(countOfPalindromes(s) == 0);
}

void test_countOfPalindromes_hasSpacesWord() {
    char s[] = " , ";
    assert(countOfPalindromes(s) == 2);
}

void test_countOfPalindromes_hasOnePalindrome() {
    char s[] = "rraarr";
    assert(countOfPalindromes(s) == 1);
}

void test_countOfPalindromes_hasPalindromes() {
    char s[] = "rraarr,toot,ff,dood";
    assert(countOfPalindromes(s) == 4);
}

void test_countOfPalindromes_hasPalindromesAndOtherWords() {
    char s[] = "rraarr,home,toot,work,dood";
    assert(countOfPalindromes(s) == 3);
}

void test_countOfPalindromes() {
    test_countOfPalindromes_isEmpty();
    test_countOfPalindromes_hasSpacesWord();
    test_countOfPalindromes_hasOnePalindrome();
    test_countOfPalindromes_hasPalindromes();
    test_countOfPalindromes_hasPalindromesAndOtherWords();
}


#endif