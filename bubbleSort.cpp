// Bubblesort algorithm
// Ash Khan, 9/13/2020

#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iterator>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& vec);
void printer(const vector<int> vec);

int main(){
	vector<int> test;
    srand(time(0)); 
    for(int i = 0; i < 10; i++) test.push_back(rand() % 100);
    printer(test);
    bubbleSort(test);
    printer(test);
}

void bubbleSort(vector<int>& vec){
    bool ready = false;
	while(!ready){
		ready = true;
		for (int i = 0; i < vec.size()-1; ++i){
			if (vec[i] > vec[i+1]){ swap(vec[i+1], vec[i]); ready = false; }
		}
	}
}

void printer(const vector<int> vec){
    printf("[ ");
	for (auto i : vec) printf("%i ", i);
	printf("]\n");
}