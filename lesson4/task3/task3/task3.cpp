#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
    string name;
    int count_sides;

public:
    Figure(const string& figure_name, int sides) : name(figure_name), count_sides(sides) {}
    Figure() :Figure("Фигура", 0) {}

    string get_name() const { return name; }
    int get_count_sides() const { return count_sides; }

    virtual bool check() const { return count_sides == 0; }
    virtual void print_info() const {
        cout << name << ":" << endl;
        if (check()) {
            cout << "Правильная" << endl;
        } else {
            cout << "Неправильная" << endl; 
        }
        cout << "Количество сторон: "<< count_sides << endl;
    }

    virtual ~Figure() = default;
};


class Triangle :public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C, const string& name = "Треугольник")
        : Figure(name,3), a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {
    }

    bool check() const override{
        return (A + B + C == 180);
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
};


class RightTriangle : public Triangle {
public:
    RightTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B)
        : Triangle(side_a, side_b, side_c, angle_A, angle_B, 90, "Прямоугольный треугольник") {
    }

    bool check() const override{
        return Triangle::check() && (C==90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int angle_A, int angle_B)
        : Triangle(side_a, side_b, side_a, angle_A, angle_B, angle_A, "Равнобедренный треугольник") {
    }

    bool check() const override { 
        return Triangle::check() && (A == C) && (a == c);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a) : Triangle(side_a, side_a, side_a, 60, 60, 60, "Равносторонний треугольник") {}

    bool check() const override {
        return Triangle::check() && (A == 60 && B==60 && C==60) && (a == b && b==c);
    }
};   




class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D, const string& name = "Четырёхугольник")
        : Figure(name,4), a(side_a), b(side_b), c(side_c), d(side_d), A(angle_A), B(angle_B), C(angle_C), D(angle_D) {
    }

    bool check() const override {
        return (A + B + C + D == 360);
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }

};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int  side_a, int side_b, int angle_A, int angle_B, const string& name = "Параллелограмм")
        : Quadrilateral(side_a, side_b, side_a, side_b, angle_A, angle_B, angle_A, angle_B, name) {
    }
    bool check() const override {
        return Quadrilateral::check() && (a==c && b==d) && (A==C && B==D);
    }
};


class Rectangle : public Parallelogram {
public:
    Rectangle(int side_a, int side_b, const string& name = "Прямоугольник") :
        Parallelogram(side_a, side_b, 90, 90, name) {
    }
    bool check() const override {
        return Parallelogram::check() && (a == c && b == d) && (A == 90 && B == 90 );
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side_a, int angle_A, int angle_B, const string& name = "Ромб")
        : Parallelogram(side_a, side_a, angle_A, angle_B, name) {
    }

    bool check() const override {
        return Parallelogram::check() && (a == b && b == c && c==d);
    }
};

class Square : public Rectangle {
public:
    Square(int side_a) : Rectangle(side_a, side_a, "Квадрат") {}
    bool check() const override {
        return Rectangle::check() && (a == b && b == c && c == d);
    }
};




void render(const Figure* figure) {
    if (figure != nullptr) {
        figure->print_info();
        cout << endl;
    }
}



int main()
{
    setlocale(LC_ALL, "RU");
    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle wrong_right_triangle(10, 20, 30, 50, 60);
    RightTriangle correct_right_triangle(10, 20, 30, 50, 40);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    render(&figure);
    render(&triangle);
    render(&wrong_right_triangle);
    render(&correct_right_triangle);
    render(&isosceles_triangle);
    render(&equilateral_triangle);

    render(&quadrilateral);
    render(&rectangle);
    render(&square);
    render(&parallelogram);
    render(&rhombus);

    return 0;

}
