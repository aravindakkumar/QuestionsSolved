#include <iostream>
#include <string>
using namespace std;

// validating a string(only numbers and alphabets)
bool validate_str(string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] > 47 && str[i] < 58 || str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}
// vowels and consonants
int vowAndCon(string str)
{
    int count = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            count++;
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
        else
            continue;
    }
    return count;
}
// toggling case of a string
string toggleCase(string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        else
            continue;
    }
    return str;
}
// reverse a string
string reverse(string str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end)
    {
        int temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    return str;
}

int main()
{
    // validating a string(only numbers and alphabets)
    std::cout << std::boolalpha;
    string val1 = "as#3j./)92nd";
    std::cout << validate_str(val1) << std::endl;

    // vowels and consonants
    string val2 = "ahjedkisooauddb";
    std::cout << vowAndCon(val2) << std::endl;

    // toggling case of a string
    string val3 = "ArAViNDAkkumAr";
    std::cout << toggleCase(val3) << std::endl;

    // reverse a string
    string val4 = "AravindakKuamr";
    std::cout << reverse(val4) << std::endl;

    return 0;
}