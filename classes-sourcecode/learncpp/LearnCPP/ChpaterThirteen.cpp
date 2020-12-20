#include "ChapterThirteen.h"

#include <string>
#include <iostream>

namespace chapterThirteen
{
	template <class T>
	class Pair1
	{
	private:
		T m_first{};
		T m_second{};
	public:

		Pair1(const T& first, const T& second) 
		{
			m_first = first;
			m_second = second;
		}

		T first() const
		{
			return m_first;
		}

		T second() const
		{
			return m_second;
		}
	};

	template <class T, class H>
	class Pair
	{
	private:
		T m_x;
		H m_y;
	public:
		Pair(const T& x, const H& y) : m_x{ x }, m_y{ y }
		{

		}

		const T& first() const { return m_x; };

		const H& second() const { return m_y; };
	};

	template <class S>
	class StringValuePair : public Pair<std::string, S>
	{
	public:
		StringValuePair(const std::string& key, const S& value)
			: Pair<std::string, S>(key, value)
		{
		}
	};

	void comprehensiveQuiz(int questionNumber)
	{
		switch (questionNumber)
		{
		case 1:
		{
			// It’s sometimes useful to define data that travels in pairs. 
			// Write a templated class named Pair1 that allows the user to define one template 
			// type that is used for both values in the pair. The following function should work:
			Pair1<int> p1(5, 8);
			std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

			const Pair1<double> p2(2.3, 4.5);
			std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';


			// mostly correct
			// const T& first() const { return m_first }; instead
			break;
		}
		case 2:
		{
			// Write a Pair class that allows you to specify separate types for each of 
			// the two values in the pair.
			// Note : We’re naming this class differently from the previous one because 
			// C++ does not currently allow you to “overload” classes that differ 
			// only in the number or type of template parameters.

			// The following program should work :

			Pair<int, double> p1(5, 6.7);
			std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

			const Pair<double, int> p2(2.3, 4);
			std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

			// correct
			break;
		}
		case 3:
		{
			// A string - value pair is a special type of pair where the first 
			// value is always a string type, and the second value can be any 
			// type.Write a template class named StringValuePair that inherits from a partially specialized 
			// Pair class (using std::string as the first type, and allowing 
			// the user to specify the second type).

			// The following program should run:
			StringValuePair<int> svp("Hello", 5);
			std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

			// incorrect...correct answer copied over
			break;
		}
		default:
			break;
		}
	}
}