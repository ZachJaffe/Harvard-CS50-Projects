// Uses command line argument to determine 26 character key for cipher (each location corresponds to
// the letter in its place alphabetically) and encrypts input accordingly

// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
bool unique_char(string a);
string substitution(string in, string key);

// Global Variable
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

// Main Function
int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26 && unique_char(argv[1]))
    {
        string input = get_string("plaintext: ");
        printf("ciphertext: %s\n", substitution(input, argv[1]));
        return 0;
    }
    else
    {
        printf("Error: Usage = ./substitution 26 unique char key\n");
        return 1;
    }
}

// Function to check if each char is unique
bool unique_char(string a)
{
    int count[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(a[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(a[i]) == alpha[j])
                {
                    count[j] += 1;
                    if (count[j] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Function to substitute input with key
string substitution(string in, string key)
{
    char *output = malloc(strlen(in) + 1);
    for (int k = 0; k < strlen(in); k++)
    {
        if (isupper(in[k]))
        {
            output[k] = toupper(key[in[k] - 'A']);
        }
        else if (islower(in[k]))
        {
            output[k] = tolower(key[in[k] - 'a']);
        }
        else
        {
            output[k] = in[k];
        }
    }
    return output;
}
