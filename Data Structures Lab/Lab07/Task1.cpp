#include <iostream>
using namespace std;

void swap(int *a, int *b);
void print(int Array[], int size);

void BubbleSort(int Array[], int size){
	for(int i=0; i<size-1; i++){
		int flag=0;
		for(int j=0; j<size-1-i; j++){
			if(Array[j]> Array[j+1]){
				swap(&Array[j], &Array[j+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	
	print(Array,size);
}

void InsertionSort(int Array[], int size){
	for(int i=1; i<size; i++){
		int j=i-1;
		int x= Array[i];
		while(j>-1 && Array[j]>x){
			Array[j+1]=Array[j];
			j--;
		}
		Array[j+1]=x;
	}
	
	print(Array,size);
}

void SelectionSort(int Array[], int size) {
   int min;
   for(int i = 0; i<size-1; i++) {
      min = i;
      for(int j = i+1; j<size; j++)
         if(Array[j] < Array[min]){
         	min = j;
		 }
         swap(&Array[i], &Array[min]);
   }
   print(Array,size);
}

void swap(int *a, int *b){
	int t= *a;
	*a= *b;
	*b= t;
}

void print(int Array[], int size){
	for(int i=0; i<size; i++)
		cout << Array[i] << " ";
	cout << endl;
}
int main(){
	int Array[]={6,5,4,3,2,1};
	int size= sizeof(Array)/sizeof(Array[0]);
	cout << "BUBBLE SORT!\n";
	cout << "Array Before Sorting :\t";
	print(Array,size);
	cout << "Array After Sorting  :\t";
	BubbleSort(Array,size);
	
	int Array2[]={10,1,3,9,6,5};
	size= sizeof(Array2)/sizeof(Array2[0]);
	cout << "\nINSERTION SORT!\n";
	cout << "Array Before Sorting :\t";
	print(Array2,size);
	cout << "Array After Sorting  :\t";
	InsertionSort(Array2,size);
	
	
	int Array3[]={7,5,1,2,8,9};
	size= sizeof(Array3)/sizeof(Array3[0]);
	cout << "\nSELECTION SORT!\n";
	cout << "Array Before Sorting :\t";
	print(Array3,size);
	cout << "Array After Sorting  :\t";
	SelectionSort(Array3,size);
//	selectionSort(Array3,size);
	
}
