#include "ChapterNine.h"

#include <algorithm>
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
		default:
			break;
		}
	}
}