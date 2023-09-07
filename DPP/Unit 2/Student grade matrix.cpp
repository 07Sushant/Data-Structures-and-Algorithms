#include <iostream>
using namespace std;

struct Node {
    int row, col, value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows, cols;
    Node** header;  
public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        header = new Node*[rows];
        for (int i = 0; i < rows; i++) {
            header[i] = new Node(i, -1, -1);  
        }
    }

    void insert(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            Node* newNode = new Node(row, col, value);
            Node* current = header[row];
            while (current->next && current->next->col < col) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            Node* current = header[i]->next;  
            for (int j = 0; j < cols; j++) {
                if (current && current->col == j) {
                    cout << current->value << " ";
                    current = current->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    ~SparseMatrix() {
        for (int i = 0; i < rows; i++) {
            Node* current = header[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] header;
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;

    SparseMatrix matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            if (value != 0) {
                matrix.insert(i, j, value);
            }
        }
    }

    matrix.display();

    return 0;
}


//Sushant
