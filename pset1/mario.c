#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	int pyramid_height = 0;
	
	// check whether the height value lies within the range 1 and 23.
	do {
		printf("Height:");
		pyramid_height = GetInt();
        if (pyramid_height == 0)
        {
            return 0;
        }
	} while (pyramid_height < 1 || pyramid_height > 23);
    
	for(int i = 0; i < pyramid_height; i++) 
	{
		// Print the required spaces
        for(int j = 0; j < pyramid_height-i-1; j++)
        {
            printf(" ");
        }
        // Print the '#' character.
		for(int k = 0; k < i+2; k++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}