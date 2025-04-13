/*Consider the Dictionary Implementations which allow for efficient storage and retrieval of key-value pairs using binary 
search trees. Each node in the tree store (key, value) pair. The dictionary should support the following operations efficiently:
1. Insert word (Handle insertion of duplicate entry)
2. Delete word
3. Search specific word
4. Display dictionary (Traversal)
5. Mirror image of dictionary
6. Create a copy of dictionary
7. Display dictionary level wise
*/
#include<iostream>
using namespace std;

struct  Node
{
    struct Node *lchild;
    struct Node *rchild;
    string key,value;
} *root = nullptr;

struct Node *Rinsert(struct Node *t,string k,string v)
{
    Node *p;
    if(t==nullptr)
    {
        p = new Node;
        p->key = k;
        p->value = v;
        p->lchild = p->rchild = nullptr;

        return p;
    }

    if(k < t->key)
        t->lchild = Rinsert(t->lchild,k,v);

    else if(k > t->key)
        t->rchild = Rinsert(t->rchild,k,v);

    return t;
}

void inorder(struct Node *t)
{
    if(t!=nullptr)
    {
        inorder(t->lchild);
        cout<<"\nKey : "<<t->key<<"\nValue : "<<t->value<<endl;
        inorder(t->rchild);
    }
}

struct Node *Rsearch(struct Node *t,string k)
{
    if(t==nullptr)
        return nullptr;

    if(k==t->key)
        return t;

    if(k < t->key)
        return Rsearch(t->lchild,k);

    else if(k > t->key)
        return Rsearch(t->rchild,k);
};

int Height(struct Node *t)
{
    if(t!=nullptr)
    {
        int x = Height(t->lchild);
        int y = Height(t->rchild);

        if(x>y)
        {
            return x+1;
        }
        return y+1;
    }
    return 0;
}


struct Node *InPre(struct Node *t)
{
    while(t && t->rchild)
    {
        t = t->rchild;
    }
    return t;
};

struct Node *InSus(struct Node *t)
{
    while(t && t->lchild)
    {
        t = t->lchild;
    }
    return t;
};

struct Node *Rdelete(struct Node *t,string k)
{
    Node *p;

    if(t==nullptr)
        return nullptr;

    if(t->lchild==nullptr && t->rchild==nullptr)
    {
        if(t==root)
            root = nullptr;
        delete(t);
        return nullptr;
    }

    if(k < t->key)
        t->lchild = Rdelete(t->lchild,k);
    else if(k > t->key)
        t->rchild = Rdelete(t->rchild,k);
    else
    {
        if(Height(t->lchild)>Height(t->rchild))
        {
            p = InPre(t->lchild);
            p->key = t->key;
            p->value = t->value;
            t->lchild = Rdelete(t->lchild,p->key);
        }
        else{
            p = InSus(t->rchild);
            p->key = t->key;
            p->value = t->value;
            t->rchild = Rdelete(t->rchild,p->key);
        }
    }
    return t;
};

//COPY OF TREE
struct Node *copy(struct Node *temp)
{
    Node *nnode = NULL;
    
    if(temp != NULL)
    {
        nnode = new Node;
        nnode->key = temp->key;
        nnode->value = temp->value;
        nnode->lchild = copy(temp->lchild);
        nnode->rchild = copy(temp->rchild);
    }
    else{
        return nullptr;
    }
    return nnode;
};

//MIRROR OF TREE
struct Node *mirror(struct Node *temp)
{
    Node *nnode = NULL;
    
    if(temp != NULL)
    {
        nnode = new Node;
        nnode->key = temp->key;
        nnode->value = temp->value;
        nnode->lchild = mirror(temp->rchild);
        nnode->rchild = mirror(temp->lchild);
    }
    return nnode;
};



int main()
{
    string k = "abc";
    string v = "abc";

    root = Rinsert(root,k,v);
    
    string c = "xys";
    string d = "yellow";
   
    Rinsert(root,c,d);
    inorder(root);

    // Node *p=Rsearch(root,c);

    // if(p)
    // {
    //     cout<<"\nKey found";
    // }
    // else{
    //     cout<<"Not found";
    // }

    // Rdelete(root,k);
    Node *m = mirror(root);
    cout<<"Mirror:-\n" ;
    inorder(m);

    // Node *n = copy(root);
    // cout<<"Copy:-\n";
    // inorder(n);
}
