//Scores Points Scored for Words without modifiers in the game Scrabble
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//Points for each letter
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Prototype
int scoring(string a);

//Main Function
int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    int x = scoring(p1);
    int y = scoring(p2);
    if (x > y)
    {
        printf("Player 1 wins!\n");
    }
    else if (y > x)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Scoring Function which takes both upper and lowercase
int scoring(string a)
{
    int score = 0;
    int l = strlen(a);
    for (int i = 0; i < l; i++)
    {
        if (isupper(a[i]))
        {
            score += points[a[i] - 'A'];
        }
        else if (islower(a[i]))
        {
            score += points[a[i] - 'a'];
        }
    }
    return score;
}
