// a program that prompts a user for their name and then outputs their initials in uppercase with no spaces or periods.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char *name;
    name = malloc(sizeof(name) * 500);
    gets(name);
    char initials[10];
    int j = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (i == 0)                              // first letter in the name
            initials[j++] = toupper(name[i]);

        if (name[i] == ' ')                      // initial after space
            initials[j++] = toupper(name[i+1]);
    }

    free(name);

    for(int i = 0; i < j; i++)                   // prints initials
    {
        if(initials[i] != ' ')
            printf("%c", initials[i]);
    }
    printf("\n");

    return 0;
}
