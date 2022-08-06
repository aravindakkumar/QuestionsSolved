#include <iostream>
#include <string>
using namespace std;

class DiagonalMatrix
{
private:
    int *arr;
    int n;

public:
    DiagonalMatrix(int size) : arr{new int[size]}, n{size} {}
    int get(int i, int j)
    {
        if (i == j)
        {
            return arr[i];
        }
        else
        {
            return 0;
        }
    }
    void set(int A[])
    {
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = A[i];
        }
    }
    void display()
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (j == i)
                    cout << arr[i] << " ";
                else
                    cout << "0"
                         << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    DiagonalMatrix Matrix(10);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Matrix.set(arr);
    Matrix.display();
    return 0;
}