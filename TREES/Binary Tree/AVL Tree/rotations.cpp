/*Implement a multiplayer game system that uses an AVL tree data structure to organize and
manage player data efficiently. The multiplayer game supports multiple players participating
simultaneously, and the AVL tree is used to store player information such as player_id and
scores (key, value pair). The system should provide following operation:
1. Player Registration
2. Leaderboard Display
3. Remove player from game
*/
#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int height;
    int player_id,scores;

}*root = nullptr;

int NodeHeight(struct Node *t)
{
    int hl,hr;
    if(t && t->lchild)
        hl = t->lchild->height;
    else 
        hl=0;

    if(t && t->rchild)
        hr = t->rchild->height;
    else 
        hr=0;

    if(hl>hr) return hl+1;
    else return hr+1;
}

int BalancedFactor(struct Node *t)
{
    int hl,hr;
    if(t && t->lchild)
        hl = t->lchild->height;
    else
        hl = 0;

    if(t && t->rchild)
        hr = t->rchild->height;
    else
        hr = 0;

    return hl-hr;
}

struct Node *LLrotation(struct Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;
}

struct Node *LRrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    p->height  = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}

struct Node *RRrotation(struct Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if(root == p)
        root = pr;

    return pr;
}

struct Node *RLrotation(struct Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height  = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;
}

struct Node *Insert(struct Node *t,int p,int s)
{
    Node *nnode;
    if(t==nullptr)
    {
        nnode = new Node;
        nnode->player_id = p;
        nnode->scores = s;
        nnode->height = 1;
        nnode->lchild = nnode->rchild = nullptr;

        return nnode;
    }

    if(p < t->player_id)
        t->lchild = Insert(t->lchild,p,s);
    else if(p > t->player_id)
        t->rchild = Insert(t->rchild,p,s);
    else 
        return t;

    t->height = NodeHeight(t);

    if(BalancedFactor(t) == 2 && BalancedFactor(t->lchild) == 1)
        return LLrotation(t);
    else if(BalancedFactor(t) == 2 && BalancedFactor(t->lchild) == -1)
        return LRrotation(t);
    else if(BalancedFactor(t) == -2 && BalancedFactor(t->rchild) == -1)
        return RRrotation(t);
    else if(BalancedFactor(t) == -2 && BalancedFactor(t->rchild) == 1)
        return RLrotation(t);

    return t;
}

struct Node *InPre(struct Node *p)
{
    while(p && p->rchild)
        p = InPre(p->rchild);
        
    return p;
}

struct Node *InSus(struct Node *p)
{
    while(p && p->lchild)
        p = InSus(p->lchild);

    return p;
}

struct Node *Delete(struct Node *t, int p)
{
    if (t == nullptr) return nullptr;

    if (p < t->player_id)
        t->lchild = Delete(t->lchild, p);
    else if (p > t->player_id)
        t->rchild = Delete(t->rchild, p);
    else
    {
        // Node with only one child or no child
        if (t->lchild == nullptr)
        {
            Node* temp = t->rchild;
            if (t == root) root = temp;
            delete t;
            return temp;
        }
        else if (t->rchild == nullptr)
        {
            Node* temp = t->lchild;
            if (t == root) root = temp;
            delete t;
            return temp;
        }

        // Node with two children: Get inorder predecessor or successor
        if (NodeHeight(t->lchild) > NodeHeight(t->rchild))
        {
            Node* inPre = InPre(t->lchild);
            t->player_id = inPre->player_id;
            t->scores = inPre->scores;
            t->lchild = Delete(t->lchild, inPre->player_id);
        }
        else
        {
            Node* inSuc = InSus(t->rchild);
            t->player_id = inSuc->player_id;
            t->scores = inSuc->scores;
            t->rchild = Delete(t->rchild, inSuc->player_id);
        }
    }

    t->height = NodeHeight(t);

    int bf = BalancedFactor(t);

    // Perform balancing rotations
    if (bf == 2 && BalancedFactor(t->lchild) >= 0)
        return LLrotation(t);
    else if (bf == 2 && BalancedFactor(t->lchild) == -1)
        return LRrotation(t);
    else if (bf == -2 && BalancedFactor(t->rchild) <= 0)
        return RRrotation(t);
    else if (bf == -2 && BalancedFactor(t->rchild) == 1)
        return RLrotation(t);

    return t;
}

void Inorder(struct Node *root)
{
    if(root!=nullptr)
    {
        Inorder(root->lchild);
        cout<<"\nPlayer_id : "<<root->player_id<<"\nScore : "<<root->scores;
        Inorder(root->rchild);
    }
}

int main()
{
    int choice, player_id, score;

    while (true)
    {
        cout << "\n===== Multiplayer Game Menu =====\n";
        cout << "1. Register Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Display Leaderboard\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Player ID: ";
                cin >> player_id;
                cout << "Enter Score: ";
                cin >> score;
                root = Insert(root, player_id, score);
                cout << "Player registered successfully!\n";
                break;

            case 2:
                cout << "Enter Player ID to remove: ";
                cin >> player_id;
                root = Delete(root, player_id);
                cout << "Player removed (if existed).\n";
                break;

            case 3:
                cout << "\n==== Leaderboard ====\n";
                Inorder(root);
                cout << "\n=====================\n";
                break;

            case 4:
                cout << "Exiting the game. GG!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
