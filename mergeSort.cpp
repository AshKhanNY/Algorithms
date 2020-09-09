// Mergesort algorithm
// Ash Khan, 9/8/2020

#include<iostream>
#include<vector>
#include<cstdio>
#include<ctime> 
#include<cstdlib>
#include<iterator>

using namespace std;

// Node struct
struct node {
    node* next;
    int val;
    node(const int& v = 0, node* n = NULL){ next = n; val = v; }
};

// Mergesort functions
void mergeSort(node* head);
void mergeSort(vector<int>& vec);

// Printer and RNG
int randNum();
void printer(const vector<int> vec);
void printer(node* head);

// Driver
int main(){
    vector<int> test;
    for (int i = 0; i < 1000; ++i) test.push_back(randNum());
    mergeSort(test);
    printer(test);
}

int randNum(){
    srand((unsigned)time(0)); // Prevents predictable random num
    return (rand() % 1000) + 1;
}

void mergeSort(vector<int>& vec){
    if (vec.size() < 2) return;
    if (vec.size() == 2){ if(vec[0] > vec[1]) swap(vec[0],vec[1]); return; }
    size_t const half = vec.size() / 2;
    vector<int> low(vec.begin(), vec.begin() + half);
    vector<int> high(vec.begin() + half, vec.end());
    mergeSort(low);
    mergeSort(high);
    vector<int> aux(vec.size());
    int i, j, k;
    for (i = j = k = 0; i < low.size() || j < high.size() || k < aux.size(); ++k){
        if (i+1 == low.size()){ aux[k] = low[j]; ++j; }
        else if (j+1 == low.size()){ aux[k] = low[i]; ++i; }
        else if (low[i] > high[j]){ aux[k] = high[j]; ++j; }
        else { aux[k] = low[i]; ++i; }
    }
}

void printer(const vector<int> vec) {
    printf("[");
	for (auto i : vec) printf("%i,", i);
	printf("]\n");
}

void printer(node* head) {
    printf("[ ");
	for (node* i = head; i != NULL; i = i->next) printf("%i,", i->val);
	printf("]\n");
}