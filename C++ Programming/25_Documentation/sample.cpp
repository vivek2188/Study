/** @file
 * @brief Introduction to Doxygen
 *
 * This file is created to provide reference to
 * various conventions and tags supported by Doxygen.
 *
 * Hope you find it helpful.
*/

/** @mainpage Palindromes
  * Test input string to see whether they are palindromes.
  *
  * A palindrome is a string that reads the same forward and backward.
  * To test for palindromes, this program needs to strip punctuation and
  * other non-essential characters from the string, and compare letters 
  * without regard to case differences.
  *
  * This program reads lines of text from the standard input and echos 
  * to the standard output those lines that are palindromes
  * 
  * Source file: @link sample.cpp @endlink
  *
  * @date 18-10-2018
  * @author Vivek Tiwari
  * @version 1.0
*/
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <algorithm>
#include <locale>
using namespace std;

/** @brief Test for non-letter\n
 * Test the character @p ch in the global locale
 * @param ch the character to test
 * @return TRUE if @p ch is not a letter
*/
bool non_letter(char ch){
	if(isalnum(ch,locale()))
		return false;
	return true;
}

/** @brief Convert to lowercase
 * @param ch the character to test
 * @return The character converted to lowercase
*/
char lower_case(char ch){
  return tolower(ch,locale());
}

/** @brief Compare two characters without regards of their case.
 * @param a one character to compare
 * @param b other character to compare
 * @return @c TRUE if the characters are the same in lowercase\n
           @c FALSE if they are different
*/
bool same_char(char a,char b){
  return (lower_case(a)==lower_case(b));
}

/** @brief Determine whether @p line is palindrome
 * @param line the string to test
 * @return TRUE if @p line is same forward and backward

*/
bool ispalindrome(string line){
  string::iterator new_end_pointer = remove_if(line.begin(),line.end(),non_letter);
  string reversed_str(line.begin(),new_end_pointer);
  reverse(reversed_str.begin(),reversed_str.end());
  return not reversed_str.empty() and equal(line.begin(),new_end_pointer,reversed_str.begin(),same_char);
}

/** @brief Main Program\n
 * Set the global locale to the user's native locale. Then imbue the I/O 
 * streams with the native locale.
*/
int main(void){
	locale::global(locale(""));
  cin.imbue(locale());
  cout.imbue(locale());
  string line;
  while(getline(cin,line)){
    if(ispalindrome(line))
      cout << line << "\n";
  }
	return 0;
}