#include <iostream>
#include <fstream>
using namespace std;

// Структура, яка описує елемент списку
struct Node {
    int data;      // Значення елемента
    Node* next;    // Вказівник на наступний елемент списку
};

// Функція для додавання елемента в кінець списку
void addToEnd(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Функція для копіювання підсписка з номера N до номера N + K в новий список
Node* copySublist(Node* head, int n, int k) {
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    Node* curr = head;
    int count = 1;

    while (curr != nullptr && count < n) {
        curr = curr->next;
        count++;
    }

    while (curr != nullptr && count <= n + k) {
        Node* newNode = new Node;
        newNode->data = curr->data;
        newNode->next = nullptr;

        if (newHead == nullptr) {
            newHead = newNode;
            newTail = newNode;
        }
        else {
            newTail->next = newNode;
            newTail = newNode;
        }

        curr = curr->next;
        count++;
    }

    return newHead;
}

int main() {
    Node* head = nullptr;
    int n, k;
    char choice;

    cout << "Do you want to read from file or from keyboard? (f/k) ";
    cin >> choice;

    if (choice == 'f') {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;

        ifstream infile(filename);
        if (infile.is_open()) {
            int value;
            while (infile >> value) {
                addToEnd(head, value);
            }
            infile.close();
        }
        else {
            cout << "Error opening file" << endl;
            return 1;
        }
    }
    else if (choice == 'k') {
        int value;
        cout << "Enter values (0 to stop): ";
        while (cin >> value && value != 0) {
            addToEnd(head, value);
        }
    }
    else {
        cout << "Invalid choice" << endl;
        return 1;
    }

    cout << "List: ";
    printList(head);

    cout << "Enter N and K: ";
    cin >> n >> k;

    Node* sublist = copySublist(head, n, k);
    cout << "Sublist: ";
    printList(sublist);

    return 0;
}
