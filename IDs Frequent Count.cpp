#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of sales: ");
    scanf("%d", &n);

    int sales[n];

    printf("Enter the product IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    int max_count = 0;    
    int most_frequent;    

    for (int i = 0; i < n; i++) {
        int count = 0;  

        for (int j = 0; j < n; j++) {
            if (sales[i] == sales[j]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            most_frequent = sales[i];
        }
    }

    printf("\nThe most frequent product ID is %d (sold %d times)\n",
           most_frequent, max_count);

    return 0;
}

