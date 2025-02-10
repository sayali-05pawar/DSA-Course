//Finding out maximum from each row
#include <iostream>
using namespace std;

int main()
{
	int arr[100][100],row,col,i,j,m;
	
	cout<<"Enter the rows: ";
	cin>>row;
	
	cout<<"Enter the columns: ";
	cin>>col;
	
	cout<<"Enter the elements for given matrix: ";
	for(i=0;i<row;i++) 
	{
		for(j=0;j<col;j++) 
		{
			cin>>arr[i][j]; 
		}
	}
	
	cout<<"The given matrix is: ";
	for(i=0;i<row;i++)
	{
		cout<<"\n"; 
		for(j=0;j<col;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
	}
	
	//Maximum Logic
	for(i=0;i<row;i++)
	{
		m = arr[i][0];
		for(j=0;j<col;j++) 
		{
			if(arr[i][j] > m)
			{
				m = arr[i][j];
			 } 
		}
		cout<<"\nThe maximum in "<<i<<" row is "<<m;
	}
	
	return 0;
}
