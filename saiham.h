#include "bits/stdc++.h"
#include "fstream"
#include "time.h"
#include "stdlib.h"
using namespace std;

typedef struct
{
    string pswd, dvsn;   // pswd = password, dvsn = division
} data;

const char *filename= "userdata.txt";
map <string, data> usr_pwd;

//------------------Prototypes---------------

void prompt();
void signup();
void login();
void LoadData();

//------------------Functions----------------

void LoadData()
{
    fstream file;
    file.open(filename, ios::in);
    if(file)
    {
        string uuid;
        while(file >> uuid)
        {
            file >> usr_pwd[uuid].pswd >> usr_pwd[uuid].dvsn;
        }
    }
}

void login()
{
    string usrname, passwd;
    system("clear");
    puts("-------Login-------");
    cout << "Username: ";
    cin >> usrname;
    cout << "Password: ";
    cin >> passwd;
    if (usr_pwd[usrname].pswd == passwd)
    {
        cout << "Login success!" << endl;
        return;
    }
    else
    {
        system("clear");
        cout << "Wrong password! Try again" << endl;
        prompt();
    }
}

void signup()
{
    string usrname, passwd1, passwd2;
    int lt;
    system("clear");
    puts("------Register------");
    cout << "Username: ";
    cin >> usrname;
    
    if (usr_pwd.find(usrname) != usr_pwd.end())
    {
        system("clear");
        cout << "Username already exist. press 1 to login or press 2 to try again..." << endl;
        cin >> lt;
        lt == 1 ? login() : signup();
        return;
    }
    LineBreak:      // come here when pswd not matched
    cout << "Password: ";
    cin >> passwd1;
    cout << "Confirm password: ";
    cin >> passwd2;
    if (passwd1 == passwd2)
    {
        fstream file;
        file.open(filename, ios::out | ios::app);
        string div;
        cout << "Division: "; cin >> div;

        file << usrname << " " << passwd1 << " " << div << endl;
        
        cout << "Registered successfully!" << endl;
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
    int ch;
    string menu = "1: login\n2: register\n3: Quit\nEnter your choice: ";
    cout << menu;
    cin >> ch;
    switch (ch)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid Input. Try again..." << endl;
        prompt();
        break;
    }
}