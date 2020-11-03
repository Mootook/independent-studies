//
//  ChapterL.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/23/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterL.hpp"

#include <ctime>
#include <cstdlib>
#include <random>
#include <iostream>

#include "constants.h"

namespace chapterL
{
    void printNumberOfLegs(Animal animal)
    {
        switch (animal)
        {
            case Animal::ANIMAL_PIG:
                std::cout << "A " << chapterL::animalName(animal) << " has 4 legs" << '\n';
                break;
            case Animal::ANIMAL_CHICKEN:
                std::cout << "A " << chapterL::animalName(animal) << " has 2 legs" << '\n';
                break;
            case Animal::ANIMAL_GOAT:
                std::cout << "A " << chapterL::animalName(animal) << " has 4 legs" << '\n';
                break;
            case Animal::ANIMAL_CAT:
                std::cout << "A " << chapterL::animalName(animal) << " has 4 legs" << '\n';
                break;
            case Animal::ANIMAL_DOG:
                std::cout << "A " << chapterL::animalName(animal) << " has 4 legs" << '\n';
                break;
            case Animal::ANIMAL_OSTRICH:
                std::cout << "A " << chapterL::animalName(animal) << " has 2 legs" << '\n';
                break;
            default:
                std::cout << "Could not determine animal printNumberOfLegs()\n";
                break;
        }
    }
    std::string animalName(Animal animalType)
    {
        switch (animalType) {
            case Animal::ANIMAL_PIG:
                return std::string{"Pig"};
                break;
            case Animal::ANIMAL_CHICKEN:
                return std::string{"Chicken"};
            case Animal::ANIMAL_GOAT:
                return std::string{"Goat"};
            case Animal::ANIMAL_CAT:
                return std::string{"Cat"};
            case Animal::ANIMAL_DOG:
                return std::string{"Dog"};
            case Animal::ANIMAL_OSTRICH:
                return std::string{"Ostrich"};
            default:
                break;
        }
        return NULL;
    }

    void quiz(int section, int number)
    {
        if (section == 4)
        {
            // quiz 4.1 in chapter L
            if (number == 1)
            {
                int numOne{};
                std::cout << "Enter a number" << '\n';
                std::cin >> numOne;
                
                int numTwo{};
                std::cout << "Enter another number" << '\n';
                std::cin >> numTwo;
                
                char operation{};
                std::cout << "Enter a mathematical operator" << '\n';
                std::cin >> operation;
                
                int result{};
                switch (operation) {
                    case '+': {
                        result = numOne + numTwo;
                        break;
                    }
                    case '-': {
                        result = numOne - numTwo;
                        break;
                    }
                    case '*': {
                        result = numOne * numTwo;
                        break;
                    }
                    case '/': {
                        result = numOne / numTwo;
                        break;
                    }
                    case '%': {
                        result = numOne % numTwo;
                        break;
                    }
                    default:
                        std::cout << "Not a valid operation." << '\n';
                        std::exit(0);
                        break;
                }
                std::cout << numOne << " " << operation << " " << numTwo << " is " << result << '\n';
            }
            else if (number == 2)
            {
                Animal ostrich = Animal::ANIMAL_OSTRICH;
                printNumberOfLegs(ostrich);
            }
        }
    }
    void section(int section)
    {
        switch (section)
        {
            case 1:
            {
                std::cout << 1 << '\n';
                std::exit(0); // quits application immediately
                break;
            }
            case 4: {
                quiz(4, 2);
                break;
            }
            default:
                break;
        }
    }

    double getInitialHeight()
    {
        std::cout << "Enter the height of the tower in meters: ";
        double initialHeight{};
        std::cin >> initialHeight;
        return initialHeight;
    }

    double calculateHeight(double initialHeight, int secondsPassed)
    {
        // Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
        double distanceFallen{ (myConstants::gravity * secondsPassed * secondsPassed) / 2.0 };
        double currentHeight{  initialHeight - distanceFallen };
     
        return currentHeight;
    }
     
    // Prints height every second till ball has reached the ground
    void printHeight(double height, int secondsPassed)
    {
        if (height > 0.0)
        {
            std::cout << "At " << secondsPassed << " seconds, the ball is at height:\t" << height <<
                " meters\n";
        }
        else
            std::cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
    }
     
    void calculateAndPrintHeight(double initialHeight, int secondsPassed)
    {
        double height{ calculateHeight(initialHeight, secondsPassed) };
        printHeight(height, secondsPassed);
    }

    void onGameEnd(bool isCorrect, int randomNumber)
    {
        if (!isCorrect)
        {
            std::cout << "Sorry, you lose. The correct number was " << randomNumber << '\n';
        }
            
        
        char answer{};
        do {
            std::cout << "Would you like to play again (y/n)? ";
            if (answer == 'y')
            {
                chapterL::quiz(2);
            }
            else if (answer == 'n')
            {
                std::cout << "Thank you for playing." << '\n';
                return;
            }
            std::cin >> answer;
        } while (answer != 'y' && answer != 'n');
    }

    void quiz(int number)
    {
        switch (number)
        {
            case 1:
            {
                // CORRECT
                const double initialHeight{ getInitialHeight() };
                double height = initialHeight;
                int secondsPassed = 0;
                while (height > 0) {
                    calculateAndPrintHeight(height, secondsPassed);
                    height = calculateHeight(height, secondsPassed);
                    secondsPassed++;
                }
                break;
            }
            case 2:
            {
                // INCORRECT
                std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries "
                "to guess what it is.\n";
                
                // Initialize our mersenne twister with a random seed based on the clock
                std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
                std::uniform_int_distribution prng{ 1, 100 };
                int randomNumber = prng(mersenne);
                std::cout << "Random number " << randomNumber << '\n';
                int numberOfGuesses{ 1 };
                int guess{};
                bool isCorrect = { false };
                do {
                    std::cout << "Guess #" << numberOfGuesses << ": ";
                    std::cin >> guess;
                    if (guess == randomNumber)
                    {
                        std::cout << "That is correct\n";
                        isCorrect = true;
                        break;
                    }
                    else if (guess < randomNumber)
                    {
                        std::cout << "Your guess is too low.\n";
                    }
                    else if (guess > randomNumber)
                    {
                        std::cout << "Your guess is too high.\n";
                    }
                    numberOfGuesses++;
                } while (numberOfGuesses <= 7);
                onGameEnd(isCorrect, randomNumber);
            }
            default:
                break;
        }
    }
}
