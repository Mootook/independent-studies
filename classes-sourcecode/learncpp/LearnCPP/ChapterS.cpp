//
//  ChapterS.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/15/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterS.hpp"

#include <iostream>
#include <string>

namespace chapterS
{
    void section(int section)
    {
        switch (section) {
            case 4: {
                std::string myName{ "Alex" };
                std::string userName{};

                std::cout << "Enter your full name" << '\n';
                std::getline(std::cin, userName);

                std::cout << "Enter your age" << '\n';
                std::string age{};
                std::getline(std::cin, age);

                std::cout << "Your name is " << userName << " and your age is " << age << '\n';

                // Because std::cin captures \n (on enter press)
                // following it with a getline defers to the \n in the buffer, bypassing user input
                std::cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
                
                // + / += operators to concatentate to strings
                // userName.length(); to get size of string
                
                // Quiz
                std::string quizName{};
                std::cout << "Enter your full name" << '\n';
                std::getline(std::cin, quizName);
                
                
                int quizAge{};
                std::cout << "Enter your age" << '\n';
                std::cin >> quizAge;
                
                std::cout << "You've lived " << quizAge/quizName.length() << " years for each letter "
                "in your name." << '\n';
                break;
            }
            case 5: {
                Color blue = COLOR_BLUE;
                std::cout << "Enum! " << blue << '\n';
                
                // Quiz
                enum Monster
                {
                    MONSTER_ORC,
                    MONSTER_GOBLIN,
                    MONSTER_TROLL,
                    MONSTER_OGRE,
                    MONSTER_SKELETON
                };
                
//                Monster troll = MONSTER_TROLL;
                
                break;
            }
            case 6: {
                City newYork{ City::CITY_NEW_YORK };
                if (newYork == City::CITY_NEW_YORK)
                {
                    std::cout << "New York.";
                }
                break;
            }
            case 7: {
                struct Employee
                {
                    short id;
                    int age;
                    double wage;
                };
                Employee reggie;
                reggie.id = 10;
                reggie.age = 45;
                reggie.wage = 10000;
                
                Employee joe{ 1, 25, 60000 }; // id, age, wage
                std::cout << "Joe makes " << joe.wage << '\n';
                break;
            }
            case 8: {
                // Final Quiz
                enum class MonsterType
                {
                    MONSTER_OGRE,
                    MONSTER_DRAGON,
                    MONSTER_ORC,
                    MONSTER_GIANT_SPIDER
                };
                
                struct Monster
                {
                    MonsterType monsterType;
                    std::string name;
                    double health;
                };
                MonsterType spiderType{ MonsterType::MONSTER_GIANT_SPIDER };
                Monster spider{ spiderType, "Todd", 100.0 };
                std::cout << "The monster's name is " << spider.name;
                std::cout << "The monster's health is " << spider.name;
                break;
            }
            default:
                break;
        }
    }
}
