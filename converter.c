/*
Program Name: Conversion Calculator
Purpose: This program allows users to perform four different conversions
Author: Zhixuan Chen
Student Number: 251314352
*/
#include <stdio.h>

int main(){
    while(1){
        printf("What do you want to convert?\n1 for conversion between Kilometre and Mile\n2 for conversion between Litres and Gallons\n3 for conversion between Hectares and Acres\n4 for conversion between Kilograms and Pounds\n5 for quit\n");
        int number;  
        char ch; 
        float value;  
        scanf("%d", &number);
        switch (number)
        {
            case 1:
            while(1){
            printf("Type K for conversion from Kilometre to Mile\n");
            printf("Type M for conversion from Mile to Kilometre\n"); 
            scanf(" %c", &ch);
            if (ch == 'K')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 0.621371;
            }
            else if (ch == 'M')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 1/0.621371;
            }
            else 
            {
                continue;
            }
            printf("Your conversion is: %f\n", value);
            break;
            }
            break;
            
            case 2:
            while(1){
            printf("Type L for conversion from Litres to Gallons\n");
            printf("Type G for conversion from Gallons to Litres\n");
            scanf(" %c", &ch);
            if (ch == 'L')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 0.264172;
            }
            else if (ch == 'G')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 1/0.264172;
            }
            else 
            {
                continue;
            }
            printf("Your conversion is: %f\n", value);
            break;
            }
            break;

            case 3:
            while(1){
            printf("Type H for conversion from Hectares to Acres\n");
            printf("Type A for conversion from Acres to Hectares\n");
            scanf(" %c", &ch);
            if (ch == 'H')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 2.47105;
            }
            else if (ch == 'A')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 1/2.47105;
            }
            else 
            {
                continue;
            }
            printf("Your conversion is: %f\n", value);
            break;
            }
            break;

            case 4:
            while(1){
            printf("Type K for conversion from Kilograms to Pounds\n");
            printf("Type P for conversion from Pounds to Kilograms\n");
            scanf(" %c", &ch);
            if (ch == 'K')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 2.20462;
            }
            else if (ch == 'P')
            {
                printf("Please enter a value: ");
                scanf("%f", &value);
                value *= 1/2.20462;
            }
            else 
            {
                continue;
            }
            printf("Your conversion is: %f\n", value);
            break;
            }
            break;

            case 5:
            goto flag;

            default:
            printf("Please try again\n");
            break;
        }
    }
    flag:
    return 0;
}


