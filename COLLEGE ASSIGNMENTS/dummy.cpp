#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float sgpa;

    // Method to read individual student data
    void read() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter SGPA: ";
        cin >> sgpa;
    }
};

class StudentManager {
    Student s[15];

public:
    int n;

    void get() {
        cout << "Enter the number of students: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nEnter details for student " << i + 1 << ":\n";
            s[i].read();
        }
    }

    void write() {
        cout << "\nStudent Details:\n";
        for (int i = 0; i < n; i++) {
            cout << "NAME: " << s[i].name << "\n";
            cout << "ROLL NUMBER: " << s[i].roll << "\n";
            cout << "SGPA: " << s[i].sgpa << "\n\n";
        }
    }

    void insertion() {
        int i, j;
        for (i = 1; i < n; i++) {
            j = i - 1;
            Student key = s[i];
            while (j >= 0 && s[j].sgpa < key.sgpa) { // Descending sort by SGPA
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = key;
        }
    }

    void shell() {
        int gap, i, j;
        for (gap = n / 2; gap > 0; gap /= 2) {
            for (i = gap; i < n; i++) {
                Student key = s[i];
                j = i - gap;
                while (j >= 0 && s[j].name < key.name) { // Descending sort by Name
                    s[j + gap] = s[j];
                    j -= gap;
                }
                s[j + gap] = key;
            }
        }
    }

    void radix() {
        int max = s[0].roll;
        for (int i = 1; i < n; i++) {
            if (s[i].roll > max) {
                max = s[i].roll;
            }
        }

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countSort(exp);
        }
    }

    void countSort(int exp) {
        Student op[15];
        int count[10] = {0};

        // Count occurrences of digits
        for (int i = 0; i < n; i++) {
            int index = (s[i].roll / exp) % 10;
            count[index]++;
        }

        // Update count array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build sorted array
        for (int i = n - 1; i >= 0; i--) {
            int index = (s[i].roll / exp) % 10;
            op[count[index] - 1] = s[i];
            count[index]--;
        }

        // Copy sorted array back to main array
        for (int i = 0; i < n; i++) {
            s[i] = op[i];
        }
    }

    // Function to reverse the array
    void reverseArray() {
        for (int i = 0; i < n / 2; i++) {
            Student temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    }

    // Function to print the top 10 roll numbers
    void displayTop10RollNumbers() {
        cout << "\nTop 10 Roll Numbers in Descending Order:\n";
        for (int i = 0; i < 10 && i < n; i++) { // Print top 10 or fewer if n < 10
            cout << s[i].roll << " ";
        }
        cout << endl;
    }
};

int main() {
    StudentManager sm;
    int choice;

    // Input data
    sm.get();

    do {
        // Menu
        cout << "\nMenu:\n";
        cout << "1. Sort by SGPA using Insertion Sort\n";
        cout << "2. Sort by Name using Shell Sort\n";
        cout << "3. Sort by Roll Number using Radix Sort\n";
        cout << "4. Display Students\n";
        cout << "5. Display Top 10 Roll Numbers\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sm.insertion();
            cout << "\nSorted by SGPA (Insertion Sort):\n";
            sm.write();
            break;
        case 2:
            sm.shell();
            cout << "\nSorted by Name (Shell Sort):\n";
            sm.write();
            break;
        case 3:
            sm.radix();
            sm.reverseArray(); // Reverse the sorted array for descending order
            cout << "\nSorted by Roll Number in Descending Order (Radix Sort):\n";
            sm.write();
            break;
        case 4:
            sm.write();
            break;
        case 5:
            sm.displayTop10RollNumbers();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}