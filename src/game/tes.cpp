#include <iostream>
using namespace std;

class A {
    private:
        char z;
    public:
        A(char _z) : z(_z) {}

        void setZ(char _z) {
            this->z = _z;
        }

        void print() {
            cout << this->z << endl;
        }

        char& getZ() {
            cout << "ref called" << endl;
            return this->z;
        }

        char getZ() const {
            cout << "const called" << endl;
            return this->z;
        }
};

class Tes {
    
    private:
        int x;
        A a;
    public:
        Tes(int y, A _a) : x(y), a(_a) {}

        A& getA() {
            cout << "ref called" << endl;
            return this->a;
        }

        A getA() const {
            cout << "const called" << endl;
            return this->a;
        }
        
        void print() {
            cout << this->x << endl;
            this->a.print();
        }

};

int main() {
    A a('x');
    Tes t = Tes(1,a);

    A& b = t.getA();
    
    b.setZ('z');
    b.print();
    cout << "ngik" << endl;
    t.print();
    t.getA().setZ('0');
    t.print();
    t.getA().getZ() = 'g';
    t.print();
        A c = t.getA();
    
    c.setZ('p');
    c.print();
    cout << c.getZ() << endl;
    return 0;
}