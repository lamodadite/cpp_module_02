#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int num)
{
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	this->value = roundf(num * (1 << this->bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &obj)
{
	this->value = obj.value;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	if (this != &obj) {
		this->value = obj.value;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->value > obj.value);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->value >= obj.value);
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->value < obj.value);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->value <= obj.value);
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->value == obj.value);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->value != obj.value);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result(this->toFloat() + obj.toFloat());
	return result;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result(this->toFloat() - obj.toFloat());
	return result;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	Fixed result(this->toFloat() * obj.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed result(this->toFloat() / obj.toFloat());
	return result;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

const Fixed	Fixed::operator++(int)
{
	const Fixed ret(*this);
	this->value++;
	return ret;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

const Fixed Fixed::operator--(int)
{
	const Fixed ret(*this);
	this->value--;
	return *this;
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt() const
{
	return this->value >> this->bits;
}

float Fixed::toFloat() const
{
	return (float)this->value / (1 << this->bits);
}