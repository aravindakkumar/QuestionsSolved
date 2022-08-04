// duplicates in string using bits
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
char max(string str)
{
    char max_char = ' ';
    for (auto s : str)
        if (s > max_char)
            max_char = s;
    return max_char;
}
void duplicate(string s)
{
    long int H = 0, x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x = 1;
        x = x << s[i] - 97;
        if (x & H)
            std::cout << "Duplicate: " << s[i] << endl;
        else
            H = x | H;
    }
}

int main()
{
    string str = "aravindakkumar";
    duplicate(str);
    return 0;
}