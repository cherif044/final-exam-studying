// ConsoleApplication44.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node
{
    node* left, * right;
    int data;
};

class BST
{
private:
    node* roots;
public:
    BST()
    {
        roots = NULL;
    }
    node* getroot()
    {
        return roots;
    }
    node* insert(node*root,int value)
    {
        node* add = new node;
        add->data = value;
        if (root == NULL)
        {
            root = add;
            add->left = add->right = NULL;
            return add;
        }
        else
        {
            if (value < root->data)
            {
                root->left=insert(root->left, value);
            }
            else if (value > root->data)
            {
                root->right=insert(root->right, value);
            }
        }
        return root;
    }
    void insert(int value)
    {
        roots = insert(roots, value);
    }

    void display(node*r)
    {
        if (r == NULL)
            return;
        else
        {
            cout << r->data<<"\t";
            
                display(r->left);
            display(r->right);
        }
    }
    void display()
    {
        display(roots);
    }
    bool search(node* r, int value)
    {
        if (r == NULL)
        {
            return false;
        }
        else if (r->data == value)
        {
            return true;
        }
        else if (value < r->data)
        {
            return search(r->left,value);
        }
        else if (value > r->data)
        {
            return search(r->right,value);
        }
    }
    bool search(int value)
    {
        return search(roots, value);
    }
    node* min(node*r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->left == NULL)
        {
            return r;
        }
        else
        {
            return min(r->left);
                
        }
    }
    node* max(node* r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->right == NULL)
        {
            return r;
        }
        else
        {
            return max(r->right);

        }
    }
};
int main()
{
    BST x;
    x.insert(5);
    x.insert(7);
    x.insert(4);
    cout << x.min(x.getroot())->data;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
