
/* -----------------------------------------------------------------------------------
Include in your homework your name, the date, and the class, in a comment line.
Submit your homework, with the homework number and the class in the subject line, by
e-mail to phjmbrass@gmail.com. Do not share code with other students.
----------------------------------------------------------------------------------- */

// Ashraq Khan // 10.05.2020 
// Homework 2 CS 22000 (Algorithms)


#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<cassert>
#include<iostream>
using namespace std;

int i; //Global index variable
void radixSort(int* A, int len);
void printer(int* A, int len);

struct node {
    int data;
    node* next;
};

class LinkedList {
private:
    node* head, * tail;
public:
    // Constructor
    LinkedList() { head = tail = NULL; }
    // Getter Methods
    node* getHead() { return head; }
    node* getTail() { return tail; }
    // Manipulators
    void insert(int entry) {
        //Inserts at tail
        node* tmp = new node;
        tmp->data = entry;
        tmp->next = NULL;
        if (head == NULL) { //Empty list
            head = tmp;
            tail = tmp;
        }
        else { //Non-empty, can use tail
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void clear() {
        node* remove_ptr;
        while (head != NULL) {
            remove_ptr = head;
            head = head->next;
            delete remove_ptr;
        }
        head = tail = NULL;
    }

    void display(node* head) {
        if (head == NULL) cout << "NULL" << endl;
        else {
            cout << head->data << endl;
            display(head->next);
        }
    }
};

int main()
{
    int i, offset, j;
    int size = 10000000;
    int* B = (int*)malloc(size * sizeof(int));
    time_t t;
    srand((unsigned)time(&t));
    offset = rand() % size;
    for (i = 0; i < size; i++)
    {
        B[i] = ((91 * i) % size) + offset;
    }
    printf("Prepared array of 10 million integers; calling sort\n");
    radixSort(B, size);
    printf("finished sort, now check result\n");
    for (i = 0, j = 0; i < size; i++)
        if (B[i] != i + offset) j++;
    if (j == 0)
        printf("Passed Test\n");
    else
        printf("Failed Test. %d numbers wrong.\n", j);
}

void concatenate(int* A, LinkedList* B);

void printer(int* A, int len) {
    printf("[ ");
    for (i = 0; i < len; ++i) printf("%i ", A[i]);
    printf("]\n");
}

void radixSort(int* A, int len) {
    LinkedList bucket[2]; // Array of buckets for 0,1
    for (i = 0; i < 2; ++i) { bucket[i] = LinkedList(); }

    int max = 16;
    int digit, buckInd, bit;
    for (i = 0; i < 16; ++i) {
        for (int k = 0; k < len; ++k) {
            digit = A[k] & 0xFFFF;
            bit = (digit >> i) & 1;
            bucket[bit].insert(A[k]);
        }
        concatenate(A, bucket);
    }
    for (i = 0; i < 16; ++i) {
        for (int k = 0; k < len; ++k) {
            digit = (A[k] >> 16) & 0xFFFF;
            bit = (digit >> i) & 1;
            bucket[bit].insert(A[k]);
        }
        concatenate(A, bucket);
    }
    
    //printer(A, len);
}

void concatenate(int* A, LinkedList* B) {
    int buckInd = 0;
    for (int j = 0; j < 2; ++j) {
        node* tmp = B[j].getHead();
        while (tmp != NULL) {
            A[buckInd++] = tmp->data;
            tmp = tmp->next;
        }
    }
    for (int j = 0; j < 2; ++j) {
        B[j].clear();
    }
}
