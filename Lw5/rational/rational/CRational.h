#pragma once

#include <iostream>

class CRational
{
public:
    CRational() = default;

    CRational(int value);

    CRational(int numerator, int denominator);

    ~CRational() = default;

    int GetNumerator() const;

    int GetDenominator() const;

    double ToDouble() const;

    std::pair<int, CRational> ToMixedFraction()const;

    const CRational operator+() const;

    const CRational operator-() const;

    const CRational operator+=(const CRational& summand);

    const CRational operator-=(const CRational& subtrahend);

    const CRational operator*=(const CRational& factor);

    const CRational operator/=(const CRational& divider);

private:
    int m_numerator = 0;

    int m_denominator = 1;

    void Assign(int numerator, int denominator);

    void Normalize();
};

const CRational operator+(const CRational& lhs, const CRational& rhs);
const CRational operator-(const CRational& lhs, const CRational& rhs);
const CRational operator*(const CRational& lhs, const CRational& rhs);
const CRational operator/(const CRational& lhs, const CRational& rhs);

const bool operator==(const CRational& lhs, const CRational& rhs);
const bool operator!=(const CRational& lhs, const CRational& rhs);

const bool operator<(const CRational& lhs, const CRational& rhs);
const bool operator>(const CRational& lhs, const CRational& rhs);
const bool operator<=(const CRational& lhs, const CRational& rhs);
const bool operator>=(const CRational& lhs, const CRational& rhs);

std::ostream& operator<<(std::ostream& stream, const CRational& value);
std::istream& operator>>(std::istream& stream, CRational& value);