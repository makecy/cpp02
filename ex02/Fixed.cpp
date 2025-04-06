#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" <<std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->_fixedPointValue + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->_fixedPointValue - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
	return result;
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_fixedPointValue++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_fixedPointValue--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}