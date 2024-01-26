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
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif