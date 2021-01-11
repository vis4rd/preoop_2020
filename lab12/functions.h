#pragma once

#include <cmath>
#include <iostream>

class Linear
{
public:
    /// Konstruktor
    /// @param wspolczynnik przy x
    /// @param wyraz wolny
    Linear(double a = 1.0, double b = 1.0);
    ~Linear();

    /// Przeciazenie operatora
    /// @param argument funkcji
    /// @return wartosc funkcji dla danego x
    double operator() (double x) const;

    /// Sformatowane wypisywanie zawartosci obiektu
    /// @param stream do ktorego jest wypisywany obiekt
    /// @param obiekt wypisywany
    friend std::ostream &operator<< (std::ostream &output, const Linear &target);
private:
    double a;
    double b;
};

class Sqrt
{
public:
    /// Konstruktor domyslny
    Sqrt();
    ~Sqrt();

    /// Przeciazenie operatora
    /// @param argument funkcji
    /// @return wartosc funkcji dla danego x
    double operator() (double x) const;
private:
};

class Sin
{
public:
    /// Konstruktor
    /// @param wspolczynnik przy x
    /// @param wyraz wolny
    Sin(double a = 1.0, double b = 1.0);
    ~Sin();

    /// Przeciazenie operatora
    /// @param argument funkcji
    /// @return wartosc funkcji dla danego x
    double operator() (double x) const;
private:
    Linear fun;
};