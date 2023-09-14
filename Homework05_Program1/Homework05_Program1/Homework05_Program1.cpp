//==================================
//Name: Nicolaas Dyk
//Date: 04-05-2023
//Desc: Using recursion to solve
//      various problems
//==================================

#include <iostream>

using namespace std;

int multiply(int, int);
int sumOfDigits(int);
int sumOfDigits(int, int);
int countPyramid(int);
int countPyramid(int, int, int);
int power(int, int);
int power(int, int, int);
int countX(string);
int countX(string, int);

int main()
{
    int mult1 = 5, mult2 = 7;
    int sumDig = 259;
    int pyramid = 5;
    int powBase = 3, powPower = 4;
    string xCounter = "TEST XXX test xxx";

    cout << "=========================================" << endl;
    cout << "           Recursion Functions           " << endl;
    cout << "=========================================" << endl;
    cout << "Multiplication    : " << mult1 << " * " << mult2 << " = " << multiply(mult1, mult2) << endl;
    cout << "Sum of Digits     : " << sumDig << " = " << sumOfDigits(sumDig) << endl;
    cout << "Blocks of Pyramid : " << "Height of " << pyramid << " = " << countPyramid(pyramid) << endl;
    cout << "Exponent          : " << powBase << "^" << powPower << " = " << power(powBase, powPower) << endl;
    cout << "Number of X's     : " << "\"" << xCounter << "\" = " << countX(xCounter) << endl;

}

//Using recursion, add x to itself y amount of times
int multiply(int x, int y)
{
    //base case, when there's only 1 x left to add
    if (y == 1)
    {
        return x;
    }
    //else add x to the next multiply
    else
    {
        return x + multiply(x, y - 1);
    }
}

//Caller function to the recursive function
int sumOfDigits(int x)
{
    return sumOfDigits(x, 0);
}

//Using recursion, find the sum of each integer in x
int sumOfDigits(int x, int sum)
{
    //when x has been reduced to 0, stop adding
    if (x <= 0)
    {
        return sum;
    }
    else
    {
        //take the modulus of x by 10 in order to get whatever is currently in the one position
        sum = sum + (x % 10);
        //move to the next sumOfDigits with an x that shifts its units one to the right
        return sumOfDigits(x / 10, sum);
    }
}

//Caller function to the recursive function
int countPyramid(int size)
{
    return countPyramid(size, 0, 0);
}

//Using recursion, create a pyramid of size height, and return how many blocks
//are in it
int countPyramid(int size, int i, int num)
{
    //Base case once at the bottom of the pyramid, return to the top
    if (size == i)
    {
        return num;
    }
    else
    {
        //increment the size of the pyramid (done first since the size starts at 0)
        i++;
        //set num to be itself plus the current row of the pyramid
        num = num + i;
        //move to the next function
        return countPyramid(size, i, num);
    }
}

//Caller function to the recursive function
int power(int b, int x)
{
    return power(b, x, 1);
}

//Using recursion, runs b^x (does not accept negative numbers for x)
int power(int b, int x, int ans)
{
    //base case
    if (x <= 0)
    {
        return ans;
    }
    //else if x is above 0 
    else
    {
        ans = ans * b;
        return power(b, x - 1, ans);
    }
}

int countX(string phrase)
{
    return countX(phrase, 0);
}

int countX(string phrase, int num)
{
    if (phrase.length() == 0)
    {
        return num;
    }
    else
    {
        if (phrase.at(0) == 'x' || phrase.at(0) == 'X')
        {
            num++;
        }
        phrase = phrase.substr(1, phrase.length());
        return countX(phrase, num);
    }
}