//
//  ChapterSix.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 9/12/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include "ChapterSix.h"

#include <iostream>

int globalVariable {}; // often prefixed g_

namespace chapterSix
{
    void section(int section)
    {
        switch (section) {
            case 2: {
                std::cout << "Created a namespace!" << '\n';
                break;
            }
            case 3: {
                chapterSix::nestedNamespace::nested();
                break;
            }
            case 12: {
                std::cout << "Nested block." << '\n';
                { // nested blocks like this can be used to limit scope
                    std::cout << "In the nested block" << '\n';
                }
                break;
            }
            case 14: {
                auto d{ 5.0 }; // double type
                std::cout << d << " is an auto variable, compiler will infer type." << '\n';
                break;
            }
            default:
                break;
        }
    }

    namespace nestedNamespace
    {
        void nested()
        {
            std::cout << "Using nested namespace" << '\n';
            /**
             * Can also create using namespace foo::goo {}
             * namespace boo = foo::goo
             * boo::nested()
             */
        }
    }
}
