/**
 * @file order.h
 * @author your name (you@domain.com)
 * @brief 이 헤더 사용시에 반드시 타입 정의 `TREE_NODE_ITEM`과 출력 함수 포인터가 설정 반드시 필요`
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ORDER_H
#define ORDER_H

#include <stdio.h>
#include <stdlib.h>

#include "treenode.h"
#include "stack_array.h"

typedef void (*execute_function)(const TreeNode * node);

void inorderLinked_Recursive(TreeNode * temp,execute_function exe_function){
    if(temp == NULL) return;
    inorderLinked_Recursive(temp->left,exe_function);
    exe_function(temp);
    inorderLinked_Recursive(temp->right,exe_function);
}

void postorderLinked_Recursive(TreeNode * temp,execute_function exe_function){
    if(temp == NULL) return;
    postorderLinked_Recursive(temp->left,exe_function);
    postorderLinked_Recursive(temp->right,exe_function);
    exe_function(temp);

}

void preorderLinked_Recursive(TreeNode * temp,execute_function exe_function){
    if(temp == NULL) return;
    exe_function(temp);
    preorderLinked_Recursive(temp->left,exe_function);
    preorderLinked_Recursive(temp->right,exe_function);
}


void postorder_iter(TreeNode * tree,execute_function exe_function){
    TreeNode * curr = tree;
    TreeNode * prev = NULL;
    StackArray * stack = Create_AStack();

    while(curr != NULL || !is_empty_AStack(stack)){
        if(curr != NULL){
            push_AStack(stack,curr);
            curr = curr->left;
        }
        else{
            curr = peek_AStack(stack);
            if(curr->right == NULL || curr->right == prev){
                exe_function(curr);
                pop_AStack(stack);
                prev = curr;
                curr = NULL;
                
            }
            else{
                curr = curr->right;
            }
        }
    }

}


#endif