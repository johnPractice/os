#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// check geeksforgeeks for more information and see how to implement Tree in C
// struct Node
// {
// 	int data;
// 	struct Node *left;
// 	struct Node *right;
// };
// void printInorder(struct Node *node)
// {
// 	if (node == NULL)
// 		return;
// 	printInorder(node->left);
// 	printf("%d ", node->data);
// 	printInorder(node->right);
// }
// int main()
// {
// 	return 0;
// }

// A O(n) C++ program to construct cartesian tree
// from a given array

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node
{
	int data;
	struct Node *left, *right;
};
struct Node *buildCartesianTree(int arr[], int n);
struct Node *utilCartezianTree(int root, int arr[],
							   int parent[], int leftchild[], int rightchild[]);
void printInorder(struct Node *node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

struct Node *buildCartesianTree(int arr[], int n)
{

	int parent[n], leftchild[n], rightchild[n];

	// Initialize all array values as -1
	memset(parent, -1, sizeof(parent));
	memset(leftchild, -1, sizeof(leftchild));
	memset(rightchild, -1, sizeof(rightchild));

	int root = 0, last;

	for (int i = 1; i <= n - 1; i++)
	{
		last = i - 1;
		rightchild[i] = -1;

		while (arr[last] <= arr[i] && last != root)
			last = parent[last];

		if (arr[last] <= arr[i])
		{
			parent[root] = i;
			leftchild[i] = root;
			root = i;
		}

		else if (rightchild[last] == -1)
		{
			rightchild[last] = i;
			parent[i] = last;
			leftchild[i] = -1;
		}

		else
		{
			parent[rightchild[last]] = i;
			leftchild[i] = rightchild[last];
			rightchild[last] = i;
			parent[i] = last;
		}
	}

	parent[root] = -1;

	return (utilCartezianTree(root, arr, parent,
							  leftchild, rightchild));
}

struct Node *utilCartezianTree(int root, int arr[],
							   int parent[], int leftchild[], int rightchild[])
{
	if (root == -1)
		return NULL;

	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = arr[root];

	temp->left = utilCartezianTree(leftchild[root],
								   arr, parent, leftchild, rightchild);
	temp->right = utilCartezianTree(rightchild[root],
									arr, parent, leftchild, rightchild);

	return temp;
}

int main()
{

	int arr[] = {3, 2, 6, 1, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	struct Node *root = buildCartesianTree(arr, n);
	printf("example 1\n");
	printInorder(root);
	printf("\n");
	int arr2[] = {3,
				  7,
				  4,
				  8};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	struct Node *root2 = buildCartesianTree(arr2, n2);
	printf("example 2\n");
	printInorder(root2);
	printf("\n");
	return (0);
}
