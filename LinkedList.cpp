#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};
void createLinkedList(vector<int> vec, Node *head)
{
    Node *current = head;
    for (size_t i = 0; i < vec.size(); i++)
    {
        current->data = vec[i];

        if (i == vec.size() - 1)
        {
            current->next = NULL;
            return;
        }
        current->next = new Node();
        current = current->next;
    }
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int RSum(Node *current)
{
    if (current->next == NULL)
    {
        return current->data;
    }
    return current->data + RSum(current->next);
}
int Rcount(Node *current)
{
    if (current == NULL)
    {
        return 0;
    }
    return 1 + Rcount(current->next);
}
int maxElement(Node *current, int max)
{
    if (current == NULL)
        return max;
    return (current->data > max) ? maxElement(current->next, current->data) : maxElement(current->next, max);
}
int LinearSearch(Node *current, int target)
{
    int index = 0;
    while (current != NULL)
    {
        if (current->data == target)
            return index;

        index++;
        current = current->next;
    }
    return -1;
}

int RLinearSearch(Node *current, int target)
{
    static int index = 0;
    if (current == NULL)
    {
        return -1;
    }

    if (current->data == target)
    {
        return index;
    }

    index++;
    return RLinearSearch(current->next, target);
}

int ImprovedLinearSearch(Node **head, int target)
{
    Node *current = *head, *q = NULL;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == target)
        {
            q->next = current->next;
            current->next = *head;
            *head = current;

            return index;
        }

        index++;
        q = current;
        current = current->next;
    }
    return -1;
}
void addLinkedList(Node **head, int data)
{
    Node *current = *head;
    Node *node = new Node(data);
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            current->next = node;
            return;
        }
        current = current->next;
    }
}
void insertLinkedList(Node **head, int index, int data)
{
    int count = 0;
    Node *current = *head, *q = NULL;
    Node *node = new Node(data);

    if (index == 0)
    {
        node->next = current;
        *head = node;
        return;
    }

    while (current != NULL)
    {
        if (count == index)
        {
            q->next = node;
            node->next = current;
            return;
        }
        count++;
        q = current;
        current = current->next;
    }
    addLinkedList(head, data);
}
void deleteNodeInLinkedList(Node **head, int index)
{
    int count{0};
    Node *current = *head, *q = NULL;

    if (index == 0)
    {
        *head = current->next;
        delete current;
        return;
    }

    while (current != NULL)
    {
        if (count == index)
        {
            q->next = current->next;
            delete current;
            return;
        }
        count++;
        q = current;
        current = current->next;
    }
}
void removeDupes(Node **head)
{
    Node *current = *head, *q = NULL;
    int prev = INT16_MIN;
    while (current != NULL)
    {
        if (prev == current->data)
        {
            q->next = current->next;
            delete current;
            current = q->next;
        }
        else
        {
            prev = current->data;
            q = current;
            current = current->next;
        }
    }
}
void reverseLinkedList(Node **head)
{
    Node *p = *head, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

void concatLinkedList(Node *link1, Node *link2)
{
    Node *current1 = link1;
    Node *current2 = link2;
    Node *prev;
    while (current1 != NULL)
    {
        prev = current1;
        current1 = current1->next;
    }
    prev->next = current2;
}

int main()
{
    // vector<int> vec = {5, 22, 11, 34, 56, 2, 42, 1, -1, 23, 9};
    // vector<int> vec = {1, 2, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9, 10};
    vector<int> vec = {1, 3, 5, 7, 9};
    vector<int> vec2 = {2, 4, 6, 8, 10};
    Node *linkedList = new Node();
    Node *linkedList2 = new Node();
    createLinkedList(vec, linkedList);
    createLinkedList(vec2, linkedList2);
    // printLinkedList(linkedList);
    // cout << RSum(linkedList) << endl;
    // cout << Rcount(linkedList) << endl;
    // cout << maxElement(linkedList, INT16_MIN) << std::endl;
    // cout << LinearSearch(linkedList, 23) << endl;
    // cout << RLinearSearch(linkedList, 56) << endl;
    // cout << ImprovedLinearSearch(&linkedList, 23) << endl;
    // deleteNodeInLinkedList(&linkedList, 0);
    // removeDupes(&linkedList);
    // reverseLinkedList(&linkedList);
    // printLinkedList(linkedList);
    // concatLinkedList(linkedList, linkedList2);

    printLinkedList(linkedList);

    return 0;
}