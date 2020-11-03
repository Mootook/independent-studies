#include "ChapterF.h"
#include <cassert>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iterator>
#include <functional>
#include <random>
#include <string_view>
#include <utility>
#include <vector>


int sumTo(const int endValue);

void printEmployeeName(const Employee &employee);

std::pair<int, int> minMax(const int x, const int y);

int getIndexOfLargestValue(const std::vector<int> &arr);

std::string getElement(const std::vector<std::string> &arr, const int index);


int getUserInt()
{
	std::cout << "Enter an integer: " << '\n';
	while (true)
	{
		int retVal{};
		std::cin >> retVal;
		return retVal;
	}
}

char getUserOperator()
{
	char retVal{};
	do
	{
		std::cout << "Enter a mathematical operator: " << '\n';
		std::cin >> retVal;
	} while (retVal != '+' && retVal != '-' && retVal != '*' && retVal != '/');
	return retVal;
}

int add(const int x, const int y)
{
	return x + y;
}

int subtract(const int x, const int y)
{
	return x - y;
}

int multiply(const int x, const int y)
{
	return x * y;
}

int divide(const int x, const int y)
{
	return x / y;
}

std::function<int(int, int)> getArihmeticFunction(const char operation)
{
	if (operation == '+')
	{
		return add;
	}
	else if (operation == '-')
	{
		return subtract;
	}
	else if (operation == '*')
	{
		return multiply;
	}
	else
	{
		return divide;
	}
}

int factorial(int number)
{
	if (number == 0)
	{
		return 1;
	}
	else
	{
		return factorial(number - 1) * (number);
	}
}

int sumOfDigits(int number)
{
	// Corrected answer:
	if (number < 10)
	{
		return number;
	}
	else
	{
		return sumOfDigits(number / 10) + number % 10;
	}

	return 0;
}



void printBinary(int number)
{
	static std::vector<int> binary{};

	if (number == 1)
	{
		std::cout << '\n';
		for (int i{ 0 }; i < binary.size(); ++i)
		{
			std::cout << binary[i] << ' ' << '\n';
		}
		return;
	}

	if (number % 2 == 0)
	{
		binary.push_back(0);
	}
	else
	{
		binary.push_back(1);
	}
	printBinary(number / 2);


	// Correct solution
	if (number == 0)
	{
		return;
	}
	printBinary(number / 2);

	std::cout << number % 2;
}

// comprehensive quiz
// 1a.
double max(const double x, const double y);
// 1b.
void swap(int& x, int& y);
// 1c.
int getLargestElement(int *arr, const int length);

// 3a.
// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max)
{
	// iterative version
	// first get middle index
	

	bool exhaustedArr{ false };
	constexpr int notFoundIndex{ -1 };
	do
	{
		//std::cout << "Max Index: " << max << "\nMin Index: " << min << '\n';
		int middleIndex{ ((max - min) / 2) + min };
		//std::cout << "Middle Index: " << middleIndex << '\n';
		//if (middleIndex > 0 && middleIndex % 2 == 0)
		//{
		//	middleIndex--;
		//}
		if (min >= max)
		{
			exhaustedArr = true;
			break;
		}
		
		//std::cout << "\nValue at middle index " << array[middleIndex] << " searching for " << target << '\n';
		


		if (target > array[middleIndex])
		{
			//std::cout << target << " is greater than " << array[middleIndex] << " setting " << min << " to " << middleIndex << '\n';
			if (min == middleIndex)
			{
				break;
			}
			min = middleIndex;
			
		}
		else if (target < array[middleIndex])
		{
			//std::cout << target << " is smaller than " << array[middleIndex] << " setting " << max << " to " << middleIndex << '\n';
			if (min == middleIndex)
			{
				break;
			}
			
			max = middleIndex;
			
		}
		else if (array[middleIndex] == target)
		{
			return middleIndex;
		}
		
	} while (!exhaustedArr);

	return notFoundIndex;
	// correct version
	assert(array);
	while (min <= max)
	{
		// implement this iteratively
		//int midpoint{ std::midpoint(min, max) };

		// Before C++20
		int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

		if (array[midpoint] > target)
		{
			// if array[midpoint] > target, then we know the number must be in the lower half of the array
			// we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
			max = midpoint - 1;
		}
		else if (array[midpoint] < target)
		{
			// if array[midpoint] < target, then we know the number must be in the upper half of the array
			// we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
			min = midpoint + 1;
		}
		else
		{
			return midpoint;
		}
	}

}

