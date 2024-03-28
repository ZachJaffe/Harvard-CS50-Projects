// Replace vowels with numbers (a with 6, e with 3, i with 1, o with 0)
// Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Prototypes
string replace(string input);

// Main Function
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("Error. Incorrect Usage.");
        return 1;
    }
}

// Function to perform vowel substitution
string replace(string input)
{
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            input[i] = '6';
        }
        else if (input[i] == 'e' || input[i] == 'E')
        {
            input[i] = '3';
        }
        else if (input[i] == 'i' || input[i] == 'I')
        {
            input[i] = '1';
        }
        else if (input[i] == 'o' || input[i] == 'O')
        {
            input[i] = '0';
        }
    }
    return input;
}
