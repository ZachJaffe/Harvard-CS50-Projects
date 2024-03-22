// Scores text based on Coleman-Liau Index to determine reading level. Above grade 16 will not display exact value but 16+ instead
// Libraries
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int letter_count(string a);
float word_count(string b);
float sentence_count(string c);
int index(float d, float e);

// Main Function
int main(void)
{
    string text = get_string("Text: ");
    float L = letter_count(text);
    float W = word_count(text);
    float S = sentence_count(text);
    float x = L / W;
    float y = x * 100;
    float z = S / W;
    float v = z * 100;
    int u = index(y, v);
    if (u < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (u >= 1 && u <= 16)
    {
        printf("Grade %i\n", u);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Count Letters
int letter_count(string a)
{
    int counter1 = 0;
    for (int i = 0, length = strlen(a); i < length; i++)
    {
        if (isalpha(a[i]))
        {
            counter1 += 1;
        }
    }
    return counter1;
}

// Calculate Words
float word_count(string b)
{
    int counter2 = 0;
    for (int j = 0, length = strlen(b); j < length; j++)
    {
        if (b[j] == ' ' && b[j - 1] != ' ')
        {
            counter2 += 1;
        }
    }
    counter2 += 1;
    return counter2;
}

// Calculate sentences
float sentence_count(string c)
{
    int counter3 = 0;
    for (int k = 0, length = strlen(c); k < length; k++)
    {
        if (c[k] == '.' || c[k] == '!' || c[k] == '?')
        {
            counter3 += 1;
        }
    }
    return counter3;
}

// Use Coleman-Liau Index to score
int index(float d, float c)
{
    float score = (0.0588 * d) - (c * .296) - 15.8;
    return round(score);
}
