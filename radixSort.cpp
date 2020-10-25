// Mark III

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<cassert>
#include<iostream>
using namespace std;

int i, k; //Global index variables
void sort(int* A, int n);
struct node;
class LinkedList;
void concatenate(int* A, LinkedList* B);

struct node {
    int data;
    node *next;
};

class LinkedList {
private:
    node *head, *tail;
public:
    // Constructor
    LinkedList() { head = tail = NULL; }
    // Getter Methods
    node* getHead() { return head; }
    node* getTail() { return tail; }
    // Manipulators

    void insert(int entry) {
        node* tmp = new node;
        tmp->data = entry;
        tmp->next = NULL;
        if (head == NULL) { head = tmp; tail = tmp; }
        else {
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
};

int main()
{
    int i, offset, j;
    int size = 1e7;
    int* B = (int*)malloc(size * sizeof(int));
    time_t t;
    srand((unsigned)time(&t));
    offset = rand() % size;
    for (i = 0; i < size; i++)
    {
        B[i] = ((91 * i) % size) + offset;
    }
    printf("Prepared array of 10 million integers; calling sort\n");
    sort(B, size);
    printf("finished sort, now check result\n");
    for (i = 0, j = 0; i < size; i++)
        if (B[i] != i + offset) j++;
    if (j == 0)
        printf("Passed Test\n");
    else
        printf("Failed Test. %d numbers wrong.\n", j);
    time_t now;
    time(&now);
    printf("%i seconds!\n", int(now - t));
}

void sort(int* A, int n) {
    const int max = 16*16*16*16;
    LinkedList* bucket = new LinkedList[max]; // Array of buckets for 0...16
    // Reads every 4 bits, checks hex digit per bit
    // Reason why we use 4 bits is b/c we compare n w/ 0xFFFF
    int digit, buckInd;
    for (k = 0; k < n; ++k) {
        // Grabs desired bit
        digit = A[k] & 0xFFFF;
        bucket[digit].insert(A[k]);
    }
    buckInd = 0;
    node* tmp;
    for (k = 0; k < 16 * 16 * 16 * 16; ++k) {
        tmp = bucket[k].getHead();
        while (tmp != NULL) {
            A[buckInd++] = tmp->data;
            tmp = tmp->next;
        }
    }
    bucket = new LinkedList[max];
    for (k = 0; k < n; ++k) {
        // Grabs desired bit
        digit = (A[k] >> 16) & 0xFFFF;
        bucket[digit].insert(A[k]);
    }
    buckInd = 0;
    for (k = 0; k < 16 * 16 * 16 * 16; ++k) {
        tmp = bucket[k].getHead();
        while (tmp != NULL) {
            A[buckInd++] = tmp->data;
            tmp = tmp->next;
        }
    }
}

void concatenate(int* A, LinkedList* B) {
    int buckInd = 0;
    node* tmp;
    for (k = 0; k < 16*16*16*16; ++k) {
        tmp = B[k].getHead();
        while (tmp != NULL) {
            A[buckInd++] = tmp->data;
            tmp = tmp->next;
        }
    }
}
