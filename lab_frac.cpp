#include <iostream>
#include <string>


using  namespace std;

class Drob {
    public:
    int chisl;
    unsigned int znam;
    Drob(int chisl, unsigned int znam) {this->chisl = chisl, this->znam = znam;}
    void print(Drob x) {cout << chisl << "/" << znam << endl;}

    int Evklid(int a, int b) {
	    if (b == 0) return a;
        else return Evklid (b, a % b);
    }

    Drob Sokrat(int a, int b) {
        int maxdiv = Evklid(a, b);
        return Drob(a/maxdiv, b/maxdiv);
    }

    Drob operator+(Drob b) {
        int ch1 = this->chisl;
        int ch2 = b.chisl;
        unsigned int zn1 = this->znam;
        unsigned int zn2 = b.znam;
        if (zn1 == zn2) return Sokrat(ch1+ch2, znam);
        else return Sokrat(ch1*zn2 + ch2*zn1, zn1*zn2);
    }

    Drob operator-(Drob b) {
        int ch1 = this->chisl;
        int ch2 = b.chisl;
        unsigned int zn1 = this->znam;
        unsigned int zn2 = b.znam;
        if (zn1 == zn2) return Sokrat(ch1-ch2, znam);
        else return Sokrat(ch1*zn2 - ch2*zn1, zn1*zn2);
    }

    Drob operator*(Drob b) {
        return Sokrat(this->chisl * b.chisl, this->znam * b.znam);
    }

    Drob operator/(Drob b) {
        if (b.chisl == 0) return Drob(0, 1);
        int sign = (b.chisl < 0) ? -1 : 1;
        Drob b_new = Drob(b.znam * sign, b.chisl);
        return Sokrat(this->chisl * b_new.chisl, this->znam * b_new.znam);
    }
};
    

int main() {
    int ch1, ch2;
    unsigned int zn1, zn2;
    cout << "Введите числитель и знаменатель дроби А (через пробел): ";
    cin >> ch1 >> zn1;
    cout << "Введите числитель и знаменатель дроби В (через пробел): ";
    cin >> ch2 >> zn2;
    Drob A = Drob(ch1, zn1);
    Drob B = Drob(ch2, zn2);
    cout << "Дробь А: ";
    A.print(A);
    cout << "Дробь B: ";
    B.print(B);
    cout << "Дробь А+B: ";
    Drob C = A+B;
    C.print(C);
    cout << "Дробь A-B: ";
    Drob D = A-B;
    D.print(D);
    cout << "Дробь A*B: ";
    Drob E = A*B;
    E.print(E);
    cout << "Дробь A/B: ";
    Drob F = A/B;
    if (F.chisl == 0 && F.znam == 1) cout << "Ошибка деления, ноль в знаменателе" << endl;
    else F.print(F);
}