/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Tal Schreiber>
 * 
 * Date: 2021-02
 */
 // This is the Test.cpp for the first part.
 // This is the test class that using doctest.h

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */

// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }

TEST_CASE("Good snowman code") {
//Hats 
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(31114411) == string("   _  \n  /_\\ \n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(41114411) == string("  ___ \n (_*_)\n (.,.) \n ( : ) \n ( : )"));
    
//Nose
    CHECK(snowman(41312222) == string("  ___ \n (_*_)\n\\(O,.)/\n (] [) \n (\" \")"));
    CHECK(snowman(42312222) == string("  ___ \n (_*_)\n\\(O..)/\n (] [) \n (\" \")"));
    CHECK(snowman(43312222) == string("  ___ \n (_*_)\n\\(O_.)/\n (] [) \n (\" \")"));
    CHECK(snowman(44312222) == string("  ___ \n (_*_)\n\\(O .)/\n (] [) \n (\" \")"));
    
//Left Eye
    CHECK(snowman(11123344) == string("      \n _===_\n (.,o) \n/(   )\\\n (   )"));
    CHECK(snowman(11223344) == string("      \n _===_\n (o,o) \n/(   )\\\n (   )"));
    CHECK(snowman(11323344) == string("      \n _===_\n (O,o) \n/(   )\\\n (   )"));
    CHECK(snowman(11423344) == string("      \n _===_\n (-,o) \n/(   )\\\n (   )"));
//Right Eye
    CHECK(snowman(12311111) == string("      \n _===_\n (O..) \n<( : )>\n ( : )"));
    CHECK(snowman(12321111) == string("      \n _===_\n (O.o) \n<( : )>\n ( : )"));
    CHECK(snowman(12331111) == string("      \n _===_\n (O.O) \n<( : )>\n ( : )"));
    CHECK(snowman(12341111) == string("      \n _===_\n (O.-) \n<( : )>\n ( : )"));
    
//Left Arm
    CHECK(snowman(11421344) == string("      \n _===_\n (-,o) \n<(   )\\\n (   )"));
    CHECK(snowman(11422344) == string("      \n _===_\n (-,o) \n\\(   )\\\n (   )"));
    CHECK(snowman(11423344) == string("      \n _===_\n (-,o) \n/(   )\\\n (   )"));
    CHECK(snowman(11424344) == string("      \n _===_\n (-,o) \n (   )\\\n (   )"));

//Right arm
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(31313231) == string("   _  \n  /_\\ \n (O,.) \n/(> <)/\n ( : )"));
    CHECK(snowman(31313331) == string("   _  \n  /_\\ \n (O,.) \n/(> <)\\\n ( : )"));
    CHECK(snowman(31313431) == string("   _  \n  /_\\ \n (O,.) \n/(> <) \n ( : )"));


//Toss
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(21114421) == string("  ___ \n .....\n (.,.) \n (] [) \n ( : )"));
    CHECK(snowman(21114431) == string("  ___ \n .....\n (.,.) \n (> <) \n ( : )"));
    CHECK(snowman(21114441) == string("  ___ \n .....\n (.,.) \n (   ) \n ( : )"));



//Base 
    CHECK(snowman(11111121) == string("      \n _===_\n (.,.) \n<(] [)>\n ( : )"));
    CHECK(snowman(11111122) == string("      \n _===_\n (.,.) \n<(] [)>\n (\" \")"));
    CHECK(snowman(11111123) == string("      \n _===_\n (.,.) \n<(] [)>\n (___)"));
    CHECK(snowman(11111124) == string("      \n _===_\n (.,.) \n<(] [)>\n (   )"));

}


TEST_CASE("Ilegal 8 digit num ") {
    
    CHECK_THROWS(snowman(81162111));
    CHECK_THROWS(snowman(22425442));
    CHECK_THROWS(snowman(31725555));
    CHECK_THROWS(snowman(21232126));
    CHECK_THROWS(snowman(11113115));
    CHECK_THROWS(snowman(52422112));
    CHECK_THROWS(snowman(12151174));
    CHECK_THROWS(snowman(12345678));
}
    
TEST_CASE("Lower then 8 digit num") {
    int num=3;
    for(int i=1;i<8;i++){
        CHECK_THROWS(snowman(num));
        num*=10;
    }
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(25));
    CHECK_THROWS(snowman(367));
    CHECK_THROWS(snowman(4674));
    CHECK_THROWS(snowman(16761));
    CHECK_THROWS(snowman(167712));
    CHECK_THROWS(snowman(3671842));
    
}

TEST_CASE("Higher then 8 digit num") {
    int num=513279329;
    for(int i=8;i<11;i++){
        CHECK_THROWS(snowman(num));
        num*=10;
    }

    CHECK_THROWS(snowman(555424266));
    CHECK_THROWS(snowman(255135343));
    CHECK_THROWS(snowman(242675555));
    CHECK_THROWS(snowman(672575553));
    CHECK_THROWS(snowman(991229999));
    CHECK_THROWS(snowman(1111111111));    
}

TEST_CASE("Negative 8 digit number") {
    CHECK_THROWS(snowman(-11231411));
    CHECK_THROWS(snowman(-1434244));
    CHECK_THROWS(snowman(-13442344));
    CHECK_THROWS(snowman(-22241334));
    CHECK_THROWS(snowman(-33311221));
    CHECK_THROWS(snowman(-12213241));
    CHECK_THROWS(snowman(-12321412));
}
