#pragma once

#include <iostream>
#include <cmath>

class Vector
{
public:

    /**
     * Konstruktor niekonwertujacy
     * @param liczba wymiarow
    */
    explicit Vector(int size);

    /**
     * Konstruktor kopiujacy
     * @param oryginal
    */
    Vector(Vector &origin);

    /**
     * Konstruktor przenoszacy
     * @param zrodlo z ktorego pamiec jest przenoszona
    */
    Vector(Vector &&source);

    /**
     * Destruktor
    */
    ~Vector();

    /**
     * Konwerter double -> Vector
    */
    explicit operator double() const;


    /**
     * Iloczyn skalarny dwoch wektorow
     * @param pierwszy wektor
     * @param drugi wektor
    */
    static double dot(const Vector &one, const Vector &two);

    /**
     * Suma dwoch wektorow
     * @param pierwszy wektor
     * @param drugi wektor
    */  
    static Vector sum(const Vector &one, const Vector &two);

    /**
     * Suma wektora i liczby
     * 
     * Do kazdej skladowej wektora dodawana jest wartosc drugiego argumentu
     *
     * @param wektor
     * @param dodawana liczba
    */  
    static Vector sum(const Vector &one, const double);

    /**
     * Norma wektora
    */  
    double norm() const;

    /**
     * Getter wartosci wektora skladowego
     * @param indeks wymiaru wektora skladowego
    */
    double &at(int index);

    /**
     * Wypisywanie wektorow skladowych
     * @param prefix wypisywany przed zawartoscia klasy
    */
    void print(std::string prefix = "") const;
protected:

private:
    double *skladowe;
    int size;
};