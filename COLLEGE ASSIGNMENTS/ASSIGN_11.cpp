/* Assignment No - 11
 Assignment Title - Consider an employee database of N employees. Make use of a hash table implementation to quickly 
 look up the employer's id number.*/

#include <iostream>
using namespace std;
#define SIZE 10

class employee 
{
    private:
    int emp_id;
    string name;
    long salary;

    public:
    void read()
    {
        cout<<"Enter the Employee Details:- ";
        cout<<"\nEmployee ID: ";
        cin>>emp_id;
        cout<<"Employee Name: ";
        cin>>name;
        cout<<"Employee Salary: ";
        cin>>salary;
    }

    void display()
    {
        cout<<emp_id<<"\t"<<name<<"\t"<<salary<<endl;
    }

    int get_id()
    {
        return emp_id;
    }
};

class hashtable
{
    employee e[SIZE];
    int flag[SIZE];

    public:
    hashtable()
    {
        for(int i=0; i<SIZE; i++)
        {
            flag[i] = 0;
        }
    }

    int isfull()
    {
        for(int i=0; i<SIZE; i++)
        {
            if(flag[i]==0)
                return 0;
        }
        return 1;
    }

    void insert()
    {
        if(isfull())
        {
            cout<<"Hashtable is full!!";
            return;
        }
        employee newr;
        newr.read();
        int id=newr.get_id();
        int pos= id % SIZE;
        if(flag[pos]==0)
        {
            flag[pos]++;
            e[pos] = newr;
        }
        else
        {
            for(int i=0; i<SIZE; i++)
            {
                pos = (pos+1) % SIZE;
                if(flag[pos]==0)
                {
                    flag[pos]++;
                    e[pos] = newr;
                    return;
                }
            }
        }
    }

    void del()
    {
        int id;
        cout<<"Enter the id which you want to delete: ";
        cin>>id;
        int pos=id % SIZE;
        for(int i=0; i<SIZE; i++)
        {
            if(flag[pos]==1)
            {
                flag[pos]--;
                cout<<"Element Deleted Sucessfully!!";
                return;
            }
        }
        cout<<"Element not found.";
    }

    void display_table()
    {
        cout<<"Position\tID\tName\tSalary"<<endl;
        for(int i=0; i<SIZE; i++)
        {
            cout<<i<<"\t\t";
            if(flag[i]==1)
            {
                e[i].display();
            }
            else{
                cout<<"-\t-\t-"<<endl;
            }
        }
    }
};

int main()
{
    hashtable ht;
    int choice;

    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Delete Employee \n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ht.insert();
            break;
        case 2:
            ht.display_table();
            break;
        case 3:
            ht.del();
            break;
        case 4:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    }

    return 0;
}