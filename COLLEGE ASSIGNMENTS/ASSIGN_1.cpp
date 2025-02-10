/*  Assignment No - 1
 Assignment Title - Consider a student database of SY COMP class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.
 a. Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort
 b. Arrange list of students alphabetically using shell sort
 c. Arrange list of students to find out first ten toppers from a class using Radix sort*/

#include <iostream>
#include <climits>
using namespace std;

class Student
{
    private:
    int roll;    // Roll number of the student
    string name; // Name of the student
    float sgpa;  // SGPA of the student

    public:
    void read();    // Function to read student data
    void display(); // Function to display student data

    friend void insertion(Student s[],int n);
    friend void shellsort(Student s[],int n);
    friend void radixsort(Student s[],int n);
    friend void countsort(Student s[],int n,int exp);

};
// Function to read student data
void Student::read()
{
    cout << "Enter the roll number of student: ";
    cin >> roll;
    cout << "Enter the name of student: ";
    cin >> name;
    cout << "Enter the SGPA of student: ";
    cin >> sgpa;
    cout << "-------------------------------------------------" << endl;
}

// Function to display sorted student list
void Student::display()
{
    cout << "Roll number of student: " << roll << endl
         << "Name of student: " << name << endl
         << "SGPA of student: " << sgpa << endl
         << "-------------------------------------------------" << endl;
}

void insertion(Student s[],int n)
{
    Student x;
    for(int i=1;i<n;i++)
    {
        x=s[i];
        int j=i-1;

        while(j>=0 && s[j].roll > x.roll)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1]=x;
    }
}

void shellsort(Student s[],int n)
{
    Student x;
    for(int gap = n/2; gap>0; gap /=2)
    {
        for(int i=gap; i<n; i++)
        {
            x=s[i];
            int j=i-gap;

            while(j>=0 && s[j].name > x.name)
            {
                s[j+gap] = s[j];
                j= j-gap;
            }
            s[j+gap] = x;
        }
    }
}

void radixsort(Student s[],int n)
{
    int max=s[0].roll;
    for(int i=0;i<n;i++)
    {
        if(s[i].roll > max)
        {
            max=s[i].roll;
        }
    }

    for(int exp=1; max/exp > 0;exp *= 10)
    {
        countsort(s,exp,n);
    }
}

void countsort(Student s[],int n,int exp)
{
    Student *op = new Student[n];
    int count[10] = {0};

    for(int i=0;i<n;i++)
    {
        int index = (s[i].roll/exp)%10;
        count[index]++;
    }

    for(int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--)
    {
        int index=(s[i].roll / exp)%10;
        op[count[index]-1] = s[i];
        count[index]--;
    }

    for(int i=0; i<n; i++)
    {
        s[i] = op[i];
    }

    delete[] op;
}

void reverse(Student s[],int n)
{
    for(int i=0; i<n/2; i++)
    {
        Student temp;
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

void display_top10(Student s[],int n)
{
    for(int i=0; i<n && i<10; i++)
    {
        cout<<s[i].display();
    }
}

void displayAll(Student s[], int n)
{
    cout << "Data after sorting:" << endl;
    // Display sorted student data
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }
}

int main()
{
    Student s[100]; // Array to store students
    int n, choice;

    cout << "Enter the number of students: ";
    cin >> n;

    // Read student data
    for (int i = 0; i < n; i++)
    {
        s[i].read();
    }

    do
    {
        cout << "Choose sorting method:" << endl
             << "1. Insertion Sort for sorting by roll number" << endl
             << "2. Shell Sort for sorting by name" << endl
             << "3. Radix Sort for finding top 10 students by SGPA" << endl
             << "4. Display sorted list" << endl
             << "5. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertion(s, n);
            cout << "Sorted by roll number!" << endl;
            break;
        case 2:
            shellsort(s, n);
            cout << "Sorted by name!" << endl;
            break;
        case 3:
            radixsort(s, n);
            // reverse(s,n);
            // cout << "Sorted by SGPA (Top 10)!" << endl;
            display_top10(s,n);
            // cout << "Top 10 students sorted by SGPA:" << endl;
            // for (int i = n - 1, count = 0; i >= 0 && count < 10; i--, count++)
            // {
            //     s[i].display();
            // }
            break;
        case 4:
            displayAll(s, n);
            break;
        case 5:
            cout << "Exiting the Program!!" << endl;
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
