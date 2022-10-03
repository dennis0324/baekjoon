#ifndef TREENODE_H
#define TREENODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "order.h"




#ifndef TREENODE_ITEM 
#define TREENODE_ITEM int
#endif

typedef int (*Compare_Function)(const void ** a, const void ** b);

typedef struct Tree_Node {
	TREENODE_ITEM data;
	struct Tree_Node* left, * right;
}TreeNode;

/**
 * @brief 이진트리 노드를 생성합니다.
 * 
 * @param data 
 * @return TreeNode* 
 */
TreeNode* addNode(TREENODE_ITEM data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = NULL;
	node->right = NULL;
	memcpy(&node->data, &data, sizeof(TREENODE_ITEM));
	return node;
}

/**
 * @brief 이진트리 노드를 추가합니다.
 * 
 * @param root 
 * @param compare_function 
 * @param data 
 */
void TreeNode_Add(TreeNode ** root,Compare_Function compare_function,TREENODE_ITEM data) {
	TreeNode* p = NULL;
	TreeNode* c = *root;

	if (c == NULL) {
		*root = addNode(data);
		return;
	}

	while (1) {
        int temp =compare_function(&(c->data),&data);
		if (compare_function(&(c->data),&data) > 0) {
			p = c;
			c = c->left;
			if (c == NULL) break;
		}
		else if (compare_function(&(c->data),&data) < 0) {
			p = c;
			c = c->right;
			if (c == NULL) break;
		}
	}

	if (compare_function(&(p->data),&data) > 0) {
		p->left = addNode(data);
	}
	else if (compare_function(&(p->data),&data) < 0) {
		p->right = addNode(data);
	}
}

/**
 * @brief 이진트리 노드를 검색합니다.
 * 
 * @param root 
 * @param compare_function 
 * @param search 
 * @return TreeNode* 
 */
TreeNode* TreeNode_Search(TreeNode * root,Compare_Function compare_function, TREENODE_ITEM search) {
	TreeNode* p = NULL;
	TreeNode* c = root;

	while (1) {
		if (compare_function(&(c->data),&search) == 0) {
			return c;
		}
		else if (compare_function(&(c->data),&search) > 0) {
			p = c;
			c = c->left;
		}
		else if (compare_function(&(c->data),&search) < 0) {
			p = c;
			c = c->right;
		}
		else {
			return NULL;
		}
	}
}

void TreeNode_Delete(TreeNode ** root,Compare_Function compare_function, TREENODE_ITEM deleteItem) {
	TreeNode* p = NULL;
	TreeNode* c = *root;

	TreeNode* child = NULL;
	TreeNode* succ_p = NULL;
	TreeNode* succ_c = NULL;

	while (c != NULL && !(compare_function(&(c->data),&deleteItem) == 0)) {
		p = c;
		c = (compare_function(&(c->data),&deleteItem) > 0) ? c->left : c->right;
	}

	if (c == NULL) {
		printf("트리에 삭제할 값이 없습니다.");
		return;
	}

	if (c->left == NULL && c->right == NULL) {
		if (p != NULL) { // 검색한 값이 root의 값이 아닐경우
			if (p->left == c) p->left = NULL;
			else p->right = NULL;
		}
		else *root = NULL;
	}
	else if (c->left == NULL || c->right == NULL) {
		child = (c->left != NULL) ? c->left : c->right;
		if (p != NULL) {
			if (p->left == c) p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {
		succ_p = c;
		succ_c = c->left;

		while (succ_c->left != NULL) {
			succ_p = succ_c;
			succ_c = succ_c->left;
		}

		if (succ_c->left == succ_c) {
			succ_p->left = succ_c->right;
		}
		else {
			succ_p->right = succ_c->left;
		}

		c->data = succ_c->data;
		c = succ_c;
	}
	free(c);
}


void free_TreeNode(TreeNode * temp){
    if(temp == NULL) return;
    free_TreeNode(temp->left);
    free_TreeNode(temp->right);
    free(temp);
}
#endif