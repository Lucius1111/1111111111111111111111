#ifndef INC_TASKS_H
#define INC_TASKS_H

#include "removeAdjacentEqualLetters.h"
#include "removeNonLetters.h"
#include "digitToStartWithPreservingOrderForAll.h"
#include "transformsNumbersToSpaces.h"
#include "transformsAllWordsW1ToW2.h"
#include "isLexigraphicallyOrderedString.h"
#include "printReverseWordsOneByOneToString.h"
#include "countOfPalindromes.h"
#include "getStringWithAlternatingWordsOfTwoStrings.h"

void test_tasks(){
    test_removeAdjacentEqualLetters();
    test_removeNonLetters();
    test_digitToStartWithPreservingOrderForAll();
    test_transformsNumbersToSpaces();
    test_transformsAllWordsW1toW2();
    test_isLexigraphicallyOrderedString();
    test_printReverseWordsOneByOneToString();
    test_countOfPalindromes();
    test_getStringWithAlternatingWordsOfTwoStrings();
}




#endif
