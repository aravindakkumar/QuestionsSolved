// Stack ADT Linked List

#include <iostream>
#include <vector>

using namespace std;
class Stack;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data = -1)
    {
        this->data = data;
        this->next = NULL;
    }
    friend Stack;
};

class Stack
{
private:
    Node *top;
    Node *S;

public:
    Stack()
    {
        this->top = NULL;
        this->S = NULL;
    }
    void push(int x)
    {
        Node *t = new Node();
        if (t == NULL)
            return;

        t->data = x;
        t->next = top;
        top = t;
    }
    int pop()
    {
        if (top == NULL)
            return -1;

        Node *current = top;
        top = top->next;
        delete current;
        current = NULL;
    }
    void display()
    {
        Node *current = top;
        while (current != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    int peek(int pos)
    {
        Node *current = top;
        int count = 1;
        while (current != NULL)
        {
            if (count == pos)
            {
                return current->data;
            }
            current = current->next;
            count++;
        }
        return -1;
    }

    bool isEmpty()
    {
        retrun(top == NULL) ? true : false;
    }
};
void create(Stack &s)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.size(); i++)
    {
        s.push(vec[i]);
    }
}

int main()
{
    Stack st;
    create(st);
    std::cout << st.peek(5) << std::endl;
    st.display();
    return 0;
}