#include "bits/stdc++.h"
#include "fstream"
#include "time.h"
#include "stdlib.h"
using namespace std;

void savedata()
{
    fstream file;
    file.open("userdata.txt", ios::out | ios::app);

    string name, pass, div;
    
    cout<<"Username: "; cin>>name; file << name<<" ";
    cout<<"Password: "; cin>>pass; file << pass<<" ";
    cout<<"Division: "; cin>>div;  file << div<<endl;
    
}


// void login()
// {
//     string usrname, passwd;
//     cout << "Username: ";
//     cin >> usrname;
//     cout << "Password: ";
//     cin >> passwd;
//     if (usr_pwd[usrname] == passwd)
//     {
//         cout << "Login success!" << endl;
//         play();
//     }
//     else
//     {
//         cout << "Wrong password! Try again" << endl;
//         prompt();
//     }
// }

// void signup()
// {
//     string usrname, passwd1, passwd2;
//     int lt;
//     cout << "Username: ";
//     cin >> usrname;
//     if (usr_pwd.find(usrname) != usr_pwd.end())
//     {
//         cout << "Username already exist. press 1 to login or press 2 to try again..." << endl;
//         cin >> lt;
//         lt == 1 ? login() : signup();
//     }
//     cout << "Password: ";
//     cin >> passwd1;
//     cout << "Confirm password: ";
//     cin >> passwd2;
//     if (passwd1 == passwd2)
//     {
//         file.open(filename, ios::app);
//         file << usrname << endl
//              << passwd1 << endl;
//         file.close();
//         cout << "Registered successfully!" << endl;
//         play();
//     }
//     else
//     {
//         cout << "Password doesn't match! Try again..." << endl;
//         signup();
//     }
// }

// void prompt()
// {
//     int ch;
//     cout << "Enter your choice (1-login 2-register):";
//     cin >> ch;
//     switch (ch)
//     {
//     case 1:
//         login();
//         break;
//     case 2:
//         signup();
//         break;
//     default:
//         cout << "Invalid Input. Try again..." << endl;
//         prompt();
//         break;
//     }
// }