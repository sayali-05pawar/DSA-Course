//SPARSE MATRIX
#include <iostream>
using namespace std;

int main()
{
	int r1,c1,i,j,a[100][100],nonze = 0,sp[100][3],k=1;
	
	cout<<"Enter the rows: ";
	cin>>r1;
	
	cout<<"Enter the columns: ";
	cin>>c1;
	
	cout<<"Enter the elements for given matrix: ";
	for(i=0;i<r1;i++) 
		for(j=0;j<c1;j++)
			cin>>a[i][j];
	
	/*Logic to count the non-zero elements	in given matrix*/
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			if(a[i][j] != 0)
				nonze = nonze+1;
	cout<<"The non zero elements in the matrix is: "<<nonze;
	
	/*Specification about original matrix*/
	sp[0][0] = r1;
	sp[0][1] = c1;
	sp[0][2] = nonze;
	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			if(a[i][j] != 0)
			{
				sp[k][0] = i;
				sp[k][1] = j;
				sp[k][2] = a[i][j];
				k++;
			}
		}
	}
	
	cout<<"\nThe SPARSE MATRIX is:\n";
	for(i=0;i<nonze+1;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
			cout<<sp[i][j]<<'\t';
	}
	
	return 0;
}
