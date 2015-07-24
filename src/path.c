/*==============================================================================#
# path.c -- Path module
# 
# Contributor: Chen Ye <ycchina@gmail.com>
#==============================================================================*/

#include <stdlib.h>
#include "path.h"

static Node *path = NULL;
static Node *curr = NULL;

Node *
path_init(float x, float y)
{
	pNode ptr = (pNode)malloc(sizeof(Node));
	if (NULL == ptr)
	{
		printf("\n Path init failed \n");
		return NULL;
	}
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;

	path = curr = ptr;
	return ptr;
}

Node *
path_append(float x, float y)
{
	if (x < 0.0 || y < 0.0)
	{
		return curr;
	}

	if (NULL == path)
	{
		return path_init(x, y);
	}

	pNode ptr = (pNode)malloc(sizeof(Node));
	if (NULL == ptr)
	{
		printf("\n Path append failed \n");
		return NULL;
	}
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;

	curr->next = ptr;
	curr = ptr;
	return ptr;
}

Node *
path_head_node()
{
	return path;
}


Node *
path_current_node()
{
	return curr;
}

void
path_free()
{
	pNode ptr;
	while(path != NULL)
	{
		ptr = path;
		path = curr = path->next;
		free(ptr);
	}
}
