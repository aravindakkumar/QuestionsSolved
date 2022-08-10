#include <iostream>
#include <vector>
using namespace std;

class DNode
{
private:
    int data;
    DNode *prev;
    DNode *next;

public:
    DNode(int data = 0)
    {
        this->data = data;
        this->next = this->prev = NULL;
    }

    void create(const vector<int> &vec)
    {
        DNode *t = NULL, *last = this;
        this->data = vec[0];

        for (int i = 1; i < vec.size(); i++)
        {
            t = new DNode(vec[i]);
            t->prev = last;
            last->next = t;
            last = t;
        }
    }

    void display()
    {
        DNode *current = this;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void insert(int index, int data)
    {
        int count = 0;
        DNode *t = new DNode(data), *current = this, *p = NULL;

        while (current != NULL)
        {
            if (count == index)
            {
                t->next = p->next;
                current = p->next;
                current->prev = t;

                p->next = t;
                t->prev = p;
                break;
            }
            count++;
            p = current;
            current = current->next;
        }
    }

    void Delete(int index)
    {
        DNode *current = this, *p = NULL;
        int count = 0;

        while (current != NULL)
        {
            if (index == count)
            {
                p->next = current->next;
                current = current->next;
                current->prev = p;
                break;
            }
            else
            {
                count++;
                p = current;
                current = current->next;
            }
        }
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    DNode *linkedList = new DNode();
    linkedList->create(vec);
    linkedList->Delete(1);
    linkedList->display();

    return 0;
}