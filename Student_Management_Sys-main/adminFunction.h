#include <fstream>      // For file input/output
#include <string.h>     // For C-style string functions
#include <bits/stdc++.h> // Includes most C++ standard libraries (not best practice, but okay here)
#include <string>       // For using C++ string class
#include <windows.h>    // For system("cls"), Sleep()
#include <stdlib.h>     // For exit()
using namespace std;
void addData(void); // done
void viewData(void); //done
void mainMenu(void); //done
void updateData(void);
void deleteData(void); //done
void adminVerification(void); //done
void studentFunction(void); 
void adminFunction() //done
{
    system("cls");
    cout << "\n\n\t\t\t\t\t | Logged In as Admin |\n";
    cout << "\n\n\t\t\t\t\t 1. Add Students Detail";
    cout << "\n\n\t\t\t\t\t 2. Delete Students";
    cout << "\n\n\t\t\t\t\t 3. update Record";
    cout << "\n\n\t\t\t\t\t 4. View Table ";
    cout << "\n\n\t\t\t\t\t 5. Main Menu ";
    cout << "\n\n\t\t\t\t\t 6. Exit";
    int option;
    cout << "\n\n\t\t\t\t\tEnter choice : ";
    do
    {
        cin >> option;
        {
            switch (option)
            {

            case 1:
                addData();
                break;

            case 2:
                deleteData();
                break;

            case 3:
                //cout << "this option is not available"; //
                updateData();
                break;

            case 4:
                viewData();
                break;

            case 5:
                mainMenu();
                break;

            case 6:
                system("cls");
                cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
                for (int i = 0; i < 4; i++)
                {

                    Sleep(1000);
                    cout << ".";
                }
                exit(0);
                break;

            default:
                system("cls");
                cout << "\n\n\t\t\t\t\t Logged In as Admin";
                cout << "\n\n\t\t\t\t\t 1. Add Students Record";
                cout << "\n\n\t\t\t\t\t 2. Delete Record";
                cout << "\n\n\t\t\t\t\t 3. update Record";
                cout << "\n\n\t\t\t\t\t 4. View Table ";
                cout << "\n\n\t\t\t\t\t 5. Main Menu ";
                cout << "\n\n\t\t\t\t\t 6. Exit";
                cout << "\n\n\t\t\t\t\t invalid input!";
                cout << "\n\n\t\t\t\t\t Enter choice : ";
            }
        }

    } while (option != '6');
}

void mainMenu()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t Login As : ";
    cout << "\n\n\n\t\t\t\t\t 1. Admin ";
    cout << "\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\t\t\t\t\t 3. Exit";
    cout << "\n\n\n\t\t\t\t\t Enter your choice : ";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        adminVerification();
        break;
    case 2:
        system("cls");
        cout << "Welcome as a Student";
        studentFunction();
        break;
    case 3:
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";
        for (int i = 0; i < 4; i++)
        {
            Sleep(1000);
            cout << ".";
        }
        exit(0);
        break;
    default:
        cout << "invalid input";
    }

    system("pause");
}

// all Functions for Admin below
void deleteData()
{
    system("cls");
    // Open File pointers
    fstream fin, fout;
    // Open the existing file
    fin.open("data.csv", ios::in);
    // Create a new file to store the non-deleted data
    fout.open("datanew.csv", ios::out);
    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;
    // Get the roll number to decide the data to be deleted
    cout << "Enter the roll number of the record to be deleted: ";
    cin >> rollnum;
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof())
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        int row_size = row.size();
        roll1 = stoi(row[0]);
        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum)
        {
            for (i = 0; i < row_size - 1; i++)
            {
                fout << row[i] << ",";
            }
            fout << row[row_size - 1] << "\n";
        }
        else
        {
            count = 1;
        }
        //if (fin.eof()) break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("data.csv");

    // renaming the new file with the existing file name
    rename("datanew.csv", "data.csv");

    Sleep(2000);

    adminFunction();
}


