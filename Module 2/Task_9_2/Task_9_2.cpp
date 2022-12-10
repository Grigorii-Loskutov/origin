#include <iostream>
#include <numeric>
#include <windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void Simplify() {
		int f_gcd = 1;
		f_gcd = static_cast<int>(std::gcd(numerator_, denominator_));
		numerator_ = numerator_ / f_gcd;
		denominator_ = denominator_ / f_gcd;
	}
	void Print() {
		std::cout << numerator_;
		if (denominator_ != 1) {
			std::cout << "/" << denominator_;
		}
	}
	bool operator==(Fraction other) { return ((numerator_ == other.numerator_) && (denominator_ == other.denominator_)); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator>(Fraction other) { return ((numerator_ / denominator_) > (other.numerator_ / other.denominator_)); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }

	Fraction operator+(Fraction other) { return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_); }
	Fraction operator-(Fraction other) { return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_); }
	Fraction operator*(Fraction other) { return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_); }
	Fraction operator/(Fraction other) { return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_); }
	Fraction& operator++() { numerator_ += denominator_; return *this; }
	Fraction operator++(int) { Fraction temp = *this; ++(*this); return temp; }
	Fraction& operator--() { numerator_ -= denominator_; return *this; }
	Fraction operator--(int) { Fraction temp = *this; --(*this); return temp; }
	Fraction& operator-() { numerator_ = 0 - numerator_; return *this; }
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
	Fraction f1(4, 3);
	Fraction f2(6, 11);
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	*/
	int f1_n = 0, f1_d = 0, f2_n = 0, f2_d = 0;
	std::cout << "Введите числитель дроби 1: "; std::cin >> f1_n;
	std::cout << "Введите знаменатель дроби 1: "; std::cin >> f1_d;
	Fraction f1(f1_n, f1_d);
	std::cout << "Введите числитель дроби 2: "; std::cin >> f2_n;
	std::cout << "Введите знаменатель дроби 2: "; std::cin >> f2_d;
	Fraction f2(f2_n, f2_d);
	Fraction f_sum = f1 + f2; f_sum.Simplify();
	f1.Print(); std::cout << " + "; f2.Print(); std::cout << " = "; f_sum.Print();
	std::cout << "\n";
	Fraction f_sub = f1 - f2; f_sub.Simplify();
	f1.Print(); std::cout << " - "; f2.Print(); std::cout << " = "; f_sub.Print();
	std::cout << "\n";
	Fraction f_mult = f1 * f2; f_mult.Simplify();
	f1.Print(); std::cout << " * "; f2.Print(); std::cout << " = "; f_mult.Print();
	std::cout << "\n";
	Fraction f_div = f1 / f2; f_div.Simplify();
	f1.Print(); std::cout << " / "; f2.Print(); std::cout << " = "; f_div.Print();
	std::cout << "\n";
	std::cout << "++";
	f1.Print(); std::cout << " * "; f2.Print(); 
	Fraction f_x = ++f1 * f2; f_x.Simplify();
	std::cout << " = "; f_x.Print();
	std::cout << "\n";
	std::cout << "Значение дроби 1: " << " = "; f1.Print();
	std::cout << "\n";
	f1.Print();
	std::cout << "--";
	std::cout << " * "; f2.Print();
	Fraction f_x1 = f1-- * f2; f_x1.Simplify();
	std::cout << " = "; f_x1.Print();
	std::cout << "\n";
	std::cout << "Значение дроби 1: " << " = "; f1.Print();
	std::cout << "\n";
	f1 = -f1;
	std::cout << "Значение дроби 1 со знаком минус: " << " = "; f1.Print();
	return 0;
}