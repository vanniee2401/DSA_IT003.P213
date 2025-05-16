#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    int CountNode(Node *root, int n)
    {
        int count = 0;
        if (root == NULL)
            return 0;
        queue<Node *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (level == n)
            {
                count += size;
            }
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return count;
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;
    int n;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    cin >> n;

    int result = myTree.CountNode(root, n);
    cout << result;

    return 0;
}