#ifndef FRACTIE_H
#define FRACTIE_H


class Fractie
{
    int a;
    int b;
public:
    Fractie(int = 0, int = 0);
    Fractie(const Fractie &);
    Fractie &operator=(const Fractie &);
    ~Fractie();
    void afis() const;
    double getValoare() const;
    Fractie getInv() const;
    void setdata(int, int);
    int getA() const;
    int getB() const;
    friend const Fractie operator+(const Fractie &, const Fractie &);
    friend const Fractie operator-( const Fractie &, const Fractie &);
    friend const Fractie operator-(const Fractie &);
    friend const Fractie operator*(const Fractie &, const Fractie &);
    friend const Fractie operator/(const Fractie &, const Fractie &);

    Fractie& operator+=(const Fractie &);
    Fractie& operator-=(const Fractie &);
    Fractie& operator*=(const Fractie &);
    Fractie& operator/=(const Fractie &);

    friend bool operator==(const Fractie &, const Fractie &);
    friend bool operator!=(const Fractie &, const Fractie &);
    friend bool operator>(const Fractie &, const Fractie &);
    friend bool operator<(const Fractie &, const Fractie &);
    friend bool operator>=(const Fractie &, const Fractie &);
    friend bool operator<=(const Fractie &, const Fractie &);
};

#endif
