#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}

int main()
{
    int size;
    cin >> size;
    cin.ignore();

    string input;
    getline(cin, input);

    string word = "";
    string updatedSentence = "";

    for (char c : input)
    {
        if (c == ' ' || !isprint(c))
        { 
            reverseString(word);
            updatedSentence += word + c; 
            word = "";
        }
        else
        {
            word += c;
        }
    }

    reverseString(word);
    updatedSentence += word;

    reverseString(updatedSentence);

    cout << "Updated array: " << updatedSentence << endl;

    return 0;
}