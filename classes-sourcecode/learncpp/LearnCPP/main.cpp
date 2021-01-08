//
//  main.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 7/26/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//
/**
 *
 * Chapter 0 - Getting Started
 * Chapter 1 - C++ Basics
 *
 */
/**
 * Preprocessor directive
 * We use angle brackets to tell the preprocessor that this library
 * is included with the compiler
 */
#include <iostream>
/**
 * Preprocessor directive
 * Use double quotes to tell preprocessor this is a user-defined header
 */
#include "ChapterTwo.h"
#include "ChapterFour.h"
#include "ChapterFive.h"
#include "ChapterO.h"
#include "ChapterSix.h"
#include "ChapterS.hpp"
#include "ChapterL.hpp"
#include "ChapterP.hpp"
#include "ChapterF.h"
#include "ChapterEight.h"
#include "ChapterNine.h"
#include "ChapterTen.h"
#include "ChapterTwelve.h"
#include "ChapterThirteen.h"
#include "ChapterFourteen.h"
#include "ChapterFifteen.h"

void forwardDeclaration(); // function prototype "forward declaration"

void chapterZero()
{
    // insert code here...
    std::cout << "Hello, World!\n";
}


void chapterOne()
{
    // Chapter 1

    // Section 3
    // A named object is called a variable
    // The name of the object is called the identifier

    // Section 4
//     int width = 5; // copy initialization of value into variable width
//     int widthTwo( 5 ); // direct initialization of value 5 into variable width
//     int width { 5 }; // direct brace (uniform) initialization of value 5 into variable width (preffered initialization)
//     int width = { 6 }; // copy brace initialization of value 6 into variable height

    // Section 5
//     std::cout << "Enter a number: ";
//     int x{};
//     std::cin >> x;
//     std::cout << "You entered " << x << '\n';

    // Section 6
    // Initialization = The object is given a known value at the point of definition
    // Assigment = THe object is given a kown value beyond the point of definition
    // Uninitialized = THe object has not been given a known value yet

    // Section 10
//     std::cout << "Enter an integer: ";
//     int num{ 0 };
//     std::cin >> num;
//     std::cout << "Double that number is: " << num * 2 << '\n';
//     std::cout << "Triple " << num << " is " << num * 3 << '\n';


    // Quiz
//    std::cout << "Enter a number: ";
//    int firstNum{ 0 };
//    std::cin >> firstNum;
//    std::cout << "Enter a second number: ";
//    int secondNum{ 0 };
//    std::cin >> secondNum;
//    std::cout << firstNum << " + " << secondNum << " is " << firstNum + secondNum << '\n';
//    std::cout << firstNum << " - " << secondNum << " is " << firstNum - secondNum << '\n';
    
}

void chapterTwo()
{
    forwardDeclaration();
}

int main()
{
    chapterFifteen::section(6);
    return 0;
}


void forwardDeclaration()
{
    std::cout << "Nailed it\n";
}
