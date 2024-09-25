#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void createlist(int n)
{
    struct node *newnode, *temp;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("unable allc memo");
    }
    else
    {
        printf("enter data for node 1\n");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        head = newnode;
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
}
void deletefront()
{
    struct node *delete;
    delete = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("unalbe to allc memo\n");
    }
    else
    {
        delete = head;
        head = head->next;

        free(delete);
    }
    printf("updated\n");
    struct node *cur = head;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
void deleteend()
{
    struct node *delete, *secondlastnode;
    delete = head;
    secondlastnode = head;
    while (delete->next != NULL)
    {
        secondlastnode = delete;
        delete = delete->next;
    }
    if (delete == head)
    {
        head == NULL;
    }
    else
    {
        secondlastnode->next = NULL;
    }
    free(delete);
    printf("udated:\n");
    struct node *r = head;
    while (r != NULL)
    {
        printf("%d\n", r->data);
        r = r->next;
    }
}
void deleteanywhere(int position)
{
    struct node *prevnode, *delete;
    if (head == NULL)
    {
        printf("list empty");
    }
    else
    {
        delete = head;
        prevnode = head;
        for (int i = 2; i <= position; i++)
        {
            prevnode = delete;
            delete = delete->next;
            if (delete == NULL)
            {
                break;
            }
        }

        prevnode->next = delete->next;
        delete->next = NULL;
        free(delete);
    }

    printf("updated1\n");
    struct node *current = head;
    while (current != 0)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{

    int n;

    printf("enter no of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    // deletefront();
    // deleteend();
    deleteanywhere(3);
}
