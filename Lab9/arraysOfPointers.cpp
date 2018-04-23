#include <iostream>
using namespace std;

bool valid_word_char(char ch)
{
    if (('A' <= ch) && ('Z' >= ch)) return true;
    if (('a' <= ch) && ('z' >= ch)) return true;
    if (('0' <= ch) && ('9' >= ch)) return true;
    if (('\'' == ch) || ('.' == ch))  return true;
    return false;
}

void print_single_word(char str[])
{
    int i = 0;
    while (valid_word_char(str[i])) 
        cout << str[i++];
}

int calc_word_length(char str[])
{
    int i = 0;
    while (valid_word_char(str[i]))
        i++;
    return i;
}

char *increment_word(char str[])
{
    int i = 0;
    while (valid_word_char(str[i])) 
        i++; // Pass through word
    while ((str[i] != '\0') &&  (!valid_word_char(str[i]))) 
        i++; // To next word
    return &str[i]; // This is a pointer to the next word
}

int main()
{
    const int max = 200;
    char sentence[max] = "The rhino is a homely beast,\nFor human eyes he's not a feast.\nFarewell, farewell, you old rhinoceros,\nI'll stare at something less prepoceros."; // (of Ogden Nash)
    char *words[max];

    cout << sentence << endl;

    int w = 0;
    words[0] = sentence;
    while (words[w][0] != '\0') {
        words[w+1] = increment_word(words[w]);
        w++;
    }

    cout << "---- Total words w = " << w << " -------" << endl;

    for (int i = 0; i < w; i++) {   
        print_single_word(words[i]);
        cout << endl;
    }
    return 0;
}