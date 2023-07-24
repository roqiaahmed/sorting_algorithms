#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->prev;
        while (temp != NULL && temp->n > current->n)
        {
            if (temp->prev != NULL)
                temp->prev->next = current;
            else
                *list = current;

            current->prev = temp->prev;
            temp->prev = current;
            temp->next = current->next;

            if (current->next != NULL)
                current->next->prev = temp;

            current->next = temp;

            print_list(*list);
            temp = current->prev;
        }
        current = current->next;
    }
}
