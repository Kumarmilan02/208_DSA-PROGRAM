// WAP TO REPRESENT SPARSE MATRIX USING LINKLIST.

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    int row_position;
    int column_postion;
    struct Node *next;
};

void create_new_node(struct Node **start, int non_zero_element, int row_index, int column_index)
{
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        // Create new node dynamically
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = non_zero_element;
        temp->row_position = row_index;
        temp->column_postion = column_index;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        // Create new node dynamically
        r = (struct Node *)malloc(sizeof(struct Node));
        r->value = non_zero_element;
        r->row_position = row_index;
        r->column_postion = column_index;
        r->next = NULL;
        temp->next = r;
    }
}
void PrintList(struct Node *start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;

    printf("row_position: ");
    while (temp != NULL)
    {

        printf("%d ", temp->row_position);
        temp = temp->next;
    }
    printf("\n");

    printf("column_postion: ");
    while (r != NULL)
    {
        printf("%d ", r->column_postion);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while (s != NULL)
    {
        printf("%d ", s->value);
        s = s->next;
    }
    printf("\n");
}
int main()
{
    int i, j, k = 1, r, c, nzero = 0, triplet[10][10];
    printf("Enter the number of rows and coloumns: ");
    scanf("%d%d", &r, &c);
    int sp[r][c];
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            printf("Enter the element[%d][%d]: ", i, j);
            scanf("%d", &sp[i][j]);
        }
    }
    printf("\nsparse matrix is: \n");
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            printf("%d | ", sp[i][j]);
        }
        printf("\n");
    }
    struct Node *start = NULL;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sp[i][j] != 0)
                create_new_node(&start, sp[i][j], i, j);

    PrintList(start);

    return 0;
}