#include "ChapterEight.h"

#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <random>


// [8.13] Begin
class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};
	// 1a. Make Point3d a friend class of Vector3d, and implement function Point3d::moveByVector()
public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}
	
	friend class Point3d;

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	friend void moveByVector(const Vector3d& v);
	
};

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);
	// 8.13.1a
};

void Point3d::moveByVector(const Vector3d& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}
// [8.13] end



namespace chapterEight
{
	constexpr int maximumScore{ 21 };
	constexpr int dealerLimit{ 17 };

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
		case 13:
		{
			// Quiz

			// Question 1. 
			// In geometry, a point is a position in space. We can define a point in
			// 3d-space as the set of coordinates x, y, and z. For example, the Point(2.0, 1.0, 0.0)
			// would be the point at coordinate space x=2.0, y=1.0, and z=0.0.

			// In physics, a vector is a quantity that has a magnitude (length) and a direction
			// (but no position). We can define a vector in 3d-space as an x, y, and z value representing
			// the direction of the vector along the x, y, and z axis (the length can be derived from these).
			// For example, the Vector(2.0, 0.0, 0.0) would be a vector representing a direction along
			// the positive x-axis (only), with length 2.0.

			// A Vector can be applied to a Point to move the Point to a new position.
			// This is done by adding the vector’s direction to the point’s position to yield a new position.
			// For example, Point(2.0, 1.0, 0.0) + Vector(2.0, 0.0, 0.0) would yield the point (4.0, 1.0, 0.0).
			// Points and Vectors are often used in computer graphics (the point to represent vertices of shape, and vectors represent movement of the shape).

			// Given the following program :


			// DEFINED ABOVE OUTSIDE CURRENT CALL [8.15]

			// 1a. Make Point3d a friend class of Vector3d, and implement function Point3d::moveByVector()

			// 1b. Instead of making class Point3d a friend of class Vector3d, make member function
			// Point3d::moveByVector a friend of class Vector3d.

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
			// 1a. Write a class named Point2d. Point2d should contain two member variables of
			// type double: m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function.

			class Point2d
			{
			private:
				double m_x{};
				double m_y{};
			public:
				Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
				{}

				void print()
				{
					std::cout << "Point2d(" << m_x << ',' << m_y << ")\n";
				}

				double distanceTo(const Point2d& point)
				{
					return std::sqrt((point.m_x - m_x) * (point.m_x - m_x) + (point.m_y - m_y) * (point.m_y - m_y));
				}
			};

			// Correct

			// 1b. Now add a member function named distanceTo that takes another
			// Point2d as a parameter, and calculates the distance between them.
			// Given two points (x1, y1) and (x2, y2), the distance between them can be calculated
			// as std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). The std::sqrt function lives in header cmath.

			Point2d first{};
			Point2d second{ 3.0, 4.0 };
			first.print();
			second.print();
			std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

			// correct
			break;
		}
		case 2:
		{
			// Write a destructor for this class:
			class HelloWorld
			{
			private:
				char* m_data{};

			public:
				HelloWorld()
				{
					m_data = new char[14];
					const char* init{ "Hello, World!" };
					for (int i = 0; i < 14; ++i)
						m_data[i] = init[i];
				}

				~HelloWorld()
				{
					delete[] m_data;
				}

				void print() const
				{
					std::cout << m_data << '\n';
				}

			};
			// correct
			break;
		}
		case 3:
		{
			// Let’s create a random monster generator. This one should be fun.

			// a. First, let’s create an enumeration of monster types named MonsterType. 
			// Include the following monster types : Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. 
			// Add an additional max_monster_types enum so we can count how many enumerators there are.
			
			// correct

			// b. Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables):
			// a type (MonsterType), a name (std::string), a roar (std::string), and the number of hit points (int).
			// Create a Monster class that has these 4 member variables.

			// correct

			// c. enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration.
			// When the enum is inside the class the “Monster” in “MonsterType” is redundant, it can be removed.

			// correct

			// d. Create a constructor that allows you to initialize all of the member variables.

			// correct

			// e. Now we want to be able to print our monster so we can validate it’s correct.
			// To do that, we’re going to need to write a function that converts a Monster::Type into a string.
			// Write that function (called getTypeString()), as well as a print() member function.

			// correct

			// f. Now we can create a random monster generator. Let’s consider how our MonsterGenerator
			// class will work. Ideally, we’ll ask it to give us a Monster, and it will create a random one for us.
			// We don’t need more than one MonsterGenerator.
			// This is a good candidate for a static class (one in which all functions are static).
			// Create a static MonsterGenerator class. Create a static function named generateMonster().
			// This should return a Monster. For now, make it return anonymous Monster(Monster::Type::skeleton, “Bones”, “*rattle*”, 4);

			// correct

			// g. Now, MonsterGenerator needs to generate some random attributes. To do that, we’ll need to make use of this handy function:
			// getRandomNumber() 
			// However, because MonsterGenerator relies directly on this function, let’s put it inside the class, as a static function.

			// correct

			// h. Now edit function generateMonster() to generate a random
			// Monster::Type (between 0 and Monster::Type::max_monster_types-1) and a
			// random hit points (between 1 and 100). This should be fairly straightforward.
			// Once you’ve done that, define two static fixed arrays of size 6 inside the function
			// (named s_names and s_roars) and initialize them with 6 names and 6 sounds of your choice.
			// Pick a random name from these arrays.

			// correct

			class Monster
			{
			public:
				enum class Type
				{
					MONSTER_DRAGON,
					MONSTER_GOBLIN,
					MONSTER_OGRE,
					MONSTER_ORC,
					MONSTER_SKELETON,
					MONSTER_TROLL,
					MONSTER_VAMPIRE,
					MONSTER_ZOMBIE,

					MONSTER_MAX_TYPES,
				};
			private:
				Type m_type{};
				std::string m_name{};
				std::string m_roar{};
				int m_hitPoints{};

				std::string getTypeString()
				{
					switch (m_type)
					{
					case Monster::Type::MONSTER_DRAGON:
						return "Dragon";
					case Monster::Type::MONSTER_GOBLIN:
						return "Goblin";
					case Monster::Type::MONSTER_OGRE:
						return "Ogre";
					case Monster::Type::MONSTER_ORC:
						return "Orc";
					case Monster::Type::MONSTER_SKELETON:
						return "Skeleton";
					case Monster::Type::MONSTER_TROLL:
						return "Troll";
					case Monster::Type::MONSTER_VAMPIRE:
						return "Vampire";
					case Monster::Type::MONSTER_ZOMBIE:
						return "Zombie";
					case Monster::Type::MONSTER_MAX_TYPES:
						break;
					default:
						break;
					}
				}

			public:
				Monster(Type type, const std::string& name, const std::string& roar, int hitPoints) :
					m_type{ type },
					m_name{ name },
					m_roar{ roar },
					m_hitPoints{ hitPoints }
				{
				}

				void print()
				{
					std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hitpoints and says " << '*' << m_roar << "*\n";
				}

			};

			class MonsterGenerator
			{
			public:
				static int getRandomNumber(int min, int max)
				{
					static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
					// evenly distribute the random number across our range
					return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
				}

				static Monster generateMonster()
				{
					static std::array<std::string, 6> s_names{ "Reggie", "Jo", "Ko", "NotReggie", "John", "StillNotReggie" };
					static std::array<std::string, 6> s_roars{ "Roar", "Reggie!", "Meow", "Bark", "Gufaw", "Hi" };

					//Monster::Type::
					return Monster{
						static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::MONSTER_MAX_TYPES))),
						s_names[getRandomNumber(0, s_names.size() - 1)],
						s_roars[getRandomNumber(0, s_roars.size() - 1)],
						getRandomNumber(0, 100) // random hitpoints
					};
				}

				
			};
			Monster m{ MonsterGenerator::generateMonster() };
			m.print();

			break;
		}
		case 4:
		{
			// Okay, time for that game face again. This one is going to be a challenge.
			// Let’s rewrite the Blackjack game we wrote in chapter 6 (chapter p) using classes!

			// Holy moly! Where do we even begin? Don’t worry, we can do this, but we’ll need a strategy here.
			// This Blackjack program is really composed of four parts:
			// the logic that deals with cards,
			// the logic that deals with the deck of cards,
			// the logic that deals with dealing cards from the deck,
			// and the game logic.
			// Our strategy will be to work on each of these pieces individually, testing each
			// part with a small test program as we go. That way, instead of
			// trying to convert the entire program in one go, we can do it in 4 testable parts.

			// a. Let’s start by making Card a class instead of a struct.
			// The good news is that the Card class is pretty similar to
			// the Monster class from the previous quiz question.
			// First, create private members to hold the rank and suit
			// (name them m_rank and m_suit accordingly).
			// Second, create a public constructor for the Card class so we can initialize Cards.
			// Third, make the class default constructible, either by adding a default
			// constructor or by adding default arguments to the current constructor.
			// Finally, move the printCard() and getCardValue() functions inside the
			// class as public members (remember to make them const!).

			// correct

			// b. Okay, now let’s work on a Deck class.
			// The deck needs to hold 52 cards, so use a private std::array
			// member to create a fixed array of 52 cards named m_deck. 
			// Second, create a constructor that takes no parametersand initializes
			// m_deck with one of each card(modify the code from the original createDeck() function). 
			// Third, move printDeck into the Deck class as a public member. 
			// Fourth, move shuffleDeck into the class as a public member.

			// correct

			// c. Now we need a way to keep track of which card is next to be
			// dealt (in the original program, this is what nextCardIndex was for).
			// First, add a member named m_cardIndex to Deck and initialize it to 0.
			// Create a public member function named dealCard(),
			// which should return a const reference to the current card and
			// advance m_cardIndex to the next index. shuffle() should also be
			// updated to reset m_cardIndex (since if you shuffle the deck, you’ll start
			// dealing from the top of the deck again).

			// Correct: also add assert to check m_cardIndex is within m_deck

			// d. Next up is the Player. Because playerTurn and
			// dealerTurn are very different from each other,
			// we’ll keep them as non-member functions. Make Player a class and add a
			// drawCard member function that deals the player one card from the deck,
			// increasing the player’s score. We’ll also need a member function to access
			// the Player‘s score. For convenience, add a member function named isBust()
			// that returns true if the player’s score exceeds the maximum (maximumScore).

			// correct

			// e. Almost there! Now, just fix up the remaining program
			// to use the classes you wrote above. Since most of the functions have
			// been moved into the classes, you can jettison them.

			// correct

			enum class CARD_RANK
			{
				TWO,
				THREE,
				FOUR,
				FIVE,
				SIX,
				SEVEN,
				EIGHT,
				NINE,
				TEN,
				JACK,
				QUEEN,
				KING,
				ACE,

				MAX_RANK
			};
			enum class CARD_SUIT
			{
				CLUBS,
				DIAMONDS,
				HEARTS,
				SPADES,

				MAX_SUIT
			};


			class Card
			{	
			private:
				CARD_RANK m_rank{};
				CARD_SUIT m_suit{};
			public:
				Card(CARD_RANK rank = CARD_RANK::ACE, CARD_SUIT suit = CARD_SUIT::CLUBS) : m_rank{ rank }, m_suit{ suit }
				{
				}

				void printCard() const
				{
					std::string rankStr{};
					switch (m_rank)
					{
					case CARD_RANK::TWO:
						rankStr = "2";
						break;
					case CARD_RANK::THREE:
						rankStr = "3";
						break;
					case CARD_RANK::FOUR:
						rankStr = "4";
						break;
					case CARD_RANK::FIVE:
						rankStr = "5";
						break;
					case CARD_RANK::SIX:
						rankStr = "6";
						break;
					case CARD_RANK::SEVEN:
						rankStr = "7";
						break;
					case CARD_RANK::EIGHT:
						rankStr = "8";
						break;
					case CARD_RANK::NINE:
						rankStr = "9";
						break;
					case CARD_RANK::TEN:
						rankStr = "T";
						break;
					case CARD_RANK::JACK:
						rankStr = "J";
						break;
					case CARD_RANK::QUEEN:
						rankStr = "Q";
						break;
					case CARD_RANK::KING:
						rankStr = "K";
						break;
					case CARD_RANK::ACE:
						rankStr = "A";
						break;
					default:
						break;
					}
					std::string suitStr{};
					switch (m_suit)
					{
					case CARD_SUIT::CLUBS:
						suitStr = "C";
						break;
					case CARD_SUIT::DIAMONDS:
						suitStr = "D";
						break;
					case CARD_SUIT::HEARTS:
						suitStr = "H";
						break;
					case CARD_SUIT::SPADES:
						suitStr = "S";
						break;
					default:
						break;
					}
					std::string shortHand{ rankStr + suitStr };
					std::cout << shortHand;
				}

				int getCardValue() const
				{
					switch (m_rank)
					{
					case CARD_RANK::TWO:
						return 2;
					case CARD_RANK::THREE:
						return 3;
					case CARD_RANK::FOUR:
						return 4;
					case CARD_RANK::FIVE:
						return 5;
					case CARD_RANK::SIX:
						return 6;
					case CARD_RANK::SEVEN:
						return 7;
					case CARD_RANK::EIGHT:
						return 8;
					case CARD_RANK::NINE:
						return 9;
					case CARD_RANK::TEN:
					case CARD_RANK::JACK:
					case CARD_RANK::QUEEN:
					case CARD_RANK::KING:
						return 10;
					case CARD_RANK::ACE:
						return 11;
						break;
					default:
						break;
					}
					return 0;
				}
			};
			
			class Deck
			{
				using cards = std::array<Card, 52>;
			private:
				cards m_deck;
				int m_cardIndex;
			public:
				Deck() : m_cardIndex{ 0 }
				{
					size_t numOfSuits{ static_cast<size_t>(CARD_SUIT::MAX_SUIT) };

					int cardNum{ 0 };

					for (int suitIndex{ 0 }; suitIndex < numOfSuits; ++suitIndex)
					{

						for (int rankIndex{ 0 }; rankIndex < static_cast<size_t>(CARD_RANK::MAX_RANK); ++rankIndex)
						{
							Card card{ static_cast<CARD_RANK>(rankIndex), static_cast<CARD_SUIT>(suitIndex) };
							m_deck[cardNum] = card;
							cardNum++;
						}
					}
				}
				void print()
				{
					for (const Card& card : m_deck)
					{
						card.printCard();
						std::cout << ' ';
					}
				}
				
				void shuffle()
				{
					static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
					std::shuffle(m_deck.begin(), m_deck.end(), mt);
					m_cardIndex = 0;
				}

				const Card& dealCard()
				{
					assert(m_cardIndex < m_deck.size());
					return m_deck[m_cardIndex++];
				}
			};

			class Player
			{
			private:
				int m_score;
			public:

				Player() : m_score{ 0 }
				{

				}

				void drawCard(Deck &deck)
				{
					m_score += deck.dealCard().getCardValue();
				}

				int getScore() const
				{
					return m_score;
				}

				bool isBust() const
				{
					return (m_score > maximumScore);
				}
			};

			Deck deck{};

			deck.shuffle();

			Player player{};
			player.drawCard(deck);
			player.drawCard(deck);
			bool playersTurn{ true };
			while (playersTurn)
			{
				if (player.isBust())
				{
					std::cout << "You went over " << maximumScore << ". Sorry, but you've lost\n";
					return;
				}
				std::cout << "You currently have: " << player.getScore() << " points. Draw another? [y/n]\n";
				char hit{};
				std::cin >> hit;
				if (hit == 'n')
				{
					playersTurn = false;
				}
				else
				{
					player.drawCard(deck);
				}
			}

			Player dealer{};
			while (dealer.getScore() <= dealerLimit)
			{
				if (dealer.isBust())
				{
					std::cout << "Dealer went over " << maximumScore << " You won.\n";
					return;
				}
				dealer.drawCard(deck);
			}

			if (dealer.getScore() > player.getScore())
			{
				std::cout << "Sorry you lost. ";
			}
			else
			{
				std::cout << "Congrats! You won!";
			}
			std::cout << " Dealer had " << dealer.getScore() << " and you had " << player.getScore() << '\n';


			break;
		}

		default:
			break;
		}
	}

}

//