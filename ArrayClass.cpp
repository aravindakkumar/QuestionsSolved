#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Array
{
private:
    int *arr;

public:
    int size;
    int length;

    Array(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->length = 0;
    }
    void append(int x)
    {
        if (length < size)
        {
            arr[length] = x;
            length++;
        }
        else
            cout << "Array Size not Sufficient" << endl;
    }
    void display()
    {
        cout << "[ ";
        for (size_t i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]";
    }
    void insert(int value, int index)
    {
        for (int i = length - 1; i >= index; i--)
        {
            if (length < size)
            {
                arr[i + 1] = arr[i];
            }
            else
            {
                cout << "Array Size not Sufficient" << endl;
                return;
            }
        }
        arr[index] = value;
        length++;
    }
    void deleteElement(int index)
    {
        for (int i = index; i < length; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
    }
    int linearSearch(int target)
    {
        for (size_t i = 0; i < length; i++)
        {
            if (target == arr[i])
                return i;
        }
        return -1;
    }
    int get(int index)
    {
        return arr[index];
    }
    void set(int value, int index)
    {
        arr[index] = value;
    }
    int max()
    {
        int max = INT16_MIN;
        for (size_t i = 0; i < this->length; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    int average()
    {
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += arr[i];
        }
        return (sum / length);
    }
    void reverse()
    {
        int s = 0;
        int e = length - 1;
        while (s < e)
        {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    bool isSorted()
    {
        for (size_t i = 0; i < length - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
};

void summa1(Array &arr)
{
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(-1);
    // arr.append(5);
    // arr.append(6);
    // arr.append(6);
}
int main()
{
    std::cout << std::boolalpha;
    Array arr(5);
    summa1(arr);
    arr.display();
    // arr.reverse();
    // arr.display();
    // std::cout << std::endl
    //           << arr.linearSearch(4) << std::endl;
    // std::cout << arr.max() << std::endl;
    std::cout << arr.isSorted() << std::endl;

    return 0;
}