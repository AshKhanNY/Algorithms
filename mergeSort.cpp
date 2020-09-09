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
void printer(const vector<int> vec);
void printer(node* head);

// Driver
int main(){
    vector<int> test;
    srand(time(0)); 
    for(int i = 0; i < 10; i++) test.push_back(rand() % 100);
    printer(test);
    mergeSort(test);
    printer(test);
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
    int low_ind, high_ind, aux_ind;
    for (low_ind = high_ind = aux_ind = 0; aux_ind < aux.size(); ++aux_ind){
        if (low_ind == low.size()){ aux[aux_ind] = high[high_ind]; ++high_ind; }
        else if (high_ind == high.size()){ aux[aux_ind] = low[low_ind]; ++low_ind; }
        else if (low[low_ind] > high[high_ind]){ aux[aux_ind] = high[high_ind]; ++high_ind; }
        else if (low[low_ind] <= high[high_ind]){ aux[aux_ind] = low[low_ind]; ++low_ind; }
    }
    vec = aux;
}

void printer(const vector<int> vec) {
    printf("[ ");
	for (auto i : vec) printf("%i ", i);
	printf("]\n");
}

void printer(node* head) {
    printf("[ ");
	for (node* i = head; i != NULL; i = i->next) printf("%i ", i->val);
	printf("]\n");
}
