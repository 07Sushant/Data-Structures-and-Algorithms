#include <iostream>

class Student {
public:
    int roll_number;
    Student* prev;
    Student* next;

    Student(int roll_number) {
        this->roll_number = roll_number;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class StudentManagementSystem {
public:
    Student* head;

    StudentManagementSystem() {
        head = nullptr;
    }

    void insertStudent(int roll_number) {
        Student* new_student = new Student(roll_number);
        if (head == nullptr) {
            head = new_student;
        } else if (roll_number < head->roll_number) {
            new_student->next = head;
            head->prev = new_student;
            head = new_student;
        } else {
            Student* current = head;
            while (current->next != nullptr && current->next->roll_number < roll_number) {
                current = current->next;
            }
            new_student->next = current->next;
            new_student->prev = current;
            if (current->next != nullptr) {
                current->next->prev = new_student;
            }
            current->next = new_student;
        }
    }

    void displayStudents() {
        Student* current = head;
        while (current != nullptr) {
            std::cout << current->roll_number;
            if (current->next != nullptr) {
                std::cout << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int N;
    std::cin >> N;
    StudentManagementSystem sms;

    for (int i = 0; i < N; ++i) {
        int roll_number;
        std::cin >> roll_number;
        sms.insertStudent(roll_number);
    }

    std::cout << "Created Doubly Linked List:" << std::endl;
    sms.displayStudents();

    return 0;
}
//Sushant