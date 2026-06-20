#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, hasUpper = 0, hasLower = 0;
    int hasDigit = 0, hasSpecial = 0;
    int score = 0;

    printf("Enter Password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {
        if(isupper(password[i]))
            hasUpper = 1;
        else if(islower(password[i]))
            hasLower = 1;
        else if(isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    if(length >= 8)
        score++;
    if(hasUpper)
        score++;
    if(hasLower)
        score++;
    if(hasDigit)
        score++;
    if(hasSpecial)
        score++;

    printf("\nPassword Analysis:\n");
    printf("Length: %d\n", length);

    if(score <= 2) {
        printf("Strength: Weak\n");
    }
    else if(score <= 4) {
        printf("Strength: Medium\n");
    }
    else {
        printf("Strength: Strong\n");
    }

    printf("\nSuggestions:\n");

    if(length < 8)
        printf("- Use at least 8 characters\n");

    if(!hasUpper)
        printf("- Add uppercase letters\n");

    if(!hasLower)
        printf("- Add lowercase letters\n");

    if(!hasDigit)
        printf("- Add numbers\n");

    if(!hasSpecial)
        printf("- Add special characters\n");

    if(score == 5)
        printf("- Excellent! Your password is very secure.\n");

    return 0;
}