// Section 16
// Interfaces - Part2

/*
 * Abstract classes are used to make INTERFACES classes in c++.
 *
 * Interface
 *  - An Interface Class in a class that has ONLY pure virtual functions.
 *  - The virtual functions provide a general set of services that users of the class
 *    can use.
 *  - These virtual functions must be public (otherwise they won't be useful).
 *  - Each subclass is free to implement these services as needed.
 *  - Every service (method) MUST BE implemented (prototypes must match exactly)
 *
 * ATTENTION: unlike other languages, C++ does not provide a specific keyword
 * to declare an interface. So we use abstract classes with pure virtual functions
 * to achieve the concept of an interface.
 *
 * TIP: sometimes an Interface Class is declared putting in the name the letter
 * 'I' before the real name. E.g. IShape.
 */

#include <iostream>
#include <vector>

/******************************
 * IPrintable Interface Class *
 ******************************/
 class IPrintable {
     /**
      * We use an interface to use the operator<<, because it cannot be virtual
      * (when we use it like a friend function) and is NOT a member method, so
      * dynamic binding won't work in concrete classes!
      */
     friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);
 public:
     virtual void print(std::ostream &os) const = 0;  // pure virtual function
     virtual ~IPrintable() = default;  // = default tells the compiler to generate a simple destructor, instead of using {}.
 };

std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
    obj.print(os);
    return os;
}

/*****************
 * Account Class *
 *****************/
class Account: public IPrintable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    void print(std::ostream &os) const override {
        os << "Account display";
    }
    ~Account() override = default;
};

/******************
 * Checking Class *
 ******************/
class Checking: public Account  {
public:
    void withdraw(double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    void print(std::ostream &os) const override {
        os << "Checking display";
    }
    ~Checking() override = default;
};

/*****************
 * Savings Class *
 *****************/
class Savings: public Account {
public:
    void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    void print(std::ostream &os) const override {
        os << "Saving display";
    }
    ~Savings() override = default;
};

/***************
 * Trust Class *
 ***************/
class Trust: public Account  {
public:
    void withdraw(double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    void print(std::ostream &os) const override {
        os << "Trust display";
    }
    ~Trust() override = default;
};

/****************************************
 * Dog Class                            *
 * Just to show the power of interfaces *
 ****************************************/
class Dog : public IPrintable {
public:
    void print(std::ostream &os) const override {
        os << "Bau!";
    }
    ~Dog() override = default;
};

/********************
 * Normal function  *
 ********************/
 void print_all(const std::vector<IPrintable *> &objs) {
     for (const auto o : objs) {
         std::cout << *o << std::endl;
     }
 }

/********
 * Main *
 ********/
int main() {
    Account *p1 = new Account();
    std::cout << *p1 << std::endl;  // Account display

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;  // Checking display

    std::cout << "==================" << std::endl;

    Dog *dog = new Dog();
    std::cout << *dog << std::endl;

    std::cout << "==================" << std::endl;

    std::vector<IPrintable *> v {};
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(dog);
    print_all(v);

    delete p1;
    delete p2;
    delete dog;

    return 0;
}

