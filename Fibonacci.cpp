#include <stdio.h>

int main() {
    int n, i;
    int first = 0, second = 1, sum;

    
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms:\n", n);

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first);  
            continue;
        }
        if (i == 2) {
            printf("%d ", second); 
            continue;
        }
        sum = first + second;  
        printf("%d ", sum);

        first = second;
        second = sum;
    }

    return 0;
}

