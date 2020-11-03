//
//  ChapterFour.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 8/19/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterFour.h"
#include <iostream>

void sectionOne()
{
    std::cout << "Section One Chapter Four" << std::endl;
    // _t suffix means "type"
    // non-consistent
}

void sectionTwo()
{
    
}

void sectionThree()
{
    // Objects of fundamental data types are generally extremely fast.
    // sizeof operator is a unary operator that returns byte size of input
    
    std::string suffix = {" bytes \n"};
    
    std::cout << "Data Type Sizes:\n";
    std::cout << "bool:\t\t" << sizeof(bool) << suffix;
    std::cout << "char:\t\t" << sizeof(char) << suffix;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << suffix;
    std::cout << "char16_t:\t" << sizeof(char16_t) << suffix;
    std::cout << "char32_t:\t" << sizeof(char32_t) << suffix;
    std::cout << "short:\t\t" << sizeof(short) << suffix;
    std::cout << "int:\t\t" << sizeof(int) << suffix;
    std::cout << "long:\t\t" << sizeof(long) << suffix;
    std::cout << "long long:\t" << sizeof(long long) << suffix;
    std::cout << "float:\t\t" << sizeof(float) << suffix;
    std::cout << "double:\t\t" << sizeof(double) << suffix;
    std::cout << "long double:\t" <<sizeof(long double) << suffix;
}


void sectionFour()
{
    // integers are signed by default
    // integer overflow is when you assign a value larger than the range alloted for that data type
    
}

void sectionFive()
{
    
    unsigned int unsignedInteger;
    unsignedInteger = {1};
    
    std::cout << "1 byte unsigned has a range of 0 to 255\n";
    std::cout << "2 byte unsigned has a range of 0 to 65,535\n";
    std::cout << "4 byte unsigned has a range of 0 to 4,294,967,295\n";
    std::cout << "8 byte unsigned has a range of 0 to 18,446,744,073,709,551,615\n";
    
    // Unsigned integer overflow
    // If a value is out of range, it is divided by one greater than the largest of the type remainder is kept
    
    // 280 into 1 byte => (0 to 255), 280 / 256 => 1 remainder 24, 24 is stored.
    
}

void sectionSix()
{
    // Fixed-width integers are guaranteed to have the same range across platforms/compilers
    // std::int8_t, -128 - 127
    // std::uint8_t, 0 - 255
    // std::int16_t ...
    // Generally to be avoided
    
    
    // also _fast and _least, #include <cstdint>
    
    std::cout << "std::int_fast32_t gives the fastest signed integer type that is at least 32 bits\n";
    std::cout << "std::int_least32_t gives the smallest signed integer with at least 32 bits\n";
    
    // ^ are used since some computers will process some data byte sizes faster than others, even if they are bigger
    
}

void sectionEight()
{
//    double y{5.0};  floating point literal, no suffix means double type
//    float z{5.0f}; floating point literal, f suffix means float type
}

void sectionTwelve()
{
    int bin{};
    bin = 0b1;  // assign binary 0000 0001 to the variable
    bin = 0b11; // assign binary 0000 0011 to the variable
    bin = 0b1010; // assign binary 0000 1010 to the variable
    bin = 0b11110000; // assign binary 1111 0000 to the variable
    
    // int maxStudents{ numClassrooms * 30 }, 30 is considered a 'magic number', no context...bad practice
}

void sectionThirteen()
{
    // const double gravity { 9 }; use of const before type
    
    // constexpr double gravity { 9.8 } ensures constant must be compile-time constant
    // constants that are assigned (by user input for example) are run-time constants
    // inline constexpr is used in C++17 or newer
    
}

void chapterFour(int section) {
    switch (section) {
        case 1:
            sectionOne();
            break;
        case 2:
            sectionTwo();
            break;
        case 3:
            sectionThree();
            break;
        case 4:
            sectionFour();
            break;
        case 5:
            sectionFive();
            break;
        case 8:
            sectionEight();
            break;
        case 12:
            sectionTwelve();
            break;
        case 13:
            sectionThirteen();
            break;
        default:
            std::cout << "Could not find relevant section call for " << section << std::endl;
            break;
    }
}

void chapterFourQuiz(const int question)
{
    switch (question) {
        case 3: {
            double a{};
            double b{};
            char oper{};
            std::cout << "Enter a number: \t";
            std::cin >> a;
            std::cout << "Enter another number:\t";
            std::cin >> b;
            std::cout << "Enter one of the following: +, -, *, or /:\t";
            std::cin >> oper;
            if (oper == '+') {
                std::cout << a << " " << oper << " " << b << " is " << a + b << "\n";
            } else if (oper == '-') {
                std::cout << a << " " << oper << " " << b << " is " << a - b << "\n";
            } else if (oper == '*') {
                std::cout << a << " " << oper << " " << b << " is " << a * b << "\n";
            } else if (oper == '/') {
                std::cout << a << " " << oper << " " << b << " is " << a / b << "\n";
            }

            break;
        }
        default:
            break;
    }
    
}
