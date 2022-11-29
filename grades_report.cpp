#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void createFile(string filename)
{
    // Open file
    ofstream outFile(filename.c_str());

    // Check for successful open
    if (outFile.fail())
    {
        cout << "File failed to open..." << endl;
        exit(1);
    }

    // Send data to the file
    outFile << "2333021 BOKOW, R. NS201 3 A" << endl
            << "2333021 BOKOW, R. MG342 3 A " << endl
            << "2333021 BOKOW, R. FA302 1 A" << endl
            << "2574063 FALLIN, D. MK106 3 C" << endl
            << "2574063 FALLIN, D. MA208 3 B" << endl
            << "2574063 FALLIN, D. CM201 3 C" << endl
            << "2574063 FALLIN, D. CP101 2 B" << endl
            << "2663628 KINGSLEY, M. QA140 3 A" << endl
            << "2663628 KINGSLEY, M. CM245 3 B" << endl
            << "2663628 KINGSLEY, M. EQ521 3 A" << endl
            << "2663628 KINGSLEY, M. MK341 3 A" << endl
            << "2663628 KINGSLEY, M. CP101 2 B" << endl;

    outFile.close();
}

vector<vector<string>> getData(string filename)
{
    // Open file
    ifstream inFile(filename.c_str());
    vector<vector<string>> data;
    string studentID;
    string firstName;
    string lastName;
    string fullName;
    string courseCode;
    string courseCredits;
    string courseGrade;

    // Check for successful open
    if (inFile.fail())
    {
        cout << "File failed to open..." << endl;
        exit(1);
    }

    // Read and display file contents
    inFile >> studentID >> firstName >> lastName >> courseCode >> courseCredits >> courseGrade;
    fullName = firstName + ' ' + lastName;
    while (inFile.good())
    {
        vector<string> row = {studentID, fullName, courseCode, courseCredits, courseGrade};
        data.push_back(row);
        inFile >> studentID >> firstName >> lastName >> courseCode >> courseCredits >> courseGrade;
        fullName = firstName + ' ' + lastName;
    }

    inFile.close();

    return data;
}

vector<string> getNames(vector<vector<string>> data)
{
    vector<string> names;
    for (int i = 0; i < data.size(); i++)
    {
        string name = data[i][1];
        bool nameInArr = false;
        for (int i = 0; i < names.size(); i++)
        {
            if (names[i] == name)
            {
                nameInArr = true;
            }
        }

        if (!nameInArr)
        {
            names.push_back(name);
        }
    }
    return names;
}

int gradeToNumber(string letter)
{

    int number;
    char c = letter[0];
    switch (c)
    {
    case 'A':
        number = 4;
        break;
    case 'B':
        number = 3;
        break;
    case 'C':
        number = 2;
        break;
    case 'D':
        number = 1;
        break;
    case 'F':
        number = 0;
        break;
    default:
        number = 0;
    }

    return number;
}

void printGradeReport(string name, vector<vector<string>> data)
{
    vector<vector<string>> nameData;
    int totalCredits = 0;
    int letterSum = 0;
    double gpa = 0;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][1] == name)
        {
            nameData.push_back(data[i]);
        }
    }

    for (int i = 0; i < nameData.size(); i++)
    {
        int credit = stoi(nameData[i][3]);
        totalCredits += credit;
        letterSum += gradeToNumber(nameData[i][4]);
    }

    gpa = (double)letterSum / (double)nameData.size();

    cout << "Student Name: " << name << endl;
    cout << "Student ID Number: " << nameData[0][0] << "\n"
         << endl;

    cout << left << setw(13) << "Course Code" << setw(16)  << "Course Credits" << setw(13) <<  "Course Grade" << endl;

    for (int i = 0; i < nameData.size(); i++)
    {
        cout << left << setw(13) << nameData[i][2] << setw(16) << nameData[i][3] << setw(13) << nameData[i][4] << endl;
    }

    cout << endl;

    cout << "Total Semester Course Credits Completed: " << totalCredits << endl;
    cout << "Semester GPA: " << setprecision(1) << fixed << gpa << endl;

    cout << endl;
}

int main()
{
    vector<vector<string>> data;
    vector<string> names;
    createFile("grades.dat");
    data = getData("grades.dat");
    names = getNames(data);

    for (int i = 0; i < names.size(); i++)
    {
        printGradeReport(names[i], data);
    }

    return 0;
}
