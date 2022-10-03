#ifndef LIST_H
#define LIST_H

/** 연결리스트 관련 구조체 선언 */
#include <stdlib.h>

typedef struct data {
	int id;
	char * name;
	int total;
}Data;

/**
 * @brief 연결리스트의 노드 구조체
 * 
 */
typedef struct node {
	Data data;
	struct node* lnk;
}Node;

/**
 * @brief 연결리스트에 관한 내용 구조체
 * 
 */
typedef struct list {
	int size;
	Node* head;
}List;

typedef int(*ComparePointer)(const void * a,const void * b);

/** list 관련 함수 원형 */

/**
 * @file list.c
 * @author dennis ko     (https://github.com/dennis0324)
 * @brief 연결리스트의 관련된 모든 함수를 저장하고 있는 소스코드입니다.
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 리스트를 생성하기 위한 함수입니다.
 * 
 * @return List* 
 */
List* CreateLink() {
	List* returnValue = (List*)malloc(sizeof(List));
	returnValue->size = 0;
	returnValue->head = NULL;
    return returnValue;
}

/**
 * @brief 연결리스트에 데이터를 추가해준다.
 * 
 * @param list 추가할 리스트
 * @param id 학번
 * @param name 이름
 * @param total 총점
 */
void addNode(List * list,int id, char * name, int total) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data.id = id;
    // 받아온 이름의 길이만큼 동적할당을 해준다.
	node->data.name = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(node->data.name,name);
    // 각 받아온 값을 구조체에 넣어준다.
	node->data.total = total;
	node->lnk = list->head;
	list->head = node;
 
	list->size++;
}
/**
 * @brief 학번 이름 총점을 출력해주는 함수이다.
 * 
 * @param head 출력하고자 하는 연결리스트를 넣는 매개변수
 */
void display(Node * head){
    Node * temp = head;
    printf("학번\t\t이름\t\t총점\n");
    printf("=========================================\n");
    while(temp != NULL){
        printf("%d\t%s\t\t%d\n",temp->data.id,temp->data.name,temp->data.total);
        temp = temp->lnk;
    }
    printf("\n");
}

/**
 * @brief 연결리스트의 마지막 노드를 반환하는 함수이다.
 * 
 * @param list 노드의 끝을 반환하고자 하는 연결리스트를 넣는 매개변수
 * @return Node* 
 */
Node * getEndList(List * list){
    Node *current  = list->head;
    while(current->lnk != NULL){
        current = current->lnk;
    }
    return current;
}

/**
 * @brief 연결리스트를 삭제하는 함수이다.
 * 
 * @param list 삭제하고자 하는 연결리스트의 매개변수
 */
void DeleteLink(List * list) {

    if(list == NULL) return;
    
	Node* temp = list->head;
	Node* remove;
	while (temp == NULL) {
		remove = temp;
		temp = temp->lnk;
        // 이름도 동적할당이 되어있기에 추가적으로 동적할당 해제를 해줘야한다.
        if(remove->data.name != NULL)
            free(remove->data.name);
		free(remove);
	}
	free(list);
}

#endif