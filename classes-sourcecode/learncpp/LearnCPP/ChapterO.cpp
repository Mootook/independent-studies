//
//  ChapterO.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/5/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterO.h"
#include <iostream>
#include <bitset>

void chapterO(int section)
{
    switch (section) {
        case 1: {
            std::bitset<8> bitset { 0b0000'0101 }; // 8 bits in size means room for 8 flags
            bitset.set(3); // set bit position 3 to 1 => 0000 1101
            bitset.set(4); // => 0001 1101
            bitset.reset(4); // set bit 4 back to 0 => 0000 1101
            
            std::cout << "All the bits: " << bitset << "\n";
            std::cout << "Bit 3 has value: " << bitset.test(3) << "\n";
            std::cout << "Bit 4 has value: " << bitset.test(4) << '\n';
            break;
        }
        case 2: {
            std::bitset<4> x { 0b1100 };
            std::cout << x << '\n';
            std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
            std::cout << (x << 1) << '\n'; // shift left by 1 => 1000
            break;
        }
        default:
            break;
    }
}
