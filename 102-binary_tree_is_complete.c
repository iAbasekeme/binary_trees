#include "binary_trees.h"
#include <stdbool.h>
/**
 * create_queue - function to create a queue
 * Return: the created queue
 */
struct Queue *create_queue()
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

	if (queue == NULL)
		return (NULL);

	queue->front = NULL;
	queue->rear =  NULL;

	return (queue);
}
/**
 * enqueue - function to enqueue to the queue
 * @queue: the queue data structure
 * @node: a pointer to the node of the binary tree
 */
void enqueue(struct Queue *queue, const binary_tree_t *node)
{
	struct QueueNode *newnode = malloc(sizeof(struct QueueNode));

	if (newnode == NULL)
	{
		return;
	}
	newnode->node = node;
	newnode->next = NULL;

	if (queue->rear != NULL)
	{
		queue->rear->next = newnode;
		queue->rear = newnode;
	}
	else
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
}

/**
 * dequeue - function to dequeue from the queue
 * @queue: queue data structure
 * Return: the dequeued node
 */
const binary_tree_t *dequeue(struct Queue *queue)
{
	struct QueueNode *temp;
	const binary_tree_t *node;

	if (queue->front == NULL)
		return (NULL);
	/*store the node front value before dequeue*/
	node = queue->front->node;

	temp = queue->front;
	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);

	return (node);
}
/**
 * free_queue - function that free the queue
 * @queue: the queue
 */
void free_queue(struct Queue *queue)
{
	struct QueueNode *temp;

	if (queue == NULL)
		return;
	while (queue->front != NULL)
	{
		temp = queue->front;
		queue->front = queue->front->next;
		if (queue->front == NULL)
			queue->rear = NULL;
		free(temp);

	}
	free(queue);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 if it's a complete BT otherwise 0
 */
int  binary_tree_is_complete(const binary_tree_t *tree)
{
	struct Queue *queue;
	bool flag = false;
	const binary_tree_t *temp;

	if (tree == NULL)
		return (0);

	/*create an empty queue*/
	queue = create_queue();
	/*enqueue the root into the queue*/
	enqueue(queue, tree);

	while (queue != NULL &&  queue->front != NULL)
	{
		temp = dequeue(queue);
		if (temp->left != NULL)
		{
			if (flag == true)
			{
				free_queue(queue);
				return (0);
			}
			enqueue(queue, temp->left);
		}
		else
			flag = true;
		if (temp->right != NULL)
		{
			if (flag == true)
			{
				free_queue(queue);
				return (0);
			}
			enqueue(queue, temp->right);
		}
		else
			flag = true;
	}
	free_queue(queue);
	return (1);
}
