#include <iostream>

class StudentNode {
public:
    int student_id;
    StudentNode* next;

    StudentNode(int id) : student_id(id), next(nullptr) {}
};

StudentNode* createStudentRecords(int n, int* studentIds) {
    if (n == 0) {
        return nullptr; 
    }

    StudentNode* head = new StudentNode(studentIds[0]);
    StudentNode* current = head;

    for (int i = 1; i < n; ++i) {
        StudentNode* newNode = new StudentNode(studentIds[i]);
        current->next = newNode;
        current = newNode;
    }

    return head;
}

StudentNode* deleteFirstStudent(StudentNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    StudentNode* newHead = head->next;
    delete head;
    return newHead;
}

void printStudentRecords(StudentNode* head) {
    StudentNode* current = head;
    while (current) {
        std::cout << current->student_id << " ";
        current = current->next;
    }
}

int main() {
    int n;
    std::cin >> n;
    int* studentIds = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> studentIds[i];
    }

    StudentNode* head = createStudentRecords(n, studentIds);

    head = deleteFirstStudent(head);

    printStudentRecords(head);

    while (head) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
    }

    delete[] studentIds;

    return 0;
}


//Sushant
