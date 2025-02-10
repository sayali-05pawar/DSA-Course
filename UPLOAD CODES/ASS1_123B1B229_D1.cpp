/* Name - SAYALI PAWAR
 Roll no - SYCOD229
 PRN - 123B1B229
 Div - D

 Assignment No - 1
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

    // Friends to allow access to private members
    friend void insertionSort(Student s[], int n);       // For sorting by roll number
    friend void shellSort(Student s[], int n);           // For sorting by name
    friend void radix_sort(Student s[], int n);          // For finding top students by SGPA
    friend void count_sort(Student s[], int pos, int n); // Helper function for radix sort
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

void displayAll(Student s[], int n)
{
    cout << "Data after sorting:" << endl;
    // Display sorted student data
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }
}

// Function to display sorted student list
void Student::display()
{
    cout << "Roll number of student: " << roll << endl
         << "Name of student: " << name << endl
         << "SGPA of student: " << sgpa << endl
         << "-------------------------------------------------" << endl;
}

// Insertion Sort Function for sorting the students according to the roll numbers
void insertionSort(Student s[], int n)
{
    Student x;
    for (int i = 1; i < n; i++)
    {
        x = s[i];
        int j = i - 1;

        // Move elements greater than `x.roll` to one position ahead
        while (j >= 0 && s[j].roll > x.roll)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = x; // Insert the student at the correct position
    }
}

// Shell Sort Function for sorting the students according to their names
void shellSort(Student s[], int n)
{
    Student x;
    for (int gap = n / 2; gap > 0; gap /= 2) // Reduce the gap each iteration
    {
        for (int i = gap; i < n; i++)
        {
            x = s[i];
            int j = i - gap;

            // Compare students' names lexicographically
            while (j >= 0 && s[j].name > x.name)
            {
                s[j + gap] = s[j];
                j -= gap;
            }
            s[j + gap] = x;
        }
    }
}

// Count Sort used by Radix Sort, sorting according to the current digit (pos)
void count_sort(Student s[], int pos, int n)
{
    int freq[10] = {0}; // Array to store the frequency of digits (0 to 9)

    // Count frequency of each digit in SGPA
    for (int i = 0; i < n; i++)
    {
        int digit = ((int)(s[i].sgpa * 100) / pos) % 10;
        freq[digit]++;
    }

    // Update the frequency array to cumulative frequencies
    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    // Create a temporary array to store the sorted output
    Student *ans = new Student[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = ((int)(s[i].sgpa * 100) / pos) % 10;
        ans[--freq[digit]] = s[i];
    }

    // Copy the sorted output back to the original array
    for (int i = 0; i < n; i++)
    {
        s[i] = ans[i];
    }

    delete[] ans; // Free dynamically allocated memory
}

// Radix Sort Function for finding the top 10 students based on SGPA
void radix_sort(Student s[], int n)
{
    // Find the maximum SGPA to determine the number of digits
    float max_sgpa = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa > max_sgpa)
        {
            max_sgpa = s[i].sgpa;
        }
    }

    // Multiply SGPA by 100 to avoid floating-point issues (considering 2 decimal places)
    int max = (int)(max_sgpa * 100);

    // Sort using count_sort based on each digit starting from the least significant digit
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        count_sort(s, pos, n);
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
            insertionSort(s, n);
            cout << "Sorted by roll number!" << endl;
            break;
        case 2:
            shellSort(s, n);
            cout << "Sorted by name!" << endl;
            break;
        case 3:
            radix_sort(s, n);
            cout << "Sorted by SGPA (Top 10)!" << endl;
            cout << "Top 10 students sorted by SGPA:" << endl;
            for (int i = n - 1, count = 0; i >= 0 && count < 10; i--, count++)
            {
                s[i].display();
            }
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
