#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		const static int bits = 8;
	public:
		Fixed();
		Fixed(int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &obj);

		Fixed& operator=(const Fixed &obj);
		bool operator>(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed &operator++(void);
		const Fixed	operator++(int);
		Fixed &operator--(void);
		const Fixed	operator--(int);

		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);

		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif