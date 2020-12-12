#include "ChapterTwelve.h"

#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// Comprehensive Quiz 2
class Point
{
private:
	int m_x{ 0 };
	int m_y{ 0 };
	int m_z{ 0 };

public:
	Point(int x, int y, int z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
		return out;
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape &p)
	{
		return p.print(out);
	}

	virtual ~Shape()
	{
	}
};

class Triangle : public Shape
{
private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
public:
	Triangle(const Point& point1, const Point& point2, const Point& point3) : m_point1{ point1 }, m_point2{ point1 }, m_point3{ point3 }
	{

	}
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Triangle(" << m_point1 << m_point2 << m_point3 << ")\n";
		return out;
	}

};

class Circle : public Shape
{
private:
	Point m_centerPoint;
	int m_radius;
public:
	Circle(const Point& centerPoint, int radius) : m_centerPoint{ centerPoint }, m_radius{ radius }
	{
	}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Circle(" << m_centerPoint << ", radius " << m_radius << '\n';
		return out;
	}

	int getRadius() const
	{
		return m_radius;
	}

};

int getLargestRadius(std::vector<Shape*>& shapes)
{
	Shape *largestShape { nullptr };
	int largestRadius{};
	for (Shape* shape : shapes)
	{
		Circle *c = dynamic_cast<Circle*>(shape);
		if (c && c->getRadius() > largestRadius)
			largestRadius = c->getRadius();
	}
	return largestRadius;
}



namespace chapterTwelve
{
	void section(int section)
	{
		switch (section)
		{
		case 1:
		{
			// Quiz
			// 1. Our Animal/Cat/Dog example above doesn’t work like 
			// we want because a reference or pointer to an Animal can’t access 
			// the derived version of speak() needed to return the right value for the 
			// Cat or Dog. One way to work around this issue would be to 
			// make the data returned by the speak() function accessible as part of the 
			// Animal base class (much like the Animal’s name is accessible via 
			// member m_name).

			// code copied for quiz

			class Animal
			{
			protected:
				std::string m_name;
				std::string m_speak;
			 
				// We're making this constructor protected because
				// we don't want people creating Animal objects directly,
				// but we still want derived classes to be able to use it.
				Animal(std::string_view name, std::string_view speak)
					: m_name{ name }, m_speak{ speak }
				{
				}
				
				// To prevent slicing (covered later)
				Animal(const Animal&) = delete;
				Animal& operator=(const Animal&) = delete;
			 
			public:
				const std::string& getName() const { return m_name; }
				std::string_view speak() const { return m_speak; }
			};
			 
			class Cat: public Animal
			{
			public:
				Cat(std::string_view name)
					: Animal{ name, "Meow" }
				{
				}
			 
				std::string_view speak() const { return "Meow"; }
			};
			 
			class Dog: public Animal
			{
			public:
				Dog(std::string_view name)
					: Animal{ name, "Woof" }
				{
				}
			 
				std::string_view speak() const { return "Woof"; }
			};
			// Update the Animal, Cat, and Dog classes in the lesson above by adding 
			// a new member to Animal named m_speak. Initialize it appropriately. The following 
			// program should work properly:
			const Cat fred{ "Fred" };
			const Cat misty{ "Misty" };
			const Cat zeke{ "Zeke" };
		 
			const Dog garbo{ "Garbo" };
			const Dog pooky{ "Pooky" };
			const Dog truffle{ "Truffle" };
		 
			// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
			//const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };
			
			// Before C++20, with the array size being explicitly specified
			 const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
			
			for (const auto animal : animals)
			{
				std::cout << animal->getName() << " says " << animal->speak() << '\n';
			}

			// correct

			// 2. Why is the above solution non-optimal
			// Dogs and cats only have one potential speak

			break;
		}
		case 2:
		{
			// Quiz
			// What do the following programs print

			// 1a. A
			// inccorect: B

			// 1b. B
			// Incorrect: C

			// 1c. A
			// Correct

			// 1d. B
			// Incorrect: C

			// 1e. A
			// Correct

			// 1f. A
			// Correct
		}
		default: break;
		}
	}



	void comprehensiveQuiz(int questionNumber)
	{
		switch (questionNumber)
		{
		case 1:
		{
			// Each of the following programs has some kind of 
			// defect. Inspect each program (visually, not by compiling) and determine 
			// what is wrong with the program. The output 
			// of each program is supposed to be “Derived”.
			
			// 1a. getName wasn't made virtual so it resolves to Base.getName()
			// correct
			// 1b. const function and non-const, meaning it isn't an override
			// correct
			// 1c. Base isn't designated override,l so derived getName() doesn't override
			// incorrect: d was assigned a value to b by value, causing d to get sliced
			// 1e. pure virtual function was defined in derived not base, so getName will 
			// resolve to base.getName()
			// almost: derived is a virtual function, therefore derived is an abstract class that
			// can't be instantiated
			// 1f. No answer
			// incorrect: This program actually produces the right output,
			// but has a different issue. We’re deleting b, which is a Base pointer,
			// but we never added a virtual destructor to the Base class.
			// Consequently, the program only deletes the Base portion of the
			// Derived object, and the Derived portion is left as leaked memory.
			break;
		}
		case 2:
		{
			// Quiz
			// 2a. Create an abstract class named Shape. This class should have three functions:
			// a pure virtual print function that takes and returns a std::ostream,
			// an overloaded operator<< and an empty virtual destructor.
			
			// correct


			// 2b) Derive two classes from Shape: a Triangle, and a Circle.
			// The Triangle should have 3 Points as members.
			// The Circle should have one center Point, and an integer radius.
			// Overload the print() function so the following program runs:

			// correctish: watch consts

			// 2c. Given the above classes (Point, Shape, Circle, and Triangle) finish the
			// following the program:

			Circle c{ Point{ 1, 2, 3 }, 7 };
			std::cout << c << '\n';

			Triangle t{ Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9} };
			std::cout << t << '\n';


			std::vector<Shape*> v{
			  new Circle{Point{1, 2, 3}, 7},
			  new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
			  new Circle{Point{4, 5, 6}, 3}
			};

			// print each shape in vector v on its own line here

			std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

			// delete each element in the vector here

			// correct: don't forget to delete vector (below)
			for (const auto* element : v)
				delete element;

			break;
		}
		default:
			break;
		}

	}
}