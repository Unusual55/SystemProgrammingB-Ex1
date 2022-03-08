#include "mat.hpp"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
namespace ariel
{
    void inputCheck(int row, int col, char a, char b)
    {
        if (row % 2 == 0 || col % 2 == 0)
        {
            std::__throw_invalid_argument("Mat size is always odd.");
        }
        if ((std::isprint(a) == 0) || (std::isprint(b) == 0) || a == ' ' || b == ' ')
        {
            std::__throw_invalid_argument("Input characters have to be printable.");
        }
        if (row < 0 || col < 0)
        {
            std::__throw_invalid_argument("The number of columns and row have can't be negative.");
        }
        if (col == 0 || row == 0)
        {
            std::__throw_invalid_argument("The number of columns and row can't be zero.");
        }
    }

    string mat(int n, int m, char a, char b)
    {
        ariel::inputCheck(n, m, a, b);
        string mat;
        string out;

        for (int i = 0; i < n; i++)
        {
            mat += a;
        }
        //ariel::print(mat);
        out = mat + '\n';
        if(m==1){
            return out;
        }
        int count = 1;
        for (int i = 1; i < m / 2; i++)
        {
            for (int j = i; j < n - i; j++)
            {
                if (mat.at(j) == a)
                {
                    mat[j] = b;
                }
                else
                {
                    mat[j] = a;
                }
            }
            count++;
            out += mat + '\n';
        }
        if (m % 2 == 1)
        {
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
            out += mat + '\n';
        }
        for (int i = count; i > 0; i--)
        {
            for (int j = i; j < n - i; j++)
            {
                if (mat.at(j) == a)
                {
                    mat[j] = b;
                }
                else
                {
                    mat[j] = a;
                }
            }
            out += mat + '\n';
        }
        return out;
    }
}

// int main(){
//     cout<<ariel::mat(7,7,'@', '-');
//     return 0;
// }