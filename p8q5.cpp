#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

class Book {
    float price;

public:
    string title, author;
    int year;

    void enterData() {
        cout << "  Title  : ";
        getline(cin >> ws, title);
        cout << "  Author : ";
        getline(cin >> ws, author);
        cout << "  Year   : ";
        cin >> year;
        cout << "  Price  : ";
        cin >> price;
    }

    void display() const {
        cout << title << " | " << author << " | " << year
             << " | Rs. " << price << "\n";
    }
};

void sortBooks(Book b[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (b[j].year > b[j + 1].year) {
                Book temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
}

int main() {
    Book shelf[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n1. New entry\n2. Print books (by year)\n3. Quit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int idx;
            if (count < MAX) {
                idx = count++;
            } else {
                idx = 0;
                for (int i = 1; i < MAX; i++)
                    if (shelf[i].year < shelf[idx].year)
                        idx = i;
                cout << "Array full. Removing oldest entry: ";
                shelf[idx].display();
            }
            cout << "Enter book data:\n";
            shelf[idx].enterData();

            sortBooks(shelf, count);
            cout << "\nBooks in chronological order:\n";
            for (int i = 0; i < count; i++)
                shelf[i].display();
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No books entered yet.\n";
            } else {
                sortBooks(shelf, count);
                cout << "\nBooks in chronological order:\n";
                for (int i = 0; i < count; i++)
                    shelf[i].display();
            }
        }
    } while (choice != 3);

    return 0;
}