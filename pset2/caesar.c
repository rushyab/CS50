// encrypting a message using caesar cipher

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    int i = 0;

    // if command line arguments are greater than 2
    if (argc != 2)
    {
        printf("Enter single valid key\n");
        return 1;
    }

    // if key is not a number
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            printf("Invalid key!\n");
            return 1;
        }
    }

    // transform the key string into an int
    int key = atoi(argv[1]);

    // ask user for text
    char text[100];
    gets(text);

    int len = strlen(text);
    char cipher[len];

    for (i = 0; i < len; i++)
    {
        // check whether the character is alphabet
        if (isalpha(text[i]))
        {
            // if the character is uppercase, convert ASCII -> Alpha, Shift with respect to key, Alpha -> ASCII
            if (isupper(text[i]))
                cipher[i] = ((int)text[i] - (int)'A' + key) % 26 + (int)'A';

            // if the character is lowercase, convert ASCII -> Alpha, Shift with respect to key, Alpha -> ASCII
            else if (islower(text[i]))
                cipher[i] = ((int)text[i] - (int)'a' + key) % 26 + (int)'a';
        }
        else
        {
            cipher[i] = text[i];
        }
    }

    // prints cipher code
    for(i = 0; i < len; i++)
        printf("%c", cipher[i]);

    printf("\n");
    return 0;
}
