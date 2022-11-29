#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string getInput()
{
    string rawSentence = "";
    string sentence = "";
    cout << "Enter a string: " << endl;
    getline(cin, rawSentence);

    for (int i = 0; i < rawSentence.length(); i++)
    {
        if (rawSentence.at(i) == '.')
        {
            sentence += ".";
            break;
        }
        else
        {
            sentence += rawSentence.at(i);
        }
    }

    return sentence;
}

void formatAndDisplayIncorrect(string sentence)
{
    // Vector to store incorrect chars.
    vector<char> incorrect;

    // Capitalize first letter
    sentence[0] = toupper(sentence[0]);

    // Get sentence length
    int len = sentence.length();

    for (int i = 1; i < len; i++)
    {
        // If letter is uppercase
        if (isupper(sentence[i]))
        {
            // Add to list
            incorrect.push_back(sentence.at(i));
            // Lower case it
            sentence[i] = tolower(sentence[i]);
            
        }
    }

    // Ensure only one whitespace
    for (int i = 0; i < len; i++)
        // Check if current char is space
        if (isspace(sentence[i]))
        {
            // Check length, look ahead to see if next char is space
            while (i < len && isspace(sentence[i + 1]))
            {
                // Remove it
                sentence.erase(i + 1, 1);
                incorrect.push_back(' ');
                len--;
            }
        }

    cout << "Cleaned up string: " << endl;
    cout << sentence << endl;

    cout << "Incorrect chars: " << endl;
    cout << "[ ";
    for(int i = 0; i < incorrect.size(); i++){
        if(i == incorrect.size() - 1){
            cout << "'" << incorrect[i] << "'";
        }else{
            cout << "'" << incorrect[i] << "', ";
        }
    }
    cout << " ]";
    cout << endl;
}

int main()
{

    // i am     going   to Go   TO   THe moVies. Plus something else.
    string sentence = getInput();
    formatAndDisplayIncorrect(sentence);
}