#ifdef _WIN32
#define CLEAR system("cls")
#endif

#ifndef _WIN32
#define CLEAR system("clear")
#endif

#include "iostream"
#include "algorithm"
// #include "utility"
#include "map"
#include "vector"
#include "fstream"
#include "sstream"
#include "ctype.h"
#include "stdlib.h"
#include "time.h"
#include "cstring"
#include "string"
#include "tangin.h"

using namespace std;

//------------------Structure----------------

typedef struct
{
    string pswd, dvsn; // pswd = password, dvsn = division
} data;

typedef struct
{
    string que, optA, optB, optC;
    char ans;
    bool used;
} quiz;

//----------------------Class--------------------

class Board
{
private:
    int row = 1, col = 1, n;

public:
    int **data;
    vector<pair<int, int>> MAP;

    Board(int);
    ~Board();

    void makeBoard()
    {
        //generate a board of n square
        int nn = n * n, i;
        for (i = 0; i < n; i++)
        {
            if ((i ^ n) % 2)
            {
                col = 1;
                setF(nn - (n * i), n);
            }
            else
            {
                col = 1;
                setR(nn - (n * i), n);
            }
            row++;
        }
        // return data;
    }

    void setF(int n, int k)
    {
        if (k == 0)
            return;

        setF(n - 1, k - 1);
        data[row - 1][col - 1] = n;
        MAP[n] = {row, col};
        col++;
    }

    void setR(int n, int k)
    {
        if (k == 0)
            return;

        data[row - 1][col - 1] = n;
        MAP[n] = {row, col};
        col++;
        setR(n - 1, k - 1);
    }
};

Board::Board(int x)
{
    n = x;
    MAP.resize(x * x + 1);
    data = new int *[x];
    for (int k = 0; k < x; k++)
        data[k] = new int[x];
}

Board::~Board()
{
    for (int i = 0; i < n; i++)
        delete data[i];
    delete data;
}

//---------------------Global varriables----------------

const char *userdata = "Data/userdata.txt";
string division = "Dhaka/Khulna/Barisal/Chittagong/Mymensingh/Rajshahi/Rangpur/Sylhet";
map<string, data> usr_pwd;
map<string, int> scoreBoard1;
vector<pair<string, int>> scoreBoard2;
quiz prosno[50];
vector<bool> isTrap;
string usrname, prefix = "Data/", suffix = ".txt";
// const char *name = "userdata.txt";
const string title = "<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~> LADDERS UP <~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>-<~>";
const string menu = "1: Play\n2: Highscore\n3: Log out\nEnter your option: ";
const string login_menu = "1: login\n2: register\n3: Quit\nEnter your choice: ";

//----------------------Prototypes----------------------

void play();
void Menu();
void prompt();
void signup();
void login();
void loadData();
void loadQuiz();
int popQuiz();
void loadTraps(int);
void loadScore();
void saveScore();
void Highscore();
int random(int, int);
string ToLower(string);
void pause();
bool compare(pair<string, int>, pair<string, int>);
//----------------------Functions-----------------------

void loadData()
{
    fstream file;
    file.open(userdata, ios::in);
    if (file)
    {
        string uuid;
        while (file >> uuid)
        {
            file >> usr_pwd[uuid].pswd >> usr_pwd[uuid].dvsn;
        }
    }
    file.close();
}

void login()
{
    loadData();

    scoreBoard1.clear();
    scoreBoard2.clear();

    string passwd;
    CLEAR;
    cout << title << endl;
    cout << "-------Login-------" << endl;

    cout << "Username: ";
    cin >> usrname;

    cout << "Password: ";
    cin >> passwd;

    if (usr_pwd[usrname].pswd == passwd)
    {
        cout << "Login success!" << endl;
        pause();

        return;
    }
    else
    {
        CLEAR;
        cout << "Wrong password! Try again" << endl;
        prompt();
    }
}

void signup()
{
    loadData();

    string passwd1, passwd2;
    int lt;

    CLEAR;
    cout << title << endl;
    puts("------Register------");

    cout << "Username: ";
    cin >> usrname;

    if (usr_pwd.find(usrname) != usr_pwd.end())
    {
        CLEAR;
        cout << "Username already exist. press 1 to login or press 2 to try again..." << endl;
        cin >> lt;
        lt == 1 ? login() : signup();
        return;
    }

LineBreak: // come here when pswd not matched

    cout << "Password: ";
    cin >> passwd1;
    cout << "Confirm password: ";
    cin >> passwd2;

    if (passwd1 == passwd2)
    {
        fstream file;
        file.open(userdata, ios::out | ios::app);

        string div;
        cout << "Select you division- " << division << endl;
        cout << "Division: ";
        cin >> div;

        file << usrname << " " << passwd1 << " " << ToLower(div) << endl;

        cout << "Registered successfully!" << endl;
        pause();

        file.close();
    }

    else
    {
        cout << "Password doesn't match! Try again..." << endl;
        goto LineBreak;
    }
    return;
}

