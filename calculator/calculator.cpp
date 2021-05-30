/*
	The MIT License

	Copyright (c) 2021 Dmitry Sushchenko

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "calculator.hpp"

// Main method
long calculator::compute(const std::string& s)
{
	size_t i = 0;
	return _parseExpression(s, i);
}

// Parse methods
long calculator::_parseNumber(const std::string& s, size_t& i)
{
	long result = 0;

	for (; i < s.length(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			break;
		result = result * 10 + (s[i] - '0');
	}

	return result;
}

long calculator::_parseExpression(const std::string& s, size_t& i)
{
	_skip_spaces(s, i);
	long result = _parseTerm(s, i);
	char op = s[i];
	while (_isOperator1(op))
	{
		result = _op1(result, _parseTerm(s, ++i), op);
		op = s[i];
	}
	return result;
}

long calculator::_parseTerm(const std::string& s, size_t& i)
{
	_skip_spaces(s, i);
	long result = _parseFactor(s, i);
	char op = s[i];
	while (_isOperator2(op))
	{
		result = _op2(result, _parseFactor(s, ++i), op);
		op = s[i];
	}
	return result;
}

long calculator::_parseFactor(const std::string& s, size_t& i)
{
	_skip_spaces(s, i);
	long result = 0;

	switch (s[i])
	{
	case '(':
		result = _parseExpression(s, ++i);
		++i;
		break;
	case '-':
		result = _parseFactor(s, ++i) * -1;
		break;
	default:
		result = _parseNumber(s, i);
		break;
	}
	_skip_spaces(s, i);

	return result;
}

// Auxiliary methods
long calculator::_op1(const long& a, const long& b, const char& op)
{
	switch (op)
	{
	case '-':
		return a - b;
		break;
	case '+':
		return a + b;
		break;
	default:
		throw std::logic_error("unknown operation");
		break;
	}
}

long calculator::_op2(const long& a, const long& b, const char& op)
{
	switch (op)
	{
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	default:
		throw std::logic_error("unknown operation");
		break;
	}
}

void calculator::_skip_spaces(const std::string& s, size_t& i)
{
	for (; s[i] == ' ' && i < s.length(); ++i)
	{
	}
}

bool calculator::_isOperator1(const char& c) const
{
	return (c == '-' || c == '+') && c != ')';
}

bool calculator::_isOperator2(const char& c) const
{
	return (c == '*' || c == '/') && c != ')';
}