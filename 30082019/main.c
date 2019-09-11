#include <stdio.h>
#include <stdlib.h>
#include "verb.h"

int main()
{
    struct list
    {
        int x;
        struct list *next;
    };

    /* Create the list */
    struct list *head = NULL;
    /* Just use an int for the counter. A char is just weird. */
    for (int counter = 0; counter < 6; counter++)
    {
        struct list *node = malloc(sizeof(*node));
        node->x = counter;
        node->next = head;
        head = node;
    }

    /* Destroy the list */
    while (head)
    {
        struct list *node = head;
        printf("%d\n", head->x);
        head = head->next;
        free(node);
    }
    return 0;
}