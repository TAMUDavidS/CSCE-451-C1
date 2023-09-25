#include <iostream>
#include "loading.h"
#include <string>
#include <unistd.h>   
#include "adminFunction.h"
#include "doSomething0.h"

using namespace std;

void passwordVerification(void);
void mainMenu(void);

//Auth Before opening the main program

void passwordVerification()
{
    system("clear");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";

    do
    {
        cin >> password;

        if (password != "password")
        {
            system("clear");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'quit' / 'exit' to Quit The program.";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        }

        if (password == "Quit" || password == "quit" || password == "exit" || password == "Exit" || password == "QUIT" || password == "EXIT")
        {
            system("clear");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

            for (int i = 0; i < 4; i++)
            {

                sleep(1); // 1 second pause;
                cout << ".";
            }

            exit(0);
        }

    }

    while (password != "password");
    mainMenu(); // main menu function is in the Header File adminFunction.h
}

int main()
{
    loadingBar(); // loadingBar() is in the loading.h header for loading animation.

    passwordVerification();
    return 0;
}
