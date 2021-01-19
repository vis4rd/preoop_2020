#pragma once

#include <iostream>

class Fraction
{
public:
    Fraction() = default;
    Fraction(int licz, int mian);
    Fraction(int source); //konwersja int -> Fraction
    Fraction(const Fraction &origin);
    ~Fraction();

    operator double() const;

    Fraction operator+ (const Fraction &other) const;
    Fraction operator* (const Fraction &other) const;
    Fraction &operator*= (const Fraction &other);
    Fraction &operator= (const Fraction &other);
    Fraction operator- (Fraction) const;

    friend std::ostream &operator<< (std::ostream &stream, const Fraction &other);

protected:

private:
    int licznik;
    int mianownik;
};

int nwd(int m, int n);