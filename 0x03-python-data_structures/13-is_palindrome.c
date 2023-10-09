#include "lists.h"

/**
 * reverse_listint - function that reverse a linked list
 * @head: pointer pointing to the first node
 *
 * Return: return pointer to the first to the list 
 */
void reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *present = *head;
	listint_t *next = NULL;

	while (present)
	{
		next = present->next;
		present->next = previous;
		previous = present;
		present = next;
	}

	*head = previous;
}

/**
 * is_palindrome - function that checks if linked list is palindrome
 * @head: pointer pointing to the linked list
 *
 * Return: 1 if it is, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *temp = *head, *dup = NULL;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	while (1)
	{
		fast = fast->next->next;
		if (!fast)
		{
			dup = slow->next;
			break;
		}
		if (!fast->next)
		{
			dup = slow->next->next;
			break;
		}
		slow = slow->next;
	}

	reverse_listint(&dup);

	while (dup && temp)
	{
		if (temp->n == dup->n)
		{
			dup = dup->next;
			temp = temp->next;
		}
		else
			return (0);
	}

	if (!dup)
		return (1);

	return (0);
}
