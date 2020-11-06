#include "ChapterEight.h"

#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>

namespace chapterEight
{
    void section(int section)
    {
		switch (section)
		{
		case 2:
		{
			// Quiz

			// 1. 
			
			// a. Create a class called IntPair that holds two integers.
			// This class should have two member variables to hold the integers.
			// You should also create two member functions: one named “set” that will
			// let you assign values to the integers, and one named “print” that will
			// print the values of the variables.

			// Correct

			class IntPair
			{
			public:
				int m_firstInt{};
				int m_secondInt{};

				void set(int firstInt, int secondInt)
				{
					m_firstInt = firstInt;
					m_secondInt = secondInt;
				};

				void print()
				{
					std::cout << "The first integer is " << m_firstInt << " and the second is " << m_secondInt << '\n';
				};
			};
			break;
		}
		case 3:
		{
			// Quiz

			// Question 1
			// a. What is a public member?
			// A piece of data within a class that can be accessed outside of the class

			// correct

			// b. What is a private member?
			// A piece of data within a class that can not be accessed outside of the class

			// correct ish: "can only be access by other members of the class"

			// c. What is access specifier?
			// A keyword within a class that informs whether the members that follow are public or private

			// correct

			// d. How many access specifers are there, and what are they?
			// 3: public, private, protected

			// Question 2.
			// a. Write a simple class named Point3d. The class should contain:
			// * Three private member variables of type int named m_x, m_y, and m_z;
			// * A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
			// * A public member function named print() that prints the Point in the following format : <m_x, m_y, m_z>

			// Correct

			class Point3d
			{
			private:
				int m_x{};
				int m_y{};
				int m_z{};

			public:
				void setValues(int x, int y, int z)
				{
					m_x = x;
					m_y = y;
					m_z = z;
				}

				void print()
				{
					std::cout << '<' << m_x << ", " << m_y << ", " << m_z << ">\n";
				}

				bool isEqual(Point3d point)
				{
					return point.m_x == m_x && point.m_y == m_y && point.m_z == m_z;
				}
			};
			Point3d point;
			point.setValues(1, 2, 3);

			point.print();
			std::cout << '\n';

			// b. Add a function named isEqual() to your Point3d class. The following code should run correctly :
			Point3d point1;
			point1.setValues(1, 2, 3);

			Point3d point2;
			point2.setValues(1, 2, 3);

			if (point1.isEqual(point2))
			{
				std::cout << "point1 and point2 are equal\n";
			}
			else
			{
				std::cout << "point1 and point2 are not equal\n";
			}

			Point3d point3;
			point3.setValues(3, 4, 5);

			if (point1.isEqual(point3))
			{
				std::cout << "point1 and point3 are equal\n";
			}
			else
			{
				std::cout << "point1 and point3 are not equal\n";
			}

			// Question 3. Now let’s try something a little more complex.
			// Let’s write a class that implements a simple stack from scratch.
			
			// The class should be named Stack, and should contain:
			// *A private fixed array of integers of length 10.
				// * A private integer to keep track of the size of the stack.
				// * A public member function named reset() that sets the size to 0.
				// * A public member function named push() that pushes a value on the stack.push() should return false if the array is already full, and true otherwise.
				// * A public member function named pop() that pops a value off the stackand returns it.If there are no values on the stack, the code should exit via an assert.
				// * A public member function named print() that prints all the values in the stack.

			// correct: see assert in pop()

			class Stack
			{
			private:
				int m_size{ };
				std::array<int, 10> m_callStack{};
			public:
				void reset()
				{
					m_size = 0;
				}
				bool push(int newLastVal)
				{
					if (m_size < 10)
					{
						m_callStack[m_size] = newLastVal;
						m_size++;
						return true;
					}
					return false;
				}
				int pop()
				{
					// correction
					assert(m_size > 0 && "Can not pop empty stack");

					m_size--;
					return m_callStack[m_size];
					
				}
				void print()
				{
					std::cout << "( ";
					for (int i = 0; i < m_size; ++i)
					{
						std::cout << m_callStack[i] << ' ';
					}
					std::cout << ")\n";
				}
			};

			Stack stack;
			stack.reset();
			stack.print();

			stack.push(5);
			stack.push(3);
			stack.push(8);
			stack.print();

			stack.pop();
			stack.print();

			stack.pop();
			stack.pop();

			stack.print();

			break;
		}
		case 5:
		{
			// Quiz

			// Question 1. Write a class named Ball. Ball should have two private member variables
			// with default values: m_color (“black”) and m_radius (10.0).
			// Ball should provide constructors to set only m_color, set only m_radius,
			// set both, or set neither value. For this quiz question, do not
			// use default parameters for your constructors.
			// Also write a function to print out the color and radius of the ball.

			class Ball
			{
			private:
				std::string m_color{ "black" };
				float m_radius{ 10.0f };
			public:
				Ball() = default;

				Ball(const std::string &color, float radius)
				{
					m_color = color;
					m_radius = radius;
				}

				Ball(const std::string &color)
				{
					m_color = color;
				}

				Ball(float radius)
				{
					m_radius = radius;
				}

				void print()
				{
					std::cout << "Radius is " << m_radius << " and the color is " << m_color << '\n';
				}

			};

			// The following sample program should compile:
			Ball def{};
			def.print();

			Ball blue{ "blue" };
			blue.print();

			Ball twenty{ 20.0 };
			twenty.print();

			Ball blueTwenty{ "blue", 20.0 };
			blueTwenty.print();

			// Correct

			// Section 5a
			// Quiz
			// Question 1. Write a class named RGBA that contains 4 member variables of type
			// std::uint_fast8_t named m_red, m_green, m_blue, and m_alpha (#include cstdint to access type std::uint_fast8_t).
			// Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.
			// Create a constructor that uses a member initializer list that allows the user to initialize values for m_red, m_blue, m_green, and m_alpha.
			// Include a print() function that outputs the value of the member variables.

			class RGBA
			{
			private:
				std::uint_fast8_t m_red;
				std::uint_fast8_t m_green;
				std::uint_fast8_t m_blue;
				std::uint_fast8_t m_alpha;
			public:
				RGBA()
				{
					m_red = 0;
					m_alpha = 255;
				}
				RGBA(std::uint_fast8_t red, std::uint_fast8_t green, std::uint_fast8_t blue, std::uint_fast8_t alpha = 255)
					: m_red{ red },
					m_green{ green },
					m_blue{ blue },
					m_alpha{ alpha }
				{

				}
				void print()
				{
					std::cout << '(' << m_red << ", " << m_green << ", " << m_blue << ", " << m_alpha << ")\n";
				}
			};
			RGBA teal{ 0, 127, 127 };
			teal.print();

			// correctish: need to cast to int in order to print, and need to provide default arguments for intializer constructor, default constructor unnecessary
			break;
		}
		default:
			break;
		}
    }
}