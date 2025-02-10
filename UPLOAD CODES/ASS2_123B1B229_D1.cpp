/*Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 2
 Assignment Title - Consider Employee database of PCCOE (at least 20 records). Database contains different fields 
 of every employee like EMP-ID, EMP-Name and EMP-Salary. 
 a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
 b. Arrange list of Employee alphabetically using Merge Sort.*/

#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    float salary;

    // Function to read employee data from user
    void read();

    // Function to display employee data
    void display();

    // Friend functions for sorting:
    // Quick sort to sort employees by ID
    /*friend void quicksort(Employee e[], int low, int high);

    // Partition function for quicksort (helper function)
    friend int partition(Employee e[], int low, int high);

    // Merge sort to sort employees by Name
    friend void mergeSort(Employee e[], int low, int high);*/
};

void Employee::read()
{
    // Input employee details from user
    cout << "Enter the ID of the employee: ";
    cin >> id;
    cout << "Enter the name of the employee: ";
    cin >> name;
    cout << "Enter the salary of the employee: ";
    cin >> salary;
    cout << "---------------------------------" << endl;
}

void Employee::display()
{
    // Display employee details
    cout << "Employee ID: " << id << endl
         << "Employee Name: " << name << endl
         << "Employee Salary: " << salary << endl
         << "---------------------------------" << endl;
}

// Divides the array into two halves based on a pivot element
int partition(Employee e[], int low, int high)
{
    int pivot = e[low].id;  // Choose the first element's ID as pivot
    int up = low + 1;
    int down = high;

    // Reorganize the array by comparing each element with the pivot
    while (up <= down)
    {
        // Increment up until finding an element greater than the pivot
        while (up <= high && e[up].id < pivot)
            up++;

        // Decrement down until finding an element less than or equal to the pivot
        while (down >= low && e[down].id > pivot)
            down--;

        // Swap elements if indices up and down haven't crossed
        if (up < down)
        {
            swap(e[up], e[down]);
        }
    }

    // Place the pivot element in its correct position
    swap(e[low], e[down]);

    // Return the partition index
    return down;
}

// QuickSort function to sort employees by ID
void quicksort(Employee e[], int low, int high)
{
    // Recursively apply quicksort if there are elements to sort
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(e, low, high);

        // Sort the left part (before the pivot)
        quicksort(e, low, pi - 1);

        // Sort the right part (after the pivot)
        quicksort(e, pi + 1, high);
    }
}

// Merge function for Merge Sort (used to merge two sorted halves)
void merge(Employee e[], int low, int mid, int high)
{
    // Temporary array to store merged elements
    int i = low, j = mid + 1, k = 0;
    Employee temp[100];

    // Compare elements from both halves and merge them in sorted order
    while (i <= mid && j <= high)
    {
        if (e[i].name < e[j].name)
        {
            temp[k++] = e[i++];
        }
        else
        {
            temp[k++] = e[j++];
        }
    }

    // Add remaining elements from the left half
    while (i <= mid)
    {
        temp[k++] = e[i++];
    }

    // Add remaining elements from the right half
    while (j <= high)
    {
        temp[k++] = e[j++];
    }

    // Copy the merged elements back to the original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        e[i] = temp[k];
    }
}

// Merge Sort function to sort employees by Name
void mergeSort(Employee e[], int low, int high)
{
    // Recursively split the array into halves and merge them in sorted order
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Sort the left half
        mergeSort(e, low, mid);

        // Sort the right half
        mergeSort(e, mid + 1, high);

        // Merge the two sorted halves
        merge(e, low, mid, high);
    }
}

// Main function to provide a menu-driven system for sorting and displaying employees
int main()
{
    Employee e[100];
    int n;
    int choice;

    // Menu-driven system with read and display options
    while (1)  
    {
        cout << "\nMENU:";
        cout << "\n1. Read Employee Data";
        cout << "\n2. Sort employees by ID (Quick Sort)";
        cout << "\n3. Sort employees by Name (Merge Sort)";
        cout << "\n4. Display Employee List";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Input the number of employees
            cout << "Enter the number of employees: ";
            cin >> n;

            // Read employee details
            for (int i = 0; i < n; i++)
            {
                e[i].read();
            }
            break;

        case 2:
            quicksort(e, 0, n - 1);
            cout << "\nEmployees sorted by ID:\n";
            for (int i = 0; i < n; i++)
            {
                e[i].display();
            }
            break;

        case 3:
            mergeSort(e, 0, n - 1);
            cout << "\nEmployees sorted by Name:\n";
            for (int i = 0; i < n; i++)
            {
                e[i].display();
            }
            break;

        case 4:
            cout << "\nEmployee List:\n";
            for (int i = 0; i < n; i++)
            {
                e[i].display();
            }
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
