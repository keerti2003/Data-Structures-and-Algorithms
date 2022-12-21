#include<stdio.h>

void bubble_sort_start(int a[], int n, int o) {
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        if(o == 0) {
            for(j=i; j<n; j++) {
                if(a[i] < a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        } else {
            for(j=i; j<n; j++) {
                if(a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printarray(a, 0, n);
    }
}

void bubble_sort_end(int a[], int n, int o) {
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        if(o == 0) {
            for(j=0; j<n-i-1; j++) {
                if(a[j] < a[j+1]) {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        } else {
            for(j=0; j<n-i-1; j++) {
                if(a[j] > a[j+1]) {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        printarray(a, 0, n);
    }
}

void insertion_sort(int a[], int n, int o) {
    int i, j, temp;
    for(i=1; i<n; i++) {
        temp = a[i];
        j = i-1;
        if(o == 0) {
            while(j > 0 && a[i] < a[j]) {
                a[j+1] = a[j];
                j--;
            }
        } else {
            while(j > 0 && a[i] > a[j]) {
                a[j+1] = a[j];
                j--;
            }
        }
        a[j+1] = temp;
        printarray(a, 0, n);
    }
}

void selection_sort(int a[], int n, int o) {
    int i, j, min, temp;
    for(i=0; i<n; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(o == 0) {
                if(a[min] > a[j]) {
                    min = j;
                }
            } else {
                if(a[min] < a[j]) {
                    min = j;
                }
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        printarray(a, 0, n);
    }
}

void merge(int a[], int st, int mid, int end, int o) {
    int l1 = mid - st + 1;
    int r1 = end - mid;
    int Left[l1], Right[r1], i;
    for(i=0; i<l1; i++) {
        Left[i] = a[st+i];
    }
    for(i=0; i<r1; i++) {
        Right[i] = a[mid+1+i];
    }
    i=0;
    int j=0, k=st;
    while(i<l1 && j<r1) {
        if(o == 0) {
            if(Left[i] <= Right[j]) {
                a[k] = Left[i];
                i++;
            } else {
                a[k] = Right[j];
                j++;
            }
            k++;
        } else {
            if(Left[i] >= Right[j]) {
                a[k] = Left[i];
                i++;
            } else {
                a[k] = Right[j];
                j++;
            }
            k++;
        }
    }
    while(i < l1) {
        a[k] = Left[i];
        i++; k++;
    }
    while(j < r1) {
        a[k] = Right[j];
        j++; k++;
    }
}

void merge_sort(int a[], int l, int r, int o) {
    if(l < r) {
        int m = (l + r)/2;
        merge_sort(a, l, m, o);
        merge_sort(a, m+1, r, o);
        merge(a, l, m, r, o);
    }
    printarray(a, l, r);
}

int partition(int arr[], int l, int r, int o) {	
    int pivot = arr[l];
    int lt = l, rt = r;
    while(lt < rt) {
        if(o == 0) {
            while(arr[lt] <= pivot) {
                lt++;
            }
            while(arr[rt] > pivot) {
                rt--;
            }
        } else {
            while(arr[lt] <= pivot) {
                lt++;
            }
            while(arr[rt] > pivot) {
                rt--;
            }
        }
        if(lt < rt) {
            int temp = arr[rt];
            arr[rt] = arr[lt];
            arr[lt] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[rt];
    arr[rt] = temp;
    return rt;
}

void quick_sort(int a[], int l, int r, int o) {
    if(l < r) {
        int pos = partition(a, l, r, o);
        quick_sort(a, l, pos-1, o);
        quick_sort(a, pos+1, r, o);
    }
    printarray(a, l, r);
}

void printarray(int a[], int m, int n) {
    int i;
    for(i=m; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    int a1[n];
    for(i=0; i<n; i++) {
        scanf("%d", &a1[i]);
    }
    printf("\nbubble_sort_start\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    bubble_sort_start(a, n, 1);
    printf("\nbubble_sort_start\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    bubble_sort_start(a, n, 0);
    
    printf("\nbubble_sort_end\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    bubble_sort_end(a, n, 1);
    printf("\nbubble_sort_end\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    bubble_sort_end(a, n, 0);
    
    printf("\ninsertion_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    insertion_sort(a, n, 1);
    printf("\ninsertion_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    insertion_sort(a, n, 0);
    
    printf("\nselection_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    selection_sort(a, n, 1);
    printf("\nselection_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    selection_sort(a, n, 0);
    
    printf("\nmerge_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    merge_sort(a, 0, n, 1);
    printf("\nmerge_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    merge_sort(a, 0, n, 0);
    
    printf("\nquick_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    quick_sort(a, 0, n, 1);
    printf("\nquick_sort\n");
    for(i=0; i<n; i++) {a[i] = a1[i];}
    printarray(a, 0, n);
    quick_sort(a, 0, n, 0);
    return 0;
}
