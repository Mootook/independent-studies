#include "ChapterFifteen.h"

#include <iostream>
#include <memory> // for std::unique_ptr

namespace chapterFifteen
{

	// Section 6
	class Fraction
	{
	private:
		int m_numerator{ 0 };
		int m_denominator{ 1 };
	 
	public:
		Fraction(int numerator = 0, int denominator = 1) :
			m_numerator{ numerator }, m_denominator{ denominator }
		{
		}
	 
		friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
		{
			out << f1.m_numerator << '/' << f1.m_denominator;
			return out;
		}
	};

	void printFraction(const Fraction* const ptr)
	{
		if (ptr)
			std::cout << *ptr << '\n';
	}

	void section(int number)
	{
		switch (number)
		{
		case 6:
		{
			// Quiz

			// 1. Convert the following program from using a normal pointer to]
			// using std::unique_ptr where appropriate
			//std::unique_ptr<Fraction>  ptr{ new Fraction{ 3, 5 } };
			 
			auto ptr{ std::make_unique<Fraction>(3, 5) };

			printFraction(ptr.get());
		 
			// Correct...almost -- Forgot to use ptr.get()
		 
			break;
		}
		case 8:
		{
			// Quiz
			

			// Fix the resource class to that the resource is properly deallocated

			// changed std::shared_ptr<Resource> m_ptr; to std::weak_ptr
			class Resource
			{
			public:
				std::weak_ptr<Resource> m_ptr; // initially created empty

				Resource() { std::cout << "Resource acquired\n"; }
				~Resource() { std::cout << "Resource destroyed\n"; }
			};

			auto ptr1 = std::make_shared<Resource>();
			ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it
	

			// correct
			break;
		}
		default:
			break;
		}
	}

	void comprehensiveQuiz(int number)
	{
		switch (number)
		{
		case 1:
		{
			// Explain when you should use the following types of pointers:

			// a. std::unique_ptr
			// when you want a singular owner of a pointer to a resource
			// correct

			// b. std::shared_ptr
			// when you want to share ownership of a resource between pointers
			// correct 

			// c. std::weak_ptr
			// when you want a pointer to a resource without ownership
			// correct

			// d. std::auto_ptr
			// avoid. deprecated.
			// correct
			break;
		}
		case 2:
		{
			// Explain how r-values references enable move semantics
			// No answer:
			// Because r - values are temporary, we know 
			// they are going to get destroyed after they are 
			// used.When passing or return an r - value 
			// by value, it’s wasteful to make 
			// a copyand then destroy the original.Instead, 
			// we can simply move(steal) the
			// r - value’s resources, which is generally more efficient.

			break;
		}
		case 3:
		{
			// 3a. what is wrong with the following code? Update the programs to be best practices compliant
			class Resource
			{
			public:
				Resource() { std::cout << "Resource acquired\n"; }
				~Resource() { std::cout << "Resource destroyed\n"; }
			};

			auto* res{ new Resource{} };
			// Original
			/*
			* 
				std::shared_ptr<Resource> ptr1{ res };
				std::shared_ptr<Resource> ptr2{ res };
				shared pointers created from same resource without knowledge
				of each other
				will crash when the second gets deallocated
			*/
			// Fixed
			auto ptr1{ std::make_shared<Resource>() };
			auto ptr2{ ptr1 };

			// Correct

			// 3b.
			/*
			class Something; // assume Something is a class that can throw an exception

			int main()
			{
				doSomething(std::shared_ptr{ new Something{} }, std::shared_ptr{ new Something{} });

				return 0;
			}
			*/
			// No answer
			// Correct answer
			// If the constructor for Something throws an exception, one of the Somethings may not
			// be deallocated properly. use make_shared
			break;
		}
		default:
			break;
		}
	}
}