#include <stdlib.h>
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf("  ");
    }
}

void hanoiCallTree(int n, char source_rod, char target_rod, char auxiliary_rod, int depth) {

    printSpaces(depth);
    printf("Hanoi(%d, '%c', '%c', '%c') call started.\n", n, source_rod, target_rod, auxiliary_rod);

    if (n == 1) {
        printSpaces(depth + 1);
        printf("Move disk 1 from %c to %c.\n", source_rod, target_rod);
        printSpaces(depth);
        printf("Hanoi(%d, '%c', '%c', '%c') call finished.\n", n, source_rod, target_rod, auxiliary_rod);
        return;
    }

    hanoiCallTree(n - 1, source_rod, auxiliary_rod, target_rod, depth + 1);

    printSpaces(depth + 1);
    printf("Move disk %d from %c to %c.\n", n, source_rod, target_rod);

    hanoiCallTree(n - 1, auxiliary_rod, target_rod, source_rod, depth + 1);

    printSpaces(depth);
    printf("Hanoi(%d, '%c', '%c', '%c') call finished.\n", n, source_rod, target_rod, auxiliary_rod);
}

int main() {
    int disk_count;

    printf("Enter number of disks for Tower of Hanoi: ");
    scanf("%d", &disk_count);

    if (disk_count < 1) {
        printf("Disk count must be at least 1.\n");
        return 1;
    }

    printf("\nTower of Hanoi Call Tree\n");
    hanoiCallTree(disk_count, 'A', 'C', 'B', 0);

    return 0;
}
