#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *right, *left;
};

struct node *insertNode(int data, struct node *root)
{
    if(root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root -> data = data;
        root -> right = root -> left = NULL;
    }
    else if( data < root-> data)
        root -> left = insertNode(data, root-> left);
    else if(data > root-> data)
        root -> right = insertNode(data, root-> right);
    return root;
}

struct node *findMin(struct node *root)
{
    while(root->left!= NULL)
    {
        root = root -> left;
    }
    return root;
}

struct node *deleteNode(struct node *root, int data)
{
    if(root == NULL)
        return root;
    if(data < root -> data)
    {   
        root -> left = deleteNode(root -> left, data);
    }
    else if(data > root -> data)
    {
        root -> right = deleteNode(root -> right, data);
    }
    else
    {
        if(root -> left == NULL) // only one child or no child
        {
            struct node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            struct node *temp = root -> left;
            free(root);
            return temp;
        }
        
        struct node *temp = findMin(root -> right);
        root -> data = temp -> data; 
        root -> right = deleteNode(root -> right,temp -> data);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main()
{
    struct node* root = NULL;
    int nodes;
    printf("Enter number of nodes:");
    scanf("%d", &nodes);
    for(int i = 0; i < nodes; i++)
    {
        int data;
        printf("Enter data :");
        scanf("%d", &data);
        root = insertNode(data, root);
    }
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    int data;
    printf("\nEnter data you want to delete :");
    scanf("%d", &data);
    root = deleteNode(root, data);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}