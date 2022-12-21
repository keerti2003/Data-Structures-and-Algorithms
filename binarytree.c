#include<stdio.h>

void insert(char arr[],int n,char x){
	arr[n] = x;
}

void del(char arr[],int n,char y){
	int i;
	printf("Item to be deleted: %c",y);
	for(i=0;i<n;i++){
		if (arr[i]==y){
			arr[i] = NULL;
		}
	}
}

int get_left_child(int index,int n,char arr[]){
	int z = 2*index;
	if (arr[index]!=NULL && arr[z]!=NULL && z<=n){
		return z;
	}
	else{
		return -1;
	}
}

int get_right_child(int index,int n,char arr[]){
	int z = (2*index)+1;
	if (arr[index]!=NULL && arr[z]!=NULL && z<=n){
		return z;
	}
	else{
		return -1;
	}
}

int parent(int index,int n,char arr[]){
	int z = index/2;
	if (arr[index]!=NULL && arr[z]!=NULL){
		return z;
	}
	else{
		return -1;
	}
}

void preorder(char arr[], int index, int n){
	if(index>=0 && arr[index]!=NULL){
		printf("%c",arr[index]);
		preorder(arr,get_left_child(index,n,arr),n);
		preorder(arr,get_right_child(index,n,arr),n);
	}
}

void postorder(char arr[], int index, int n){
	if(index>=0 && arr[index]!=NULL){
		postorder(arr,get_left_child(index,n,arr),n);
		postorder(arr,get_right_child(index,n,arr),n);
		printf("%c",arr[index]);
	}
}

void inorder(char arr[], int index, int n){
	if(index>=0 && arr[index]!=NULL){
		inorder(arr,get_left_child(index,n,arr),n);
		printf("%c",arr[index]);
		inorder(arr,get_right_child(index,n,arr),n);
	}
}

int main(){
	int i,n,choice, flag = 1;
	char arr[50];
	scanf("%d",&n);
	n = n+1;
	for(i=1;i<n;i++){
		scanf("%s",&arr[i]);
	}
	int option;
	while (flag == 1){
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Element to be added : ");
				char a;
                scanf("%s",&a);
                insert(arr, ++n, a);
                break;
            case 2:
                printf("Element to be deleted: ");
                char b;
                scanf("%s",&b);
                del(arr,n,b);
                break;
            case 3:
                preorder(arr,1,n);
                printf("\n");
                break;
            case 4:
                postorder(arr,1,n);
                printf("\n");
                break;
            case 5:
                inorder(arr,1,n);
                printf("\n");
                break;
        }
        printf("Do you want to continue? : ");
        scanf("%d",&flag);
    }
}
