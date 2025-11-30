#pragma once
#include <string>

#ifdef MONEYDLL2_EXPORTS
#define MONEY_API __declspec(dllexport)
#else
#define MONEY_API __declspec(dllimport)
#endif

class MONEY_API Money {
private:
    long hryvnia;
    unsigned char kopiyky;
    void Normalize();

public:
    Money();
    Money(long h, unsigned char k);

    std::string ToString() const;

    Money operator+(const Money& m) const;
    Money operator-(const Money& m) const;
    Money operator*(double n) const;
    Money operator/(double n) const;
    double operator/(const Money& m) const;

    bool operator==(const Money& m) const;
    bool operator!=(const Money& m) const;
    bool operator>(const Money& m) const;
    bool operator<(const Money& m) const;
    bool operator>=(const Money& m) const;
    bool operator<=(const Money& m) const;
};
