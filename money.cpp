#include "pch.h"
#include "Money.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

Money::Money() : hryvnia(0), kopiyky(0) {}

Money::Money(long h, unsigned char k) : hryvnia(h), kopiyky(k) {
    Normalize();
}

void Money::Normalize() {
    if (kopiyky >= 100) {
        hryvnia += kopiyky / 100;
        kopiyky %= 100;
    }
    if (kopiyky < 0) {
        long borrow = (abs(kopiyky) + 99) / 100;
        hryvnia -= borrow;
        kopiyky += borrow * 100;
    }
}

std::string Money::ToString() const {
    ostringstream ss;
    ss << hryvnia << "," << setw(2) << setfill('0') << (int)kopiyky;
    return ss.str();
}

Money Money::operator+(const Money& m) const {
    return Money(hryvnia + m.hryvnia, kopiyky + m.kopiyky);
}

Money Money::operator-(const Money& m) const {
    long total1 = hryvnia * 100 + kopiyky;
    long total2 = m.hryvnia * 100 + m.kopiyky;
    long diff = total1 - total2;
    return Money(diff / 100, diff % 100);
}

Money Money::operator*(double n) const {
    long total = (hryvnia * 100 + kopiyky) * n;
    return Money(total / 100, total % 100);
}

Money Money::operator/(double n) const {
    if (n == 0) throw runtime_error("Ділення на нуль");
    long total = (hryvnia * 100 + kopiyky) / n;
    return Money(total / 100, total % 100);
}

double Money::operator/(const Money& m) const {
    long total1 = hryvnia * 100 + kopiyky;
    long total2 = m.hryvnia * 100 + m.kopiyky;
    if (total2 == 0) throw runtime_error("Ділення на нуль");
    return (double)total1 / total2;
}

bool Money::operator==(const Money& m) const {
    return hryvnia == m.hryvnia && kopiyky == m.kopiyky;
}

bool Money::operator!=(const Money& m) const {
    return !(*this == m);
}

bool Money::operator>(const Money& m) const {
    return (hryvnia * 100 + kopiyky) > (m.hryvnia * 100 + m.kopiyky);
}

bool Money::operator<(const Money& m) const {
    return (hryvnia * 100 + kopiyky) < (m.hryvnia * 100 + m.kopiyky);
}

bool Money::operator>=(const Money& m) const {
    return !(*this < m);
}

bool Money::operator<=(const Money& m) const {
    return !(*this > m);
}

