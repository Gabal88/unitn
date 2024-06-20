#include <iostream>

using namespace std;

// Struttura per la lista concatenata
struct List {
    int data;
    List* next;
};

List* initList() {
    return nullptr;
}

bool isEmpty(List* l) {
    return (l == nullptr);
}

void insert(List*& l, int value) {
    List* newNode = new List;
    newNode->data = value;
    newNode->next = l;
    l = newNode;
}

void printList(List* l) {
    while (l != nullptr) {
        cout << l->data << " ";
        l = l->next;
    }
    cout << endl;
}

void deleteList(List*& l) {
    while (!isEmpty(l)) {
        List* temp = l;
        l = l->next;
        delete temp;
    }
}

// Dichiarazione della funzione listOperator
List* listOperator(List* l);

// Funzione di utilità per calcolare la somma degli elementi precedenti
List* listOperatorHelper(List* l, int& accumulatedSum) {
    if (l == nullptr) {
        return nullptr;
    }

    int current = l->data;
    accumulatedSum += current;

    List* newNode = new List;
    newNode->data = accumulatedSum;
    newNode->next = listOperatorHelper(l->next, accumulatedSum);

    accumulatedSum -= current;
    List* originalNode = new List;
    originalNode->data = current;
    originalNode->next = newNode;

    return originalNode;
}

List* listOperator(List* l) {
    int accumulatedSum = 0;
    return listOperatorHelper(l, accumulatedSum);
}

// Main function
int main() {
    List* l = initList();
    insert(l, 5);
    insert(l, 4);
    insert(l, 2);
    insert(l, 1);

    cout << "Original list: ";
    printList(l);

    List* r = listOperator(l);

    cout << "Modified list: ";
    printList(r);

    deleteList(l);
    deleteList(r);

    return 0;
}
