#include <iostream>
using namespace std;

struct student {
    char stuname[25];
    int regno;
    float total;
    float mark1, mark2, mark3, mark4, mark5;

    float calculate() {
        return mark1 + mark2 + mark3 + mark4 + mark5;
    }

    void havedata() {
        cout << "Enter registration number: ";
        cin >> regno;
        cin.ignore();
        cout << "Enter student name: ";
        cin.getline(stuname, 25);
        cout << "Enter 5 marks: ";
        cin >> mark1 >> mark2 >> mark3 >> mark4 >> mark5;
        cin.ignore();
        total = calculate();
    }
};

void dispdata(student s) {
    cout << "\n--- Student Details ---\n";
    cout << "Name      : " << s.stuname << "\n";
    cout << "Reg. No.  : " << s.regno << "\n";
    cout << "Marks     : " << s.mark1 << ", " << s.mark2 << ", "
         << s.mark3 << ", " << s.mark4 << ", " << s.mark5 << "\n";
    cout << "Total     : " << s.total << "\n";
}

int main() {
    student s1;
    student *p = &s1;
    p->havedata();
    dispdata(s1);
    return 0;
}