#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;
node *root = NULL;
node *insert(node *ptr, int val)
{
    if (ptr == NULL)
    {
        ptr = (node *)malloc(sizeof(node));
        ptr->val = val;
        ptr->left = ptr->right = NULL;
        return ptr;
    }
    if (ptr->val == val)
    {
        printf("Duplicate key\n");
        return ptr;
    }
    else if (val < ptr->val)
    {
        ptr->left = insert(ptr->left, val);
    }
    else
    {
        ptr->right = insert(ptr->right, val);
    }
    return ptr;
}
node *search(node *ptr, int val)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->val == val)
    {
        printf("Valur found\n");
        return ptr;
    }
    else if (val < ptr->val)
    {
        return search(ptr->left, val);
    }
    else
    {
        return search(ptr->right, val);
    }
}
node *del(node *ptr, int val)
{
    // printf("\n deleteing : %d\n",val);
    if (ptr == NULL)
    {
        printf("Key not found\n");
        return ptr;
    }
    else if (val < ptr->val)
    {
        ptr->left = del(ptr->left, val);
    }
    else if (val > ptr->val)
    {
        ptr->right = del(ptr->right, val);
    }
    else
    {
        //  printf("\n deleteing : %d with 2cs\n",val);
        if (ptr->left && ptr->right)
        {
            node *prsucc = ptr;
            node *succ = ptr->right;
            while (succ->left)
            {
                prsucc = succ;
                succ = succ->left;
            }
            ptr->val = succ->val;
            ptr->right = del(ptr->right, succ->val);
        }
        else
        {
            node *t = ptr;
            if (ptr->left)
            {
                ptr = ptr->left;
            }
            else if (ptr->right)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = NULL;
            }
            free(t);
        }
    }
    return ptr;
}
void preorder(node *r)
{
    if (r)
    {
        printf("%d ", r->val);
        preorder(r->left);
        preorder(r->right);
    }
}
int main()
{

    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 16);
    preorder(root);
    // node*ans=search(root,8);
    // node*ans2=search(root,18);
    // if(!ans2)printf("Val not found\n");
    printf("\n");
    printf("Deleting 8\n");
    root = del(root, 8);

    preorder(root);
    printf("\n");
    printf("Deleting 16\n");
    root = del(root, 16);
    preorder(root);
    printf("\n");
    printf("Deleting 10\n");
    root = del(root, 10);
    preorder(root);
    return 0;
}