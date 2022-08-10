// circular linked list
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    friend void deleteList(Node **head, int index);

    Node(int data = 0)
    {
        this->data = data;
        this->next = this;
    }
    void create(vector<int> vec)
    {
        Node *current = this, *t;
        current->data = vec[0];

        for (int i = 1; i < vec.size(); i++)
        {
            t = new Node(vec[i]);
            t->next = current->next;
            current->next = t;
            current = t;
        }
    }
    void display()
    {
        Node *current = this;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != this);
    }
    void insert(int index, int data)
    {
        int count = 0;
        Node *t = new Node(data), *current = this, *p = NULL;

        do
        {
            if (count == index)
            {
                t->next = p->next;
                p->next = t;
                break;
            }

            count++;
            p = current;
            current = current->next;
        } while (current != this);
    }
};

void deleteList(Node **head, int index)
{
    Node *current = *head, *p = NULL;
    int count = 0;

    do
    {
        if (count == index)
        {
            p->next = current->next;
            delete current;
            break;
        }
        count++;
        p = current;
        current = current->next;
    } while (current != *head);
}

int main()
{
    Node *ClinkedList = new Node();
    vector<int> vec = {1, 2, 3, 4, 5};
    ClinkedList->create(vec);
    deleteList(&ClinkedList, 1);
    ClinkedList->display();
    return 0;
}