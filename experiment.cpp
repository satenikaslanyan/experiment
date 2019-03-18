#include <iostream>

class A
{
protected:
    int a;
public:
    A() { std::cout << "Constructor A" << std::endl; }
    A(int a_a) : a(a_a) { std::cout << "Parametrized constructor A" << std::endl;}
    
    A(const A& a_a) : a(a_a.a)
    {
        std::cout << "Copy Constructor of A" << std::endl;
    }
    
    A& operator=(const A& a_a)
    {
        a = a_a.a;
        std::cout << "= operator of A" << std::endl;
        return *this;
    }
    
    ~A(){std::cout << "Destructor A" << std::endl;}
};

class B : A
{
protected:
    int b;
public:
    B() { std::cout << "Constructor of B" << std::endl; }
    B(int a, int b_b) : A(a), b(b_b) { std::cout << "Parametrized constructor of B" << std::endl; }
    
    B(const B& b_b) : A(b_b), b(b_b.b)
    {
        std::cout << "Copy Constructor of B" << std::endl;
    }
    
    B& operator=(const B& b_b)
    {
        b = b_b.b;
        A::operator=(b_b);
        std::cout << "= operator of B" << std::endl;
        return *this;
    }
    
    ~B(){std::cout << "Destructor B" << std::endl;}
};

int main()
{
    //A a;
    //A a1(10);
    //B b;
    B b1(10, 10);
    //B b2(b1);
    B b3(20, 20);
    
    b3 = b1;
}