void prompt()
{
    string ch;

    cout << title << endl;
    cout << login_menu;
    cin >> ch;
    switch (ch[0])
    {
    case '1':
        login();
        break;
    case '2':
        signup();
        break;
    case '3':
        exit(0);
    default:
        cout << "Invalid Input. Try again..." << endl;
        prompt();
        break;
    }
}

string ToLower(string s)
{
    for (char &c : s)
    {
        c = tolower(c);
    }
    return s;
}

void loadQuiz()
{
    string line;
    fstream file;
    file.open("Data/Trivia.txt", ios::in);

    if (file)
        for (int i = 0; i < 50; i++)
        {
            getline(file, prosno[i].que);
            getline(file, line);

            vector<string> options;
            string option;
            stringstream stream(line);

            while (getline(stream, option, ','))
            {
                options.push_back(option);
            }

            prosno[i].optA = options[0];
            prosno[i].optB = options[1];
            prosno[i].optC = options[2];
            prosno[i].ans = options[3][0];
            prosno[i].used = false;
        }
    file.close();
}

void loadTraps(int size)
{
    isTrap.resize(size * size);
    srand(time(0));
    int opacity;
    switch (size)
    {
    case 9:
        opacity = 20;
        break;

    case 13:
        opacity = 15;
        break;

    case 18:
        opacity = 10;
        break;
    }
    for (int i = 1; i < size * size; i++)
    {
        isTrap[i] = ((rand() % opacity) * rand() % opacity ? 0 : 1);
    }
}

void saveScore(int score)
{
    loadScore();

    string div = prefix + usr_pwd[usrname].dvsn + suffix;
    if (score > scoreBoard1[usrname] && score)
    {
        cout << "Hooray! You have made a new highscore." << endl;
        pause();
    }
    scoreBoard1[usrname] = max(scoreBoard1[usrname], score);
    vector<pair<int, string>> pairs;

    for (auto x : scoreBoard1)
    {
        pairs.push_back({x.second, x.first});
    }
    sort(pairs.rbegin(), pairs.rend());

    fstream fout;
    fout.open(div.c_str(), ios::out);
    if (fout)
        for (auto x : pairs)
        {
            fout << x.second << " " << x.first << endl;
        }
    fout.close();
}

int random(int minN, int maxN)
{
    srand(time(0));
    return (rand() % (maxN - minN)) + minN;
}

int popQuiz()
{
    cout << "~~~~~~~~Stop! You have stumbled upon a trivia. Time to test your IQ~~~~~~~~" << endl;
    int r;
    do
    {
        r = random(0, 49);
    } while (prosno[r].used);

    cout << prosno[r].que << endl;
    cout << "(A) " << prosno[r].optA << "(B) " << prosno[r].optB << "(C) " << prosno[r].optC << endl;
    cout << "Your answer(a/b/c): ";
    char c;
    cin >> c;
    prosno[r].used = true;
    if (tolower(c) == prosno[r].ans)
    {
        cout << "Yeppy! Correct answer." << endl;
        return 10;
    }
    else
    {
        cout << "Oops! You are wrong..." << endl;
        return -5;
    }
}

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void Highscore()
{
    loadScore();
    cout << "--------------Leaderboard--------------" << endl;
    for (auto x: scoreBoard2)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << "---------------------------------------" << endl
         << endl;
    pause();
}

void loadScore()
{
    string div = prefix + usr_pwd[usrname].dvsn + suffix;
    fstream fin;
    fin.open(div.c_str(), ios::in);
    scoreBoard2.clear();
    if (fin)
    {
        string name;
        int score;
        while (fin >> name)
        {
            fin >> score;
            // auto value = make_pair(name, score);
            scoreBoard1[name] = score;
            scoreBoard2.push_back({name,score});
        }
    }
    fin.close();
}

void pause()
{
    cout << "Press Enter to continue...";
    cin.get();
    cin.get();
}

void Menu()
{
    CLEAR;
    cout << title << endl;
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
    }

    Menu();
}

void play()
{
    int n;
    int score = 0;

    srand(time(0));
    loadQuiz();
    n = getDifficulty();
    loadTraps(n);
    Board gameboard(n);
    gameboard.makeBoard();
    int **board = gameboard.data;

    int pos = 1, inc;

    while (pos < n * n)
    {
        // system("cls");       // for windows

        CLEAR;
        cout << title << endl;

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= 5 * n; k++)
            {
                printf("-");
            }
            cout << endl;

            for (int j = 0; j < n; j++)
            {
                if (pos == board[i][j])
                {
                    // isTrap[pos-1]?cout << "| 😟 ":cout << "| 🙂 ";
                    if (pos % 19 == 0)
                        cout << "| \U0001F914 "; //thinking emoji
                    else
                        isTrap[pos - 1] ? cout << "| \U0001F635 " : cout << "| \U0001F642 ";
                }
                else
                {
                    cout << "|    ";
                }
            }
            cout << "|" << endl;
        }
        for (int k = 0; k <= 5 * n; k++)
        {
            cout << "-";
        }
        cout << endl;

        if (pos % 19 == 0)
        {
            score += popQuiz();
        }
        else if (isTrap[pos - 1])
        {
            cout << "Oops! You have landed on a trap..." << endl;
            score -= 5;
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
    saveScore(score);
}