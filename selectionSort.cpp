// Insertionsort algorithm
// Ash Khan, 9/13/2020

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iterator>
#include<vector>

using namespace std;

//Sorting and printer
void selectionSort(vector<int>& vec);
void printer(const vector<int> vec);

//Driver function
int main(){
	vector<int> test;
    srand(time(0)); 
    for(int i = 0; i < 10; i++) test.push_back(rand() % 100);
    printer(test);
    selectionSort(test);
    printer(test);
}

void selectionSort(vector<int>& vec){
    int max, maxIndex; //Keeps track of current max number and index of max number
    for (int i = 0; i < vec.size(); ++i){
        max = vec[vec.size()-1-i]; //Assume last element is max
        maxIndex = vec.size()-1-i;
        for (int k = 0; k < vec.size()-i; ++k){
            if (vec[k] >= max){ 
                max = vec[k]; //Overriding step for new max number
                maxIndex = k;
            }
        }
        swap(vec[vec.size()-1-i], vec[maxIndex]); //Swaps last element with current max number
    }
}

void printer(const vector<int> vec){
    printf("[ ");
	for (auto i : vec) printf("%i ", i);
	printf("]\n");
}