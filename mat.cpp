#include "mat.hpp"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
namespace ariel
{

    /**
     * @brief This function receive the arguments from mat function and check if the inputs are valid,
     *  and if it's not, the function will throw an exception
     * @param row number of rows
     * @param col number of columns
     * @param a the first character
     * @param b the second character
     */

    void inputCheck(int row, int col, char a, char b)
    {
        /**
        If the row or the column number is even, the function will throw an exception
        This chekck will also cover the case where the number of rows or columns is 0 since
        zero is even number
        */
        if (row % 2 == 0 || col % 2 == 0)
        {
            std::__throw_invalid_argument("Mat size is always odd.");
        }

        // If one or both of the characters are unprintable or ' ', the funtion will throw an exception
        if ((std::isprint(a) == 0) || (std::isprint(b) == 0) || a == ' ' || b == ' ')
        {
            std::__throw_invalid_argument("Input characters have to be printable.");
        }

        /**
        If the number of rows or columns is odd and negative, the function will throw an exception
        It will only deal with odd negative numbers since any even negative number will be thrown in
        the first check
        */
        if (row < 0 || col < 0)
        {
            std::__throw_invalid_argument("The number of columns and row have can't be negative.");
        }

        /**
         * This check will probably never throw an exception since zero is an even number and it will be thrown in the
         * first check, but in order to be more formal, and make sure that every input would be valid, I would like to add
         * it as one final check.
         */
        if (col == 0 || row == 0)
        {
            std::__throw_invalid_argument("The number of columns and row can't be zero.");
        }
    }

    /**
     * @brief This function get the size of the mat and the wanted characters and returns a mat in the wanted size and format.
     * The function divide the mat into 3 parts:
     * The upper part
     * The middle row
     * The lower half
     * and deals with each part differently in order to receive the desired result
     * @param n number of columns
     * @param m number of rows
     * @param a first character
     * @param b second character
     * @return string that represent the mat
     */

    string mat(int n, int m, char a, char b)
    {
        // Check if the input is valid
        ariel::inputCheck(n, m, a, b);

        // Create the string which will be used to be the output and the current row in the mat
        string mat;
        string out;

        // Set the first row to contain only the first character and add it to the output string
        for (int i = 0; i < n; i++)
        {
            mat += a;
        }
        out = mat + '\n';

        // If the number of row is 1, we finished the mat and will return it.
        if (m == 1)
        {
            return out;
        }

        // Set the counter of steps we took from the beginning of the mat
        int count = 1;

        /**
         * @brief Upper half of the mat:
         * In each iteration-step, we will flip* every character in range (i,m-i), which means we will update 2 characters less
         * than last iteration in each iteration.
         * After each iteration we will increase count by one
         * *Flip: Change from the first character to the second character, and from the second character to the first character
         */
        for (int i = 1; i < m / 2; i++)
        {
            for (int j = i; j < n - i; j++)
            {

                // Flips from first to second character
                if (mat.at(j) == a)
                {
                    mat[j] = b;
                }

                // Flip from second to first character
                else
                {
                    mat[j] = a;
                }
            }

            // Increase count by 1 and add the current row to the output mat
            count++;
            out += mat + '\n';
        }

        //Middle row of the mat
        //Flip only the characters that we need to flip before reaching the lower half without increasing count
        for (int i = count; i < n - count; i++)
        {
            if (mat.at(i) == a)
            {
                mat[i] = b;
            }
            else
            {
                mat[i] = a;
            }
        }

        //Add the current row to the output
        out += mat + '\n';

        /**
         * @brief Lower half of the mat
         * The each iteration will reverse the mat string using count, and each time after the internal iteration
         * will finished, we will decrease count by 1 and flip the characters from count to n-count
         * @param i 
         */

        for (int i = count; i > 0; i--)
        {
            for (int j = i; j < n - i; j++)
            {
                //Flip from first to second character
                if (mat.at(j) == a)
                {
                    mat[j] = b;
                }

                //Flip from second to first character
                else
                {
                    mat[j] = a;
                }
            }
            //Add the row to the current mat
            out += mat + '\n';
        }
        //Return the output mat
        return out;
    }
}

// int main(){
//     cout<<ariel::mat(7,7,'@', '-');
//     return 0;
// }