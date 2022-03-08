/**
 * AUTHORS: Ofri Tavor 208601401
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

/**
These test case will check if the code can deal well with the base cases, it is very
important to deal perfectly with the base cases in order to check further complicated cases
*/


TEST_CASE("Good base input"){
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n"));
	CHECK(nospaces(mat(5, 1, '@', '-'))==nospaces("@@@@@\n"));
	CHECK(nospaces(mat(1, 5, '@', '-'))==nospaces("@\n"
													"@\n"
													"@\n"
													"@\n"
													"@\n"));
	CHECK(nospaces(mat(3, 3, '@', '@'))==nospaces("@@@\n"
													"@@@\n"
													"@@@\n"));
}

/**
Even parameter as row or column:
	1) Even columns, odd rows
	2) Odd columns, even rows
	3) Even columnd and rows

Zero parameter as row or column- derived from last base case since 0 is even number
	1) 0 columns, odd rows
	2) 0 columns, even rows
	3) 0 columns and rows

Negative parameter as row or column
	1) Negative columns, positive rows
	2) Positive columns, negative rows
	3) Negative columns and rows


*/


TEST_CASE("Matrix size bad base inputs"){
	CHECK_THROWS(mat(2, 1, '@', '-'));
	CHECK_THROWS(mat(1, 2, '@', '-'));
	CHECK_THROWS(mat(2, 2, '@', '-'));
	CHECK_THROWS(mat(0, 1, '@', '-'));
	CHECK_THROWS(mat(1, 0, '@', '-'));
	CHECK_THROWS(mat(0, 0, '@', '-'));
	CHECK_THROWS(mat(-5, 1, '@', '-'));
	CHECK_THROWS(mat(1, -5, '@', '-'));
	CHECK_THROWS(mat(-9, -1, '@', '-'));
}

/**
After we finished check the bad base cases for the size of the matrix, we need to check if
the inputs are valid in order to eventually get the valid output
1) One input ' '
2) One input '\n'
3) both inputs are not printable.
*/

TEST_CASE("Characters base bad inputs"){
	CHECK_THROWS(mat(3, 9, '@', ' '));
	CHECK_THROWS(mat(3, 9, '\n', 'x'));
	CHECK_THROWS(mat(3, 9, '\n', '\t'));
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	CHECK(nospaces(mat(7, 7, '@', '-'))==nospaces("@@@@@@@\n"
													"@-----@\n"
													"@-@@@-@\n"
													"@-@-@-@\n"
													"@-@@@-@\n"
													"@-----@\n"
													"@@@@@@@\n"));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(0, -1, '@', '-'));
	CHECK_THROWS(mat(0, -1, ' ', '-'));
	CHECK_THROWS(mat(0, -1, ' ', '\t'));
	CHECK_THROWS(mat(2, -1, '@', '-'));
	CHECK_THROWS(mat(2, -1, '\n', '-'));
	CHECK_THROWS(mat(-2, 0, '@', '-'));
}
