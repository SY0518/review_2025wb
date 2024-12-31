#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 6, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n2, &n1 };
TreeNode n4 = { 4, NULL, NULL };
TreeNode n5 = { 2, &n4, NULL };
TreeNode n6 = { 1, &n5, &n3 };

TreeNode* root = &n6;

void print_level(TreeNode* r);

int main(void)
{
	print_level(root);
	return 0;
}

void print_level(TreeNode* r)
{
	TreeNode* level[10] = { NULL };
	TreeNode* node;
	int front, rear;
	int level_size;
	int i;
	front = 0;
	rear = 0;

	level[rear++] = r;

	while (front < rear) {
		level_size = rear - front;

		for (i = 0; i < level_size; i++) {
			node = level[front++];
			printf("%d ", node->data);

			if (node->left != NULL)
				level[rear++] = node->left;
			if (node->right != NULL)
				level[rear++] = node->right;
		}
		printf("\n");
	}

	return;
}