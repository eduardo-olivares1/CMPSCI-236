#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printArray(vector<double> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr.at(i) << ' ';
    }
}


char getLetterGrade(double grade)
{
    if (grade >= 90 && grade <= 100)
    {
        return 'A';
    }
    else if (grade >= 80 && grade < 90)
    {
        return 'B';
    }
    else if (grade >= 70 && grade < 80)
    {
        return 'C';
    }
    else if (grade >= 60 && grade < 70)
    {
        return 'D';
    }
    else if (grade < 60)
    {
        return 'F';
    }
}

char addAstericks(double grade, double average)
{
    if (grade < average)
    {
        return '*';
    }
    else
    {
        return ' ';
    }
}

int main()
{
    vector<double> grades;
    double input = 0;
    int count = 0;

    cout << "Enter grades (-1 to end): " << endl;

    while (input != -1)
    {
        cout << "Enter grade: " << endl;
        cin >> input;

        if (input != -1)
        {
            grades.push_back(input);
            count = grades.size();
        }
    }

    sort(grades.begin(), grades.end(), greater<int>());

    cout << "Grades in desc order: " << endl;
    printArray(grades, count);

    double sum = accumulate(grades.begin(), grades.end(), 0);
    double average = sum / count;

    cout << "\n" << endl;
    cout << "Sum of Grades: " << sum << endl;
    cout << "Average: " << average << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Grade " << (i + 1) << ": " << getLetterGrade(grades.at(i)) << " " << grades.at(i) << addAstericks(grades.at(i), average) << endl;
    }

    return 0;
}