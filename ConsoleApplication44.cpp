#include <iostream>
using namespace std;
#include <algorithm>
#include <list>
#include <map>
#include <queue>
void displayList(const std::list<int>& myList) {
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    cout << std::endl;
}
class graph
{
private:
    
    map<int,list<int>> adjacency;
public:
    graph(int array[],int size)
    {
        
        for (int i = 0; i < size; i++)
        {
            list<int> temp;
            adjacency.insert(pair<int,list<int>>(array[i], temp));
        }
    }
    void addedge(int x, int y)
    {
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }

    void print_adjecency_list()
    {
        cout << "adjecency list: " << endl;
        for (const auto& pair : adjacency)
        {
            std::cout << pair.first << "  :  ";
            displayList(pair.second);
            cout << endl;
        }
    }
    
    void BFS(int x)
    {
        cout << endl;
        cout << "traversing using BFS: " << endl;
       map<int, bool> visited;
        
        vector<int> completed;
       
        
        for (const auto& pai : adjacency)
        {
     
            visited.insert(pair<int, bool>(pai.first, false));
        }
        
        queue<int>q;
        visited[x]=true;
        cout << "visited: " << x<<endl;

        q.push(x);
        int temp;
        bool v = true;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            list<int>::iterator it;
            for (it = adjacency[temp].begin(); it != adjacency[temp].end(); it++)
            {
                if (!visited[*it])
                {
                    cout << "visited: " << *it << endl;
                    q.push(*it);
                    visited[*it] = true;
                }
            }
            
            
        }
       
    }
    
    
};


