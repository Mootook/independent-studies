//
//  ChapterP.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/28/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterP.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string_view>
#include <cstddef>
#include <array>
#include <vector>
#include <numeric>
#include <random>
#include <ctime>

namespace chapterP
{
    int* find(int* beginning, int* end, int valueToFind)
    {
        for (int *ptr { beginning }; ptr != end; ptr++)
        {
            
            if (*ptr == valueToFind)
            {
                std::cout << ptr << " is the matching pointer." << '\n';
                return ptr;
            }
        }
        return end;
    }

    void section(int section)
    {
        switch (section)
        {
            case 1:
            {
                int prime[5]{}; // init array of size 5 with integers
                prime[0] = 2;
                prime[1] = 3;
                prime[2] = 5;
                prime[3] = 7;
                prime[4] = 11;
                std::cout << "Array start with " << prime[0] << '\n';
                
                
                // Arrays can hold structs
                struct Rectangle
                {
                    int length{};
                    int width{};
                };
                Rectangle rects[5]{};
                rects[0].length = 24;
                
                
                // Fixed arrays must be compile-time constant
                // Following chunk will not compile as length
                // is not a compile-time constant
                /*
                 int length{};
                 std::cin >> length;
                 int array[length];
                 */
            
                
                break;
            }
            case 2:
            {
                int prime[5]{2, 3, 5, 7, 11};
                std::cout << prime[0];
                
                int arr[]{ 0, 1, 2, 3, 4, 5 };
                std::cout << "Compiler infers array size "<< arr[0] << '\n';
                enum StudentNames
                {
                    kenny, // 0
                    kyle, // 1
                    stan, // 2
                    butters, // 3
                    cartman, // 4
                    wendy, // 5
                    max_students // 6
                };

                
                int testScores[static_cast<int>(StudentNames::max_students)]{};
                testScores[static_cast<int>(StudentNames::kenny)] = 76;
                
                std::cout << "Test score has " <<  static_cast<int>(StudentNames::max_students)
                << " elements\n";
                
                
                // Quiz 1
                int daysInYear = { 365 };
                int highTemperatures[365]{ };
                
                std::cout << "Days in a year " << daysInYear << " each value is "
                "initialized at zero: " << highTemperatures[0] << '\n';
                
                // Quiz 2
                enum class Animal
                {
                    chicken,
                    dog,
                    cat,
                    elephant,
                    duck,
                    snake,
                    max_animals
                };
                int numberOfLegsPerAnimals[static_cast<int>(Animal::max_animals)];
                numberOfLegsPerAnimals[static_cast<int>(Animal::chicken)] = 2;
                numberOfLegsPerAnimals[static_cast<int>(Animal::elephant)] = 4;
                
                std::cout << "The Elephant has " << numberOfLegsPerAnimals[static_cast<int>(Animal::elephant)] << " legs\n";
                
                std::cout << "There are " << std::size(numberOfLegsPerAnimals) << " animals\n";
                break;
            }
            case 3:
            {
                // Quiz 1 and 2
                
                constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

                int userIntChoice{};
                do
                {
                    std::cout << "Pick a number between 1 and 9\n";
                    std::cin >> userIntChoice;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, 'n');
                    }
                    
                } while (userIntChoice < 1 || userIntChoice >> 9);
                
                
                for (int i{ 0 }; i < std::size(array); i++)
                {
                    std::cout << "Array of " << i << " is " << array[i] << '\n';
                    int currentVal = array[i];
                    if (currentVal == userIntChoice)
                    {
                        std::cout << "Your choice is at index " << i << '\n';
                    }
                }
                
                // Quiz 3
                constexpr int scores[]{ 84, 92, 76, 81, 56 };
                constexpr int numStudents{ static_cast<int>(std::size(scores)) };
                
                int indexOfMaxScore{ 0 };
                int maxScore{ 0 };
                for (int student{ 0 }; student < numStudents; student++)
                {
                    if (scores[student] > maxScore)
                    {
                        maxScore = scores[student];
                        indexOfMaxScore = student;
                    }
                    
                    // alternative
                    /*
                     if (scores[student] > scores[maxIndex])
                     {
                        maxIndex = student;
                     }
                     */
                }
                std::cout << " Index of highest score is " << indexOfMaxScore << '\n';
                break;
            }
            case 4:
            {
                // Quiz 3
                int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
                std::cout << "Initial Array: \n";
                for (int i{ 0 }; i < std::size(array); i++)
                {
                    std::cout << array[i] << ' ';
                }
                
                for (int i{ 0 }; i < std::size(array) - 1; i++)
                {
                    for (int currentIndex{ 0 }; currentIndex < std::size(array) - 1; ++currentIndex)
                    {
                        if (array[currentIndex] > array[currentIndex + 1])
                        {
                            std::swap(array[currentIndex], array[currentIndex+1]);
                        }
                    }
                }
                
                std::cout << "Sorted: " << '\n';
                for (int i{ 0 }; i < std::size(array); i++)
                {
                    std::cout << array[i] << ' ';
                }
                break;
            }
            case 5:
            {
                // Multidimensional array
                int array[3][5];
                array[2][3] = 7;
                // Two dimensional arrays are commonly used in tile-based games,
                // where each array element represents one tile.
                // They’re also used in 3d computer graphics (as matrices)
                // in order to rotate, scale, and reflect shapes.
                break;
            }
            case 6:
            {
                char myString[]{ "string" };
                const int length{ static_cast<int>(std::size(myString)) };
                std::cout << myString << " has " << length << " characters.\n";
                // 7 characters, trailing \0, (null terminator)
                for (int i{ 0 }; i < length; ++i)
                {
                    std::cout << static_cast<int>(myString[i]) << ' ';
                }
                std::cout << '\n';
                
                
                std::string_view text{ "hello" };
                std::string_view str{ text };
                std::string_view mor{ str };
                
                
                std::cout << text << ' ' << str << ' ' << mor << '\n';
                break;
            }
            case 7:
            {
                int x{ 5 };
                std::cout << x << '\n';
                std::cout << &x << '\n'; // memory address for x
                std::cout << *(&x) << '\n'; // get value at the memory address of x
                
                
                int *iPtr{};
                std::cout << iPtr << " is a pointer to an integer value" << '\n';
                
                
                // int v{ 5 };
                // int *vPtr{ &v };
                
                // Quiz 1
                
                // 0012FF60
                // 7
                // 0012FF60
                // 7
                
                // 0012FF60
                // 9
                // 0012FF60
                // 9
                
                // 0012FF54
                // 3
                // 0012FF54
                // 3
                
                
                // 7A
                float *nPtr { 0 };
                std::cout << &nPtr << " is a null pointer" << '\n';
                
                // int nullPointer *x { nullptr };
                // nullptr is a keyword that implicitly converts null pointer
                // to assigned data type
                
                break;
            }
            case 8:
            {
                // Quiz 1
                int arr[]{ 1, 2, 3 };
                std::cout << 2[arr] << '\n';
                // This works because of the operator [] is an addition and indeirectin
                // equivalent to
                // *(arr + 2)
                // *(2 + arr)
                // arr[2]
                
                // Quiz 2
                int quizArr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
                int *found{ chapterP::find(std::begin(quizArr), std::end(quizArr), 20) };
                
                // If an element with value 20 was found, print it.
                if (found != std::end(quizArr))
                {
                   std::cout << *found << '\n';
                }
                break;
            }
            case 9:
            {
                // Quiz 1
                std::cout << "How many names do you want to enter?\n";
                std::size_t size{};
                std::cin >> size;
                
                std::string* names{ new std::string[size]{} };
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                
                for (std::size_t i{ 0 }; i < size; ++i)
                {
                    std::cout << "Enter name #" << i+1 << ": ";
                    std::getline(std::cin, names[i]);
                }
                
                std::sort(names, names + size);
                
                for (std::size_t i{ 0 }; i < size; ++i)
                {
                    std::cout << "Name #" << i+1 << ": " << names[i] << '\n';
                }
                break;
            }
            case 10:
            {
                int value = 5;
                const int *ptr = &value;
                value = 6;
                
                std::cout << "Value is " << value << ". \n &value is " << *ptr << '\n';
                break;
            }
            case 11:
            {
                // Which should be passed by value
                // and which by const reference
                // assume function doesn't modify

                // char - value
                // std::string - reference
                // unsinged long - value
                // bool - value
                // enum - value
                // struct - reference
                // struct - reference
                // double - value
                // struct - reference
                
                // yay all correct
                // fundamental data types pass by value
                // custom objects/complex data types by reference
                break;
            }
            case 12:
            {
                
                // Quiz 1
                std::string names[] { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
                std::cout << "Enter a name: ";
                std::string name{};
                std::getline(std::cin, name);
                
                for (std::string &n: names)
                {
                    if (name.compare(n) == 0)
                    {
                        std::cout << n << " was found.\n";
                        return;
                    }
                }
                std::cout << name << " was not found.\n";
                break;
            }
            case 13:
            {
                // quiz 1
                
                /*
                 The difference between a void pointer and a null pointer is
                 that a void pointer can point to any data type and a null pointer
                 points to nothing.
                 */
                break;
            }
            case 15:
            {
                
                std::array<int, 5> myArray = { 1, 2 };
                std::cout << myArray[0] << " is the first element in my std::array\n";
                
                
                std::array inferedArray { 1, 2, 3 };
                inferedArray[0] = 1;
                std::cout << "Infered Array is deduced to std::array<int, 3>\n";
                
                break;
            }
            case 16:
            {
                // no need to specify length on initialization
                std::vector<int> vectorArr = { 0, 1};
                std::cout << vectorArr[0] << '\n';
                break;
            }
            default:
                break;
        }
    }

    int countTotalItems(const std::array<int, 3> arr)
    {
        return std::reduce(arr.begin(), arr.end());
    }

    void questionOne()
    {
        
        /*
         Pretend you’re writing a game where the player can hold 3 types of items: health
         potions, torches, and arrows. Create an enum to identify the different types of items,
         and an std::array to store the number of each item the player is carrying (The
         enumerators are used as indexes of the array). The player should start with 2 health
         potions, 5 torches, and 10 arrows. Write a function called countTotalItems() that
         returns how many items the player has in total. Have your main() function print the
         output of countTotalItems() as well as the number of torches.
         */
        
        /* Correct -- use enum rather than enum class to avoid the need for static cast
         define it globally and then define
         using inventory_type = stdLLarray<int, ItemTypes::ITEM_COUNT>;
         so that countTotalItems can read off of it for array argument size,
         int countTotalItems(const inventory_type& items) alias
        */
        enum class ITEM
        {
            HEALTH_POTION,
            TORCH,
            ARROW,
            ITEM_COUNT
        };
        constexpr int itemCount = static_cast<int>(ITEM::ITEM_COUNT);
        
        constexpr int numberOfPotions{ 2 };
        constexpr int numberOfTorches{ 5 };
        constexpr int numberOfArrows{ 10 };
        
        std::array<int, itemCount> items{};
        
        items[static_cast<int>(ITEM::HEALTH_POTION)] = numberOfPotions;
        items[static_cast<int>(ITEM::TORCH)] = numberOfTorches;
        items[static_cast<int>(ITEM::ARROW)] = numberOfArrows;
        
        int totalItemCount = countTotalItems(items);
        std::cout << "Player has a total of " << totalItemCount << " items\n"
        "And " << numberOfTorches << " torches.\n";
    }

    struct Student
    {
        std::string name;
        int grade;
    };

    bool gradeSorter(Student const& studentOne, Student const& studentTwo)
    {
        return studentOne.grade > studentTwo.grade;
    }

    void questionTwo()
    {
        /*
         Write the following program: Create a struct that holds a student’s first name and grade
         (on a scale of 0-100). Ask the user how many students they want to enter.
         Create a std::vector to hold all of the students. Then prompt the user for each name
         and grade. Once the user has entered all the names and grade pairs, sort the list
         by grade (highest first). Then print all the names and grades in sorted order.
         */
        
        /* Correct -- static_cast<vector_type::size_type> for Student vector size initializer
         */
        
        
        int numberOfStudents{};
        std::cout << "How many students would you like to record grades for?\n";
        std::cin >> numberOfStudents;
        std::vector<Student> students(numberOfStudents);
        
        for (int index = 0; index < numberOfStudents; ++index)
        {
            Student student{};
            std::cout << "What is student #" << index+1 << "'s name? ";
            std::cin >> student.name;
            
            std::cout << "And their grade? ";
            std::cin >> student.grade;
            
            students[index] = student;
        }
        std::sort(students.begin(), students.end(), &gradeSorter);
        std::cout << "\n\n";
        for (Student &student: students)
        {
            std::cout << student.name << " has a grade of " << student.grade << '\n';
        }
    }

    void swap(int& a, int&b)
    {
        int c{ a };
        a = b;
        b = c;
    }

    void questionThree()
    {
        /*
         Write your own function to swap the value of two integer variables.
         Write a main() function to test it.
         */
        // Correct
        int a{ 1 };
        int b{ 2 };
        
        std::cout << "Before swap, a is " << a << " and b is " << b << '\n';
    
        swap(a, b);
    
        std::cout << "After swap, a is " << a << " and b is " << b << '\n';
    }

    void printEachCharacter(const char* str)
    {
        // CORRECT ANSWER BELOW
        while (*str != '\0')
        {
            std::cout << *str;
            
            ++str;
        }
    }

    void questionFour()
    {
        
        /*
         Write a function to print a C-style string character by character.
         Use a pointer to step through each character of the string and print
         that character. Stop when you hit the null terminator. Write a main
         function that tests the function with the string literal “Hello, world!”.
         */
        // INCORRECT:
        const char* stringToPrint{ "Hello, world!" };
        printEachCharacter(stringToPrint);
        std::cout << '\n';
        
    }

    void questionFive()
    {
        /** What’s wrong with each of these snippets, and how would you fix it? */
        /* a).
         {
           int array[]{ 0, 1, 2, 3 };
          
           for (std::size_t count{ 0 }; count <= std::size(array); ++count)
           {
             std::cout << array[count] << ' ';
           }
          
           std::cout << '\n';
          
           return 0;
         }
         
         -- make count comparison just < std::size(array) rather than <=
         to prevent indexing outside of array
         
         CORRECT
         */
        
        /* b).
         {
           int x{ 5 };
           int y{ 7 };
          
           const int* ptr{ &x };
           std::cout << *ptr << '\n';
           *ptr = 6;
           std::cout << *ptr << '\n';
           ptr = &y;
           std::cout << *ptr << '\n';
         }
         
         -- *ptr = 6 is invalid since it's initialized as a pointer to a constant
         value
         
         CORRECT
         */
        
        
        /* c).
         void printArray(int array[])
         {
           for (int element : array)
           {
             std::cout << element << ' ';
           }
         }
          
         int main()
         {
           int array[]{ 9, 7, 5, 3, 1 };
          
           printArray(array);
          
           std::cout << '\n';
          
           return 0;
         }
         
         -- pass array as reference, printArray(int (&array)[])
         
         
         -- INCORRECT:
         Array will decay to pointer in printArray (thus loops won't work since pointers
         aren't aware of length). use std::array instead
         */
        
        /* d).
         int* allocateArray(const int length)
         {
           int temp[length]{};
           return temp;
         }
         
         -- return value is returning array, while function type is returning
         pointer
         
         -- INCORRECT(ISH):
         temp is a fixed array and thus needs a compile time constant (length in the arguments
         is not one). Temp will go out of scope once function ends and the return pointer
         will be dangling. Should be a std::vector or use dynamic memory allocation
         */
        
        /* e.
         int main()
         {
           double d{ 5.5 };
           int* ptr{ &d };
           std::cout << ptr << '\n';
          
           return 0;
         }
         
         -- *ptr must point to a type of int, either cast to an int or use double *ptr
         
         -- CORRECT
         */
        std::cout << "SEE COMMENTS\n";
    }

    // QUIZ 6
    /* a.
     A deck of cards has 52 unique cards (13 card ranks of 4 suits).
     Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace)
     and suits (clubs, diamonds, hearts, spades).
     Those enumerators will not be used to index arrays.
     */
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
    // CORRECT: Though better practice to prefex enum on each, i.e. TWO => CARD_RANK_2 or
    // CARD_RANK_TWO

    /* b.
     Each card will be represented by a struct named Card that contains a rank and a suit.
     Create the struct.
     */
    struct Card
    {
        CARD_RANK rank{};
        CARD_SUIT suit{};
    };
    // CORRECT

    void printCard(const Card &card)
    {
        std::string rankStr{};
        switch (card.rank) {
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
        switch (card.suit) {
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

    std::array<Card, 52> createDeck()
    {
        std::array<Card, 52>deck{};
        
        size_t numOfSuits{ static_cast<size_t>(CARD_SUIT::MAX_SUIT) };
        
        int cardNum{ 0 };
        
        for (int suitIndex{ 0 }; suitIndex < numOfSuits; ++suitIndex)
        {
            
            for (int rankIndex{ 0 }; rankIndex < static_cast<size_t>(CARD_RANK::MAX_RANK); ++rankIndex)
            {
                Card card{ static_cast<CARD_RANK>(rankIndex), static_cast<CARD_SUIT>(suitIndex) };
                deck[cardNum] = card;
                cardNum++;
            }
        }
        
        return deck;
    }

    void printDeck(const std::array<Card, 52>& deck)
    {
        for (const Card& card: deck)
        {
            printCard(card);
            std::cout << ' ';
        }
    }

    void shuffleDeck(std::array<Card, 52>& deck)
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(deck.begin(), deck.end(), mt);
    }

    int getCardValue(Card &card)
    {
        switch (card.rank)
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

    void questionSix()
    {
        
        /* c.
         Create a printCard() function that takes a const Card reference as a parameter
         and prints the card rank and suit as a 2-letter code
         (e.g. the jack of spades would print as JS).
         
         CORRECT
         */
        
        /* d).
         A deck of cards has 52 cards. Create an array (using std::array) to represent
         the deck of cards, and initialize it with one of each card. Do this in a
         function named createDeck and call createDeck from main. createDeck should return
         the deck to main.
         */
        std::array<Card, 52>deck{ createDeck() };
        
        // CORRECT
        
        /* e).
         Write a function named printDeck() that takes the deck as a const reference
         parameter and prints the cards in the deck. Use a range-based for-loop.
         */
        
        
        
        
        // CORRECT
        
        /* f).
         Write a function named shuffleDeck to shuffle the deck of cards
         using std::shuffle. Update your main function to shuffle the deck and
         print out the shuffled deck.
         */
        shuffleDeck(deck);
        
        // INCORRECT
        
        /* g).
         Write a function named getCardValue() that returns the value of a
         Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10.
         Assume an Ace is worth 11).
         */
        // CORRECT
        printDeck(deck);
    }

    bool playBlackjack(std::array<Card, 52> &shuffledDeck)
    {
        constexpr int maxCardValue{ 21 };
        bool playerHasUsedTurn{ false };
        std::vector<Card> playerCards
        {
            shuffledDeck[0],
            shuffledDeck[1]
        };
        
        int lastUsedCardIndex{ 1 };
        int playerScore{};
        while (!playerHasUsedTurn)
        {
            ++lastUsedCardIndex;
            std::cout << "You currently have: \n";
            int accumCardValue{ 0 };
            for (Card card : playerCards)
            {
                printCard(card);
                std::cout << ", ";
                accumCardValue += getCardValue(card);
            }
            playerScore = accumCardValue;
            std::cout << " for a total of " << accumCardValue << '\n';
            if (accumCardValue > maxCardValue)
            {
                std::cout << "Looks like you went over 21. Dealer wins.\n";
                return false;
            }
        
            
            std::cout << "Would you like to hit? y/n : ";
            char hit{};
            std::cin >> hit;
            if (hit == 'y')
            {
                playerCards.push_back(shuffledDeck[lastUsedCardIndex]);
            }
            else
            {
                playerHasUsedTurn = true;
            }
        }
        
        constexpr int dealerLimit{ 17 };
        int dealerScore{ 0 };
        bool dealerHasFinished{ false };
        std::vector<Card>dealerCards{};
        while (!dealerHasFinished)
        {
            if (dealerScore >= dealerLimit)
            {
                if (dealerScore > maxCardValue)
                {
                    return true;
                }
                dealerHasFinished = true;
                break;
            }
            dealerCards.push_back(shuffledDeck[lastUsedCardIndex]);
            int accum{ 0 };
            for (Card card : dealerCards)
            {
                accum += getCardValue(card);
            }
            dealerScore = accum;
            ++lastUsedCardIndex;
        }
        std::cout << "Dealer's score " << dealerScore << '\n';
        return playerScore > dealerScore;
    }

    void questionSeven()
    {
        std::array<Card, 52>deck{ createDeck() };
        shuffleDeck(deck);
        bool userWon{ playBlackjack(deck) };
        if (userWon)
        {
            std::cout << "Congrats! You won.\n"
            "\n============================\n";
        }
        else
        {
            std::cout << "Sorry, you lost.\n"
            "\n============================\n";
        }
        std::cout << "\nPlayer again? y/n : ";
        char playAgain{};
        std::cin >> playAgain;
        if (playAgain == 'y')
        {
            questionSeven();
        }
        else
        {
            std::cout << "Goodbye.\n";
        }
        
        
    }


    void quiz(int section)
    {
        switch (section)
        {
            case 1:
                questionOne();
                break;
            case 2:
                questionTwo();
                break;
            case 3:
                questionThree();
                break;
            case 4:
                questionFour();
                break;
            case 5:
                questionFive();
                break;
            case 6:
                questionSix();
                break;
            case 7:
                questionSeven();
                break;
            default:
                break;
        }
    }
}

