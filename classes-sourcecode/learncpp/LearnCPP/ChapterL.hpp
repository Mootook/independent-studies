//
//  ChapterL.hpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/23/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#ifndef ChapterL_hpp
#define ChapterL_hpp

#include <stdio.h>
#include <string>

/**
 * Chapter L - Control Flow
 *
 */
namespace chapterL
{
    enum class Animal
    {
        ANIMAL_PIG,
        ANIMAL_CHICKEN,
        ANIMAL_GOAT,
        ANIMAL_CAT,
        ANIMAL_DOG,
        ANIMAL_OSTRICH
    };
    std::string animalName(Animal animalType);
    void section(int section);
    void quiz(int number);
}

#endif /* ChapterL_hpp */
