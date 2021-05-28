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
    // int seed = size % 5;
    for(int i=1; i<size; i++)
    {
        time(0)&1 && !array[i-1] ? array[i] = true : array[i] = false;
    }

    return array;
}
