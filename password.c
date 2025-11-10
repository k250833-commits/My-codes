#include <stdio.h>
#include <string.h>

int main() {
    char correct[] = "hogwarts";
    char pass[50];

    printf("Enter password: ");
    scanf("%s", pass);

    if (strlen(pass) <8) {
        printf("Your password must contain 8 characters!\n");
    } else if (strcmp(pass, correct) == 0) {
        printf("confirm your password\n");
        scanf(" %s", pass);
         if (strcmp(pass, correct) == 0) {
         printf("Correct password.\n");	
		 }
    } else {
        printf("Incorrect password.\n");
    }

    return 0;
}

