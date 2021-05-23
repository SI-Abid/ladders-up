#include "bits/stdc++.h"
#include "library.h"
#include "fstream"
#include "saiham.cpp"

using namespace std;

// const int n=10;
const char *filename = "userdata.txt";
map<string, pair<string, string>> usr_pwd;
fstream file;

void play();
void prompt();
void login();
void signup();

int main()
{
    system("clear");
    savedata();

    string uuid;
    file.open(filename, ios::in);
    if (file)
    {
        while (file >> uuid)
        {
            file >> usr_pwd[uuid].first >> usr_pwd[uuid].second;
        }
    }
    file.close();

    for(auto X : usr_pwd)
    {
        cout << X.first << " " << X.second.first<<" "<<X.second.second<<endl;
    }

    // prompt();
    // auto gm = gameboard.MAP;
    // for (int i = 1; i < gm.size(); i++)
    // {
    //     printf("%2d = (%d, %d)\n", i, gm[i].first, gm[i].second);
    // }
    // gameboard.
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
        system("clear"); // for linux
    }
    cout << endl;
}
