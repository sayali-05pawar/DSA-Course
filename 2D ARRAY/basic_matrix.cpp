#include <iostream>
using namespace std;

int main()
{
	int arr[100][100],row,col,i,j;
	
	cout<<"Enter the rows: ";
	cin>>row;
	
	cout<<"Enter the columns: ";
	cin>>col;
	
	cout<<"Enter the elements for given matrix: ";
	for(i=0;i<row;i++) //loop to build rows
	{
		for(j=0;j<col;j++) //loop to build columns
		{
			cin>>arr[i][j]; /*elements will be store like first row then all elements in first col 
								& so on*/
		}
	}
	
	cout<<"The resultant matrix is: ";
	for(i=0;i<row;i++)
	{
		cout<<"\n"; //a newline after each row of the matrix
		for(j=0;j<col;j++)
		{
			cout<<arr[i][j]<<'\t';
		}
	}
}
