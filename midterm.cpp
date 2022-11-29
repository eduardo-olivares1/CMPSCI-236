#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

double getSum(double *arr, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void createFile(string filename, double *arr, int size, double average)
{
    // Open file
    ofstream outFile(filename.c_str());

    // 6. Handles any potential exceptions e.g. unable to create or read file. (2 pt)
    if (outFile.fail())
    {
        cout << "File failed to open..." << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            outFile << arr[i] << ' ';
        }
        else
        {
            outFile << arr[i] << '\n';
        }
    }

    outFile << average;

    outFile.close();
}

double getData(string filename)
{
    // Open file
    ifstream inFile(filename.c_str());

    string firstLine;
    string averageString;
    double average;

    // 6. Handles any potential exceptions e.g. unable to create or read file. (2 pt)
    if (inFile.fail())
    {
        cout << "File failed to open..." << endl;
        exit(1);
    }

    while (inFile.good())
    {

        getline(inFile, firstLine);
        getline(inFile, averageString);

        if (inFile.eof())
        {
            break;
        }
    }

    inFile.close();

    return stod(averageString);
}

int main()
{
    // 1. Asks user the number of students in class and creates a dynamic array of doubles of that size. (2 pts)
    int numgrades;
    cout << "Enter the number of students in class: ";
    cin >> numgrades;
    double *grades = new double[numgrades];

    double input = 0;
    int count = 0;

    cout << "Enter " << numgrades << " grades: " << endl;

    // 2. Asks user each student's grade (range is 1-100) and stores in array created in step 1. (1 pt
    while (count < numgrades)
    {
        cout << "Enter grade " << count + 1 << " (1-100):" << endl;
        cin >> input;

        if (input != -1)
        {
            grades[count] = input;
            count++;
        }
    }

    // 3. Calculates average of class. (1 pt)
    double sum = getSum(grades, count);
    double average = sum / count;

    // 4. Stores the information in a file named "class_grades.dat" - all grades on first line separated by spaces and average on the second line. (3 pts)
    createFile("class_grades.dat", grades, numgrades, average);

    // 5. Reads from the file and displays class average only (You must read from file). (3 pts)
    double data = getData("class_grades.dat");
    cout << "Average: " << data << endl;

    delete [] grades;
}