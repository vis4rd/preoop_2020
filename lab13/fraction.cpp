#include "fraction.h"

Fraction::Fraction(int licz, int mian)
{
    int n = nwd(licz, mian);
    if(n > 1)
    {
        licz /= n;
        mian /= n;
    }
    this->licznik = licz;
    this->mianownik = mian;
}

Fraction::Fraction(int source)
{
    this->licznik = source;
    this->mianownik = 1;
}

Fraction::Fraction(const Fraction &origin)
{
    if(this != &origin)
    {
        this->licznik = origin.licznik;
        this->mianownik = origin.mianownik;
    }
}

Fraction::~Fraction()
{

}

Fraction::operator double() const
{
    return (double)this->licznik / this->mianownik;
}

Fraction Fraction::operator+ (const Fraction &other) const
{
    Fraction result(*this);
    if(result.mianownik == other.mianownik)
    {
        result.licznik += other.licznik;
    }
    else 
    {
        const int nww = (result.mianownik + other.mianownik) \
            / nwd(result.mianownik, other.mianownik);
        
        if(nww > result.mianownik)
        {
            result.licznik *= (nww/result.mianownik);
            result.mianownik *= (nww/result.mianownik);
        }
        Fraction temp(other);
        if(nww > temp.mianownik)
        {
            temp.licznik *= (nww/temp.mianownik);
            temp.mianownik *= (nww/temp.mianownik);
        }
        //teraz ulamki maja wspolny mianownik

        result.licznik += temp.licznik;
    }
    
    return result;
}

Fraction Fraction::operator* (const Fraction &other) const
{
    Fraction result(*this);
    result.licznik *= other.licznik;
    result.mianownik *= other.mianownik;

    int n = nwd(result.licznik, result.mianownik);
    if(n > 1)
    {
        result.licznik /= n;
        result.mianownik /= n;
    }

    return result;
}

Fraction &Fraction::operator*= (const Fraction &other)
{
    this->licznik *= other.licznik;
    this->mianownik *= other.mianownik;

    int n = nwd(this->licznik, this->mianownik);
    if(n > 1)
    {
        this->licznik /= n;
        this->mianownik /= n;
    }

    return *this;
}

Fraction &Fraction::operator= (const Fraction &other)
{
    if(this == &other)
        return *this;
        
    this->licznik = other.licznik;
    this->mianownik = other.mianownik;
    return *this;
}

Fraction Fraction::operator- (Fraction) const
{
    Fraction result(*this);
    result.licznik = -result.licznik;
    return result;
}

//funkcje

std::ostream &operator<< (std::ostream &stream, const Fraction &other)
{
    int temp_l, temp_m, temp_calk = 0;
    bool negative;
    temp_l = other.licznik;
    temp_m = other.mianownik;

    if(temp_l < 0) //liczba ujemna
    {
        negative = true;
        temp_l = -temp_l;
    }
    else
        negative = false;

    while(temp_l > temp_m) //dopoki da sie wyciagnac czesc calkowita
    {
        temp_l -= temp_m;
        temp_calk++;
    }

    if(temp_l == 1 and temp_m == 1) //przypadek szczegolny: 1/1
    {
        temp_l = 0;
        temp_calk += 1;
    }

    if(negative) //jesli liczba ujemna
        stream << "-";

    if(temp_calk > 0) //jesli mozna wyciagnac czesc calkowita
        stream << temp_calk << " ";

    if(temp_l > 0) //jesli ulamek nie jest liczba calkowita
        stream << temp_l << "/" << temp_m; 

    return stream;
}

int nwd(int m, int n)
{
	int oldm, oldn;
    while( m % n != 0 )
    {
        oldm = m;
        oldn = n;
	    m = oldn;
	    n = oldm % oldn;
	}
    return n;
}
