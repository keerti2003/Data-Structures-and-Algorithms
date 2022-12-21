#include<stdio.h>

int *dijkstra(int adj[][9], int *dist, int *visit, int src, int size) {
    int i, dst, cost, costn;
    for(dst=0; dst<size; dst++) {
        cost = adj[src][dst];
        if(visit != 1 && cost != 0) {
			if(dist[dst] > cost + dist[src]) {
                dist[dst] = cost + dist[src];
            }
        }
    }
    visit[src] = 1;
//    printdist(dist, size);
    int min = 1000, minidx = -1;
    for(i=0; i<size; i++) {
        if(visit[i] != 1 && dist[i] != -1 && dist[i] < min) {
            min = dist[i];
            minidx = i;
        }
    }
    if(minidx == -1) {
    	return dist;
	}
    dist = dijkstra(adj, dist, visit, minidx, size);
    return dist;
}

void printdist(int *dist, int n) {
	int i;
	for(i=0; i<n; i++) {
		if(dist[i] != 10000) {
			printf("%d ", dist[i]);
		} else {
			printf("-1 ");
		}
	}
	printf("\n");
}

int main() {
	int i, j, k;
    int adj[][9] = {{0, 4, 8, 0, 0, 0, 0, 0, 0},{4, 0, 11, 0, 8, 0, 0 , 0, 0},{8, 11, 0, 1, 0, 7, 0, 0, 0},{0, 0, 1, 0, 0, 6, 0, 2, 0},{0, 8, 0, 0, 0, 2, 7, 4, 0},{0, 0, 7, 6, 2, 0, 0, 0, 0},{0, 0, 0, 0, 7, 0, 0, 14, 9},{0, 0, 0, 2, 4, 0, 14, 0, 10},{0, 0, 0, 0, 0, 0, 9, 10, 0}};
    printf("Adjacency matrix: \n");
    for(i=0; i<9; i++) {
    	for(j=0; j<9; j++) {
    		printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	printf("Enter starting node: ");
	scanf("%d", &j);
    dst[--j] = 0;
    int dst[] = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
    int visit[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    dst[k] = 0;
    int *dist = dijkstra(adj, dst, visit, k, 9);
    printf("\n");
    for(i=0; i<9; i++) {
        printf("%d ", dist[i]);
	}
}
