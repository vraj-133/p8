#include <iostream>
#include <string>
using namespace std;

class Tire {
private:
    string make;
    int year;

public:
    Tire() : make(""), year(0) {}
    Tire(string m, int y) : make(m), year(y) {}

    void print_tire() const {
        cout << "Tire make: " << make << '\n'
             << "Tire year: " << year << '\n';
    }
};

class Engine {
private:
    string make;
    int numberOfStrokes;
    int cubicCapacity;
    int year;

public:
    Engine() : make(""), numberOfStrokes(0),
               cubicCapacity(0), year(0) {}

    Engine(string m, int strokes, int capacity, int y)
        : make(m), numberOfStrokes(strokes),
          cubicCapacity(capacity), year(y) {}

    void print_engine() const {
        cout << "Engine make: " << make << '\n'
             << "Number of strokes: " << numberOfStrokes << '\n'
             << "Cubic capacity: " << cubicCapacity << " cc\n"
             << "Engine year: " << year << '\n';
    }
};

class Vehicle {
private:
    string model, colour;
    int year;
    double price;
    Engine engine;
    Tire* tires;
    int numberOfTires;

public:
    Vehicle()
        : model(""), colour(""), year(0), price(0),
          engine(), tires(nullptr), numberOfTires(0) {}

    Vehicle(string m, string c, int y, double p,
            const Engine& e, const Tire inputTires[], int count)
        : model(m), colour(c), year(y), price(p),
          engine(e), tires(nullptr), numberOfTires(count) {
        if (numberOfTires > 0) {
            tires = new Tire[numberOfTires];
            for (int i = 0; i < numberOfTires; ++i)
                tires[i] = inputTires[i];
        }
    }

    Vehicle(const Vehicle& other)
        : model(other.model), colour(other.colour),
          year(other.year), price(other.price), engine(other.engine),
          tires(nullptr), numberOfTires(other.numberOfTires) {
        if (numberOfTires > 0) {
            tires = new Tire[numberOfTires];
            for (int i = 0; i < numberOfTires; ++i)
                tires[i] = other.tires[i];
        }
    }

    Vehicle& operator=(const Vehicle& other) {
        if (this != &other) {
            Tire* newTires = nullptr;
            if (other.numberOfTires > 0) {
                newTires = new Tire[other.numberOfTires];
                for (int i = 0; i < other.numberOfTires; ++i)
                    newTires[i] = other.tires[i];
            }

            delete[] tires;
            model = other.model;
            colour = other.colour;
            year = other.year;
            price = other.price;
            engine = other.engine;
            numberOfTires = other.numberOfTires;
            tires = newTires;
        }
        return *this;
    }

    ~Vehicle() {
        delete[] tires;
    }

    void print_vehicle() const {
        cout << "\nModel: " << model << '\n'
             << "Colour: " << colour << '\n'
             << "Vehicle year: " << year << '\n'
             << "Price: Rs. " << price << '\n';

        cout << "\nEngine details:\n";
        engine.print_engine();

        cout << "\nTire details:\n";
        for (int i = 0; i < numberOfTires; ++i) {
            cout << "Tire " << i + 1 << ":\n";
            tires[i].print_tire();
        }
    }
};

class Person {
private:
    string name;
    int age;
    double bankBalance;
    Vehicle vehicle;

public:
    Person() : name(""), age(0), bankBalance(0), vehicle() {}

    Person(string n, int a, double balance, const Vehicle& v)
        : name(n), age(a), bankBalance(balance), vehicle(v) {}

    Person(const Person& other)
        : name(other.name), age(other.age),
          bankBalance(other.bankBalance), vehicle(other.vehicle) {}

    void withdraw(double amount) {
        if (amount > 0 && amount <= bankBalance) {
            bankBalance -= amount;
            cout << name << " withdrew Rs. " << amount << ".\n";
        } else {
            cout << "Insufficient balance for " << name << ".\n";
        }
    }

    void print() const {
        cout << "\nPERSON DETAILS\n"
             << "Name: " << name << '\n'
             << "Age: " << age << '\n'
             << "Bank balance: Rs. " << bankBalance << '\n';
        vehicle.print_vehicle();
    }
};

int main() {
    Tire scooterTires[2] = {
        Tire("MRF", 2019),
        Tire("MRF", 2019)
    };

    Tire carTires[4] = {
        Tire("CEAT", 2021),
        Tire("CEAT", 2021),
        Tire("CEAT", 2021),
        Tire("CEAT", 2021)
    };

    Engine scooterEngine("TATA", 4, 110, 2019);
    Engine carEngine("Suzuki", 4, 1200, 2021);

    Vehicle scooter("Hero", "Black", 2019, 80000,
                    scooterEngine, scooterTires, 2);

    Vehicle car("Maruti", "White", 2021, 600000,
                carEngine, carTires, 4);

    Person Hari("Hari", 20, 100000, scooter);
    Person Mohan("Mohan", 22, 250000, car);

    cout << "BEFORE WITHDRAWAL\n";
    Hari.print();
    Mohan.print();

    Hari.withdraw(10000);
    Mohan.withdraw(20000);

    cout << "\nAFTER WITHDRAWAL\n";
    Hari.print();
    Mohan.print();

    return 0;
}
