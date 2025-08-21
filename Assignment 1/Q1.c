#include <stdio.h>

int arr[100], n = 0;

void createArray() {
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    int pos, val;
    if (n == 100) {
        printf("Array is full!\n");
        return;
    }
    printf("Enter position (0 to %d) and value: ", n);
    scanf("%d %d", &pos, &val);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;

    displayArray();
}

void deleteElement() {
    int pos;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Enter position (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    displayArray();
}

void linearSearch() {
    int searchVal, found = 0;
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &searchVal);
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchVal) {
            printf("Found at position %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Not found\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
