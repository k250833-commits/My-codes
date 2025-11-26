#include <stdio.h>

int main() {
    int n, i;
    printf("Input: \n");
    scanf("%d\n", &n);

    int length[n], width[n], height[n];
    int volume[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &length[i], &width[i], &height[i]);
        volume[i] = length[i] * width[i] * height[i];
    }
    printf("\nOutput: \n");
    for (i = 0; i < n; i++) {
        if (height[i] < 41) {
            printf("%d\n", volume[i]);
        }
    }

    return 0;
}

