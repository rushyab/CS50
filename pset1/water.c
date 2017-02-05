#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes, bottles;
    bottles = 12; //about 12 bottles of water is used for 1 minute in shower.
    printf("minutes: ");
    minutes = GetInt();
    printf("bottles: %d\n", bottles*minutes);
    return 0;
}
