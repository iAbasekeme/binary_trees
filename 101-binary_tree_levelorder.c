#include "binary_trees.h"

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
 * binary_tree_levelorder - level-order traversal function
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	struct Queue *queue;
	const  binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;


	queue = create_queue();
	/*enqueue(queue, tree);*/
	current = tree;

	while (current != NULL)
	{
		func(current->n);
		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);

		current = dequeue(queue);
	}
	free(queue);
}