int binarySearchRecrusive(const int* array, int target, int min, int max)
{
	
	if (min > max)
	{
		return -1;
	}
	int midpoint{ min + ((max - min) / 2) };
	if (array[midpoint] > target)
	{
		binarySearchRecrusive(array, target, min, midpoint - 1);
	}
	else if (array[midpoint] < target)
	{
		binarySearchRecrusive(array, target, midpoint + 1, max);
	}
	else if (array[midpoint] == target)
	{
		return midpoint;
	}
}


namespace chapterF
{
    void section(int section)
    {
		switch (section)
		{
			case 4:
			{
				// Quiz

				// Write function prototypes for each of the following functions.
				// Use the most appropriate parameter and return types (by value, by address, or by reference),
				// including use of const where appropriate.


				// 1. A function named sumTo() that takes an integer parameter
				// and returns the sum of all the numbers between 1 and the input number.
				
				// Correct: remember to use const where necessary

				// 2. A function named printEmployeeName() that takes an Employee struct as input.
				
				// Correct: remember use of const

				// 3. A function named minmax() that takes two integers as input and returns back to
				// the caller the smaller and larger number in a std::pair. A std::pair works identical to
				// a std::tuple but stores exactly two elements.

				// Correct: const

				// 4. A function named getIndexOfLargestValue() that takes an integer array
				// (as a std::vector), and returns the index of the largest element in the array.

				// Correct

				// 5. A function named getElement() that
				// takes an array of std::string (as a std::vector) and an index and returns
				// the array element at that index (not a copy). Assume the index is valid, and the return value is const.


				// Almost: const std::string& getElement(const std::vector<std::string>& array, const int index);
				// Note: (not a copy)
				break;
			}
			case 8:
			{
				// Quiz

				// 1a.  Create a short program asking the user for
				// two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’).
				// Ensure the user enters a valid operation.
				int x { getUserInt() };
				int y { getUserInt() };
				char operation{ getUserOperator() };

				// Correct: unnecessary loop in getUserInt

				// 1b. Write functions named add(), subtract(), multiply(), and divide().
				// These should take two integer parameters and return an integer.

				// Correct

				// 1c. Create a type alias named arithmeticFcn for a pointer
				// to a function that takes two integer parameters and returns an integer. Use std::function. 

				// std::function<int(int, int)> arithmeticFcn{};

				// almost
				using arithmeticFcn = std::function<int(int, int)>;

				// 1d. Write a function named getArithmeticFunction()
				// that takes an operator character and returns the appropriate function as a function pointer.

				// correct, though ^ using could be defined outside this local scope so that it could be
				// specified as return type for getArithmeticFunction

				// 1e. Modify your main() function to call getArithmeticFunction().
				// Call the return value from that function with your inputs and print the result.

				arithmeticFcn operationFcn{ getArihmeticFunction(operation) };
				std::cout << x << ' ' << operation << ' ' << y << " is " << operationFcn(x, y) << '\n';

				// Correct!

				break;
			}
			case 11:
			{
				// Quiz

				// 1. A factorial of an integer N (written N!) is defined as the product
				// (multiplication) of all the numbers between 1 and N (0! = 1).
				// Write a recursive function called factorial that returns the factorial of the input
				// Test it with the first 7 factorials.

				// Hint: Remember that(x * y) = (y * x), so the product of all the numbers between 1
				// and N is the same as the product of all the numbers between N and 1.
				
				int intToFactorial{ 7 };
				int factorialResult{ factorial(intToFactorial) };
				std::cout << "Factorial of  " << intToFactorial << " = " << factorialResult << '\n';

				// Correct: just make sure to check for n < 0 as well for negative input


				// 2. Write a recursive function that takes an integer as input and
				// returns the sum of each individual digit in the integer
				// (.g. 357 = 3 + 5 + 7 = 15). Print the answer for input 93427 (which is 25).
				// Assume the input values are positive.

				int digitsToSum{ 123 };


				std::cout << "The sum of the digits that compose " << digitsToSum << " = " << sumOfDigits(digitsToSum) << '\n';

				// incorrect

				// 3a. Write a program that asks the user to enter a positive integer,
				// and then uses a recursive function to print out the binary representation for that number. 

				// Hint: Using method 1, we want to print the bits from the "bottom up",
				// which means in reverse order. This means your print statement should be _after_ the recursive call.

				int userInt{};
				do
				{
					std::cout << "Please enter a positive integer: " << '\n';
					std::cin >> userInt;
				} while (userInt <= 0);

				//printBinary(userInt);

				// incorrect

				// 3b. Update your code from 3a to handle the case where the user may enter 0 or a negative number.
				// Hint: You can turn a negative integer into a positive one by converting it to an unsigned integer.
				// These have identical bit representations (the type is used to determine how to interpret the number into decimal).


				//printBinary(static_cast<unsigned int>(userInt));

				// incorrect



				break;
			}
			case 15:
			{

				// Quiz


				// 1. Create a struct Student that stores the name and points of a student.
				// Create an array of students and use std::max_element to find the student with the most points,
				// then print that student’s name. std::max_element takes the begin and end of a list,
				// and a function that takes 2 parameters and returns true if the first argument is less than the second.
				

				struct Student
				{
					std::string name{};
					int points{};
				};

				std::array<Student, 8> arr{
					{ { "Albert", 3 },
					{ "Ben", 5 },
					{ "Christine", 2 },
					{ "Dan", 8 }, // Dan has the most points (8).
					{ "Enchilada", 4 },
					{ "Francis", 1 },
					{ "Greg", 3 },
					{ "Hagrid", 5 } }
				};

				// your program should print
				// Dan is the best student

				auto higherScore{ [](const Student& x, const Student& y) -> bool {
					return x.points < y.points;
				} };
				

				const auto highestScoreStudent{
					std::max_element(arr.begin(), arr.end(), higherScore)
				};
				std::cout << highestScoreStudent->name << " is the best student.\n";

				// correct


				// 2. Use std::sort and a lambda in the following code to sort
				// the seasons by ascending average temperature.


				struct Season
				{
					std::string_view name{};
					double averageTemperature{};
				};
				
				std::array<Season, 4> seasons{
				  { { "Spring", 285.0 },
					{ "Summer", 296.0 },
					{ "Fall", 288.0 },
					{ "Winter", 263.0 } }
				};


				// Sorty here by asc average temperature
				std::sort(seasons.begin(), seasons.end(),
					[](const Season& x, const Season& y) -> bool {
					return x.averageTemperature < y.averageTemperature;
				});



				for (const auto& season : seasons)
				{
					std::cout << season.name << '\n';
				}

				// correct

				break;
			}
			case 16:
			{

				// Quiz

				// 1. Which of the following variables can be used by the lambda without explicitly capturing them?
				/*
					int i{};
					static int j{};
 
					int getValue()
					{
					  return 0;
					}
 
					int main()
					{
					  int a{};
					  constexpr int b{};
					  static int c{};
					  static constexpr int d{};
					  const int e{};
					  const int f{ getValue() };
					  static const int g{}; 
					  static const int h{ getValue() }; 
 
					  [](){
						// Try to use the variables without explicitly capturing them.
						a;
						b;
						c;
						d;
						e;
						f;
						g;
						h;
						i;
						j;
					  }();
 
					  return 0;
					}
				*/


				// 2. What does the following code print? Don’t run the code, work it out in your head.
				/*
					#include <iostream>
					#include <string>
 
					int main()
					{
					  std::string favoriteFruit{ "grapes" };
 
					  auto printFavoriteFruit{
						[=]() {
						  std::cout << "I like " << favoriteFruit << '\n';
						}
					  };
 
					  favoriteFruit = "bananas with chocolate";
 
					  printFavoriteFruit();
 
					  return 0;
					}
				*/
				// I like grapes

				// Correct


				// 3. We’re going to write a little game with square numbers 
				// numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).


				// Ask the user to input 2 numbers, the first is the square root of
				// the number to start at, the second is the amount of numbers to generate.
				// Generate a random integer from 2 to 4, and square numbers in the range that was chosen by the user. 
				// Multiply each square number by the random number. You can assume that the user enters valid numbers.

				// The user has to calculate which numbers have been generated. The program checks
				// if the user guessed correctlyand removes the guessed number from the list.
				// If the user guessed wrong, the game is overand the program prints the number
				// that was closest to the user’s final guess, but only if the final guess was not off by more than 4.


				// Here are a couple of sample sessions to give you a better understanding of how the game works :

				// Start where ? 4
					// How many ? 8
					// I generated 8 square numbers.Do you know what each number is after multiplying it by 2 ?
					// > 32
					// Nice!7 number(s) left.
					// > 72
					// Nice!6 number(s) left.
					// > 50
					// Nice!5 number(s) left.
					// > 126
					// 126 is wrong!Try 128 next time.

				std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
				std::uniform_int_distribution prng{ 2, 4 };
				int randomNumber = prng(mersenne);

				// Get integer to start
				int startInt{};
				std::cout << "Start where? ";
				std::cin >> startInt;

				int numberOfInts{};
				std::cout << "How many? ";
				std::cin >> numberOfInts;

				std::vector<int> listOfNumbers{};

				auto multiplyByIntAndAddToArray {
					[&listOfNumbers, randomNumber](int x) {
						listOfNumbers.push_back(x*x*randomNumber);
						std::cout << x * x * randomNumber;
					}
				};

				// Generate numberOfInts square numbers starting at startInt
				// multiply each by randomNumber
				
				for (int i{ startInt }; i < numberOfInts+startInt; i++)
				{
					multiplyByIntAndAddToArray(i);
				}



				std::cout << "I generated " << numberOfInts << " square numbers. Do you konw what ecah number is after multiplying it by " << randomNumber << "?\n";
				bool gameOver{ false };
				// game loop
				do
				{
					int currentGuess{};
					std::cin >> currentGuess;

					auto found{ std::find(listOfNumbers.begin(), listOfNumbers.end(), currentGuess) };
					if (found != listOfNumbers.end())
					{
						listOfNumbers.erase(found);
						if (listOfNumbers.size() > 0)
						{
							std::cout << "Nice! " << listOfNumbers.size() << " numbers left\n";
						}
					}
					else
					{
						// check if the guess is within the allowance
						const int intAllowance{ 4 };
						auto isNumberWithinAllowance{ [currentGuess, intAllowance](const int x, const int y) -> bool {
							return std::abs(x - currentGuess) <= 4;
						} };
						const auto foundNearestInt{
							std::min_element(listOfNumbers.begin(), listOfNumbers.end(), isNumberWithinAllowance)
						};

						if (foundNearestInt != listOfNumbers.end())
						{
							std::cout << currentGuess << " is wrong! Try " << *foundNearestInt << " next time\n";
							gameOver = true;
							break;
						}
						else
						{
							std::cout << currentGuess << " is wrong!";
							gameOver = true;
							break;
						}
					}

					if (listOfNumbers.size() == 0)
					{
						std::cout << "Nice! You found all numbers, good job!" << '\n';
						gameOver = true;
					}
				} while (!gameOver);


				// Correct: note author's answer which largely used list_type
				break;
			}
			default:
				break;
		}
    }

