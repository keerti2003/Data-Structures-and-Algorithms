#include<stdio.h>
#define MAXSIZE 20

struct heapstruct{
	int cap;
	int size;
	int arr[MAXSIZE];
};

typedef heapstruct heap;

heap init(int maxelements){
	heap h;
	h.cap = maxelements;
	h.size = sizeof(arr)/sizeof(arr[0]);
	h.arr[0]=-1;
	return h;
}

/*void insert(heap h,int x){
	i = h.size;
	while (h.arr[i/2]>x){
		h.arr[i] = h.arr[i/2];
		h.size++;
		i=i/2;
	}
	h.arr[i] = x;
}*/

void insert(heap h,int x){
	for(int i=++h.size;h.arr[i/2]>x;i=i/2){
		h.arr[i]=h.arr[i/2];
	}
	h.arr[i]=x;
}

heap heapify(heap h,int lastele){
	int i=1;
	while (i<h.size){
		a = 2*i;
		b = 2*i +1;
		if(lastele<b&& lastele<a){
			h.arr[1] = lastele;
			h.size--;
			break;
		}
		else if(lastele<b && lastele>a){
			temp = b;
			b = lastele;
			lastele = temp;
			h.size--;
			break;
		}
		else if(lastele<a && lastele>b){
			temp = a;
			a = lastele;
			lastele = temp;
			h.size--;
			break;
		}
		else{
			i++;
		}
		
	}
	return h;
}

int delmin(heap h){
	int child;
	int minele,lastele;
	minele = h.arr[1];
	lastele = h.arr[size--];
	heapify(h,lastele);
}


int main(){
	heap h;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",h.arr[i]);
	}
	init(n);
	int k;
	scanf("%d",&k);
	insert(h,k);
	delmin(h);
	return 0;
}
