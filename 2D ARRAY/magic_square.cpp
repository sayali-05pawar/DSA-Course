//MAGIC  SQUARE
#include <iostream>
using namespace std;

int main()
{
	int num,i,j,k,a[100][100],r=0,c;
	
	cout<<"Enter an odd number: ";
	cin>>num;
	
	if(num%2 != 0)
	{
		c = num/2;
		for(k=1;k<=num*num;k++)
		{
			a[r][c] = k;
			r--;
			c--;
			
			if (r<0 && c<0)
			{
				r = r+2;
				c++;
			}
			else if(r<0)
				r = num-1;
			else if(c<0)
				c = num-1;
			else if(a[r][c] != 0)
			{
				r = r+2;
				c = c+1;
			}
		}
		
		cout<<"\nMAGIC SQUARE: ";
		for(i=0;i<num;i++)
		{
			cout<<"\n";
			for(j=0;j<num;j++)
			{
				cout<<a[i][j]<<'\t';
			}
		}		
	}
	else
	{
		cout<<"\nCannot Make MAGIC SQUARE !!!";
	}
	
	return 0;
}
