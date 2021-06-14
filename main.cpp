#include "iostream"
#include "map"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "library.h"
#include "saiham.h"

using namespace std;


int main()
{
    CLEAR;
    loadQuiz();
    while (true)
    {
        prompt();
        Menu();
    }

    return 0;
}

