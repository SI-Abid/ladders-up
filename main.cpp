#include "iostream"
#include "map"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "library.h"
#include "saiham.h"
#include "tangin.h"

using namespace std;

int score = 0;
// const char *name = "userdata.txt";
string title = "<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~> LADDERS UP <~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>";
void play();
void Menu();

int main()
{
    system("clear");
    loadQuiz();
    while(true)
    {
        prompt();
        Menu();
    }
    
    return 0;
}

void Menu()
{
    string menu = "1: Play\n2: Highscore (X)\n3: Log out\nEnter your option: ";
    cout << menu;
    string opt;
    cin >> opt;
    switch (opt[0])
    {
    case '1':
        play();
        break;
    case '2':
        Highscore();
        break;
    case '3':
        return;

    default:
        break;
    }
    // if(opt=="1")
    // {
    //     play();
    // }
    // else if(opt=="2")
    // {
    //     Highscore();
    // }
    // else if(opt=="3")
    // {
    //     return;
    // }
    saveScore(score);
    Menu();
}

void play()
{
    srand(time(0));
    int n;
    n = getDifficulty();
    loadTraps(n);
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;

    while (pos < n * n)
    {

        // system("cls");       // for windows
        
        system("clear"); // for linux
        cout << title << endl;

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 4 * n; k++)
            {
                printf("-");
            }
            cout << endl;

            for (int j = 0; j < n; j++)
            {
                if(pos==board[i][j])
                {
                    cout << "| X ";
                }
                else
                {
                    cout<<"|   ";
                }
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 4 * n; k++)
        {
            cout << "-";
        }
        cout << endl;
        
        if (isTrap[pos])
        {
            cout << "Oops! You have landed on a trap..." << endl;
            score -= 5;
        }
        else if (pos%19==0)
        {
            score += popQuiz();
        }
        else
        {
            score += 5;
        }
        int move = 1;
        
        do
        {
            if (move > 10 || move < 1)
            {
                cout << "Invalid move. Try again..." << endl;
            }
            cout << "Enter how many cell you want to move forward(1-10): ";
            cin >> move;
        } while (move > 10 || move < 1);

        pos += move;
        
        // printf("\033");
    }
    cout << endl;
}
