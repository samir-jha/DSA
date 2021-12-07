/*
    Given a string, replace all the spaces by %20. The given string has sufficient size to accomodate the additional characters.
        Brute Force: O(n2)
        Best approach: O(n)
*/
#include <iostream>
#include <cstring>

using namespace std;

void replaceSpaces(char *s)
{
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    int index = n + (2 * count);
    s[index] = '\0';
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3;
        }
        else
        {
            s[index - 1] = s[i];
            index--;
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 1000);
    replaceSpaces(input);
    cout << input << endl;
    return 0;
}