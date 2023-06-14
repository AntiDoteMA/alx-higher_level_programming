#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half, *prev_slow = *head;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return is_palindrome;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL)
    {
        second_half = slow->next;
    }
    else
    {
        second_half = slow;
    }

    prev_slow->next = NULL;
    second_half = reverse_list(second_half);

    listint_t *p1 = *head;
    listint_t *p2 = second_half;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->n != p2->n)
        {
            is_palindrome = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    second_half = reverse_list(second_half);

    if (fast != NULL)
    {
        prev_slow->next = slow;
        slow->next = second_half;
    }
    else
    {
        prev_slow->next = second_half;
    }

    return is_palindrome;
}
