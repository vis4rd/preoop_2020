#pragma once

#include <functional>
#include <vector>
#include <iostream>

class FunctionVector
{
public:
    /// Konstruktor domyslny
    FunctionVector() = default;
    ~FunctionVector();

    /// Umieszczenie funkcji w wektorze
    /// @param funkcja ktora umieszczamy
    void insert(std::function<double(double)> input);

    /// Obliczenie wektora funkcji od x
    /// @param argument dla ktorego wykonywane sa obliczenia
    /// @return zwracany wynik obliczen
    double calc(double x);

    /// Operator dostepu do konkretnego indeksu wektora
    /// @param indeks
    /// @return wartosc pod indeksem
    double operator[] (int index);
protected:

private:
    std::vector<std::function<double(double)>> data;
    std::vector<double> results;
};