int main()
{
    int array[5] = { 1,2,3,4,5 };
    graph x(array, 5);
    x.addedge(1, 2);
    x.addedge(1, 3);
    x.addedge(2, 4);
    x.addedge(2, 5);
    x.print_adjecency_list();
    cout << endl;
    x.BFS(5);


}
/*
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
    node* insert(node* root, int value)
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
                root->left = insert(root->left, value);
            }
            else if (value > root->data)
            {
                root->right = insert(root->right, value);
            }
        }
        return root;
    }
    void insert(int value)
    {
        roots = insert(roots, value);
    }

    void display(node* r)
    {
        if (r == NULL)
            return;
        else
        {
            cout << r->data << "\t";

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
            return search(r->left, value);
        }
        else if (value > r->data)
        {
            return search(r->right, value);
        }
    }
    bool search(int value)
    {
        return search(roots, value);
    }
    node* min(node* r)
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
struct element
{
    string value;
    int key;
};
class hashtable
{
private:
    element* table;
    int size;
public:
    hashtable(int siz)
    {
        size = siz;
        table = new element[size];
        for (int i = 0; i < size; i++)
        {
            table[i].value = "-1";
            table[i].key = -1;
        }
    }
    bool isfull()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].value == "-1")
                return false;
        }
        return true;

    }

    void insert(int k,string v)
    {
        element temp;
        temp.value = v;
        temp.key = k;
        if (!isfull())
        {
            int index = k%size;
            while (table[index].value != "-1")
            {
                index=(index+1) % size;
            }
            table[index] = temp;
        }
        else
        {
            cout << "table is full";
        }
    }
    bool search(int k,string v)
    {

            int index = k % size;
            while (index < size && index >= 0 && k % size!=index-1)
            {
                if (table[k%size].value == v)
                    return true;
                else if (table[k%size].value == "-1")
                    return false;
                else
                    k++;
            }

    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i<<" :  key : " << table[i].key << " value : " << table[i].value << endl;
        }

    }
};
struct element
{
    element* next;
    int value;
};
class linkedlist {
private:
    element* head, * prev, * cursor;
public:
    linkedlist()
    {
        head == NULL;
        prev == NULL;
        cursor = NULL;
    }
    bool isempty()
    {
        return (head == NULL);
    }
    bool iscursorempty()
    {
        return (cursor == NULL);
    }
    void tofirst()
    {
        cursor = head;
        prev = NULL;
    }
    bool isatfirst()
    {
        return (cursor==head)
    }
    void advance()
    {
        prev = cursor;
        cursor = cursor->next;
    }
    void toEnd()
    {
        if(!isempty())
        while (cursor->next != NULL)
        {
            advance();
        }
    }
    bool atEnd()
    {
        return cursor->next == NULL;
    }
    int getlistsize()
    {
        element* temp = head;
        int count=0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void update_cursor(int v)
    {
        cursor->value = v;
    }
    void retrieve(int v)
    {
        v = cursor->value;
    }
    void insert_head(int v)
    {
        element* add;
        add->value = v;
        add->next = head;
        head = add;
        cursor = add;
        prev = NULL;
    }
    void insert_after_cursor(int v)
    {
        element* add;
        add->value = v;
        if (atEnd())
        {
            cursor->next = add;
            add->next = NULL;
        }
        else
        {
            add->next = cursor->next;
            cursor->next = add;

        }
    }
    void insert_before_cursor(int v)
    {
        element* add;
        add->value = v;

        if (isatfirst())
        {
            add->next = cursor;
            head = add;
            cursor = add;
            prev = NULL;
        }
        else
        {
            add->next = cursor;
            prev->next = add;
            cursor = add;
        }
    }
    void insert_end(int v)
    {
        toEnd();
        element* add;
        add->value = v;
        cursor->next = add;
        prev = cursor;
        cursor = add;
        add->next = NULL;
    }
    void delete_cursor()
    {
        element* q = cursor;
        if (!iscursorempty())
        {
            if (isatfirst())
            {

                head = cursor->next;
                cursor = head;
                prev = NULL;
                delete q;
            }
            else if(atEnd())
            {
                prev->next = NULL;
                cursor = NULL;
                delete q;
            }
            else
            {
                prev->next = cursor->next;
                cursor = cursor->next;
                delete q;
            }
        }

    }
    void deletehead()
    {
        if (!isempty())
        {
            tofirst();
            delete_cursor();
        }
    }
    void deleteEnd()
    {
        if (!isempty()) { toEnd(); delete_cursor(); }
    }
    void makelistempty()
    {
        tofirst();
        while (!isempty())
        {
            delete_cursor();
        }
    }
    bool search(int v)
    {
        element* temp = head;
        bool found = false;
        if (!isempty())
        {
            while (temp->next != NULL )
            {
                if (temp->value == v)
                {
                    found = true;
                    cursor = temp;
                }
                temp = temp->next;

            }
        }
        return found;
    }
    void (int v)
    {
        tofirst();
        while ((cursor != NULL) && (v > cursor->value))
        {
            advance();
        }
        insert_before_cursor(v);

    }
    void display()
    {
        tofirst();
        while (cursor != NULL)
        {
            cout << cursor->value << endl;
            advance();
        }
    }
    void rotate(int count)
    {
        element* end,*kth;
        end = head;
        kth = head;
        int temp = 1;
        while (end->next != NULL)
        {
            end = end->next;
        }
        while (temp < count && kth->next != NULL)
        {
            kth = kth->next;
            temp++;
        }
        end->next = head;
        head = kth->next;
        kth->next = NULL;

    }
    void reverse()
    {
        element* current = head;
        element* previous = NULL;
        element* next = head->next;
        element* temp;
        while (current != NULL)
        {
            temp = current->next;
            current->next = previous;
            temp->next = current;
        }

    }

};
void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}
int partition(int array[], int start, int end)
{
    int pindex = start;
    int pivot = array[end];
    for (int i = start; i < end; i++)
    {
        if (array[i] < pivot)
        {
            swap(array[pindex], array[i]);
            pindex++;
        }
    }
    swap(array[pindex], array[end]);
}
quick_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int pindex = partition(array, start, end);
        quick_sort(array, start, pindex);
        quick_sort(array, pindex + 1, end);

    }
}
void merge_sort(int array[], int start,int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        merge_sort(array, start, middle);
        merge_sort(array, middle+1, end);
        merge(array, start, middle, end);
    }
}
void merge(int array, int start, int middle, int end)
{
    int i = start;
    int j = middle + 1;
    int k = start;
    int* temp = new int[end-start];
    while (i <= middle && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
    }
    while (i <= middle)
    {
        temp[k] = array[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = array[j];
        k++;
        j++;
    }
    for (int j = start, j <= end; j++)
    {
        array[j] = temp[j];
    }
}
void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int it = i - 1;
        while (it >= 0 && temp < array[it])
        {
            array[it + 1] = array[it];
            it--;
        }
        array[it + 1] = temp;
    }
}
*/
