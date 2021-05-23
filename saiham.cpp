#include "bits/stdc++.h"
#include "fstream"
using namespace std;

int main()
{
    fstream file;
    file.open("in.csv", ios::in);

    string greetings, commit;
    
    file >> greetings >> commit;

    cout<< greetings <<endl<<commit<<endl;
    
    return 0;
}