#include <iostream>
#include <string>
using namespace std;

class LowerTriangularMatrix
{
private:
    int *arr;
    int n;

public:
    LowerTriangularMatrix(int size) : arr{new int[size]}, n{size} {}

    void display()
    {
        int A_count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j <= i)
                {
                    cout << arr[A_count++] << " ";
                }
                else
                    cout << "0"
                         << " ";
            }

            cout << endl;
        }
    }

    void set(int A[], int len)
    {
        for (size_t i = 0; i < len; i++)
        {
            arr[i] = A[i];
        }
    }
};

class UpperTriangularMatrix
{
private:
    int *arr;
    int n;

public:
    UpperTriangularMatrix(int size) : arr{new int[size]}, n{size} {}
    void set(int A[], int len)
    {
        for (size_t i = 0; i < len; i++)
        {
            arr[i] = A[i];
        }
    }
    void display()
    {
        int A_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    cout << "0 ";
                }
                else
                {
                    cout << arr[A_count++] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int len = sizeof(arr) / sizeof(arr[0]);
    LowerTriangularMatrix matrix(5);
    matrix.set(arr, len);
    matrix.display();

    cout << endl;

    UpperTriangularMatrix matrix2(5);
    matrix2.set(arr, len);
    matrix2.display();
    return 0;
}