void updateData()
{
    system("cls");
    cout << "In update function\n";

    fstream fin, fout;
    fin.open("data.csv", ios::in);
    fout.open("datanew.csv", ios::out);

    int rollnum, roll1, count = 0;
    char sub;
    int index;
    string new_data, line, word;
    vector<string> row;

    // Get the roll number and field to update
    cout << "Enter the roll number of the record to be updated: ";
    cin >> rollnum;

    cout << "Enter the first letter of the field to be updated (N/G/B/A/P/C/M): ";
    cin >> sub;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    // Determine index to update
    if (sub == 'n' || sub == 'N') index = 1;
    else if (sub == 'g' || sub == 'G') index = 2;
    else if (sub == 'b' || sub == 'B') index = 3;
    else if (sub == 'a' || sub == 'A') index = 4;
    else if (sub == 'p' || sub == 'P') index = 5;
    else if (sub == 'c' || sub == 'C') index = 6;
    else if (sub == 'm' || sub == 'M') index = 7;
    else {
        cout << "Wrong choice. Try again.\n";
        Sleep(1500);
        updateData(); // re-call
        return;
    }

    // Get new data for update
    cout << "Enter new Detail: ";
    getline(cin, new_data);

    // Read and write data line by line
    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        // Skip invalid rows
        if (row.size() < 8) continue;

        try {
            roll1 = stoi(row[0]);
        } catch (...) {
            continue;
        }

        // Check for matching roll number
        if (roll1 == rollnum) {
            count = 1;
            row[index] = new_data;
        }

        // Write updated or original row to new file
        for (size_t i = 0; i < row.size(); ++i) {
            fout << row[i];
            if (i != row.size() - 1) fout << ", "; // no space
        }
        fout << "\n";
    }

    fin.close();
    fout.close();

    if (count == 0)
        cout << "Record not found.\n";
    else
        cout << "Data updated successfully.\n";

    // Replace old file
    remove("data.csv");
    rename("datanew.csv", "data.csv");

    Sleep(2000);
    adminFunction();
}


void addData()
{
    system("cls");
    fstream file("data.csv", ios::out | ios::app);
    if (!file)
    {
        cout << "\nFailed to open data.csv / data.csv file not found!";
    }
    else
        cout << "\t|Enter Data|" << endl
             << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;
    // file<<"\n";
    file << rollNumber << ", ";
    cout << "\nEnter Student's Name : ";
    // cin>>name;  [take only the first name]
    cin.ignore();
    getline(cin, name);
    file << name << ", ";

    cout << "\nEnter College : ";
    cin >> college;
    file << college << ", ";

    cout << "\nEnter Branch : ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nEnter Attendance : ";
    cin >> attendance;
    file << attendance << ", ";

    cout << "\nEnter Physic's Marks : ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nEnter Chemistry Marks : ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nEnter Maths Marks : ";
    cin >> maths;
    file << maths;
    file<<"\n";
    file.close();

    cout << "\nAdd more Record? (Y / N) : ";

    cin >> moreData;
    if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
    {
        addData();
    }
    else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
        adminFunction();

    else
        cout << "\nEnter a valid option";

    adminFunction();
}

void viewData()
{
    system("cls");
    ifstream file("data.csv");
    if (!file)
    {
        cout << "fail in opening the file/ data.csv doesn't exist";
    }
    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    while (!file.eof()) // file.eof() = detects as how long the file is
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');
        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }
    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();
    cout<<"Taking back to admin section"<<endl;
    system("pause");
    adminFunction();
}
void adminVerification()
{
    system("cls");
    string password;
    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";
    do
    {
        cin >> password;
        if (password != "password")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'menu' to Navigate to Main Menu";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        }
        if (password == "Menu" || password == "menu" || password == "MENU")
        {
            mainMenu();
        }

    }while (password != "password");
    adminFunction(); // main menu function is in the Header File adminFunction.h
}
void studentFunction()
{
    system("cls");
    string targetRoll;
    cout << "\n\t\tEnter your Roll Number to view your record: ";
    cin >> targetRoll;
    fstream file("data.csv", ios::in);
    if (!file)
    {
        cout << "\n\t\t  Failed to open the file!";
        Sleep(2000);
        mainMenu();
        return;
    }
    bool found = false;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    while (getline(file, rollNumber, ',') &&
           getline(file, name, ',') &&
           getline(file, college, ',') &&
           getline(file, branch, ',') &&
           getline(file, attendance, ',') &&
           getline(file, physics, ',') &&
           getline(file, chemistry, ',') &&
           getline(file, maths, '\n'))
    {
        if (rollNumber == targetRoll)
        {
            found = true;
            cout << "\n\n\t\t\t\t\t\t| Student Record |\n";
            cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
            cout << "Roll \t Name \t\t\t College \t Branch \t Attendance \t Physics \t Chemistry \t Maths\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------\n";
            cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance
                 << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << "\n";
            cout << "-----------------------------------------------------------------------------------------------------------------------\n";
            break;
        }
    }
    if (!found)
    {
        cout << "\n\n\t\tStudent with roll number '" << targetRoll << "' not found.\n";
    }
    file.close();
    system("pause");
    mainMenu();
}
