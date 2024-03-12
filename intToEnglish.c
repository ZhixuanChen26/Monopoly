/*
Program Name: Number to English Word Converter
Purpose: This program converts an integer from 1 to 999 into its English word representation.
Author: Zhixuan Chen
Student Number: 251314352
*/
#include <stdio.h>

int main(){
    int number;
    while(1){
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf(" %d", &number);
        if(number == 0){
            break;
        }else if(number < 1000 && number > 0){
            printf("You entered the number ");
            const char* one[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"};
            const char* tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
            here:
            if (number >= 1 && number <= 19) {
                printf("%s", one[number - 1]);
            } else if (number >= 20 && number <= 99) {
                printf("%s", tens[number / 10 - 2]);
                if (number % 10 != 0) {
                    printf("-%s", one[number % 10 - 1]);
                }
                } else if (number >= 100 && number <= 999) {
                    printf("%s hundred", one[number / 100 - 1]);
                    if (number % 100 != 0) {
                        printf(" and ");
                        number = number % 100;
                        goto here;
                        }
                }
                printf("\n\n");
            }else{
                continue;
        }
    }
    return 0;
}