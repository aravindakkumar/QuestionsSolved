// finding duplicates in a sorted array
#include <iostream>

using namespace std;

void dupesSorted(int arr[], int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            int dupe = arr[i];
            int count = 0;
            int j = i;
            while (true)
            {
                if (arr[j] != dupe)
                    break;
                count++;
                j++;
            }
            std::cout << dupe << " Appeared " << count << " times" << std::endl;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 7, 8, 9, 10, 10, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    dupesSorted(arr, len);
    return 0;
}