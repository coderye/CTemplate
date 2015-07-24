/*==============================================================================#
# path.h
# 
# Contributor: Chen Ye <ycchina@gmail.com>
#==============================================================================*/

#ifndef PATH_H
#define PATH_H

typedef struct Node
{
	float x, y;
	struct Node* next;
} Node, *pNode;

Node *path_init(float x, float y);
Node *path_append(float x, float y);
Node *path_head_node();
Node *path_current_node();
void path_free();

#endif /* PATH_H */
