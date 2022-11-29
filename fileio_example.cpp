#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void print(ifstream &inFile)
{
    string line;

    // getline(inFile, line);
    // cout << line << endl;

    while (true)
    {
        // inFile >> line;
        // getline(inFile, line);
        if (inFile.eof())
        {
            break;
        }
        cout << line;
    }

    cout << endl;
}

void printFormatted(ifstream &inFile)
{
    cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
    

    string idHeader, name, priceHeader;
    int id;
    double price;

    inFile >> idHeader;
    inFile >> name;
    inFile >> priceHeader;

    cout << setw(7) << idHeader << endl;
    cout << setw(20) << name << endl;
    cout << setw(10) << priceHeader << endl;

    while (true)
    {
        inFile >> id;

        if (inFile.eof())
        {
            break;
        }

        inFile.ignore(); // Take care of phantom character
        getline(inFile, name, '\t');
        inFile >> price;

        cout << setw(7) << id << endl;
        cout << setw(20) << name << endl;
        cout << setprecision(2) << setw(10) << "$" << price << endl;
    }

    cout << endl;
}

int main()
{
    // < --- Write to file --->
    string filename = "C:\\temp\\file_io_example.txt";

    ofstream outFile;
    outFile.open(filename.c_str()); // open explicitly

    if (outFile.fail())
    {
        cout << filename << " refused to open..." << endl;
        exit(1);
    }

    outFile << "Hello world!" << endl;
    outFile.close();

    // <--- Read file --->
    ifstream inFile(filename.c_str());

    if (inFile.fail())
    {
        cout << filename << " refused to open..." << endl;
        exit(2);
    }

    printFormatted(inFile);

    return 0;
}