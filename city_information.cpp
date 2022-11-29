#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

bool contAnswer()
{

    while (true)
    {
        string answer;

        cout << "Add another entry? (y/n)" << endl;
        getline(cin, answer);

        if (answer == "y")
        {
            return true;
        }
        else if (answer == "n")
        {
            return false;
        }
        else
        {
            cout << "Answer not understood please try again" << endl;
            continue;
        }
    }
}

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

    string cityName = "";
    string population = "";
    string mayor = "";
    bool cont = true;

    // Send data to the file
    while (cont)
    {
        cout << "Enter city name: " << endl;
        getline(cin, cityName);

        cout << "Enter population: " << endl;
        getline(cin, population);

        cout << "Enter mayor: " << endl;
        getline(cin, mayor);

        outFile << cityName << "\t" << population << "\t" << mayor << endl;
        cont = contAnswer();
    }

    outFile.close();
}

vector<vector<string>> getData(string filename)
{
    // Open file
    ifstream inFile(filename.c_str());
    vector<vector<string>> data;
    string cityName;
    string population;
    string mayor;
    string line;

    // Check for successful open
    if (inFile.fail())
    {
        cout << "File failed to open..." << endl;
        exit(1);
    }

    while (inFile.good())
    {

        getline(inFile, cityName, '\t');
        getline(inFile, population, '\t');
        getline(inFile, mayor);

        if (inFile.eof())
        {
            break;
        }

        vector<string> row = {cityName, population, mayor};
        data.push_back(row);
    }

    inFile.close();

    return data;
}


bool sortAlphabetically(const vector<string>& r1, const vector<string>& r2)
{
    return r1[0] < r2[0];
}



int main()
{
    vector<vector<string>> data;
    createFile("cities.dat");
    data = getData("cities.dat");

    sort(data.begin(), data.end(), sortAlphabetically);

    cout << left << setw(17) << "City" << setw(15) << "Population" << setw(25) << "Mayor" << endl;

    for (int i = 0; i < data.size(); i++)
    {
        cout << left << setw(17) << data[i][0] << setw(15) << data[i][1] << setw(25) << data[i][2] << endl;
    }
    return 0;
}