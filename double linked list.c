//double linked list

#include<stdio.h>

struct node{
	int ele;
	struct node* prev;
	struct node * next;
};

typedef struct node* dll;

dll init(){
	dll d;
	d = (struct node*) malloc(sizeof(struct node));
	d->prev = NULL;
	d->next = NULL; //d
	d->ele = -1;
	return d;
}

dll insert(dll d,int ch,int pos){
	dll p,n;
	if(pos==0){
		d = init();
		return d;
	}
	else{
		if(pos>0){
			p = d;
			i = 0;
			while(i<pos && p!=NULL){ //p!=d
				p = p->next;
				++i;
			}
			if(p==NULL){
				printf("Invalid index");
				return d;
			}
		}
		n = init();
		n->next = p->next;
		n->prev = p;
		if(p->next==NULL){ //p->next ==d
			p->next = n;
		}
		else{
			p->next = n;
			p->next->prev = n;
		}
	}
	return d;
}


dll deletee(dll d,int pos){
	dll p,temp;
	if(pos<0){
		printf("Invalid position");
		return d;
	}
	p = d->next;
	i = 0;
	while(i<pos && p->next!=NULL){ //p->next != d
		p = p->next;
		++i;
	}
	temp = p->next;
	if(temp->next==NULL){ //temp->next == d;
		p->next = NULL; //p->next = d;
	}
	else{
		p->next = temp->next;
		temp->next->prev = p;
	}
	free(temp);
	return d;
}

int main(){
	dll d;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		insert(p,x,i);
	}
	//element position to be deleted
	int k;
	scanf("%d",&k);
	deletee(d,k)
	return 0;
}

