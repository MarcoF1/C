#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Given an integer N greater than 1, determine its prime factorization. Note that N may be quite large, so you should use a data type larger than int.

int MultipleRemainders(unsigned int divisible, unsigned int divisor);

int main () {
    // declare num and assign a value
    unsigned int num;
    scanf("%d", &num);

    // declare variables
    unsigned int currentDividedNum = num;
    unsigned int remainder;

    // array where the prime factors will be
    char factors[1000];

    for(unsigned int i = 2; i<num; i++) {
        remainder = currentDividedNum % i;

        if (remainder == 0) {
            // factor was found
            const int power = MultipleRemainders(currentDividedNum, i);
            currentDividedNum = currentDividedNum / (int) pow(i, power);
            
            if(factors[0] != '\0') {
                char spaceString[3] = " * ";
                strncat(factors, spaceString, 3);
            }

            char iString[100];
            sprintf(iString, "%d", i);
            char quote[1] = "^";
            char powerString[100];
            sprintf(powerString, "%d", power);

            strncat(factors, iString, 100);
            strncat(factors, quote, 1);
            strncat(factors, powerString, 100);    
            
        }
    }
    printf("%s", factors);
}

// checks how many times the divisor can be divided in 
int MultipleRemainders(unsigned int divisible, unsigned int divisor) {
    int remainder = divisible % divisor;

    if(remainder == 0) {
        return 1 + MultipleRemainders(divisible/divisor, divisor);
    }
    return 0;
}

// returns 1 if the number is prime, 0 otherwise
int isPrime(unsigned int num) {
    unsigned int remainder;
    for(unsigned int i = 1; i < num; i++){
        remainder = num % i;
        if (remainder == 0){
            return 0;
        }
    }
    return 1;
}