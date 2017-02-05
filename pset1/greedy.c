#include<stdio.h>
#include<cs50.h>
#include<math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5

int main(void)
{
    float total_money;
    int no_of_coins, money_owed;
    no_of_coins = 0;
    
    //asking for a positive valid number.
    do
    {
        printf("hi! How much change is owed?\n");
        total_money = GetFloat();
        if (total_money == 0)
        {
            return 0;
        }
    } while (total_money < 0);
    
    //round amount to 2 decimals for avoiding imprecisions.
    money_owed =(int)round(total_money*100); // converting into cents and typecasting float value to integer
    
    //number of Quarters:
    no_of_coins += money_owed / QUARTER;
    money_owed = money_owed % QUARTER;
    
    //number of Dimes:
    no_of_coins += money_owed / DIME;
    money_owed = money_owed % DIME;
    
    //number of Nickels:
    no_of_coins += money_owed / NICKEL;
    money_owed = money_owed % NICKEL;
   
    printf("%d\n", no_of_coins + money_owed); // adding the remaining pennys if any.
    return 0;
}