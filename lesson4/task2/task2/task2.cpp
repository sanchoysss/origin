#include <iostream>
#include <string>
using namespace std;

class Figure {
protected: 
    string name;
    Figure(const string& figure_name) : name(figure_name) {}

public:
    string get_name() const { return name; }

    virtual void description() const = 0;
    virtual ~Figure() = default;
};


class Triangle :public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C, const string& name = "Треугольник")
        : Figure(name), a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {}

    int get_a() const { return a; }
    int get_b() const { return b; }
    int get_c() const { return c; }
    int get_A() const { return A; }
    int get_B() const { return B; }
    int get_C() const { return C; }

    void description() const override {
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
};


class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B) 
        : Triangle(side_a, side_b, side_c, angle_A, angle_B, 90, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int angle_A, int angle_B) 
        : Triangle(side_a, side_b, side_a, angle_A, angle_B, angle_A, "Равнобедренный треугольник") {}
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a) : Triangle(side_a, side_a, side_a, 60, 60, 60, "Равносторонний треугольник") {}
};



class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const string& name = "Четырёхугольник")
        : Figure(name), a(side_a), b(side_b), c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D) {}

    int get_a() const { return a; }
    int get_b() const { return b; }
    int get_c() const { return c; }
    int get_d() const { return d; }
    int get_A() const { return A; }
    int get_B() const { return B; }
    int get_C() const { return C; }
    int get_D() const { return D; }

    void description() const override {
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int  side_a, int side_b, int angle_A, int angle_B, const string& name = "Параллелограмм")
        : Quadrilateral(side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B, name) {}
};


class Rectangle : public Parallelogram {
    public:
        Rectangle(int side_a, int side_b, const string& name = "Прямоугольник") :
            Parallelogram(side_a, side_b,  90, 90, name) {}
    };

class Rhombus : public Parallelogram {
public:
    Rhombus(int side_a, int angle_A, int angle_B, const string& name = "Ромб") 
        : Parallelogram(side_a, side_a, angle_A, angle_B, name) {}
};

class Square : public Rectangle {
public:
    Square(int side_a) : Rectangle(side_a, side_a, "Квадрат") {}
};

void print_info(const Figure* figure) {
    if (figure != nullptr) {
        cout << figure->get_name() << ":" << endl;
        figure->description();
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;

}
