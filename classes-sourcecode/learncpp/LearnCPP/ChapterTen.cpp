#include "ChapterTen.h"
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <string>
#include <string_view>


namespace chapterTen
{

	int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}
	// Comprehensive Quiz 3
	class Creature
	{
	private:
		std::string m_name;
		char m_symbol;
		int m_health;
		int m_gold;
	protected:
		int m_attack;
	public:
		Creature(const std::string& name, char symbol, int health, int attack, int gold) :
			m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_attack{ attack }, m_gold{ gold }
		{
		}

		const std::string& getName() { return m_name; }

		char getSymbol() const { return m_symbol; }

		int getHealth() const { return m_health; }

		int getAttack() const { return m_attack; }

		int getGold() const { return m_gold; }

		void reduceHealth(int damage) { m_health -= damage; }

		bool isDead() const { return m_health <= 0; }

		void addGold(int gold) { m_gold += gold; }

	};

	class Player : public Creature
	{
	private:
		int m_level;
	public:
		Player(const std::string& name) : Creature{ name, '@', 10, 1, 0 }, m_level{ 1 }
		{
		}
		
		int getLevel() { return m_level; }

		void levelUp()
		{
			m_level++;
			m_attack++;
		}

		bool hasWon() const
		{
			return m_level >= 20;
		}
	};


	class Monster : public Creature
	{
	public:
		enum class Type
		{
			dragon,
			orc,
			slime,

			max_types
		};
		Monster(Type type) : Creature{ getDefaultCreature(type) }
		{
		}

		static Monster getRandomMonster()
		{
			int num{ getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
			return Monster{ static_cast<Type>(num) };
		}

	private:
		static const Creature& getDefaultCreature(Type type)
		{

			static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{

			   Creature("dragon", 'D', 20, 4, 100),
			   Creature("orc", 'o', 4, 2, 25),
			   Creature("slime", 's', 1, 1, 10)

			};
			return monsterData.at(static_cast<std::size_t>(type));
		}

	};

	bool userEncounter(Player& player, Monster& monster)
	{

		char choice;
		do
		{
			std::cout << "You encounted a " << monster.getName() << " (" << monster.getSymbol() << ") " << 
				"\n(R)un or (F)ight?";
			std::cin >> choice;
		} while (choice != 'r' && choice != 'f');
		
		if (choice == 'r')
		{
			int num{ getRandomNumber(0, 1) };
			if (num == 0)
			{
				std::cout << "You failed to flee.\n";
				// failed to run
				// monster attacks, still in encounter
				player.reduceHealth(monster.getAttack());
				return true;
			}
			else
			{
				std::cout << "You successfully fled.\n";
				// no longer in encounter
				return false;
				// success on run
			}
		}
		// Fight
		monster.reduceHealth(player.getAttack());
		std::cout << "You hit the monster for " << player.getAttack() << " damage\n";
		if (monster.isDead())
		{
			std::cout << "You killed the " << monster.getName() << '\n';
			player.addGold(monster.getGold());
			player.levelUp();
			// encounter over
			return false;
		}
		else
		{
			std::cout << "The " << monster.getName() << " hit you for " << monster.getAttack() << " damage.\n";
			player.reduceHealth(monster.getAttack());
			return true;
		}

	}


	bool startRound(Player& player)
	{
		Monster monster{ Monster::getRandomMonster() };
		while (true)
		{
			bool userIsInEncounter{ userEncounter(player, monster) };
			if (!userIsInEncounter)
			{
				return true;
			}
			if (player.isDead())
			{
				std::cout << "You've died at level " << player.getLevel() << " with " << player.getGold() << " gold!\n";
				return false;
			}
		}
	}

	std::string getUsername()
	{
		std::string name;
		std::cout << "Enter your name: ";
		std::cin >> name;
		return name;
	}

	void startGame()
	{
		std::string name{ getUsername() };
		Player player{ name };
		std::cout << "Welcome " << player.getName() << ".\nYou have " << player.getHealth() << " health and are carrying " <<
			player.getGold() << " gold\n.";
		std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
		std::rand(); // get rid of first result
		while (true)
		{
			bool userWon{ startRound(player) };
			if (!userWon || player.isDead())
			{
				// fail
				std::cout << "You Lost\n";
				return;
			}
			else if (player.hasWon())
			{
				std::cout << "Congratulations\n";
			}
		}
	}

	void section(int section)
	{
		switch (section)
		{
		case 4:
		{
			// Quiz
			// 1. Let’s implement our Fruit example 
			// that we talked about in our introduction to inheritance. 
			// Create a Fruit base class that contains two private 
			// members: a name (std::string), 
			// and a color (std::string). Create 
			// an Apple class that inherits Fruit. Apple should have 
			// an additional private member: fiber (double). 
			// Create a Banana class that also inherits Fruit. Banana has no additional members.
			// quiz 11.4
			class Fruit
			{
			private:
				std::string m_name;
				std::string m_color;
			};

			class Apple : public Fruit
			{
			private:
				double m_fiber;
			};

			class Banana : public Fruit
			{
			};
			// correct -- incomplete...needed to write operator overloaders to std::cout the classes variables
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
			// For each of the following programs, determine 
			// what they output, or if they would not 
			//compile, indicate why. This exercise is meant 
			// to be done by inspection, so do not 
			// compile these (otherwise the answers are trivial).


			// a
			/*
			
			class Base
			{
			public:
				Base()
				{
					std::cout << "Base()\n";
				}
				~Base()
				{
					std::cout << "~Base()\n";
				}
			};
			 
			class Derived: public Base
			{
			public:
				Derived()
				{
					std::cout << "Derived()\n";
				}
				~Derived()
				{
					std::cout << "~Derived()\n";
				}
			};
			 
			int main()
			{
				Derived d{};
			 
				return 0;
			}
			*/

			// Base()
			// Derived()
			// ~Derived()
			// ~Base()

			// Correct

			// b.
			/*

			class Base
			{
			public:
				Base()
				{
					std::cout << "Base()\n";
				}
				~Base()
				{
					std::cout << "~Base()\n";
				}
			};

			class Derived: public Base
			{
			public:
				Derived()
				{
					std::cout << "Derived()\n";
				}
				~Derived()
				{
					std::cout << "~Derived()\n";
				}
			};

			int main()
			{
				Derived d;
				Base b;

				return 0;
			}

			*/

			// Base()
			// Dervived()
			// Base()
			// ~Derived()
			// ~Base()
			// ~Base()

			// Incorrect
			// Base()
			// Derived()
			// Base()
			// ~Base()
			// ~Derived()
			// ~Base()

			// c.
			/*
			class Base
			{
			private:
				int m_x;
			public:
				Base(int x): m_x{ x }
				{
					std::cout << "Base()\n";
				}
				~Base()
				{
					std::cout << "~Base()\n";
				}
			 
				void print() const { std::cout << "Base: " << m_x << '\n';  }
			};
			 
			class Derived: public Base
			{
			public:
				Derived(int y):  Base{ y }
				{
					std::cout << "Derived()\n";
				}
				~Derived()
				{
					std::cout << "~Derived()\n";
				}
			 
				void print() const { std::cout << "Derived: " << m_x << '\n'; }
			};
			 
			int main()
			{
				Derived d{ 5 };
				d.print();
			 
				return 0;
			}
			
			*/

			// Base()
			// Derived()
			// Derived 5
			// ~Derived()
			
			// Incorrect: print() can't access private member m_x

			// d.
			/*
			class Base
			{
			protected:
				int m_x;
			public:
				Base(int x): m_x{ x }
				{
					std::cout << "Base()\n";
				}
				~Base()
				{
					std::cout << "~Base()\n";
				}
			 
				void print() const { std::cout << "Base: " << m_x << '\n';  }
			};
			 
			class Derived: public Base
			{
			public:
				Derived(int y):  Base{ y }
				{
					std::cout << "Derived()\n";
				}
				~Derived()
				{
					std::cout << "~Derived()\n";
				}
			 
				void print() const { std::cout << "Derived: " << m_x << '\n'; }
			};
			 
			int main()
			{
				Derived d{ 5 };
				d.print();
			 
				return 0;
			}
			*/

			// Base()
			// Derived()
			// Derived 5
			// ~Derived()
			// ~Base()

			// Correct

			// e
			/*
			class Base
			{
			protected:
				int m_x;
			public:
				Base(int x): m_x{ x }
				{
					std::cout << "Base()\n";
				}
				~Base()
				{
					std::cout << "~Base()\n";
				}
			 
				void print() const { std::cout << "Base: " << m_x << '\n';  }
			};
			 
			class Derived: public Base
			{
			public:
				Derived(int y):  Base{ y }
				{
					std::cout << "Derived()\n";
				}
				~Derived()
				{
					std::cout << "~Derived()\n";
				}
			 
				void print() { std::cout << "Derived: " << m_x << '\n'; }
			};
			 
			class D2 : public Derived
			{
			public:
				D2(int z): Derived{ z }
				{
					std::cout << "D2()\n";
				}
				~D2()
				{
					std::cout << "~D2()\n";
				}
			 
					// note: no print() function here
			};
			 
			int main()
			{
				D2 d{ 5 };
				d.print();
			 
				return 0;
			}	
			
			*/
			// Base()
			// Derived()
			// Derived: 5
			// ~Derived()
			// ~Base()

			// Incorrect: Forgot D2()
			
			break;
		}
		case 2:
		{
			// a. Write an Apple class and a Banana class that are derived
			// from a common Fruit class. Fruit should have two members: a name, and a color.

			class Fruit
			{
			protected:
				std::string m_name;
				std::string m_color;
			public:
				Fruit(const std::string &name, const std::string &color) : m_name{ name }, m_color{ color }
				{
				}

				std::string getName()
				{
					return m_name;
				}

				std::string getColor()
				{
					return m_color;
				}
			};

			class Apple : public Fruit
			{
			public:
				Apple(const std::string& color) : Fruit{ "apple", color }
				{
				}
			};

			class Banana : public Fruit
			{
			public:
				Banana(const std::string& color) : Fruit{ "banana", color }
				{
				}
			};
		

			// correct : con't forget const refs on the getName and getColor, also Fruit member variabels should be private

			// b. Add a new class to the previous program called GrannySmith that inherits from Apple.

			class GrannySmith : public Apple
			{
			public:
				GrannySmith(const std::string& color = "red") : Apple{ color }
				{
				}
			};

			// partial: need to update Apple constructor to take in name parameter, Granny should default to "granny smith"
			// in its own constructor

			break;
		}
		case 3:
		{
			/*
			Challenge time! The following quiz question is more difficult and
			lengthy. We're going to write a 
			simple game where you fight monsters. The goal of 
			the game is to collect as much gold as you can before you die or get to level 20.
			Our program is going to consist of 3 classes :
			A Creature class, a Player class, and 
			a Monster class. Player and Monster both inherit 
			from Creature.

			a) First create the Creature class. Creatures have 5 
			attributes: A name (std::string), 
			a symbol (a char), an amount of 
			health (int), the amount of damage they 
			do per attack (int), and the amount 
			of gold they are carrying (int). Implement 
			these as class members. Write a full set 
			of getters (a get function for each member). 
			Add three other functions: void reduceHealth(int) 
			reduces the Creature's health by 
			an integer amount. bool isDead() returns true 
			when the Creature's health is 0 or 
			less. void addGold(int) adds gold to the Creature.
			*/
			
			// correct

			/*
			b) Now we're going to create the Player class. 
			The Player class inherits from Creature. Player has one 
			additional member, the player's level, which starts at 1. 
			The player has a custom name (entered by the user), uses symbol 
			'@', has 10 health, does 1 damage to start, and has no 
			gold. Write a function called levelUp() that increases the player's 
			level and damage by 1. Also write a getter for the level member
			. Finally, write a function called hasWon() that returns true if the 
			player has reached level 20.
			Write a new main() function that asks the user for their name 	
			*/

			// correct
			

			/*
			c. Next up is the Monster class. Monster also inherits from Creature. 
			Monsters have no non-inherited member variables.

			First, write an empty Monster class inheriting from Creature, and then add 
			an enum inside the Monster class named Type that contains enumerators for the 3 
			monsters that we'll have in this game: DRAGON, ORC, 
			and SLIME (you'll also want a max_types enumerator, as that 
			will come in handy in a bit).
			*/

			// correct

			/*
			d. Each Monster type will have a different name, symbol, starting health, 
			gold, and damage. Here is a table of stats for each monster Type:

			Type	Name	Symbol	Health	Damage	Gold
			dragon	dragon	D		20		4		100
			orc		orc		o		4		2		25
			slime	slime	s		1		1		10

			Next step is to write a Monster constructor, so we can create monsters. 
			The Monster constructor should take a Type enum as a parameter, and then 
			create a Monster with the appropriate stats for that kind of monster.

			There are a number of different ways to implement this (some better, some worse). 
			However in this case, because all of our monster attributes are predefined
			(not random), we'll use a lookup table. A lookup 
			table is an array that holds all of the predefined attributes. We can 
			use the lookup table to look up the attributes for a given monster as needed.

			So how do we implement this lookup table? It's not hard. 
			We just need an array that contains an element for each monster Type. 
			Each array element will contain a Creature that contains all of the predefined attribute 
			values for that Type of Monster. We place this array inside of a 
			static member function of Monster so that we can get a default Creature for a given Monster::Type.
			*/
			// correct

			/*
			e) Finally, add a static function to Monster named getRandomMonster().
			This function should pick a random number from 0 to max_types-1 and return a monster
			(by value) with that Type (you'll need to static_cast the int to a
			Type to pass it to the Monster constructor).
			*/

			// incorrect: faile random number generation...correct code copied over

			
			/*
			
			f) We're finally set to write our game logic!

			Here are the rules for the game:

			The player encounters one randomly generated monster at a time.
			For each monster, the player has two choices: (R)un or (F)ight.
			If the player decides to Run, they have a 50% chance of escaping.
			If the player escapes, they move to the next encounter with no ill effects.
			If the player does not escape, the monster gets a free attack, and the player chooses their next action.
			If the player chooses to fight, the player attacks first. The monster's health is reduced by the player's damage.
			If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
			If the monster does not die, the monster attacks the player back. The player's health is reduced by the monster's damage.
			The game ends when the player has died (loss) or reached level 20 (win)
			If the player dies, the game should tell the player what level they were and how much gold they had.
			If the player wins, the game should tell the player they won, and how much gold they had
			
			*/


			startGame();
			break;
		}
		default:
			break;
		}
	}
}