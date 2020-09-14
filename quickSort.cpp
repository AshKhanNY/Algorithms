// Quicksort algorithm
// Ash Khan, 9/14/2020

#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

//Sorting and printer
void quickSort(int* vec, int len);
void printer(int* vec, int len);
int randomIndex(int k);
int i;

//Driver function
int main(){
    int A[20];
    srand(time(0)); //Prevents predictable random numbers
    for(i = 0; i < 20; i++) A[i] = (rand() % 100);
    int aSize = sizeof(A)/sizeof(A[0]);
    printer(A, aSize);
    quickSort(A, aSize);
    printer(A, aSize);
}

void quickSort(int* vec, int len){
    if (len < 2) return;
    int temp = randomIndex(len);
    int pivot = vec[temp];
    vec[temp] = vec[len - 1];
    vec[len-1] = pivot;
    int smInd = 0, lgInd = len-1;
    while (smInd < lgInd){
        while (vec[smInd] < pivot) ++smInd;
        while (vec[lgInd] >= pivot && smInd < lgInd) --lgInd;
        if (vec[smInd] != vec[lgInd]){ int hold = vec[smInd]; vec[smInd] = vec[lgInd]; vec[lgInd] = hold; }
    }
    vec[len-1] = vec[smInd]; 
    vec[smInd] = pivot;
    quickSort(vec, smInd);
    quickSort(vec + smInd + 1, len - smInd - 1);
}

int randomIndex(int k){ return rand() % k; }

void printer(int* vec, int len){
    printf("[ ");
	for (i = 0; i < len; ++i) printf("%i ", vec[i]); 
	printf("]\n");
}