	void comprehensiveQuiz()
	{
		// Quiz

		// 1. Write function prototypes for the following cases. Use const if/when necessary.

		// a. A function named max() that takes two doubles and returns the larger of the two.
		// correct

		// b. A function named swap() that swaps two integers.
		// correct

		// c. A function named getLargestElement() that takes a dynamically allocated array of
		// integers and returns the largest number in such a way that the caller can change the
		// value of the element returned (don’t forget the length parameter).
		// correct

		// 2. What's wrong with these programs
		// a.
		/*
		int& doSomething()
		{
			int array[]{ 1, 2, 3, 4, 5 };
			return array[3];
		}
		*/
		// the specified return value is a reference but the array will be destroyed
		// at end of call, so it's a dangling reference
		// correct

		// b.
		/*
		int sumTo(int value)
		{
			return value + sumTo(value - 1);
		}
		*/
		// No terminate condition, recursive funciton results in infinite loop

		// c.
		/*
		float divide(float x, float y)
		{
			return x / y;
		}
 
		double divide(float x, float y)
		{
			return x / y;
		}
		*/
		// arguments and function name are the same, won't compile
		// correct


		// d.
		/*
		int main()
		{
			int array[100000000]{};
 
			for (auto x: array)
				std::cout << x << ' ';
 
			std::cout << '\n';
 
			return 0;
		}
		*/
		// to much memory on the stack
		// will terminate program
		// correct

		// e.
		/*
		int main(int argc, char *argv[])
		{
			int age{ argv[1] };
			std::cout << "The user's age is " << age << '\n';
 
			return 0;
		}
		*/
		// cant cast to an int, need to static stream convert
		// partial correct: argv[1] may not exist

		// 3. 
		// The best algorithm for determining whether a value exists in a sorted array is called binary search.
		// Binary search works as follows :

		// Look at the center element of the array(if the array has an even number of elements, round down).
			// If the center element is greater than the target element, discard the top half of the array(or recurse on the bottom half)
			// If the center element is less than the target element, discard the bottom half of the array(or recurse on the top half).
			// If the center element equals the target element, return the index of the center element.
			// If you discard the entire array without finding the target element, return a sentinel that
			// represents “not found”(in this case, we’ll use - 1, since it’s an invalid array index).
			// Because we can throw out half of the array with each iteration, this algorithm is very fast.
			// Even with an array of a million elements, it only takes at most 20 iterations to determine whether a 
			// value exists in the array or not!However, it only works on sorted arrays.

			// Modifying an array(e.g.discarding half the elements in an array) is expensive, so
			// typically we do not modify the array.Instead, we use two integer(min and max) to hold the indices of the minimumand maximum
			// elements of the array that we’re interested in examining.

		// Let’s look at a sample of how this algorithm works, given an array{ 3, 6, 7, 9, 12, 15, 18, 21, 24 },
		// and a target value of 7. At first, min = 0, max = 8, because we’re searching
		// the whole array(the array is length 9, so the index of the last element is 8).

			// Pass 1) We calculate the midpoint of min(0) and max(8), which is 4. Element #4 has value 12, which is
			// larger than our target value.Because the array is sorted, we know that all elements with index equal to or greater than the midpoint(4) must be too large.So we leave min alone, and set max to 3.
			// Pass 2) We calculate the midpoint of min(0) and max(3), which is 1. Element #1 has value 6, which is
			// smaller than our target value.Because the array is sorted, we know that all elements with index equal to or lesser than the midpoint(1) must be too small.So we set min to 2, and leave max alone.
			// Pass 3) We calculate the midpoint of min(2) and max(3), which is 2.
			// Element #2 has value 7, which is our target value. So we return 2.

		// Given the following code:

		constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
 
		// We're going to test a bunch of values to see if they produce the expected results
		constexpr int numTestValues{ 9 };
		// Here are the test values
		constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
		// And here are the expected results for each value
		int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };
 
		// Loop through all of the test values
		for (int count{ 0 }; count < numTestValues; ++count)
		{
			// See if our test value is in the array
			int index{ binarySearchRecrusive(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
			// If it matches our expected value, then great!
			if (index == expectedValues[count])
					std::cout << "test value " << testValues[count] << " passed!\n";
			else // otherwise, our binarySearch() function must be broken
					std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
		}
 
		

		// a. Write an iterative version of the binarySeach function.
		// Hint: You can safely say the target element doesn't exist when the min index is greater than the max index

		// correctish: see author's answer for a more efficient, less condition heavy version

		// b. Write a recursive version of the binarySearch function.
		// correct

	}
}