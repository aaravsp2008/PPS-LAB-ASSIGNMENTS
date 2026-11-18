#include <stdio.h>

int main() {
    int a[3][3], b[3][3], res[3][3];
    int i, j;

    printf("::: Enter 3x3 matrix for robot sensor A :::\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element [%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n::: Enter 3x3 matrix for robot sensor B :::\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element [%d][%d] : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\n* Output :\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("robot sensor A(3x3) + robot sensor B(3x3) = resultant(3x3)\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    for (i = 0; i < 3; i++) {
        printf("[%3d %3d %3d] ", a[i][0], a[i][1], a[i][2]);
        
        if (i == 1) 
          printf("+ ");
        else 
          printf("  ");

        printf("[%3d %3d %3d] ", b[i][0], b[i][1], b[i][2]);
        
        if (i == 1) 
          printf("= ");
        else 
          printf("  ");

        printf("[%3d %3d %3d]\n", res[i][0], res[i][1], res[i][2]);
    }

    printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

    return 0;
}
