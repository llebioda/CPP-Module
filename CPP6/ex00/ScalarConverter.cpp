/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:15:56 by llebioda          #+#    #+#             */
/*   Updated: 2025/03/04 15:20:09 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum ValueType { CHAR, INT, FLOAT, DOUBLE, UNKNOW };

bool isCharLiteral(const std::string& literal)
{
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool isIntLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;

	long long value = 0;
	bool isNegative = literal[0] == '-';
	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;

	for (; i < literal.size(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;

		value = value * 10 + (literal[i] - '0');

		if (isNegative && -value < std::numeric_limits<int>::min())
			return false;
		if (!isNegative && value > std::numeric_limits<int>::max())
			return false;
	}

	return true;
}

bool isFloatLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;

	if (literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;

	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;

	bool hasDecimal = false;
	bool hasDigits = false;
	bool hasExponent = false;
	for (; i < literal.size(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
        else if (literal[i] == 'e' || literal[i] == 'E')
        {
            if (hasExponent || !hasDigits)
                return false;
            hasExponent = true;
            hasDigits = false;
        }
        else if (literal[i] == '-' || literal[i] == '+')
        {
			if (i == 0)
				return false;
            if (literal[i-1] != 'e' && literal[i-1] != 'E')
                return false;
        }
		else if (std::isdigit(literal[i]))
			hasDigits = true;
		else if (literal[i] == 'f' && i == literal.size() - 1 && hasDigits)
			return true;
		else
			return false;
	}
	return false;
}

bool isDoubleLiteral(const std::string& literal)
{
	if (literal.empty())
		return false;

	if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan")
		return true;

	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;

	bool hasDecimal = false;
	bool hasDigits = false;
	bool hasExponent = false;
	for (; i < literal.size(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDecimal || hasExponent)
				return false;
			hasDecimal = true;
		}
        else if (literal[i] == 'e' || literal[i] == 'E')
        {
            if (hasExponent || !hasDigits)
                return false;
            hasExponent = true;
            hasDigits = false;
        }
        else if (literal[i] == '-' || literal[i] == '+')
        {
			if (i == 0)
				return false;
            if (literal[i-1] != 'e' && literal[i-1] != 'E')
                return false;
        }
		else if (std::isdigit(literal[i]))
			hasDigits = true;
		else
			return false;
	}
	return hasDigits;
}

ValueType getLiteralType(const std::string& literal)
{
    if (isCharLiteral(literal)) return CHAR;
	if (isIntLiteral(literal)) return INT;
	if (isFloatLiteral(literal)) return FLOAT;
    if (isDoubleLiteral(literal)) return DOUBLE;
    return UNKNOW;
}

char convertToChar(const std::string& literal)
{
	if (literal.length() >= 1)
		return literal[0];
	return 0;
}

int convertToInt(const std::string& literal)
{
    int result = 0;
    size_t i = 0;
    bool isNegative = false;

    if (literal[0] == '-')
	{
        isNegative = true;
        i++;
    } else if (literal[0] == '+')
        i++;

    for (; i < literal.size(); i++)
        result = result * 10 + (literal[i] - '0');
    return isNegative ? -result : result;
}

double	ftPower(double nb, int power)
{
	double a;

	if (power < 0)
		return (0.0);
	if (power == 0)
		return (1.0);
	a = 1.0;
	while (power > 0)
	{
		a *= nb;
		power--;
	}
	return (a);
}

float convertToFloat(const std::string& literal)
{
    if (literal == "-inff")
		return -std::numeric_limits<float>::infinity();
    if (literal == "inff" || literal == "+inff")
		return std::numeric_limits<float>::infinity();
    if (literal == "nanf")
		return std::numeric_limits<float>::quiet_NaN();

    float result = 0.0f;
    size_t i = 0;
    bool isNegative = literal[0] == '-';
    bool isFraction = false;
    bool isExponent = false;
    float fractionValue = 1.0f;
    int exponentValue = 0;
    bool exponentNegative = false;

	if (literal[0] == '-' || literal[0] == '+')
		i++;

    for (; i < literal.size(); i++)
	{
        if (literal[i] == '.')
            isFraction = true;
		else if (literal[i] == 'e' || literal[i] == 'E')
		{
			isExponent = true;
			i++;
			exponentNegative = literal[i] == '-';
			if (literal[i] == '-' || literal[i] == '+')
				i++;
			break;
		}
        else if (std::isdigit(literal[i]))
		{
            if (isFraction)
			{
                fractionValue *= 0.1f;
                result += (literal[i] - '0') * fractionValue;
            }
			else
                result = result * 10.0f + (literal[i] - '0');
        }
		else if (literal[i] == 'f')
			break;
    }

    if (isExponent)
    {
        for (; i < literal.size(); i++)
            if (std::isdigit(literal[i]))
                exponentValue = exponentValue * 10 + (literal[i] - '0');

        result *= ftPower((exponentNegative ? 0.1 : 10.0), exponentValue);
	}

    return isNegative ? -result : result;
}

double convertToDouble(const std::string& literal)
{
    if (literal == "-inf")
		return -std::numeric_limits<double>::infinity();
    if (literal == "inf" || literal == "+inf")
		return std::numeric_limits<double>::infinity();
    if (literal == "nan")
		return std::numeric_limits<double>::quiet_NaN();

	double result = 0.0;
	size_t i = 0;
    bool isNegative = literal[0] == '-';
	bool isFraction = false;
	bool isExponent = false;
	double fractionValue = 1.0;
	int exponentValue = 0;
	bool exponentNegative = false;

	if (literal[0] == '-' || literal[0] == '+')
		i++;

	for (; i < literal.size(); i++)
	{
		if (literal[i] == '.')
			isFraction = true;
		else if (literal[i] == 'e' || literal[i] == 'E')
		{
			isExponent = true;
			i++;
			exponentNegative = literal[i] == '-';
			if (literal[i] == '-' || literal[i] == '+')
				i++;
			break;
		}
		else if (std::isdigit(literal[i]))
		{
			if (isFraction)
			{
				fractionValue *= 0.1;
				result += (literal[i] - '0') * fractionValue;
			}
			else
				result = result * 10.0 + (literal[i] - '0');
		}
	}

	if (isExponent)
	{
		for (; i < literal.size(); i++)
			if (std::isdigit(literal[i]))
				exponentValue = exponentValue * 10 + (literal[i] - '0');

		result *= ftPower((exponentNegative ? 0.1 : 10.0), exponentValue);
	}

	return isNegative ? -result : result;
}

void printChar(char c, bool isImpossible=false)
{
	if (isImpossible)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(int i, bool isImpossible=false)
{
	if (isImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void printFloat(float f, bool isImpossible=false)
{
	if (isImpossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

void printDouble(double d, bool isImpossible=false)
{
	if (isImpossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	switch (getLiteralType(literal))
	{
		case CHAR:
			{
				char c = convertToChar(literal);
				printChar(c);
				printInt(static_cast<int>(c));
				printFloat(static_cast<float>(c));
				printDouble(static_cast<double>(c));
			}
			break;

		case INT:
			{
				int i = convertToInt(literal);
				printChar(static_cast<char>(i), i < 0 || i >= 128);
				printInt(i);
				printFloat(static_cast<float>(i));
				printDouble(static_cast<double>(i));
			}
			break;

		case FLOAT:
			{
				float f = convertToFloat(literal);
				printChar(static_cast<char>(f), f < 0.0f || f >= 128.0f);
				printInt(static_cast<int>(f), f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()));
				printFloat(f);
				printDouble(static_cast<float>(f));
			}
			break;

		case DOUBLE:
			{
				double d = convertToDouble(literal);
				printChar(static_cast<char>(d), d < 0.0 || d >= 128.0);
				printInt(static_cast<int>(d), d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()));
				bool isInfOrNaN = d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::quiet_NaN();
				printFloat(static_cast<float>(d), !isInfOrNaN && (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()));
				printDouble(d);
			}
			break;

		default:
			printChar(0, true);
			printInt(0, true);
			printFloat(0.0f, true);
			printDouble(0.0, true);
			break;
	}
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}
