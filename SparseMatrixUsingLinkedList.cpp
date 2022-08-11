#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
    int data;
    int col;
    Node *next;

public:
    friend class Sparsematrix;
    Node(int col = -1, int data = -1)
    {
        this->col = col;
        this->data = data;
        this->next = NULL;
    }
};

class Sparsematrix
{
private:
    vector<Node *> nodes;

public:
    Sparsematrix(int m, vector<vector<int>> vec)
    {
        nodes.resize(m);
        Node *t = NULL, *current = NULL;

        for (size_t i = 0; i < m; i++)
        {
            nodes[i] = new Node();
            current = nodes[i];

            for (int j = 0; j < vec[0].size(); j++)
            {
                if (vec[i][j] != 0)
                {
                    t = new Node(j, vec[i][j]);
                    t->next = NULL;
                    current->next = t;
                    current = t;
                }
            }
            // std::cout << current->data << std::endl;
        }
    }
    void Display(int n)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            Node *current = nodes[i];
            // std::cout << current->data << std::endl;
            current = current->next;

            for (int j = 0; j < n; j++)
            {
                if (current->col == j)
                {
                    std::cout << current->data << " ";
                    current = current->next;
                }
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    vector<vector<int>> vec = {
        {1, 0, 8, 1},
        {0, 0, 0, 1},
        {2, 0, 0, 1}};
    Sparsematrix *mat = new Sparsematrix(vec.size(), vec);
    mat->Display(vec[0].size());
    return 0;
}