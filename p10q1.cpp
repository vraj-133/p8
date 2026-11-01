#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Assets {
private:
    string material, make;
    int year, warranty;
    double price, depreciation;

public:
    Assets() : material(""), make(""), year(0), warranty(0),
               price(0), depreciation(0) {}

    Assets(string mat, string mk, int y, int w, double p, double d)
        : material(mat), make(mk), year(y), warranty(w),
          price(p), depreciation(d) {}

    double netWorth(int currentYear) const {
        int age = max(0, currentYear - year);
        int yearsOfDepreciation = max(0, age - warranty);
        return price * pow(1.0 - depreciation / 100.0,
                           yearsOfDepreciation);
    }

    void print_assets() const {
        cout << "Material: " << material << '\n'
             << "Make: " << make << '\n'
             << "Year: " << year << '\n'
             << "Price: Rs. " << price << '\n'
             << "Warranty: " << warranty << " years\n"
             << "Depreciation: " << depreciation << "% per year\n"
             << "Net worth in 2025: Rs. " << netWorth(2025) << '\n';
    }
};

class Parent {
private:
    string name;
    double bank_balance;
    Assets house;

public:
    Parent() : name(""), bank_balance(0), house() {}

    Parent(string n, double balance, const Assets& h)
        : name(n), bank_balance(balance), house(h) {}

    void withdraw(double amount) {
        if (amount > 0 && amount <= bank_balance) {
            bank_balance -= amount;
            cout << name << " withdrew Rs. " << amount << ".\n";
        } else {
            cout << "Withdrawal unsuccessful for " << name << ".\n";
        }
    }

    double getBalance() const {
        return bank_balance;
    }

    double houseWorth() const {
        return house.netWorth(2025);
    }

    void print() const {
        cout << "\nName: " << name
             << "\nBank balance: Rs. " << bank_balance << '\n';
        house.print_assets();
    }
};

class Child {
private:
    Assets bike;
    int age;
    Parent* father;
    Parent* mother;

public:
    Child() : bike(), age(0), father(nullptr), mother(nullptr) {}

    Child(const Assets& b, int a)
        : bike(b), age(a), father(nullptr), mother(nullptr) {}

    void setParents(Parent* f, Parent* m) {
        father = f;
        mother = m;
    }

    void print() const {
        cout << "\nCHILD DETAILS\nAge: " << age << "\nBike details:\n";
        bike.print_assets();

        if (father != nullptr) {
            cout << "\nFather details:";
            father->print();
        }
        if (mother != nullptr) {
            cout << "\nMother details:";
            mother->print();
        }

        if (father != nullptr && mother != nullptr) {
            double total = bike.netWorth(2025)
                         + father->houseWorth()
                         + mother->houseWorth()
                         + father->getBalance()
                         + mother->getBalance();
            cout << "\nTotal family net assets: Rs. " << total << '\n';
        }
    }

    void spendFromParents(double fatherAmount, double motherAmount) {
        if (father != nullptr)
            father->withdraw(fatherAmount);
        if (mother != nullptr)
            mother->withdraw(motherAmount);
    }
};

int main() {
    Assets scooter("Plastic", "Scooter", 2017, 3, 50000, 20);
    Assets villa("Concrete", "Villa", 2015, 10, 3500000, 5);

    Parent father("Father", 100000, villa);
    Parent mother("Mother", 100000, villa);

    cout << "FATHER DETAILS\n";
    father.print();

    cout << "\nMOTHER DETAILS\n";
    mother.print();

    Child newchild(scooter, 18);
    newchild.setParents(&father, &mother);

    newchild.print();

    cout << "\nAFTER SPENDING\n";
    newchild.spendFromParents(20000, 10000);

    cout << "Father's final bank balance: Rs. "
         << father.getBalance() << '\n';
    cout << "Mother's final bank balance: Rs. "
         << mother.getBalance() << '\n';

    return 0;
}
