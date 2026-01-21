#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert grade to grade point
int getGradePoint(char grade) {
    switch (grade) {
        case 'A': return 5;
        case 'B': return 4;
        case 'C': return 3;
        case 'D': return 2;
        case 'E': return 1;
        case 'F': return 0;
        default: return -1;
    }
}

int main() {
    int semesters;
    double totalGPA = 0;

    cout << "GPA & CGPA Calculator System\n";
    cout << "----------------------------\n";

    cout << "Enter number of semesters: ";
    cin >> semesters;

    for (int s = 1; s <= semesters; s++) {
        int courses;
        double totalPoints = 0, totalUnits = 0;

        cout << "\nSemester " << s << endl;
        cout << "Enter number of courses: ";
        cin >> courses;

        for (int i = 1; i <= courses; i++) {
            int unit;
            char grade;

            cout << "\nCourse " << i << endl;
            cout << "Enter course unit: ";
            cin >> unit;

            cout << "Enter grade (A-F): ";
            cin >> grade;
            grade = toupper(grade);

            int gradePoint = getGradePoint(grade);

            if (gradePoint == -1) {
                cout << "Invalid grade entered!\n";
                i--; // repeat this course
                continue;
            }

            totalPoints += gradePoint * unit;
            totalUnits += unit;
        }

        double gpa = totalPoints / totalUnits;
        totalGPA += gpa;

        cout << fixed << setprecision(2);
        cout << "\nGPA for Semester " << s << " = " << gpa << endl;
    }

    double cgpa = totalGPA / semesters;
    cout << "\n----------------------------\n";
    cout << "Final CGPA = " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}