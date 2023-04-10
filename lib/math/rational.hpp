//
//  rational.hpp
//  ATC
//
//  Created by yuki on 2022/06/22.
//

#ifndef rational_h
#define rational_h

struct rational {
    int num, den;
    
    rational() : num(0), den(1) {}
    rational(int num) : num(num), den(1) {}
    
    rational(int num, int den) {
        if (den == 0) { this->num = 0; this->den = 1; return; }
        auto ngcd = rational::gcd(num, den);
        this->num = num / ngcd;
        this->den = den / ngcd;
    }
    
    rational operator + () const { return *this; }
    rational operator - () const { return rational{ -num, den }; }
    
    rational operator + (const rational& r) const { return rational(num*r.den+r.num*den, den*r.den); }
    rational operator - (const rational& r) const { return rational(num*r.den-r.num*den, den*r.den); }
    rational operator * (const rational& r) const { return rational(num*r.num, den*r.den); }
    rational operator / (const rational& r) const { return rational(num*r.den, den*r.num); }
    
    rational& operator += (const rational& r) { return *this = *this + r; }
    rational& operator -= (const rational& r) { return *this = *this - r; }
    rational& operator *= (const rational& r) { return *this = *this * r; }
    rational& operator /= (const rational& r) { return *this = *this / r; }
    
    bool operator < (const rational& r) const { return num*r.den < r.num*den; }
    bool operator > (const rational& r) const { return num*r.den > r.num*den; }
    bool operator <= (const rational& r) const { return num*r.den <= r.num*den; }
    bool operator >= (const rational& r) const { return num*r.den >= r.num*den; }
    bool operator == (const rational& r) const { return num*r.den == r.num*den; }
    bool operator != (const rational& r) const { return num*r.den != r.num*den; }
    
    friend ostream& operator << (ostream& os, const rational& r) { return os << r.num << '/' << r.den; }
    friend istream& operator >> (istream& is, rational& r) { return cin >> r.num; }
    
private:
    static int gcd(int a, int b) {
        while (a % b) { int _a = a; a = b; b = _a % a; }
        return b;
    }
};

rational abs(const rational &r) {
    return rational(abs(r.num), r.den);
}


#endif /* rational_h */
