#include <stdio.h>

typedef struct pl{
	int v;
	struct pl * next;
} node;

int main(){
	node *head = NULL;
	head = malloc(sizeof(node));
	head->v=1;
	head->next = malloc(sizeof(node));
	head->next->v = 2;
	head->next->next = malloc(sizeof(node));
	head->next->next->v = 3;
	head->next->next->next=NULL;
	print_list(head);
	insert_node(head, 678);
	print_list(head);
	remove_l(head);
	print_list(head);
}

void print_list(node *head){
	node *cur = head;
	while (cur !=NULL){
		printf("%d ", cur->v);
		cur = cur->next;
	}
	printf("\n");
}

void insert_node(node *head, int v){
	node *cur = head;
	while(cur->next!=NULL){
		cur = cur->next;
	}

	cur->next = malloc(sizeof(node));
	cur->next->v = v;
	cur->next->next = NULL;
}

void remove_l(node *head){
	if(head->next==NULL){
		free(head);
	}

	node *cur = head;
	while(cur->next->next != NULL){
		cur = cur->next;
	}

	free(cur->next);
	cur->next = NULL;
}
