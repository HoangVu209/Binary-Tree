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
        pleft = pright = NULL;
    }
};

void insert(node *root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        if(q.front()->pleft == NULL)
        {
            q.front()->pleft = new node(data);
            return;
        }
        if(q.front()->pright == NULL)
        {
            q.front()->pright = new node(data);
            return;
        }
        
        q.push(q.front()->pleft);
        q.push(q.front()->pright);
        q.pop();
    }
}
bool deleteNode(node *root, int data)
{
    if(root == NULL)
        return false;
    node *pre = root;
    queue<node *> q;
    q.push(root);
    if(root->data == data)
    {
        node *run = root->pright;
        if(run == NULL)
        {
            node *temp = root;
            root = root->pleft;
            delete temp;
            return true;
        }
        if(run->pright == NULL)
        {
            node *temp = root;
            root->data = run->data;
            root->pright = run->pleft;
            delete run;

            return true;
        }
        while(run->pright->pright != NULL)
        {
            run = run->pright;
        }
        node *temp = run->pright;
        cout << temp->data;
        run->pright = temp->pleft;
        root->data = temp->data;
        delete temp;
        return true;
    }
    while(!q.empty())
    {
        if(q.front()->pleft != NULL)
        {
            if(q.front()->pleft->data == data)
            {
                node *run = q.front();
                node *temp = q.front()->pleft;
                if(run->pright == NULL)
                {
                    run->pright = temp->pright;
                    run->pleft = temp->pleft;
                    delete temp;
                    return true;
                }
                while(run->pright->pright != NULL)
                {
                    run = run->pright;
                }
                node *temp1 = run->pright;
                run->pright = temp1->pleft;
                temp->data = temp1->data;
                delete temp1;
                return true;
            }
        }
        if(q.front()->pright != NULL)
        {
            if(q.front()->pright->data == data)
            {
                node *run = q.front();
                node *temp = q.front()->pright;
                if(temp->pright == NULL)
                {
                    run->pright = temp->pleft;
                    delete temp;
                    return true;
                }
                while(run->pright->pright != NULL)
                {
                    run = run->pright;
                }
                node *temp1 = run->pright;
                run->pright = temp1->pleft;
                temp->data = temp1->data;
                delete temp1;

                return true;
        
            }
        }
        pre = q.front();
        q.pop();
        if(pre->pleft != NULL)
            q.push(pre->pleft);
        if(pre->pright != NULL)
            q.push(pre->pright);
        
    }
    return false;
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
    print2DUtil(root, 0);
}

int main()
{
    node *root = new node(1);

    for(int i = 2; i < 10; i++)
        insert(root, i);

    
    
    deleteNode(root, 8);
    deleteNode(root, 7);
    deleteNode(root, 2);
    deleteNode(root, 9);
    deleteNode(root, 1);
    deleteNode(root, 5);
    deleteNode(root, 3);
    print2D(root);
    return 0;
}