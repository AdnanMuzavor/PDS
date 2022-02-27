/*
449. Serialize and Deserialize BST
Medium

2542

125

Add to List

Share
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.



Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
*/

#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// USING INORDER TRAVERSAL
class Codec
{
public:
    // Encodes a tree to a single string.
    string preorder(TreeNode *root)
    {
        if (!root)
        {
            return "#,";
        }
        string s = "";
        s += to_string(root->val);
        s += ",";
        s += preorder(root->left);
        s += preorder(root->right);
        return s;
    }
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        // Returns preorder traversal of BST
        string s = preorder(root);
        cout << s << endl;
        return s;
    }
    TreeNode *maketree(vector<int> res, int l, int h)
    {
        if (l > h)
            return NULL;
        TreeNode *newnode = new TreeNode(res[l]);
        if (l == h)
            return newnode;
        int mid = l + 1;
        while (mid <= h && res[mid] < res[l])
        {
            mid++;
        }
        newnode->left = maketree(res, l + 1, mid - 1);
        newnode->right = maketree(res, mid, h);
        return newnode;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        // To stop while loop we add this number at add
        data += "-10000";
        // creating strin g strem to get value by value
        stringstream s(data);
        string str;

        // Vector for storing int values
        vector<int> res;

        while (str != "-10000")
        {
            // getting elemenyt and pushing into array
            getline(s, str, ',');
            if (str != "#" && str != "-10000")
                res.push_back(stoi(str));
        }
        // inserting node using inorder traversal
        return maketree(res, 0, res.size() - 1);
    }
};

// optimised and clean soln (TC/SC SAME)
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "";
        // Getting level orer traversal
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t == NULL)
                    s += "#,";
                else
                {
                    s += to_string(t->val);
                    s += ",";
                }
                if (t)
                {
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        queue<TreeNode *> q;
        // Getting stringsteam to traverse val by val
        stringstream s(data);
        string str;
        getline(s, str, ',');
        // Getting first val in str and making it int using stoi
        TreeNode *root = new TreeNode(stoi(str));
        // Puashing in into queue
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            // Inseryting value for curr node's left
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                node->left = newnode;
                q.push(newnode);
            }
            // Inserting val for curr node's right
            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *newnode = new TreeNode(stoi(str));
                node->right = newnode;
                q.push(newnode);
            }
        }
        return root;
    }
};
