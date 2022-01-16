/*
#include<iostream>
#include<queue>
using namespace std;
#define COUNT 10

struct node
{
    int data;
    node *pleft;
    node *pright;
    node(int data)
    {
        this->data = data;
        this->pleft = this->pright = NULL;
    }
};

void insert(node *proot, int data)
{
    if(proot == NULL)
    {
        proot = new node(data);
        return;
    }
    queue<node*> root;
    root.push(proot);
    while(!root.empty())
    {
        if(root.front()->pleft == NULL)
        {
            root.front()->pleft = new node(data);
            return; 
        }
        if(root.front()->pright == NULL)
        {
            root.front()->pright = new node(data);
            return;
        }
        if(root.front()->pleft != NULL)
            root.push(root.front()->pleft);
        if(root.front()->pright != NULL)
        root.push(root.front()->pright);
        root.pop();
    }
}
void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->pright, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    print2DUtil(root->pleft, space);
}
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
void print(node *proot)
{
    queue<node *>root;
    root.push(proot);
    cout << proot->data << endl;
    while(!root.empty())
    {
        if(root.front()->pleft != NULL)
            cout << root.front()->pleft->data << " ";
        if(root.front()->pright != NULL)
            cout << root.front()->pright->data << " " << endl;
        if(root.front()->pleft != NULL)
            root.push(root.front()->pleft);
        if(root.front()->pright != NULL)
        root.push(root.front()->pright);
        root.pop();
    }
}
int main()
{
    node *proot = new node(10);

    // Insert 
    /*
    for(int i = 2; i < 11; i++)
    {
        insert(proot, i);
    }
    
    proot->pleft = new node(11);
    proot->pleft->pleft = new node(7);
    proot->pright = new node(9);
    proot->pright->pleft = new node(15);
    proot->pright->pright = new node(8);
    cout << "Before insertion: \n";
    print2D(proot);
    insert(proot, 12);
    cout << "After insertion: \n";
    print2D(proot);

    return 0;
}
*/