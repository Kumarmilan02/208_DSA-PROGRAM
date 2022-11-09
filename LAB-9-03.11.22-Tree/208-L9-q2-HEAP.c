/*WAP TO CREATE A HEAP AND TRAVERSE IT IN SPIRAP ORDER AND LEVEL ORDER.*/

#include "stdio.h"
#include "stdlib.h"
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
int x[8]={10,90,100,20,30,12,88,120};
void levelorder(struct tree *root, int i) // i show level of tree
{
    if (root == 0)
        return;
    if (i == 0)
        printf("%d ", root->data);
    else
    {
        levelorder(root->left, i - 1);
        levelorder(root->right, i - 1);
    }
}
void spiralorder(struct tree *root, int i, int f)
{
    if (root == 0)
        return;
    if (i == 0)
        printf("%d ", root->data);
    else if (f == 1)
    {
        spiralorder(root->left, i - 1, f);
        spiralorder(root->right, i - 1, f);
    }
    else
    {
        spiralorder(root->right, i - 1, f);
        spiralorder(root->left, i - 1, f);
    }
}
int height(struct tree *p)
{
    int a = 0, b = 0;
    if (p != 0)
    {
        a = 1 + height(p->left);
        b = 1 + height(p->right);
    }
    if (a > b)
        return a;
    else
        return b;
}
struct tree *heap(struct tree *p,int i)
{   
    if (i<8)
    {
        if (p == 0)
        {
            p = (struct tree *)malloc(sizeof(struct tree));
            p->left = 0;
            p->data = x[i];
            p->right = 0;
            p->left = heap(p->left, 2 * i + 1);
            p->right = heap(p->right, 2 * i + 2);
        }
        return p;
    }
}
int main()
{
    struct tree *root = NULL;
    root=heap(root,0);
    int h=height(root);
    printf("\nHeight:%d",h);
    int i,f=0;
    printf("\nlevel order: ");
    for (i = 0; i < h; i++)
    {
        levelorder(root, i);
    }
    printf("\n");
    printf("\nspiral order: ");
    for (i = 0; i < h; i++)
    {
        spiralorder(root, i, f);
        f=!f;
    }
    printf("\n");
    return 0;
}
    /*{
    int ch = 1;
    int i,f=0,n;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];
    printf("\n CREATION: ");
    for (i = 0; i < n; i++)
    {
        int num;
        printf("\n ENTER ELEMENT: ");
        scanf("%d", &num);
        root = heap(root, 0,n);
    }
    while (ch != 0)
    {
        printf("\n");
        printf("\n BINARY SEARCH TREE: ");
        printf("\n1.CREATE.\n2.Height.\n3.level. \n4.spiral \n0.EXIT");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int en;
            printf("\n Enter Element: ");
            scanf("%d", &en);
            root = heap(root,0,root);
        }
        break;
        case 2:
            printf("\nHEIGHT: ");
            int h = height(root);
            printf("\n");
            break;
        case 3:
            printf("\nlevel order: ");
            for (i = 0; i < h; i++)
            {
                levelorder(root, i);
            }
            printf("\n");
            break;
        case 4:
            printf("\nspiral order: ");
            for (i = 0; i < h; i++)
            {
                spiralorder(root, i, f);
                f=!f;
            }
            printf("\n");
            break;
        default:
            printf("\ninvalid choice.\n");
            break;
        }
    }*/