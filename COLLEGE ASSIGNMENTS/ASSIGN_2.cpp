/*Assignment No - 2
 Assignment Title - Consider Employee database of PCCOE (at least 20 records). Database contains different fields 
 of every employee like EMP-ID, EMP-Name and EMP-Salary. 
 a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
 b. Arrange list of Employee alphabetically using Merge Sort.*/

#include <iostream>
using namespace std;

class Employee
{
    private:
    string name;
    int emp_id;
    float salary;

    public:
    void read();
    void display();

    friend int partition(Employee e[],int low,int high);
    friend void quicksort(Employee e[],int low,int high);
    friend void merge(Employee e[],int low,int mid,int high);
    friend void mergesort(Employee e[],int low,int high);
};

void Employee::read()
{
    cout<<"\nEnter the employee details:- ";
    cout<<"\nEmployee Name: ";
    cin>>name;
    cout<<"\nEmployee ID: ";
    cin>>emp_id;
    cout<<"\nEmplyoee Salary: ";
    cin>>salary;
    cout<<"\n-----------------------------------\n";
}

void Employee::display()
{
    cout<<"\nEmployee Name: "<<name;
    cout<<"\nEmployee ID: "<<emp_id;
    cout<<"\nEmplyoee Salary: "<<salary;
    cout<<"\n-----------------------------------\n";
}

int partition(Employee e[],int low,int high)
{
    int pivot,up,down;
    pivot=e[low].emp_id;
    up=low+1;
    down=high;

    while(up<=down)
    {
        while(up<=high && e[up].emp_id < pivot)
            up++;
        while(down>=low && e[down].emp_id > pivot)
            down--;

        if(up<down)
            swap(e[up],e[down]);
    }
    swap(e[low],e[down]);

    return down;
}

void quicksort(Employee e[],int low,int high)
{
    if(low<high)
    {    
        int k = partition(e,low,high);
        quicksort(e,low,k-1);
        quicksort(e,k+1,high);
    }
}

void merge(Employee e[],int low,int mid,int high)
{
    Employee temp[100];;
    int k=0,i,j;
    i=low;
    j=mid+1;

    while(i<=mid && j<=high)
    {
        if(e[i].name < e[j].name)
            temp[k++]=e[i++];
        else if (e[i].name > e[j].name)
            temp[k++]=e[j++];
    }
    while(i<=mid)
    {
         temp[k++]=e[i++];
    }
    while(j<=high)
         temp[k++]=e[j++];

    for(i=low,k=0;i<=high;i++,k++)
    {
        e[i]=temp[k];
    }
}

void mergesort(Employee e[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort(e,low,mid);
        mergesort(e,mid+1,high);

        merge(e,low,mid,high);
    }
}

int main()
{
    Employee e[100];
    int n,choice;

    while(1)
    {
        cout<<"\nMENU:- "
            <<"\n1.Read the Employee Details"
            <<"\n2.Display the Employee Details"
            <<"\n3.Sort Employees by ID(quick sort)"
            <<"\n4.Sort Employees by Name(merge sort)"
            <<"\n5.Exit"
            <<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n-----------------------------------\n";

        switch (choice)
        {
        case 1:
            cout<<"Enter the number of employees: ";;
            cin>>n;
            for(int i=0;i<n;i++)
                e[i].read();
            break;
        
        case 2:
            for(int i=0;i<n;i++)
                e[i].display();
            break;

        case 3:
            quicksort(e,0,n-1);
            for(int i=0;i<n;i++)
                e[i].display();
            break;
        
        case 4:
            mergesort(e,0,n-1);
            for(int i=0;i<n;i++)
                e[i].display();
            break;
            
        case 5:
            cout<<"\nThank You >_< !!!";
            exit(0);

        default:
            cout<<"\nInvalid Choice! Please Enter a valid choice.";

        }
    }
    return 0;
}