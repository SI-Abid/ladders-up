//make the map for randomized traps
#include <bits/stdc++.h>
#include "time.h"
#include "stdlib.h"
using namespace std;

vector<bool> traps(int size);

vector<bool> traps(int size)
{
    vector<bool> array(size);
    srand(time(0));

    for(int i=0; i<size; i++)
    {
        rand()*100 % size == 0  ? array[i] = true : array[i] = false;
    }

    return array;
}

int main()
{
    return 0;
}