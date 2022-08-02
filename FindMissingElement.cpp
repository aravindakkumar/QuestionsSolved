// Code to find missing elements in consecutive natural numbers
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findAllMissingElements(int arr[], int len)
{
    static int diff = 1;
    for (size_t i = 1; i < len; i++)
    {
        if ((arr[i] - arr[i - 1]) == 1)
            continue;
        else
        {
            while (true)
            {
                if (arr[i - 1] + diff != arr[i])
                {
                    std::cout << arr[i - 1] + diff++ << " ";
                }
                else
                    break;
            }
            diff = 1;
        }
    }
}

int main()
{
    int arr[] = {6, 7, 8, 9, 11, 12, 13, 14, 17, 18, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    findAllMissingElements(arr, len);
}