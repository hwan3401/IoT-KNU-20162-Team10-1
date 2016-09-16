//linked_list.cpp

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

NODE* init_list(char* data){	//creat linked list
	NODE* head = NULL;			
	head = (NODE*)malloc(sizeof(NODE));		//ù��° ����� �޸� ������ �Ҵ� �޴´�.
	if (head == NULL){			//���� ó��
		printf("���� �޸� �Ҵ� ����\n");
	}
	strcpy(head->data, data);	//ù��° ����� ���ڿ� data�� �����Ѵ�.
	head->index = 1;			//ù��° ����̹Ƿ� index�� 1�� �����Ѵ�.
	head->next_link = NULL;		//���� ���� ���� �����Ƿ� ���� ��� link�� NULL�� �����Ѵ�.
	return head;
}

//linked list�� ���� ����Ű�� tail�� �Լ����� �����ؾ��ϹǷ� ���� ������ ���
void append_NODE(NODE** tail, char* data){	//linked list�� �������� ��带 �߰�
	NODE* new_NODE = NULL;
	new_NODE = (NODE*)malloc(sizeof(NODE));		//���ο� ��忡 ���� ���� �޸� �Ҵ�
	if (new_NODE == NULL){						//���� ó��
		printf("���� �޸� �Ҵ� ����\n");
	}
	(*tail)->next_link = new_NODE;				//���� ������ ����� ���� linked ��带 ���� ���� ���� ����
	strcpy(new_NODE->data, data);				//�Լ��� �μ��� ���� data�� ���ο� ����� data�� copy 
	new_NODE->index = ((*tail)->index) + 1;		//���ο� ����� index�� �� ����� index���� 1 ũ�� ����
	new_NODE->next_link = NULL;					//���� ���� ����� ���� ��带 ����Ű�� �����͸� NULL�� ����
	(*tail) = new_NODE;							//linked list�� ������ ���(tail)�� ���� ���� ���� ����
}

void print_list(NODE* head){			//linked list�� head���� ��ȸ�ϸ� �� ����� data�� index�� print
	NODE* current = head;				//���� ��带 head��
	while (1){							
		printf("data : %-25s   index : %d\n", current->data, current->index);	//���� ����� data, index�� print
		current = current->next_link;		//���� ��带 ���� ����
		if (current == NULL) break;			//���� ����� link�� NULL�� ����Ű�� ������ while���� Ż���ϰ� �Լ��� ������.
	}
}

void destroy_list(NODE* head){			//linked list�� head���� ��ȸ�ϸ� �� ����� �޸𸮸� OS�� �ݳ�
	NODE* current = head;				//���� ��带 head��
	NODE* next = current->next_link;	//���� ��带 head�� ���� ����
	while (1){
		free(current);					//���� ��带 �ݳ�
		current = next;					//���� ��带 ���� ���� ����
		next = current->next_link;		//���� ��带 �ٴ��� ���� ����
		if (next == NULL){		//���� ��尡 ���ٸ�, �� ���� ������ �����
			free(current);		//���� ��带 �ݳ��ϰ� while�� Ż���ϰ� �Լ��� ����.
			break;
		}
	}
}

//head���� ��ȸ�ϸ� �μ� search_data�� ���� ���ڿ��� ���� ��带 ���� Ž���Ѵ�.
int search_NODE(NODE* head, char* search_data){		
	NODE* current = head;		//���� ��带 head��
	int counting = 0;			//ã���� ��带 counting�ϴ� ����, 0 ���� �ʱ�ȭ
	while (1){
		if (strcmp(current->data, search_data) == 0){	//���� ����� data���ڿ��� �μ� search_data���ڿ��� ���� ���
			printf("finded index : %d\n", current->index);	//���� ����� �ε����� ����Ѵ�.
			counting++;										//counting������ 1���� ��Ų��.
		}
		current = current->next_link;					//���� ��带 ��������
		if (current == NULL) break;						//���� ���� ��尡 NULL�̶�� while���� Ż���Ѵ�.
	}
	printf("counting : %d\n", counting);				//��� ��带 ��ȸ�����Ƿ� ã���� ����� ������ ����Ѵ�.
	return counting;
}
