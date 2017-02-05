// encrypting a message using vigenere cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    int i, n;
    string key = argv[1];
    
    // check if only single key(string) is passed
    if (argc != 2)
    {
        printf("ERROR!, enter a single key\n");
        return 1;
    }
    // chek if the characters of the key are alphabets
    for(i = 0, n = strlen(key); i < n; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("ERROR!, enter a valid character key!\n");
            return 1;
        }
    }
    
    int keylen = strlen(key);  // length of the key, if declared before checking, doesn't handle lack of argv[1] case
    string text = GetString(); // user text to be encrypted
    int len = strlen(text);    // length of the text
    int k, j = 0;
    char c[len];               // array to store the encrypted text
    
    for (i=0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            
            // j is used for advancement of character in "key" only if the "character" of text is "alphabet" and
            // if it's not an "alphabet" then, only i increments and j doen't.
            // modulo is used so that the characters of the key are used in circular fashion.
            
            if (isupper(key[j % keylen]))
                // k is the integer, determines how many places the character of text should be shifted
                k = (int)key[j % keylen] - (int)'A';
            if (islower(key[j % keylen]))
                k = (int)key[j % keylen] - (int)'a';
            
            j++;
            
            // convert ASCII -> Alpha, Shift with respect to key, Alpha -> ASCII
            if (isupper(text[i]))
                c[i] = ((int)text[i] - (int)'A' + k) % 26 + (int)'A';
            else if(islower(text[i]))
                c[i] = ((int)text[i] - (int)'a' + k) % 26 + (int)'a';
        }
        else
            c[i] = text[i];
    }
    
    // prints the encrypted text
    for(i = 0; i < len; i++)
        printf("%c", c[i]);
    
    printf("\n");
    return 0;
}