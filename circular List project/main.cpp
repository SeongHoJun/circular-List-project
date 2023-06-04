#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;

    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head->link);
    printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL)
    {
        head = node;
        node->link = head;
    }
    else
    {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode* delete_first(ListNode* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    ListNode* removed = head->link;
    if (removed == head)
    {
        free(removed);
        return NULL;
    }

    head->link = removed->link;
    printf("First node has been deleted.\n");
    free(removed);
    return head;
}

ListNode* delete_last(ListNode* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    ListNode* prev = head;

    if (head->link == head)
    {
        free(head);
        return NULL;
    }

    ListNode* new_head = head;
    while (new_head->link != head)
    {
        new_head = new_head->link;
    }

    new_head->link = head->link;
    free(head);
    head = new_head;

    printf("Last node has been deleted.\n");
    return head;
}

int main()
{
    ListNode* head = NULL;
    int menu, num;

    while (1)
    {
        printf("***** Menu *****\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(0) Exit\n");

        printf("Enter the menu: ");
        scanf_s("%d", &menu);

        if (menu == 1)
        {
            printf("Input a number: ");
            scanf_s("%d", &num);
            head = insert_first(head, num);
        }

        else if (menu == 2)
        {
            printf("Input a number: ");
            scanf_s("%d", &num);
            head = insert_last(head, num);
        }

        else if (menu == 3)
        {
            head = delete_first(head);
        }

        else if (menu == 4)
        {
            head = delete_last(head);
        }

        else if (menu == 5)
        {
            print_list(head);
        }
        else if (menu == 0)
        {
            printf("Exit the program.\n");
            return 0;
        }
        else
        {
            printf("Invalid Menu. Please select again.\n");
        }
        printf("\n");
    }

}