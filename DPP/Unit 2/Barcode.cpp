#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

ListNode* addOneToBarcode(ListNode* head) {
    head = reverseList(head);
    ListNode* current = head;
    int carry = 1;
    
    while (current) {
        int sum = current->val + carry;
        carry = sum / 10;
        current->val = sum % 10;
        
        if (carry == 0)
            break;
        
        if (!current->next) {
            current->next = new ListNode(carry);
            break;
        }
        
        current = current->next;
    }
    
    return reverseList(head);
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int digit;
        std::cin >> digit;
        
        ListNode* newNode = new ListNode(digit);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    head = addOneToBarcode(head);
    
    printList(head);
    
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}


//Sushant