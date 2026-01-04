#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void clearList(struct Node** start) {
    struct Node* current = *start;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *start = NULL;
}

void printList(struct Node* start) {
    if (start == NULL) {
        printf("List is currently empty.\n");
        return;
    }
    struct Node* temp = start;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void append(struct Node** start, int data) {
    struct Node* newNode = createNode(data);
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    struct Node* last = *start;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteFromBeginning(struct Node** start) {
    if (*start == NULL) {
        printf("List is already empty, nothing to delete.\n");
        return;
    }
    struct Node* toDelete = *start;
    *start = (*start)->next;
    printf("Value %d deleted from beginning.\n", toDelete->data);
    free(toDelete);
}

void deleteFromEnd(struct Node** start) {
    if (*start == NULL) {
        printf("List is already empty, nothing to delete.\n");
        return;
    }
    if ((*start)->next == NULL) {
        printf("Value %d deleted from end.\n", (*start)->data);
        free(*start);
        *start = NULL;
        return;
    }
    struct Node* previous = NULL;
    struct Node* temp = *start;
    while (temp->next != NULL) {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    printf("Value %d deleted from end.\n", temp->data);
    free(temp);
}

void deleteFromMiddle(struct Node** start, int position) {
    if (*start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *start;
    if (position == 1) {
        deleteFromBeginning(start);
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Value %d at position %d deleted.\n", toDelete->data, position);
    free(toDelete);
}

void prepend(struct Node** start, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *start;
    *start = newNode;
}

void showMenu() {
    printf("\n1. Create New List\n");
    printf("2. Add Element to Beginning\n");
    printf("3. Add Element to End\n");
    printf("4. Delete Element from Beginning\n");
    printf("5. Delete Element from End\n");
    printf("6. Delete Element from Middle\n");
    printf("7. Display List\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

int main() {
    struct Node* head = NULL;
    int choice, data, count, position;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearList(&head);
                printf("How many elements do you want to add to the list? ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &data);
                    append(&head, data);
                }
                printf("New list created.\n");
                printList(head);
                break;
            case 2:
                printf("Enter data to add to beginning: ");
                scanf("%d", &data);
                prepend(&head, data);
                printList(head);
                break;
            case 3:
                printf("Enter data to add to end: ");
                scanf("%d", &data);
                append(&head, data);
                printList(head);
                break;
            case 4:
                deleteFromBeginning(&head);
                printList(head);
                break;
            case 5:
                deleteFromEnd(&head);
                printList(head);
                break;
            case 6:
                printf("Which position do you want to delete? ");
                scanf("%d", &position);
                deleteFromMiddle(&head, position);
                printList(head);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 0);

    clearList(&head);

    return 0;
}
