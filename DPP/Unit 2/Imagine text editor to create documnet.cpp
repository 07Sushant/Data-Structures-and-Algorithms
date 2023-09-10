#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a singly linked list node
struct Node {
    char data;
    struct Node* next;
};

// Function to insert a character node at the end of the linked list
struct Node* insertEnd(struct Node* head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list of characters is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // An empty list or a list with one character is a palindrome
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow->next;
    slow->next = NULL; // Split the list into two halves

    secondHalf = reverseList(secondHalf); // Reverse the second half of the list

    struct Node* p1 = head;
    struct Node* p2 = secondHalf;

    while (p2 != NULL) {
        if (p1->data != p2->data) {
            return false; // If characters don't match, it's not a palindrome
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main() {
    struct Node* head = NULL;
    char c;

    while (1) {
        scanf(" %c", &c);
        if (c == '$') {
            break;
        }
        head = insertEnd(head, c);
    }

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome\n");
    } else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}


//Susahnt
