/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;
node *root = NULL;
node *Insert(int val)
{
    node *ptr = root;
    node *pr = NULL;
    while (ptr)
    {
        if (ptr->val == val)
        {
            printf("Duplicate key\n");
            return root;
        }
        pr = ptr;
        if (val < ptr->val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = NULL;
    if (pr == NULL)
    {
        root = temp;
        return root;
    }
    if (val < pr->val)
    {
        pr->left = temp;
    }
    else
    {
        pr->right = temp;
    }
    return root;
}
void search(int val)
{
    if (!root)
        printf("\nTree is empty\n");
    else
    {
        node *ptr = root;
        while (ptr)
        {
            if (ptr->val == val)
            {
                break;
            }
            if (val < ptr->val)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (ptr)
        {
            printf("\nValue %d found\n", ptr->val);
            ;
        }
        else
        {
            printf("\n value not found\n");
        }
    }
}
node *deleteleaf(node *root, node *pr, node *ptr)
{
    // root node deletion case
    if (pr == NULL)
    {
        root = NULL;
        free(ptr);
        return root;
    }
    if (ptr == pr->left)
    {
        free(ptr);
        pr->left = NULL;
    }
    else
    {
        free(ptr);
        pr->right = NULL;
    }
    return root;
}
node *deleteone(node *root, node *pr, node *ptr)
{
    node *child = NULL;
    if (ptr->left)
        child = ptr->left;
    else
        child = ptr->right;
    if (pr->left == ptr)
    {
        pr->left = child;
    }
    else
    {
        pr->right = child;
    }
    free(ptr);
    return root;
}
node *deletetwo(node *root, node *pr, node *ptr)
{
    node *prsucc = ptr;
    node *succ = ptr->right;
    while (succ->left)
    {
        prsucc = succ;
        succ = succ->left;
    }
    ptr->val = succ->val;
    if (!succ->left && !succ->right)
    {
        root = deleteleaf(root, prsucc, succ);
    }
    else if (!succ->left || !succ->right)
    {
        root = deleteone(root, prsucc, succ);
    }
    return root;
}
node *delete (int val)
{
    if (!root)
        printf("\nTree is empty\n");
    else
    {
        node *delnode = root;
        node *pr = NULL;
        while (delnode)
        {
            if (delnode->val == val)
            {
                break;
            }
            pr = delnode;
            if (val < delnode->val)
                delnode = delnode->left;
            else
                delnode = delnode->right;
        }
        if (delnode)
        {
            printf("\nValue %d found\n", delnode->val);
            // return ptr;
        }
        else
        {
            printf("\n value not found\n");
            return root;
        }

        if (!delnode->left && !delnode->right)
        {
            // Delete root node case
            root = deleteleaf(root, pr, delnode);
        }
        else if (!delnode->left || !delnode->right)
        {
            // One child exists
            root = deleteone(root, pr, delnode);
        }
        else
        {
            // Both child exist
            root = deletetwo(root, pr, delnode);
        }
    }
    return root;
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
void postorder(node *r)
{
    if (r)
    {

        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->val);
    }
}
void inorder(node *r)
{
    if (r)
    {

        inorder(r->left);
        printf("%d ", r->val);
        inorder(r->right);
    }
}

int main()
{
    printf("Hello World");
    int n;
    while (1)
    {
        printf("Enetr your choice\n1 to insert a node\n2 to delete a node\n3 to search a node\n4 to traverse a node\nYour choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter value you want to insert: ");
            scanf("%d", &n);
            root = Insert(n);
            break;
        case 2:
            printf("\nEnter value you want to delete: ");
            scanf("%d", &n);
            root = delete (n);
            break;
        case 3:
            printf("\nEnter value you want to search: ");
            scanf("%d", &n);
            search(n);
            break;
        case 4:
            printf("\n1 for preorder\n2 for postorder\n3 for inorder\nchoice: ");
            scanf("%d", &n);
            printf("Elements of tree are: ");
            switch (n)
            {
            case 1:
                preorder(root);
                break;
            case 2:
                postorder(root);
                break;
            case 3:
                inorder(root);
                break;
            default:
                printf("\nInvalid input\n");
            }

            printf("\n");
            break;
        case 5:
            exit(1);
        default:
            printf("\nInvalid input\n");
        }
    }
    return 0;
}
