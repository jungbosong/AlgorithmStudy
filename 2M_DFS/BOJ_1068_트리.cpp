#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value, parent;
    Node *left, *right;
};

Node* CreateNode(int value, int parent)
{
    Node* newNode = new Node();
    if(!newNode) {
        return NULL;
    }
    newNode -> value = value;
    newNode -> parent = parent;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* InsertNode(Node* root, int data, int parent)
{
    cout << "InsertNode\n";
    queue<Node*> q;
    q.push(root);

    /*while(!q.empty())
    {
        Node* tmp = q.front(); q.pop();
        
        if(tmp->left != NULL)
            q.push(tmp->left);
        else if(tmp -> value == parent) {
            tmp->left = CreateNode(data, parent);
            return root;
        }

        if(tmp->right != NULL)
            q.push(tmp->right);
        else if(tmp -> value == parent) {
            tmp->right = CreateNode(data, parent);
            return root;
        }
    }*/
}

Node* DeleteNode(Node* root, int data)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* tmp = q.front(); q.pop();
        
        if(tmp->left != NULL)
            if(tmp -> value == data) {
                tmp -> left = NULL;
                return root;
            }
            q.push(tmp->left);

        if(tmp->right != NULL)
            if(tmp -> value == data) {
                tmp -> right = NULL;
                return root;
            }
            q.push(tmp->right);
    }
}

int GetLeafNodeCnt(Node* root)
{
    int cnt = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* tmp = q.front(); q.pop();
        
        if(tmp->left != NULL)
            q.push(tmp->left);
        else
            cnt++;

        if(tmp->right != NULL)
            q.push(tmp->right);
        else
            cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N, D;
    cin >> N;

    Node* root = CreateNode(-1,-2);
    for(int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        root = InsertNode(root, i, parent);
    }

    cin >> D;
    root = DeleteNode(root, D);

    cout << GetLeafNodeCnt(root);
}