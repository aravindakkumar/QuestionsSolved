// finding duplicate elements in an unsorted array
#include <iostream>

using namespace std;

void dupes(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == -1)
            continue;
        int count = 1;
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == arr[i] && i != j)
            {
                count++;
                arr[j] = -1;
            }
        }
        if (count > 1)
        {
            std::cout << arr[i] << " Appeared " << count << " times" << std::endl;
        }
    }
}
int main()
{
    int arr[] = {8, 3, 4, 2, 4, 11, 8, 3, 2, 8, 9, 23, 4, 5, 5, 6, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    dupes(arr, len);
    return 0;
}