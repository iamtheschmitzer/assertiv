/*
   Copyright (C) 2013 Object Computing Incorporated.
   All rights reserved.
   See the file license.txt for licensing information.

   Assertive - miminal C++ unit test library.  Nothing to build, just #include
               in your test code, use the TEST() and ASSERT_* macros.
*/
// Note the path to the header file may be different in your 
// applications build environment
#define ASSERTIV_NO_MAIN
#include "assertiv.h" 
// Note assertiv.h imports a bunch o' stuff from stdlib

TEST(three_expected_to_pass)
{
    int d1 = 1;
    int d2 = 1;
    ASSERT_EQ(d1, d2);
    ASSERT_TRUE(d1 == d2);
    ASSERT_FALSE(d1 != d2)
    ASSERT_NO_THROW(
        int d3 = d1 + d2;
        if( d3 != 2)
        {
            throw std::exception("That shouldn't happen");
        }
    );         
}
