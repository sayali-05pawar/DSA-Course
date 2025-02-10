//Transpose of matrix
#include <iostream>
using namespace std;

int main()
{
	int A[100][100],B[100][100],row,col,i,j;
	
	cout<<"Enter the rows: ";
	cin>>row;
	
	cout<<"Enter the columns: ";
	cin>>col;
	
	cout<<"Enter the elements for given matrix: ";
	for(i=0;i<row;i++) 
	{
		for(j=0;j<col;j++) 
		{
			cin>>A[i][j];
		}
	}
	cout<<"\nThe given matrix is: ";
	for(i=0;i<row;i++) 
	{
		cout<<"\n";
		for(j=0;j<col;j++) 
		{
			cout<<A[i][j]<<'\t';
		}
	}
	
	cout<<"\nTRANSPOSE MATRIX: ";
	for(i=0;i<row;i++) 
	{
		for(j=0;j<col;j++) 
		{
			B[i][j] = A[i][j];
		}
	}
	for(i=0;i<row;i++) 
	{
		cout<<"\n";
		for(j=0;j<col;j++) 
		{
			cout<<B[j][i]<<'\t';
		}
	}
	
	return 0;
}
