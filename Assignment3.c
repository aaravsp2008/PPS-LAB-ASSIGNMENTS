#include <stdio.h>

int main() {
    int choice, num1, num2;
    float div_result;

    printf("--- Basic Arithmetic Calculator ---\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);
    }

    switch (choice) {
        case 1:
            printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
            break;

        case 2:
            printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
            break;

        case 3:
            printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
            break;

        case 4:
            if (num2 != 0) {
                div_result = (float)num1 / num2;
                printf("Result: %d / %d = %.2f\n", num1, num2, div_result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;

        case 5:
            if (num2 != 0) {
                printf("Result: %d %% %d = %d\n", num1, num2, num1 % num2);
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid choice! Please select a number between 1 and 5.\n");
    }

    return 0;
}