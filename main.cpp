#include "bits/stdc++.h"
#include "library.h"
#include "fstream"
#include "saiham.cpp"

using namespace std;

// const int n=10;
// const char *name = "userdata.txt";
map<string, pair<string, string>> usrpwd;
fstream file;

void play();

int main()
{
    system("clear");
    
    LoadData();
    prompt();    

    string uuid;
    file.open(filename, ios::in);
    if (file)
    {
        while (file >> uuid)
        {
            file >> usrpwd[uuid].first >> usrpwd[uuid].second;
        }
    }
    file.close();

    for(auto X : usrpwd)
    {
        cout << X.first << " " << X.second.first<<" "<<X.second.second<<endl;
    }

    play();

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
