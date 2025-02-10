//Multiplication of matrix
#include <iostream>
using namespace std;

int main()
{
	int arr1[100][100],row1,col1,arr2[100][100],row2,col2,res[100][100],i,j,k;
	
	cout<<"Enter the rows of first matrix: ";
	cin>>row1;
	cout<<"Enter the columns of first matrix: ";
	cin>>col1;
	
	cout<<"Enter the rows of second matrix: ";
	cin>>row2;
	cout<<"Enter the columns of second matrix: ";
	cin>>col2;
	
	cout<<"Enter the elements for given first matrix: ";
	for(i=0;i<row1;i++) 
	{
		for(j=0;j<col1;j++) 
		{
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter the elements for given second matrix: ";
	for(i=0;i<row2;i++) 
	{
		for(j=0;j<col2;j++) 
		{
			cin>>arr2[i][j];
		}
	}
	
	cout<<"Multiplication of given two matrix is: ";
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			res[i][j] = 0;
			for(k=0;k<col2;k++)
			{
				res[i][j] = res[i][j] + (arr1[i][k] * arr2[i][j]);
			}
		}
	}
	for(i=0;i<row1;i++)
	{
		cout<<"\n";
		for(j=0;j<col2;j++)
		{
			cout<<res[i][j]<<'\t';
		}
	}
	
	return 0;
}
