#include <stdio.h>

int main() {
    int num;
    unsigned long long result = 1;

    
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }

    
    printf("Factorial of %d = %llu\n", num, result);

    return 0;
}

