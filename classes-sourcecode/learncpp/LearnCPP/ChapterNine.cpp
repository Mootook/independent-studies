#include "ChapterNine.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace chapterNine
{
	// section 2 quiz
	class Fraction
	{
	private:
		int m_numerator{ 0 };
		int m_denominator{ 1 };
	public:
		Fraction(int num = 0, int denom = 1) : m_numerator{ num }, m_denominator{ denom }
		{
		}
		void print()
		{
			std::cout << m_numerator << "/" << m_denominator << '\n';
		}


		friend Fraction operator*(const Fraction& f, int i);
		friend Fraction operator*(int i, const Fraction& f);
		friend Fraction operator*(const Fraction& fFirst, const Fraction& fSecond);
		friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
		// no const ref to fraction so that this can modify member variables
		friend std::istream& operator>>(std::istream &in, Fraction &f);

	};

	Fraction operator*(int i, const Fraction& f)
	{
		return { f.m_numerator * i, f.m_denominator };
	}

	Fraction operator*(const Fraction& f, int i)
	{

		return { f.m_numerator * i, f.m_denominator };
	}

	Fraction operator*(const Fraction& fFirst, const Fraction& fSecond)
	{
		int num{ fFirst.m_numerator * fSecond.m_numerator };
		int denom{ fFirst.m_denominator * fSecond.m_denominator };

		return { num, denom };
	}

	std::ostream& operator<<(std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << "/" << f.m_denominator;
		return out;
	}
		
	std::istream& operator>>(std::istream& in, Fraction& f)
	{
		in >> f.m_numerator;

		in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

		in >> f.m_denominator;
		return in;
	}

	// section 8 quiz
	struct StudentGrade
	{
		std::string name{};
		char grade{};
	};

	class GradeMap
	{
	public:
		char& operator[](std::string name);
	private:
		std::vector<StudentGrade> m_map{};
	};

	char& GradeMap::operator[](std::string name)
	{
		auto found = std::find_if(
			m_map.begin(),
			m_map.end(),
			[name](const StudentGrade& studentGrade) -> bool {
				return name == studentGrade.name;
		});
		if (found != m_map.end())
		{
			return found->grade;
		}
		else
		{
			// not found, add StudentGrade for name
			StudentGrade newStudent{ name };
			m_map.push_back(newStudent);
			return m_map.back().grade;
		}
	}

	class String
	{
	private:
		std::string m_string{};
	public:
		String(std::string string = "") : m_string { string }
		{
		};
		
		std::string operator() (int startingIndex, int length);
	};

	std::string String::operator() (int startingIndex, int length)
	{
		return m_string.substr(startingIndex, length);
	}

	// comprehensive quiz 2
	class Average
	{
	private:
		std::int_least32_t m_sum{};
		std::int_least8_t m_numCount{};
	public:
		Average& operator+=(int num)
		{
			m_sum += num;
			m_numCount++;
			return *this;
		}

		Average() = default;

		Average(const Average& copy) : m_sum(copy.m_sum), m_numCount(copy.m_numCount)
		{

		}

		friend std::ostream& operator<<(std::ostream& out, const Average& f);
	};

	std::ostream& operator<<(std::ostream& out, const Average& a)
	{
		out << a.m_sum / a.m_numCount;
		return out;
	}

	// comprehensive quiz 3
	class IntArray
	{
	public:
		int* m_arr{ nullptr };
		int m_size{};

		IntArray(int length) :
			m_size{ length }
		{
			assert(length > 0 && "IntArray length should be a positive integer");

			m_arr = new int[m_size] {};
		}

		IntArray(const IntArray& array) :
			m_size{ array.m_size }
		{
			// Allocate a new array
			m_arr = new int[m_size];

			// Copy elements from original array to new array
			for (int count{ 0 }; count < array.m_size; ++count)
				m_arr[count] = array.m_arr[count];
		}

		~IntArray()
		{
			delete[] m_arr;
		}

		int& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);
	};

	int& IntArray::operator[] (int index)
	{
		return m_arr[index];
	}

	std::ostream& operator<<(std::ostream& out, const IntArray& arr)
	{
		for (int i = 0; i < arr.m_size; ++i)
		{
			out << arr.m_arr[i];
		}
		return out;
	}

	IntArray fillArray()
	{
		IntArray a(5);
		a[0] = 5;
		a[1] = 8;
		a[2] = 2;
		a[3] = 3;
		a[4] = 6;
		return a;
	}

	// comprehensive quiz 4
	class FixedPoint2
	{
	private:
		std::int_least16_t m_nonFractional{};
		std::int_least8_t m_fractional{};
	public:
		FixedPoint2(std::int_least16_t nonFractional = 0, std::int_least8_t fractional = 0) : 
			m_nonFractional{ nonFractional }, m_fractional{ fractional }
		{
			// correction
			if (m_nonFractional < 0 || m_fractional < 0)
			{
				if (m_fractional > 0)
				{
					m_fractional = -m_fractional;
				}
				if (m_nonFractional > 0)
				{
					m_nonFractional = -m_nonFractional;
				}
			}
		}

		FixedPoint2(double d)
		{
			m_nonFractional = static_cast<int>(d);
			m_fractional = std::round((m_nonFractional - d) * 100);
		}

		friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& point)
		{
			out << static_cast<double>(point);
			return out;
		}

		operator double() const {
			return m_nonFractional + static_cast<double>(m_fractional) / 100;
		}
	};

	void section(int section)
	{
		switch (section)
		{
		case 2:
		{
			// Quiz
			// 1. Write a class named Fraction that
			// has a integer numerator and denominator member.
			// Write a print() function that prints out the fraction.

			// correct

			// 1b. Add overloaded multiplication operators to handle
			// multiplication between a Fraction and integer,
			// and between two Fractions. Use the friend function method.

			// correct	

			Fraction f1{ 2, 5 };
			f1.print();

			Fraction f2{ 3, 8 };
			f2.print();

			Fraction f3{ f1 * f2 };
			f3.print();

			Fraction f4{ f1 * 2 };
			f4.print();

			Fraction f5{ 2 * f2 };
			f5.print();

			Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
			f6.print();
			break;
		}
		case 3:
		{
			// Quiz 
			// 1. Take the Fraction class we wrote in the previous
			// quiz (listed below) and add an overloaded operator<< and operator>> to it.

			// The following program should compile:
			Fraction f1{};
			std::cout << "Enter fraction 1: ";
			std::cin >> f1;

			Fraction f2{};
			std::cout << "Enter fraction 2: ";
			std::cin >> f2;

			std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

			// correct: check on non-const for std::istream operator overload
			break;
		}
		case 4:
		{
			// Quiz
			// 1. Implement overload operator for the Point class

			break;
		}
		case 8:
		{
			// Quiz

			// A map is a class that stores elements as a key-value pair.
			// The key must be unique, and is used to access the
			// associated pair. In this quiz, we’re going to write an
			// application that lets us assign grades to students by name,
			// using a simple map class.
			// The student’s name will be the key, and the grade (as a char) will be the value.

			// 1a. First, write a struct named StudentGrade that contains the student’s
			// name (as a std::string) and grade (as a char).
			
			// correct

			// 1b. Add a class named GradeMap that contains a std::vector of StudentGrade named m_map. 

			// correct

			// 1c. Write an overloaded operator[] for this class.
			// This function should take a std::string parameter,
			// and return a reference to a char. In the body of the
			// function, first see if the student’s name already
			// exists (You can use std::find_if from <algorithm>).
			// If the student exists, return a reference to the grade
			// and you’re done. Otherwise, use the
			// std::vector::push_back() function to add a StudentGrade
			// for this new student. When you do this, std::vector will
			// add a copy of your StudentGrade to itself
			// (resizing if needed, invalidating all previously returned references).
			// Finally, we need to return a reference to the grade for the student
			// we just added to the std::vector. We can access the student
			// we just added using the std::vector::back() function.

			GradeMap grades{};

			grades["Joe"] = 'A';
			grades["Frank"] = 'B';

			std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
			std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

			// correct
			break;
		}
		case 9:
		{
			// Quiz
			// 1. Write a class that holds a string. Overload operator() to
			// return the substring that starts at the index of
			// the first parameter.
			// The length of the substring should be defined by the second parameter. 
			String string{ "Hello, world!" };
			std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

			// correct: make sure to do safety checks against m_string so it's not accessing outside of the string length

			break;
		}
		default:
			break;
		}
	}

	void comprehensiveQuiz(int questionNumber)
	{
		switch (questionNumber)
		{
		case 1:
		{

			// 1.  Assuming Point is a class and point is an instance of that class,
			// should you use a normal/friend or member function overload
			// for the following operators?

			// 1a. point + point -> friend
			// correct

			// 1b. - point -> friend
			// incorrect: unary operator- is best implemented as a member function

			// 1c std::cout << point -> member
			// incorrect: << must be implemented as a normal function

			// 1d. point = 5; -> member
			// correct

			break;
		}
		case 2:
		{
			// 2) Write a class named Average that will keep 
			// track of the average of all integers passed to it. 
			// Use two members: The first one should be 
			// type std::int_least32_t, and used to keep 
			// track of the sum of all the numbers you’ve 
			// seen so far. The second should be of 
			// type std::int_least8_t, and used to keep 
			// track of how many numbers you’ve seen 
			// so far. You can divide them to find your average.


			Average avg{};

			avg += 4;
			std::cout << avg << '\n'; // 4 / 1 = 4

			avg += 8;
			std::cout << avg << '\n'; // (4 + 8) / 2 = 6

			avg += 24;
			std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

			avg += -10;
			std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

			(avg += 6) += 10; // 2 calls chained together
			std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7


			Average copy{ avg };
			std::cout << copy << '\n';
			// correct
			break;
		}
		case 3:
		{
			// 3. Write your own integer array class named IntArray from scratch 
			// (do not use std::array or std::vector). 
			// Users should pass in the size of the array 
			// when it is created, and the array should be dynamically allocated. Use 
			// assert statements to guard against bad data. Create any constructors 
			// or overloaded operators needed to make the following program operate 
			// correctly:

			IntArray a{ fillArray() };
			std::cout << a << '\n';
			return;
			auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
			a = ref;

			IntArray b(1);
			b = a;

			std::cout << b << '\n';
			// correct-ish: watch the copy overloader
			break;
		}
		case 4:
		{
			// Extra credit: This one is a little more tricky. 
			// A floating point number is a number with a 
			// decimal where the number of digits after the decimal can be 
			// variable. A fixed point number is a number 
			// with a fractional component where the number of digits 
			// in the fractional portion is fixed.

			// In this quiz, we’re going to write a class to
			// implement a fixed point number with two fractional digits 
			// (e.g. 12.34, 3.00, or 1278.99). Assume 
			// that the range of the class should be 
			// -32768.99 to 32767.99, 
			// that the fractional component should hold any two digits, 
			// that we don’t want precision errors, 
			// and that we want to conserve space.

			// 4a. What type of member variable(s) do you think we 
			// should use to implement our fixed point 
			// number with 2 digits after the decimal? (
			// Make sure you read 
			// the answer before proceeding with the next questions)

			// incorrect: 16bit signed integer to hold the non-fractional part of the number, and
			// an 8-bit signed integer to hold the fractional component

			// 4b. Write a class named FixedPoint2 that 
			// implements the recommended solution from the previous question. 
			// If either (or both) of the non-fractional 
			// and fractional part of the number are negative, 
			// the number should be treated as negative. Provide 
			// the overloaded operators and constructors required for the following 
			// program to run:
			FixedPoint2 a{ 34, 56 };
			std::cout << a << '\n';

			FixedPoint2 b{ -2, 8 };
			std::cout << b << '\n';

			FixedPoint2 c{ 2, -8 };
			std::cout << c << '\n';

			FixedPoint2 d{ -2, -8 };
			std::cout << d << '\n';

			FixedPoint2 e{ 0, -5 };
			std::cout << e << '\n';

			std::cout << static_cast<double>(e) << '\n';

			// almost! -- use std::int_least16_t and make sure that gets implicitly converted by constructor
			// safety check in constructor was missing

			// 4c. Now add a constructor that takes a double. 
			// You can round a number (on the left 
			// of the decimal) by using the std::round() function 
			// (included in header cmath).

			// almost, use unfirom initializer in constructor, i.e:
			// m_base{ static_cast<int_least16_t>(d) },
			// m_decimal{ static_cast<std::int_least8_t>(std::round((d - static_cast<int_least16_t>(d)) * 100))



			break;
		}
		default:
			break;
		}
	}

}