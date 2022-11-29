#include <iostream>

using namespace std;

void printArray(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}

double getSum(double arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
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
    double grades[10];
    double input = 0;
    int count = 0;

    cout << "Enter grades (-1 to end): " << endl;

    while (input != -1 && count < 10)
    {
        cout << "Enter grade: " << endl;
        cin >> input;

        if (input != -1)
        {
            grades[count] = input;
            count++;
        }
    }

    printArray(grades, count);

    double sum = getSum(grades, count);
    double average = sum / count;

    cout << "\n" << endl;
    cout << "Sum of Grades: " << sum << endl;
    cout << "Average: " << average << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Grade " << (i + 1) << ": " << getLetterGrade(grades[i]) << " " << grades[i] << addAstericks(grades[i], average) << endl;
    }
}