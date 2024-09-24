#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *header = NULL;
void createlist(int n)
{
    struct node *newnode, *temp;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        printf("enter data at node 1:");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        header = newnode;
        temp = newnode;
    }
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("unable to allocate memory");
        }
        else
        {
            printf("enter the data :", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
    }

    struct node *ptr = header;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void insertatstart(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("unable to allc memory");
    }
    else
    {
        newnode->data = data;
        newnode->next = header;
        header = newnode;

        printf("data inserted\n ");
    }
    struct node *current = header;
    while (current != 0)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
void insertatend(int data)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("error");
    }
    else
    {
        newnode->data = data;
        newnode->next = NULL;
        temp = header;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        printf("updated node\n");
    }
    struct node *cur = header;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
void insertanywhere(int data, int position)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("error");
    }
    else
    {
        newnode->data = data;
        newnode->next = NULL;
        temp = header;
    }
    for (int i = 2; i <= position - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            break;
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    printf("updated\n");
    struct node *r = header;
    while (r != NULL)
    {
        printf("%d\n", r->data);
        r = r->next;
    }
}

int main()
{
    int n;
    printf("enter no of nodes:");
    scanf("%d", &n);
    createlist(n);
    // insertatstart(7);
    // insertatend(99);
    insertanywhere(45, 3);

    return 0;
}
