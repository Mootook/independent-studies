//
//  ChapterTwo.cpp
//  LearnCPP
//
//  Created by Alex Mutuc on 8/8/20.
//  Copyright © 2020 Alex Mutuc. All rights reserved.
//

#include <iostream>
#include "ChapterTwo.h"

/**
 * Ordering "#include"
 * 1. User-defined
 * 2. 3rd party
 * 3. standard libraries
 *
 * Each section should be sorted alphabetically
 */

#define PRINT_JOE
/**
 * A namespace is a region that allows you to declare names inside of it
 * for the purpose of disambiguation.
 * Namespace scope - any named declared inside won't be mistaken for identical names
 * in other scopes
 *
 * Accessing namespaces:
 * with " :: ", i.e. std::cout -> cout of the standard namespace
 * "::" is called the scope resolution operator.
 * 'using namespace std' is another option which allows for the use of just 'cout'.
 * To be avoided.
 *
 * Macro defines - a macro is a rule that defines how input text is converetd into replacement output text
 *
 * "ifdef" is a preprocessor directive to check if an identifier has been "defined"
 * --> If true, the code within the ifdef and endif is compiled.
 * "ifndef" checks if something has NOT been defined.
 *
 *
 */
void sectionTen()
{
    
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will compile
#endif
    
#ifdef PRINT_BOB
    std::cout << "Joe\n"; // will not compile
#endif
    
#if 0 // Don't compile starting here
    std::cout << "This won't compile, and using this preprocessir directive is seen as another way to comment out.\n";
#endif //  until here
    
}

void sectionEleven()
{
    std::cout << "Section Eleven\n";
}
