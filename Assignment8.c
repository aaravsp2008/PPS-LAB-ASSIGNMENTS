#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int m1, m2;
    int *p1, *p2;

    printf("Enter speed of Motor 1 (m1): ");
    scanf("%d", &m1);
    printf("Enter speed of Motor 2 (m2): ");
    scanf("%d", &m2);

    p1 = &m1;
    p2 = &m2;

    printf("\n--- Before Swapping ---\n");
    printf("Motor 1 Speed: %d | Memory Address: %p\n", m1, (void*)p1);
    printf("Motor 2 Speed: %d | Memory Address: %p\n", m2, (void*)p2);

    swap(p1, p2);

    printf("\n--- After Swapping ---\n");
    printf("Motor 1 Speed: %d | Memory Address: %p\n", m1, (void*)p1);
    printf("Motor 2 Speed: %d | Memory Address: %p\n", m2, (void*)p2);

    return 0;
}