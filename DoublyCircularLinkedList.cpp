#include <iostream>
#include <vector>

using namespace std;

class CDNode
{
private:
    int data;
    CDNode *prev;
    CDNode *next;

public:
    CDNode(int data = 0)
    {
        this->data = data;
        this->prev = this->next = this;
    }

    void create(vector<int> vec)
    {
        this->data = vec[0];
        CDNode *t = NULL, *last = this, *p = NULL;

        for (size_t i = 1; i < vec.size(); i++)
        {
            t = new CDNode(vec[i]);

            t->next = this;
            t->prev = last;

            last->next = t;
            last->prev = p;

            p = last;
            last = last->next;
        }
        this->prev = last;
    }

    void display()
    {
        CDNode *current = this;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != this);
    }

    void insert(int index, int data)
    {
        CDNode *t = new CDNode(data), *current = this, *q = NULL;
        int count = 0;

        do
        {
            if (index == count)
            {
                t->next = current;
                t->prev = q;

                current->prev = t;

                q->next = t;
                break;
            }
            else
            {
                count++;
                q = current;
                current = current->next;
            }
        } while (current != this);
    }
    void Delete(int index)
    {
        int count = 0;
        CDNode *current = this, *q = NULL, *p = NULL;

        do
        {
            if (index == count)
            {
                q->next = current->next;

                p = current;
                current = current->next;
                current->prev = q;

                delete p;
                p = NULL;

                break;
            }
            else
            {
                count++;
                q = current;
                current = current->next;
            }
        } while (current != this);
    }

    int midElement()
    {
        CDNode *p = this, *q = this;

        do
        {

            p = p->next;
            if (p != this)
            {
                q = q->next;
                p = p->next;
            }
        } while (p != this);
        return q->data;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    CDNode *linkedList = new CDNode();
    linkedList->create(vec);
    // linkedList->insert(4, 1000);
    // linkedList->Delete(3);
    std::cout << linkedList->midElement() << std::endl;

    linkedList->display();
    return 0;
}