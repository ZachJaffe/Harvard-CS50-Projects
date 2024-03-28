// Checks to see if a password contains an uppercase and lowercase letter in addition to a number and a symbol
// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
bool valid(string password);

// Main Function
int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Function to check if password is valid
bool valid(string password)
{
    int countupper = 0;
    int countlower = 0;
    int countnumber = 0;
    int countsymbol = 0;
    for (int i = 0, length = strlen(password); i < length; i++)
    {
        if (isupper(password[i]))
        {
            countupper += 1;
        }
        else if (islower(password[i]))
        {
            countlower += 1;
        }
        else if (isdigit(password[i]))
        {
            countnumber += 1;
        }
        else if (!isalnum(password[i]))
        {
            countsymbol += 1;
        }
    }
    if (countupper > 0 && countlower > 0 && countnumber > 0 && countsymbol > 0)
    {
        return true;
    }
    return false;
}
