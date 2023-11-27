#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Complex {
   private:
    double real, img;
    double get_number(const char *str, int from, int to) const;

   public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex &c) { real = c.real, img = c.img; }
    Complex(const char *str);

    Complex operator+(const Complex &c) const;
    Complex &operator=(const Complex &c);

    void println() { cout << "( " << real << " , " << img << " ) \n"; }

    friend Complex operator+(const Complex &a, const Complex &b);
    friend ostream &operator<<(ostream &a, const Complex &c);
};

// -----------------------------------------------------------------------------

Complex operator+(const Complex &a, const Complex &b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}

Complex::Complex(const char *str) {
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);
    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

// ---------------------------------------------------------------------------------------------

double Complex::get_number(const char *str, int from, int to) const {
    bool minus = false;
    char *temp = new char[to - from + 1];
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) || str[i] == '.') {
            temp[i - from] = str[i];
        } else
            continue;
    }
    num = atof(temp);
    if (minus) num *= -1;
    return num;
}

// ---------------------------------------------------------------------------------------------

Complex Complex::operator+(const Complex &c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex &Complex::operator=(const Complex &c) {
    real = c.real;
    img = c.img;
    return *this;
}

ostream &operator<<(ostream &os, const Complex &c) {
    os << "( " << c.real << " , " << c.img << " ) ";
    return os;
}

int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a.println();
    cout << "a의 값은 " << a << "이다. "
         << "\n";
}