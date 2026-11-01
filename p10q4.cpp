#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
protected:
    double x, y;

public:
    Point2D() : x(0), y(0) {}
    Point2D(double a, double b) : x(a), y(b) {}

    void setXY(double a, double b) {
        x = a;
        y = b;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    virtual void print() const = 0;
    virtual ~Point2D() {}
};

class Point3D : public Point2D {
private:
    double z;

public:
    Point3D() : Point2D(), z(0) {}

    Point3D(double a, double b, double c)
        : Point2D(a, b), z(c) {}

    Point3D(const Point3D& other)
        : Point2D(other.x, other.y), z(other.z) {}

    void setXYZ(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }

    double getZ() const { return z; }

    void print() const override {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    friend void move(Point3D& point, double dx, double dy, double dz);
};

void move(Point3D& point, double dx, double dy, double dz) {
    point.x += dx;
    point.y += dy;
    point.z += dz;
}

class Polygon {
protected:
    int n;
    Point3D* points;

public:
    explicit Polygon(int vertices) : n(vertices), points(nullptr) {
        if (n > 0)
            points = new Point3D[n];
    }

    Polygon(const Polygon& other) : n(other.n), points(nullptr) {
        if (n > 0) {
            points = new Point3D[n];
            for (int i = 0; i < n; ++i)
                points[i] = other.points[i];
        }
    }

    Polygon& operator=(const Polygon& other) {
        if (this != &other) {
            Point3D* newPoints = nullptr;
            if (other.n > 0) {
                newPoints = new Point3D[other.n];
                for (int i = 0; i < other.n; ++i)
                    newPoints[i] = other.points[i];
            }
            delete[] points;
            n = other.n;
            points = newPoints;
        }
        return *this;
    }

    void setVertex(int index, const Point3D& point) {
        if (index >= 0 && index < n)
            points[index] = point;
    }

    void displayvertex() const {
        for (int i = 0; i < n; ++i) {
            points[i].print();
            cout << '\n';
        }
    }

    virtual double printperimeter() const {
        if (n < 2)
            return 0;

        double perimeter = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            double dx = points[i].getX() - points[j].getX();
            double dy = points[i].getY() - points[j].getY();
            double dz = points[i].getZ() - points[j].getZ();
            perimeter += sqrt(dx * dx + dy * dy + dz * dz);
        }
        return perimeter;
    }

    virtual ~Polygon() {
        delete[] points;
    }
};

class ThreeDObject : public Polygon {
private:
    double area, height;

public:
    ThreeDObject(int vertices, double crossSectionArea, double h)
        : Polygon(vertices), area(crossSectionArea), height(h) {}

    double printperimeter() const override {
        // Assumes a right prism with n vertical edges of length height.
        return 2 * Polygon::printperimeter() + n * height;
    }

    double volume() const {
        return area * height;
    }

    void display() const {
        cout << "Cross-sectional area: " << area << '\n'
             << "Height: " << height << '\n'
             << "Volume: " << volume() << '\n'
             << "Sum of all edge lengths: " << printperimeter() << '\n';
    }
};

int main() {
    Point3D p1(0, 0, 0);
    Point3D p2(3, 0, 0);
    Point3D p3(3, 4, 0);
    Point3D p4(0, 4, 0);

    cout << "Original point: ";
    p1.print();

    move(p1, 2, 3, 4);
    cout << "\nPoint after moving: ";
    p1.print();

    Polygon polygon(4);
    polygon.setVertex(0, Point3D(0, 0, 0));
    polygon.setVertex(1, p2);
    polygon.setVertex(2, p3);
    polygon.setVertex(3, p4);

    cout << "\n\nPolygon vertices:\n";
    polygon.displayvertex();
    cout << "Polygon perimeter: " << polygon.printperimeter() << '\n';

    ThreeDObject object(4, 12, 5);
    object.setVertex(0, Point3D(0, 0, 0));
    object.setVertex(1, p2);
    object.setVertex(2, p3);
    object.setVertex(3, p4);

    cout << "\n3D object details:\n";
    object.display();

    return 0;
}
