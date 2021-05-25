#include "bits/stdc++.h"
#include "library.h"
#include "fstream"
#include "saiham.cpp"

using namespace std;

// const int n=10;
// const char *name = "userdata.txt";

void play();

int main()
{
    system("clear");
    
    LoadData();
    prompt();    

    string uuid;
    fstream file;
    file.open(filename, ios::in);
    if (file)
    {
        while (file >> uuid)
        {
            file >> usr_pwd[uuid].pswd >> usr_pwd[uuid].dvsn;
        }
    }
    file.close();

    for(auto X : usr_pwd)
    {
        cout << X.first << " " << X.second.pswd<<" "<<X.second.dvsn<<endl;
    }

    play();

    return 0;
}


void play()
{
    cout<<"Enter size: ";
    int n;
    cin >> n;
    
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;
    while (pos < n * n)
    {
        system("clear"); // for linux
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 4 * n; k++)
                printf("-");
            cout << endl;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == pos)
                    printf("| X ");
                else
                    printf("|   ");
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 4 * n; k++)
            printf("-");
        cout << endl
             << "How many cell you want to move forward: ";
        cin >> inc;
        pos += inc;
        // printf("\033");
        // system("cls");       // for windows
        
    }
    cout << endl;
}
