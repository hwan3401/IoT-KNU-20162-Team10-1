//header.h

typedef struct NODE{		//NODE ����ü
	char data[25];			//25byte ũ�⸦ ������ data �������, text���Ͽ��� �о�帰 �ܾ �����Ѵ�.
	int index;				//�� ��° ��������� �����ϴ� index �������
	struct NODE* next_link;	//���� ��带 ����ų �������
}NODE;

NODE* init_list(char* data);

void append_NODE(NODE** tail, char* data);

void print_list(NODE* head);

void destroy_list(NODE* head);

int search_NODE(NODE* head, char* search_data);