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

#pragma once
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

// C++
#include <iostream>
#include <exception>

class calculator
{
public:
	// Main method
	long compute(const std::string& s);

private:
	// Parse methods
	long _parseNumber(const std::string& s, size_t& i);
	long _parseExpression(const std::string& s, size_t& i);
	long _parseTerm(const std::string& s, size_t& i);
	long _parseFactor(const std::string& s, size_t& i);

	// Auxiliary methods
	long _op1(const long& a, const long& b, const char& op);
	long _op2(const long& a, const long& b, const char& op);
	void _skip_spaces(const std::string& s, size_t& i);
	bool _isOperator1(const char& c) const;
	bool _isOperator2(const char& c) const;
};

#endif //CALCULATOR_HPP