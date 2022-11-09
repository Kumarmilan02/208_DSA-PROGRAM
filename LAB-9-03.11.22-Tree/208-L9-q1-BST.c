/*BST->CREATE,INSERT,DISPLAY,TRAVERSAL,SEARCH,DELETE,HEIGHT,MINIMUM,MAXIMUM,COUNT NODE*/
/*TRAVERSAL: INORDER,PREORDER,POSTORDER,LEVELORDER,SPIRALORDER*/

#include "stdio.h"
#include "stdlib.h"
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
int preorder(struct node *root) // NLR
{
    if (root != 0)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int inorder(struct node *root) // LNR
{
    if (root != 0)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int postorder(struct node *root) // LRN
{
    if (root != 0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int levelorder(struct node *root)
{
    struct node *q[100];
    int size=0;
    int qptr=0;
    while(root)
    {
        printf("%d ",root->data);
        if(root->left)
        {
            q[size++]=root->left;
        }
        if(root->right)
        {
            q[size++]=root->right;
        }
        root=q[qptr++];
    }
}
int printGivenLevel(struct node *root,int level,int ltr)
{
    if(root==NULL)
        return;
    if(level == 1)
        printf("%d ",root->data);
    else if(level > 1)
    {
        if(ltr)
        {
            printGivenLevel(root->left,level-1,ltr);
            printGivenLevel(root->right,level-1,ltr);
        }
        else
        {
            printGivenLevel(root->right,level-1,ltr);
            printGivenLevel(root->left,level-1,ltr);
        }
    }
}
int spiralorder(struct node *root)
{
    int h=height(root);
    int i,ltr=0; //ltr used to change printing order of levels.
    for(i=1;i<=h;i++)
    {
        printGivenLevel(root,i,ltr);
        ltr!=ltr;
    }
}
int height(struct node *root) // FIND HEIGHT OF BST
{
    int lh,rh;
    if (root == 0)
        return 0;
    else
    {
        lh = height(root->left);
        rh = height(root->right);
    }
    if (lh > rh)
        return (lh+1);
    else
        return (rh+1);
}
int countnode(struct node *root)
{
    if(root==0)
        return (0);
    else
    {
        if(root->left ==0 && root->right ==0)
            return(1);
        else
            return(1+(countnode(root->left)+countnode(root->right)));
    }
}
struct node *minimumT(struct node *root)
{
    // recursive
    struct node *p = root;
    if (p == NULL)
        return NULL;
    else if (p->left == NULL)
        return p;
    else
        return minimumT(p->left);
    /* non recursive
    if(!p)
        return NULL;
    while(p->left!=NULL)
    {
        p=p->right;
    }
    printf("\nMAXIMUM ELEMENT IN BST: %d",p->data);
    */
}
struct node *maximumT(struct node *root)
{
    struct node *q = root;
    // recursive
    if (q == NULL)
        return NULL;
    else if (q->right == NULL)
        return q;
    else
        return maximumT(q->right);
    /*nonrecursive
    if(!q)
        return NULL;
    while(q->right!=NULL)
    {
        q=q->right;
    }
    printf("\nMAXIMUM ELEMENT IN BST: %d",q->data);*/
}
void display(struct node *root, int level)
{
    int i;
    if (root == NULL)
        return;
    else
    {
        display(root->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("  ");
        printf("%d", root->data);
        display(root->left, level + 1);
    }
}
struct node *bst(struct node *root, int n) // CREATION OF BST AND INSERATION
{
    if (root == 0)
    {
        root = malloc(sizeof(struct node));
        root->data = n;
        root->left = 0;
        root->right = 0;
    }
    else if (n > root->data)
        root->right = bst(root->right, n);
    else
        root->left = bst(root->left, n);
    return root;
}
struct node *search(struct node *root, int key) // SEARCHING OPERATION IN BST
{
    if (!root)
    {
        return NULL;
    }
    if (key == root->data)
    {   
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
struct node *delete (struct node *root, int n) // DELETE OPERATION IN BST
{
    struct node *curr = root;
    struct node *prev = NULL;
    while (curr != NULL && curr->data != n) // check if data is actually present in bst or not.
    {                                       // the variables prev points to the parent of the key to be deleted.
        prev = curr;
        if (n < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr == NULL)
    {
        printf("\nvalue %d  not found in the provided BST.\n", root->data);
        return root;
    }
    if (curr->left == NULL || curr->right == NULL) // case 1:node to be deleted atmost one child
    {
        struct node *newcurr;
        if (curr->left == NULL) // left child is absent
            newcurr = curr->right;
        else
            newcurr = curr->left;

        if (prev == NULL) // node to be deleted is root
            return newcurr;

        if (curr == prev->left)
            prev->left = newcurr;
        else
            prev->right = newcurr;
        free(curr);
    }
    else // has two children
    {
        struct node *s = NULL;
        struct node *temp;
        temp = curr->right; // inorder successor/minimum of rights of tree
        while (temp->left != NULL)
        {
            s = temp;
            temp = temp->left;
        }
        if (s != NULL)
            s->left = temp->right;
        else
            curr->right = temp->right; // inorder predeccessor

        curr->data = temp->data;
        free(temp);
    }
    return root;
}
int main()
{
    struct node *ptr = NULL, *s;
    int ch = 1;
    int i = 0, n;
    /*printf("\nEnter size: ");
    scanf("%d",&n);
    printf("\n CREATION: ");
    for(i=0;i<n;i++)
    {
        int num;
        printf("\n ENTER ELEMENT: ");
        scanf("%d",&num);
        ptr=bst(ptr,num);

    }*/
    while (ch != 0)
    {
        printf("\n");
        printf("\nBINARY SEARCH TREE: ");
        printf("\n1.CREATE.");
        printf("\n2.DISPLAY");
        printf("\n3.HEIGHT");
        printf("\n4.PREORDER.");
        printf("\n5.INORDER.");
        printf("\n6.POSTORDER");
        printf("\n7.DELETE");
        printf("\n8.SEARCH");
        printf("\n9.MINIMUM");
        printf("\n10.MAXIMUM");
        printf("\n11.COUNT NODE");
        printf("\n12.LEVELORDER");
        printf("\n13.SPIRALORDER");
        printf("\n0.EXIT");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int en;
            printf("\n Enter Element: ");
            scanf("%d", &en);
            ptr = bst(ptr, en);
        }
        break;
        case 2:
            printf("\n");
            display(ptr, 0);
            printf("\n");
            break;
        case 3:
            printf("\nHEIGHT of TREE: %d\n", height(ptr));
            break;
        case 4:
            printf("\nPREORDER: ");
            preorder(ptr);
            printf("\n");
            break;
        case 5:
            printf("\nINORDER: ");
            inorder(ptr);
            printf("\n");
            break;
        case 6:
            printf("\nPOSTORDER: ");
            postorder(ptr);
            printf("\n");
            break;
        case 7:
            int a;
            printf("\nEnter data to delete: ");
            scanf("%d", &a);
            ptr = delete (ptr, a);
            display(ptr,0);
            printf("\n\nINORDER: ");
            inorder(ptr);
            printf("\n");
            break;
        case 8:
            int b;
            printf("\nEnter element to search: ");
            scanf("%d", &b);
            ptr = search(ptr, b);
            if (ptr != 0)
                printf("%d is in BST.", b);
            else
                printf("%d is absent in BST.", b);
            break;
        case 9:
            s = minimumT(ptr);
            if (s != NULL)
                printf("\nMINIMUM: %d", s->data);
            printf("\n");
            break;
        case 10:
            s = maximumT(ptr);
            if (s != NULL)
                printf("\nMAXIMUM: %d", s->data);
            printf("\n");
            break;
        case 11:
            printf("\nTOTAL NODE: %d",countnode(ptr));
            printf("\n");
            break;
        case 12:
            printf("\nLEVELORDER: ");
            levelorder(ptr);
            printf("\n");
            break;
        case 13:
            printf("\nSPIRALORDER: ");
            spiralorder(ptr);
            printf("\n");
            break;
        default:
            printf("\ninvalid choice.\n");
            break;
        }
    }
    return 0;
}