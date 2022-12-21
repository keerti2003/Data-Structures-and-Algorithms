#include<stdio.h>
#include<stdlib.h>

struct treenode{
	int element;
	struct treeode* right;
	struct treenode* left;
};

typedef struct treenode* bst;

bst init(int x){
	bst b;
	b = (struct treenode*)malloc(sizeof(struct treenode));
	b->element = x;
	b->right=NULL;
	b->left = NULL;
	return b;
}

bst find(int x, bst b){
	if(b==NULL){
		return NULL;
	}
	if(x<b->element){
		return find(x,b->left);
	}
	else if(x>b->element){
		return find(x,b->right);
	}
	else{
		return b;
	}
}

bst findmin(bst b){
	if(b==NULL){
		return NULL;
	}
	else{
		if(b->left == NULL){
			return b;
		}
		else{
			return findmin(b->left);
		}
	}
}

bst findmax(bst b){
	if(b==NULL){
		return NULL;
	}
	else{
		if(b->right == NULL){
			return b;
		}
		else{
			return findmax(b->right);
		}
	}
}

bst addto(bst b,int x){
	if(b==NULL){
		return init(x);
	}
	else{
		if(x<t->element){
			b->left = addto(b->left,x);
		}
		else if(x>b->element){
			b->right = addto(b->right,x);
		}
		else{
			return b;
		}
	}
	return b;
}

bst del(bst b,int x){
	bst temp;
	if(b==NULL){
		printf("code properly");
	}
	else{
		if(x<b->element){
			b->left = del(b->left,x);
		}
		else {
			if(x>b->element){
				b->right = del(b->right,x);
			}
			else{
				if(b->left && b->right){
					temp = findmin(b->right);
					b->element = temp->element;
					b->right = del(b->right,b->element);
				}
				else{
					if(b->right==NULL){
						b = b->left;
					}
				}
			}	
		}
	}
	return b;	
}

void inorder(bst b){
	if(b==NULL){
		return;
	}
	inorder (b->left);
	printf("%d",b->element);
	inorder(b->right);
}
	
int main() {
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    BST t=init(x);
    
    for(int i =0;i<n-1;i++){
        int p;
        scanf("%d",&p);
        t=addto(p,t);
        //printf("%d\n",p);
    }

    inorder(t);
    printf("\n");
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d\n",findmin(t)->val);
    printf("%d\n",findmax(t)->val);
    
    t=del(a,t);
    t=del(b,t);
    inorder(t);
	return 0;
}






