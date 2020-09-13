/* -----------------------------------------------------------------------------------
Include in your homework your name, the date, and the class, in a comment line.
Submit your homework, with the homework number and the class in the subject line, by
e-mail to phjmbrass@gmail.com. Do not share code with other students. 
----------------------------------------------------------------------------------- */

// Ashraq Khan // 09.13.2020 // CS 22000 (Algorithms)

#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void mergeSort(int* vec, int* aux, int len);
void printer(int* vec, int len);
int common(int A[], int B[], int m, int n);
int i; //Global index variable

// Driver
int main(){
    int A[20]; int auxA[20];
    int B[40]; int auxB[40];
    srand(time(0)); //Prevents predictable random numbers
    for(i = 0; i < 20; i++) A[i] = (rand() % 100);
    for(i = 0; i < 40; i++) B[i] = (rand() % 100);
    int aSize = sizeof(A)/sizeof(A[0]);
    int bSize = sizeof(B)/sizeof(B[0]);
    
    mergeSort(A, auxA, aSize);
    mergeSort(B, auxB, bSize);
    printer(A, aSize);
    printer(B, bSize);
    printf("The number of common elements between the two arrays is %i.", common(A, B, aSize, bSize));
}

void mergeSort(int* vec, int* aux, int len){
    //Base cases
    if (len < 2) return;
    if (len == 2){ 
        if(vec[0] > vec[1]){ int temp = vec[0]; vec[0] = vec[1]; vec[1] = temp; return; } 
    }
    //Recursive step: merge two halves
    int const half = len/2;
    mergeSort(vec, aux, half);
    mergeSort(vec+half, aux, len-half);
    int low_ind, high_ind, aux_ind;
    for (low_ind = aux_ind = 0, high_ind = half; aux_ind < len; ++aux_ind){
        if (low_ind == half){ aux[aux_ind] = vec[high_ind++]; }
        else if (high_ind == len){ aux[aux_ind] = vec[low_ind++]; }
        else if (vec[low_ind] > vec[high_ind]){ aux[aux_ind] = vec[high_ind++]; }
        else if (vec[low_ind] <= vec[high_ind]){ aux[aux_ind] = vec[low_ind++]; }
    }
    for (i = 0; i < len; ++i) vec[i] = aux[i];
}

void printer(int* vec, int len) {
    printf("[ ");
	for (i = 0; i < len; ++i) printf("%i ", vec[i]); 
	printf("]\n");
}

int common(int A[], int B[], int m, int n){
    //count stores number of duplicate elements, temp holds current dupe element
    int a, b, temp, count;
    a = b = count = 0;
    while(a < m && b < n){
        if (A[a] == B[b]){
            ++count;
            temp = A[a];
            //Iterates thru each array until next unique num is found, or until end of array
            while (A[a] == temp){ ++a; if (a == m) return count; }
            while (B[b] == temp){ ++b; if (b == n) return count; }
        }
        else if (A[a] > B[b]) ++b;
        else ++a;
    }
    return count;
}