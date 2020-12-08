#pragma once

#include <iostream>
#include <cmath>

class Vector2D
{
public:
    /** konstruktor
     *  @param nazwa wektora
     */
    Vector2D(std::string name = "Vx");
    /** konstruktor kopiujacy
     *  @param oryginal
     */
    Vector2D(const Vector2D &original);

    /** konstruktor przenoszacy
     *  @param zrodlo
     */
    Vector2D(Vector2D &&source);

    /** destruktor
     */
    ~Vector2D();

    /** Metoda pomocnicza do inicjalizacji obiektow
     *  @param nazwa wektora
     *  @param wspolrzedna x
     *  @param wspolrzedna y
     */
    static Vector2D fromCarthesian(std::string name, double x, double y);

    /** Metoda pomocnicza do inicjalizacji obiektow
     *  @param wspolrzedna x
     *  @param wspolrzedna y
     */
    static Vector2D fromCarthesian(double x, double y);

    /** Metoda pomocnicza do inicjalizacji obiektow we wspolrzednych biegunowych
     *  @param nazwa wektora
     *  @param promien
     *  @param kat
     */
    static Vector2D fromPolar(std::string name, double r, double deg);

    /** Wypisywanie wektora 
     *  @param prefix wypisywany przed zawartoscia wektora
     */
    void print(std::string prefix = "") const;

    /** Iloczyn skalarny wektorow
     *  @param drugi wektor brany do iloczynu
     */
    double dot(Vector2D two) const;

    /** Dodawanie wektorow
     *  @param drugi wektor brany do sumy
     */
    Vector2D add(Vector2D two) const;

    static int count;
protected:

private:

    /** Konstruktor prywatny
    *  @param nazwa wektora
    *  @param wspolrzedna x
    *  @param wspolrzedna y
    */
    Vector2D(std::string name, double x, double y); //prywatny konstruktor

    std::string name;
    double _x;
    double _y;

};