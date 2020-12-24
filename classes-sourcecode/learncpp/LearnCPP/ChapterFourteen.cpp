#include "ChapterFourteen.h"

#include <iostream>
#include <stdexcept>

namespace chapterFourteen
{
	class Fraction
	{
	private:
		int m_denom;
		int m_num;
	public:
		Fraction(int num, int denom) : m_num{ num }, m_denom{ denom }
		{
			if (denom == 0)
				throw std::runtime_error("Entered invalid denominator");
		}

		void print()
		{
			std::cout << m_num << '/' << m_denom;
		}
	};
	void comprehensiveQuiz()
	{
		// Comprehensive Quiz
		// 1. Write a Fraction class that has a constructor that 
		// takes a numerator and a denominator. If the 
		// user passes in a denominator of 0, throw 
		// an exception of type std::runtime_error (included 
		// in the stdexcept header). In your main program,
		// ask the user to enter two integers. 
		// If the Fraction is valid, print the fraction.
		// If the Fraction is invalid, catch a 
		// std::exception, and tell the user that 
		// they entered an invalid fraction.

		int num{};
		std::cout << "Enter a numerator: ";
		std::cin >> num;

		std::cout << "\nNow enter a denominator: ";
		int denom{};
		std::cin >> denom;
		try
		{
			Fraction frac{ num, denom };
			std::cout << "Your fraction is ";
			frac.print();
		}
		catch (const std::exception& exception)
		{
			std::cerr << "Exception raised: " << exception.what() << '\n';
		}
	}
}