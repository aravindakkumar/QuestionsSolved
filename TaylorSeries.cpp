// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double pow(int x, int p)
{
    if (p == 0)
        return 1;
    return x * pow(x, p - 1);
}
int factorial(int n)
{
    if (n < 0)
        return (-1); /*Wrong value*/
    if (n == 0)
        return (1); /*Terminating condition*/
    else
    {
        return (n * factorial(n - 1));
    }
}

double tlr(int x, int f, int p)
{
    if (f == 0 || p == 0)
        return 1;

    return (pow(x, p) / factorial(f)) + tlr(x, f - 1, p - 1);
}

int main()
{
    std::cout << tlr(2, 3, 3);
    return 0;
}