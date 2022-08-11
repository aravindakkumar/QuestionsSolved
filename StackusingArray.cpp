// Stack ADT using Array

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *S;

public:
    Stack(int size = 1)
    {
        this->size = size;
        this->top = -1;
        this->S = new int[size];
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            std::cout << "Stack Overflow!!" << std::endl;
            return;
        }
        S[++top] = data;
    }
    int pop()
    {
        if (top == -1)
        {
            std::cout << "Stack Underflow" << std::endl;
        }
        return S[top--];
    }
    int peek(int index)
    {
        if (index >= this->size)
        {
            std::cout << "Invalid Index" << std::endl;
            return -1;
        }

        return S[this->top - index + 1];
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            std::cout << this->S[i] << " ";
        }
    }
    bool isEmpty()
    {
        if (this->top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        return (this->top == size - 1) ? true : false;
    }
};
void create(Stack &s)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.size(); i++)
        s.push(vec[i]);
}
int main()
{
    std::cout << std::boolalpha;
    Stack st(10);
    create(st);
    // cout << st.pop() << endl;
    // cout << st.pop() << endl;
    // cout << st.peek(1) << std::endl;
    cout << st.isFull() << std::endl;
    st.display();
    return 0;
}