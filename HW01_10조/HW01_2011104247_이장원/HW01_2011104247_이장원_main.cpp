//main.cpp

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

int main(){

	FILE* fp = NULL;		//file ������
	NODE* head = NULL;		//linked list�� ù��° ��带 ����ų ����
	NODE* tail = NULL;		//linked list�� ������ ��带 ����ų ����
	char data[25];			//���Ͽ��� ���ڿ��� �о�帮�� �ӽú���
	char* temp;				//strtok�� �̿��ϱ� ���� �ӽú���

	fp = fopen("Korean_text.txt", "r");
	if (fp == NULL)
		printf("���� �б� ����\n");
	else
		printf("���� �б� ����\n");

	fscanf(fp, "%s", data);		//ù��° ��忡 �� ���ڿ� �����͸� ���Ͽ��� �޾ƿ�.
	head = init_list(data);		//linked list �ʱ�ȭ, ù��° ��� ����
	tail = head;				//��尡 �ϳ��ۿ� �����Ƿ� 

	while (1){
		if (fscanf(fp, "%s", data) == EOF) break;		//���鹮�� �������� ������ ���ڿ� �Է�, ���� ���� �����ϸ� while�� Ż��
		if (strchr(data, ',') || strchr(data, '.')){	//�ܾ� �޺κ� �����ȣ ',' and '.' ����
			temp = strtok(data, ",.");
			strcpy(data, temp);
		}
		append_NODE(&tail, data);	//���Ͽ��� �޾ƿ� ���ڿ�(�� �ܾ�)�� �����ͷ� �Ͽ� linked list�� �������� ���ο� ��� �߰� 
	}

	print_list(head);				//linked list�� ó������ ���������� ��ȸ(travel)�ϸ� linked list�� data�� index ���

	printf("ã���� �ϴ� �ܾ �Է��Ͻÿ�. : ");
	scanf("%s", data);
	search_NODE(head, data);

	destroy_list(head);				//linked list�� ó������ ���������� ��ȸ(travel)�ϸ� linked list�� ��� ��带 ����
	fclose(fp);				
}
