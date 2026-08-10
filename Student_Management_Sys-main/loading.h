#include <iostream>
#include <windows.h>
#include <iomanip> // for setw
using namespace std;

void loadingBar() {
    system("cls");
    char fillChar = 219; // solid white block
    const string indent = "\t\t\t\t\t";
    cout << "\n\n\n\n" << indent << "Student's Record Management System";
    cout << "\n"        << indent << "Project By Adarsh RAI";
    cout << "\n\n\n"    << indent << "Loading...\n\n";
    cout << indent;
    // total blocks = 26
    string bar = "";
    for (int i = 0; i < 26; i++) {
        bar += fillChar;
        double percent = (i + 1) * 100 / 26;        // "\r" brings cursor to start of line to overwrite
        cout << "\r" << indent << bar << " " << setw(3) << percent << "%" << flush; //setwidth
        Sleep(300); // adjust speed here
    }
	cout<<"\n";
    cout << "\n" << indent << " Loading Complete!\n\n";
	cout<<endl;
    system("pause");
}
