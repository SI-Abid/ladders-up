#include "bits/stdc++.h"
#include "library.h"
#include "saiham.h"
#include "tangin.h"

using namespace std;

// const int n=10;
// const char *name = "userdata.txt";
const char *title = "<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<> LADDERS UP <>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>";
void play();

int main()
{
    system("clear");
    
    LoadData();
    prompt();
    // LoadData();

    // for(auto X : usr_pwd)
    // {
    //     cout << X.first << " " << X.second.pswd<<" "<<X.second.dvsn<<endl;
    // }

    play();

    return 0;
}

void play()
{
    int n;
    n = getDifficulty();
    
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;

    while (pos < n * n)
    {
        system("clear");        // for linux
        // system("cls");       // for windows
        puts(title);

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 4 * n; k++)
            {
                printf("-");
            }
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
        {
            printf("-");
        }
        cout << endl
             << "How many cell you want to move forward: ";
        cin >> inc;
        pos += inc;

        // printf("\033");
    }
    cout << endl;
}
