#include <iostream>
using namespace std;

void heapify(int input[], int n, int i) {
    int small = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && input[small]>input[l])
        small = l;
    if(r<n && input[small]>input[r]) 
        small = r;
    if(small!=i) {
        int temp = input[small];
        input[small] = input[i];
        input[i] = temp;
        heapify(input, n,small);
    }
}

void inplaceHeapSort(int input[], int n){
    
    int start = (n/2)-1;
    for(int i=start; i>=0;i--) {
        heapify(input,n,i);
    }
    
    while(n>1) {
        int temp = input[0];
        input[0] = input[n-1];
        input[n-1]=temp;
        n--;
        heapify(input,n,0);
    }

}


int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
	inplaceHeapSort(input, size);
	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}
