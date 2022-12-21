#include<stdio.h>
#include<stdlib.h>

struct node{
	int ele;
	struct node* next;
};

typedef struct node* llist;

llist init(){
	llist L;
	L = (struct node*)malloc(sizeof(struct node));
	L->ele = -1;
	L->next = NULL;
	//L->next = L;    circular linkedlist
	return L; 
}

llist insert(llist L,int ch,int pos){
	int i;
	llist p,n;
	if(pos<0){
		printf("Invalid position");
		return L;
	}
	p = L;
	i=0;
	while((i<pos) && (p!=NULL)){ //traversing through linked list  //circular linkedlist p!=L
		p = p->next;
		++i;
	}
	if(p==NULL){
		printf("Invalid index");
		return L;
	}
	n = init();
	n->element = ch;
	n->next = p->next;
	p->next = n;
	return L;
}

llist dlt(llist L,int pos){
	int i;
	llist p,temp;
	if(pos<0){
		printf("Invalid position");
		return L;
	}
	p = L;
	i=0;
	while((i<pos) && (p->next!=NULL)){ //traversing through linked list
		p = p->next;
		++i;
	}
	if(p->next==NULL){
		printf("Invalid index");
		return L;
	}
	temp = p->next;
	p->next = temp->next;
	free(temp);
}

llist find(llist L,int ch){
	llist p;
	p=L->next;
	while (p!=NULL){
		if(p->ele==ch){
			return p;
		}
		p=p->next;
	}
	return NULL;
}

int findkth(llist L, int pos){
	llist p;
	if(pos<0){
		printf("Invalid position");
	}
	p = L->next;
	i=0;
	while((i<pos)&&(p!=NULL)){
		p = p->next;
		++i;
	}
	if(p==NULL){
		printf("Invalid index");
		return -1;
	}
	return p->element;
}

void printlist(llist L){
	llist p;
	p = L->next;
	while(p!=NULL){
		printf("%d",p->ele);
		p = p->next;
	}
}

llist sort(llist L){
	llist temp;
	int t;
	while(L!=NULL){
		temp = L->next;
		while(temp!=NULL){
			while(temp->ele>L->ele){
				t = temp->ele;
				temp->ele = L->ele;
				L->ele = t;
			}
			temp = temp->ele;
		}
		L = L->ele;
	}
	return L;
}
