/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 11
 Assignment Title - Consider an employee database of N employees. Make use of a hash table implementation to quickly 
 look up the employer's id number.*/

#include <iostream>
using namespace std;
#define SIZE 10

class employee
{
    int empId;
    string name;
    long salary;

public:
    employee() {}
    employee(int id, string n, long s)
    {
        empId = id;
        name = n;
        salary = s;
    }
    void read()
    {
        cout << "Enter the Employee id: ";
        cin >> empId;
        cout << "Enter the Employee name: ";
        cin >> name;
        cout << "Enter the Employee salary: ";
        cin >> salary;
    }
    void display()
    {
        cout << empId << "\t" << name << "\t" << salary << endl;
    }
    int getId()
    {
        return empId;
    }
};

class Hashtable
{
    employee e[SIZE];
    int flag[SIZE];

public:
    Hashtable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            flag[i] = 0;
        }
    }
    int isFull()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (flag[i] == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    void Insert()
    {

        if (isFull())
        {
            cout << "Hashtable is full!!\n\n";
            return;
        }
        employee newr;
        newr.read();
        int id = newr.getId();
        int pos = id % SIZE;
        if (flag[pos] == 0)
        {
            flag[pos]++;
            e[pos] = newr;
        }
        else
        {
            for (int i = 0; i < SIZE; i++)
            {
                pos = (pos + 1) % SIZE;
                if (flag[pos] == 0)
                {
                    flag[pos]++;
                    e[pos] = newr;
                    return;
                }
            }
        }
    }

    // Function to display all employees in the hash table
    void DisplayTable()
    {
        cout << "Position\tID\tName\tSalary" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << "\t\t";
            if (flag[i] == 1)
            { // Slot is occupied
                e[i].display();
            }
            else
            {
                cout << "-\t-\t-" << endl; // Display '-' for empty slots
            }
        }
    }

    void Delete()
    {
        int id;
        cout << "Enter the employee id to delete: ";
        cin >> id;
        int pos = id % SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            if (flag[pos] == 1)
            {
                flag[pos]--;
                cout << "Element Deleted Succesfully" << endl;
                return;
            }
        }
        cout << "Element not found" << endl;
    }
};

int main()
{
    Hashtable ht;
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
            ht.Insert();
            break;
        case 2:
            ht.DisplayTable();
            break;
        case 3:
            ht.Delete();
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
