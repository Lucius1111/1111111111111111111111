#ifndef INC_STRING_H
#define INC_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>

# define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20

char stringBuffer[MAX_STRING_SIZE + 1];

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

BagOfWords bag;
BagOfWords bag2;

size_t strlen_(const char *begin);

char *find(char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));


char *copyReverse(char *rbeginSource, const char *rendSource,
                  char *beginDestination);

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

int getWord(char *beginSearch, WordDescriptor *word);

int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

void wordDescriptorToString(WordDescriptor word, char *destination);

#endif
