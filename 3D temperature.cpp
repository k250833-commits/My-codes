#include <stdio.h>

int main() {
    int cities, days;
    printf("Enter number of cities: ");
    scanf("%d", &cities);
    printf("Enter number of days: ");
    scanf("%d", &days);

    float temp[cities][days][3]; // 3 = morning, afternoon, night
    float max[cities];           

    for (int i = 0; i < cities; i++) {
        printf("\nCity %d:\n", i + 1);
        for (int j = 0; j < days; j++) {
            for (int k = 0; k < 3; k++) {
                printf("Enter temp for day %d, time %d (0=Morning,1=Aft,2=Night): ",
                       j + 1, k);
                scanf("%f", &temp[i][j][k]);
            }
        }
    }

    for (int i = 0; i < cities; i++) {
        max[i] = temp[i][0][0]; // start with first value
        for (int j = 0; j < days; j++) {
            for (int k = 0; k < 3; k++) {
                if (temp[i][j][k] > max[i])
                    max[i] = temp[i][j][k];
            }
        }
    }

    printf("\nHighest temperatures:\n");
    for (int i = 0; i < cities; i++)
        printf("City %d: %.1f\n", i + 1, max[i]);

    return 0;
}

