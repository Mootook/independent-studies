//
//  ChapterFive.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 8/29/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//
#include <iostream>
#include <cmath>
#include "ChapterFive.h"



void chapterFive(int section)
{
    switch (section) {
        case 3: {
            double x { std::pow(3.0, 4.0) }; // 3 to the fourth power
            std::cout << "Three to the fourth power is " << x << "\n";
            break;
        }
        case 4: {
            int x { 5 };
            int y = ++x;
            // x is incremented to 6,
            // x is evaluated to the value 6,
            // and is assigned to y
            std::cout << x << ' ' << y;
            // 6 6
            
            x = 5;
            y = x++;
            // x is incremenetd to 6, copy of original x is
            // evaluted to the value of 5, and 5 is
            // assignd to y
            std::cout << x << ' ' << y;
            // 6 5
        }
        default: {
            std::cout << "Could not find call for section " << section << "\n";
            break;
        }
    }
}
