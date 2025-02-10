#include <iostream>
using namespace std;

//QUICK SORT LOGIC
int partition(int a[10],int low,int high)
{
	int up,down,pivot,temp;
	
	pivot = a[low];
	up = low +1;
	down = high;
	
	while(up < down)
	{
		while(a[up] < pivot)
			up++;
		while(a[down] > pivot)
			down--;
			
		if(up < down)
		{
			temp = a[up];
			a[up] = a[down];
			a[down] = temp;
		}
	}
	
	a[low] = a[down];
	a[down] = pivot;
	
	return down;
}

void quicksort (int a[10],int low,int high)
{
	if (low<high)
	{
		int k = partition (a,low,high);
		quicksort(a,low,k-1);
		quicksort(a,k+1,high);
	}
}

int main()
{
	int a[] = {28,34,1,2,16,84,38,11,23,20},i,j,low=0,mid=0,high=0,size;
	int n = sizeof(a) / sizeof(a[0]); // Calculate the size of the array
	
	quicksort(a,0,10);
	cout<<"The Quick SORT IS: ";
	for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
	cout<<endl;
	
	return 0;
}
