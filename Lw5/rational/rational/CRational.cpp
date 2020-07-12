#include "CRational.h"

CRational::CRational(int value)
{
    m_numerator = value;
}

CRational::CRational(int numerator, int denominator)
{
    m_numerator = numerator;
    m_denominator = denominator;

    Assign(numerator, denominator);
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

double CRational::ToDouble() const
{
    const auto doublePrecisionNumerator = static_cast<double>(m_numerator);

    return doublePrecisionNumerator / m_denominator;
}

std::pair<int, CRational> CRational::ToMixedFraction() const
{
    const int integerPart = m_numerator / m_denominator;

    const int fractionalPartNumerator = m_numerator - integerPart * m_denominator;
    CRational fractionalPart = CRational(fractionalPartNumerator, m_denominator);

    return { integerPart, fractionalPart };
}

const CRational CRational::operator+() const
{
    return *this;
}

const CRational CRational::operator-() const
{
    return CRational(-m_numerator, m_denominator);
}

const CRational CRational::operator+=(const CRational& addend)
{
    const int addendNumerator = addend.GetNumerator();
    const int addendDenominator = addend.GetDenominator();

    if (!addendNumerator)
    {
        return *this;
    }

    const int numerator = m_numerator * addendDenominator + addendNumerator * m_denominator;
    const int denominator = m_denominator * addendDenominator;

    Assign(numerator, denominator);

    return *this;
}

const CRational CRational::operator-=(const CRational& subtrahend)
{
    const int subtrahendNumerator = subtrahend.GetNumerator();
    const int subtrahendDenominator = subtrahend.GetDenominator();

    if (!subtrahendNumerator)
    {
        return *this;
    }

    const int numerator = m_numerator * subtrahendDenominator - subtrahendNumerator * m_denominator;
    const int denominator = m_denominator * subtrahendDenominator;

    Assign(numerator, denominator);

    return *this;
}

const CRational CRational::operator*=(const CRational& multiplier)
{
    const int numerator = m_numerator * multiplier.GetNumerator();
    const int denominator = m_denominator * multiplier.GetDenominator();

    Assign(numerator, denominator);

    return *this;
}

const CRational CRational::operator/=(const CRational& divider)
{
    const int numerator = m_numerator * divider.GetDenominator();
    const int denominator = m_denominator * divider.GetNumerator();

    Assign(numerator, denominator);

    return *this;
}

void CRational::Assign(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw std::logic_error("Denominator must not be equal to zero");
    }

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    m_numerator = numerator;
    m_denominator = denominator;

    Normalize();
}

void CRational::Normalize()
{
    const auto getGreatestCommonDivisor = [](unsigned int a, unsigned int b) -> unsigned int {
        while (b != 0)
        {
            std::swap(a, b);
            b = b % a;
        }

        return (a != 0) ? a : 1;
    };

    const int greatestCommonDivisor = getGreatestCommonDivisor(abs(m_numerator), m_denominator);

    m_numerator /= greatestCommonDivisor;
    m_denominator /= greatestCommonDivisor;
}

const CRational operator+(const CRational& lhs, const CRational& rhs)
{
    const int numerator = lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator();
    const int denominator = lhs.GetDenominator() * rhs.GetDenominator();

    return CRational(numerator, denominator);
}

const CRational operator-(const CRational& lhs, const CRational& rhs)
{
    const int numerator = lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator();
    const int denominator = lhs.GetDenominator() * rhs.GetDenominator();

    return CRational(numerator, denominator);
}

const CRational operator*(const CRational& lhs, const CRational& rhs)
{
    const int numerator = lhs.GetNumerator() * rhs.GetNumerator();
    const int denominator = lhs.GetDenominator() * rhs.GetDenominator();

    return CRational(numerator, denominator);
}

const CRational operator/(const CRational& lhs, const CRational& rhs)
{
    const int numerator = lhs.GetNumerator() * rhs.GetDenominator();
    const int denominator = lhs.GetDenominator() * rhs.GetNumerator();

    return CRational(numerator, denominator);
}

const bool operator==(const CRational& lhs, const CRational& rhs)
{
    const bool isNumeratorsEqual = lhs.GetNumerator() == rhs.GetNumerator();
    const bool isDenominatorsEqual = lhs.GetDenominator() == rhs.GetDenominator();

    return isNumeratorsEqual && isDenominatorsEqual;
}

const bool operator!=(const CRational& lhs, const CRational& rhs)
{
    const bool isNumeratorsUnequal = lhs.GetNumerator() != rhs.GetNumerator();
    const bool isDenominatorsUneEqual = lhs.GetDenominator() != rhs.GetDenominator();

    return isNumeratorsUnequal || isDenominatorsUneEqual;
}

const bool operator<(const CRational& lhs, const CRational& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator()) < (rhs.GetNumerator() * lhs.GetDenominator());
}

const bool operator>(const CRational& lhs, const CRational& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator()) > (rhs.GetNumerator() * lhs.GetDenominator());
}

const bool operator<=(const CRational& lhs, const CRational& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator()) <= (rhs.GetNumerator() * lhs.GetDenominator());
}

const bool operator>=(const CRational& lhs, const CRational& rhs)
{
    return (lhs.GetNumerator() * rhs.GetDenominator()) >= (rhs.GetNumerator() * lhs.GetDenominator());
}

std::ostream& operator<<(std::ostream& output, const CRational& number)
{
    output << number.GetNumerator() << "/" << number.GetDenominator();

    return output;
}

std::istream& operator>>(std::istream& stream, CRational& number)
{
    int numerator = 0;
    int denominator = 1;

    if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
    {
        number = CRational(numerator, denominator);

        return stream;
    }

    stream.setstate(std::ios_base::failbit);

    return stream;
}