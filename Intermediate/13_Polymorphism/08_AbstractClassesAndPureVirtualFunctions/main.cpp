// Section 16
// Pure virtual functions and abstract base classes

/*
 * Pure virtual functions allow us to create abstract classes.
 *
 * Abstract Class
 *    It is a class that CANNOT be instantiated!
 *    So the abstract classes are used as Base Classes in inheritance
 *    hierarchies (often called Abstract Base Classes).
 *    It contains at least one pure virtual function.
 *
 * Concrete Class
 *    It is a class that CAN be instantiated!
 *    In these classes all their member functions must be defined.
 *
 *    An Abstract Base Class is usually too generic to be useful to directly derive
 *    objects from, but it serves as a parent to be derived from.
 *
 *    For example, if we get the Account Hierarchy used thought the projects, we have:
 *            Account
 *          ^    ^    ^
 *         /     |     \
 *        /      |      \
 *    Trust   Checking  Savings
 *
 *    In this hierarchy we never use a base account class and in practice it will be
 *    the same. Indeed, if a customer walked in a back office and said that he would like
 *    to open an account, it simply will choose a specific account to open. So we would
 *    never really have account objects directly instantiated in our system.
 *    So the account class can be thought as Abstract Class.
 *
 * Pure Virtual Function
 *    It is used to make a class abstract.
 *    The method declaration contains "=0".
 *      e.g. virtual void function() = 0;
 *    Typically pure virtual functions don't have any implementation, because
 *    it's really up to the derived concrete classes to define the behaviour!
 *
 * When we derive a class from an abstract class, we must override the pure virtual functions
 * in the base class in order to be a concrete class.
 * ATTENTION: if we don't override ALL the pure virtual functions in the base class,
 * then the derived class will also be abstract.
 *
 */
#include <iostream>
#include <vector>

/**
 * Shape is the Abstract Base Class
 */
class Shape {
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0;	 // pure virtual function
    virtual void rotate() = 0;   // pure virtual function
    virtual ~Shape() {}
};

/**
 * OpenShape is an Abstract Class (don't override all the pure virtual methods)
 */
class OpenShape: public Shape {
public:
    virtual ~OpenShape() { }
};

/**
 * ClosedShape is an Abstract Class (don't override all the pure virtual methods)
 */
class ClosedShape: public Shape {
public:
    virtual ~ClosedShape() { };
};


/**
 * Line is a Concrete Class
 */
class Line: public OpenShape {
public:
    void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    ~Line() override {}
};

/**
 * Circle is a Concrete Class
 */
class Circle: public ClosedShape {
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    ~Circle() override {}
};

/**
 * Square is a Square Class
 */
class Square: public ClosedShape {
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


// a normal function
void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p : shapes)
        p->draw();  // dynamic binding
}

int main() {
//    Shape s;                 // compiler error
//    Shape *p = new Shape();  // compiler error

//    OpenShape o;                 // compiler error
//    Shape *p = new OpenShape();  // compiler error

//    ClosedShape c;                       // compiler error
//    ClosedShape *p = new ClosedShape();  // compiler error

    Circle c;
    c.draw();  // static binding

    Shape *ptr = new Circle();
    ptr->draw();    // dynamic binding
    ptr->rotate();  // dynamic binding

    std::cout << "\n=================\n";

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape *> shapes {s1, s2, s3};

    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;

    return 0;
}
