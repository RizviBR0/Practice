#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>
using namespace std;

// Mapping from text to Morse code
unordered_map<char, string> textToMorse = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "/"} // Use '/' to represent space between words
};

// Mapping from Morse code to text
unordered_map<string, char> morseToText;

// Initializing morseToText map from textToMorse
void initializeMorseToText()
{
    for (const auto &pair : textToMorse)
    {
        morseToText[pair.second] = pair.first;
    }
}

// Function to convert Text to Morse code
void t2m(const string &s)
{
    cout << "-------------------\nOutput: ";
    for (size_t i = 0; i < s.length(); ++i)
    {
        char c = toupper(s[i]);
        if (textToMorse.count(c))
        {
            cout << textToMorse[c] << " ";
        }
        else
        {
            // Handle unknown characters
            cout << "? ";
        }
    }
    cout << endl;
}

// Function to convert Morse code to Text
void m2t(const string &s)
{
    cout << "-------------------\nOutput: ";
    istringstream iss(s);
    string morseChar;
    while (iss >> morseChar)
    {
        if (morseChar == "/")
        {
            cout << " ";
        }
        else if (morseToText.count(morseChar))
        {
            cout << morseToText[morseChar];
        }
        else
        {
            // Handle unknown Morse codes
            cout << "?";
        }
    }
    cout << endl;
}

int main()
{
    int input;
    string str;

    // Initializing Morse to Text mapping
    initializeMorseToText();

    cout << "1) Morse to Text.\n2) Text to Morse.\n-----------------\n";

    cout << "Enter a choice: ";
    cin >> input;
    cin.ignore(); // Consume the newline character left by cin

    switch (input)
    {
    case 1:
        cout << "Enter Morse code (separate letters by spaces and words by '/'): ";
        getline(cin, str);
        m2t(str);
        break;

    case 2:
        cout << "Enter text: ";
        getline(cin, str);
        t2m(str);
        break;

    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}