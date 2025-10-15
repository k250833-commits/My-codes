#include <stdio.h>
int main() {
    
    int sectionA[] = {101, 102, 103, 104, 105};
    int sizeA = sizeof(sectionA) / sizeof(sectionA[0]);

    int sectionB[] = {201, 202, 203};
    int sizeB = sizeof(sectionB) / sizeof(sectionB[0]);

    int combinedSize = sizeA + sizeB;
    int combinedRollNumbers[combinedSize];

    for (int i = 0; i < sizeA; i++) {
        combinedRollNumbers[i] = sectionA[i];
    }
    
    for (int i = 0; i < sizeB; i++) {
        combinedRollNumbers[sizeA + i] = sectionB[i];
    }

    printf("Combined Roll Numbers:\n");
    for (int i = 0; i < combinedSize; i++) {
        printf("%d\n", combinedRollNumbers[i]);
    }

	return 0;
}
