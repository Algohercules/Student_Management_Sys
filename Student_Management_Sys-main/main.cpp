#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm> // for transform
#include "loading.h"
#include "adminFunction.h"
using namespace std;
void mainMenu(); // forward declaration
void passwordVerification() {
    system("cls");
    string password;
    cout << "\n\n\t\t\tStarting password verification..." << flush;
    cout << "\n\n\t\t\tEnter Password : " << flush;
    do {
        cin >> password;
        // // Convert to lowercase for case-insensitive check
        // transform(password.begin(), password.end(), password.begin(), ::tolower);
        if (password == "password") {
            break;
        }
        if (password == "quit" || password == "exit") {
            system("cls");
            cout << "\n\n\t\tQuitting the Program";
            for (int i = 0; i < 3; i++) {
                Sleep(500);
                cout << "." << flush;
            }
            exit(0);
        }

        // Wrong password
        system("cls");
        cout << "\n\n\t\tWrong password! Try again or type 'quit' / 'exit' to quit.";
        cout << "\n\n\t\tEnter Password : " << flush;

    }while (true);
    cout << "\n\n\t\tCorrect password! Going to main menu..." << flush;
    Sleep(1000);
    mainMenu(); // go to main menu
}
int main() {
    system("cls");
    system("color 9F");
    loadingBar();
    Sleep(1000);
    passwordVerification();
    return 0;
}
