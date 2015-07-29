/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {

    int x1;
    int y1;
    int x2;
    int y2;

}node;

bool comparer(node a, node b){
	return ((a.x1)<(b.x1));
}

int main(){

	register int a;
	register int b;
	register int c;
	register int d;
	register int tamanho=0;

	node queue[1000];


	while(scanf("%d %d %d %d", &a,&b,&c,&d)!=EOF){
		queue[tamanho].x1=a;
		queue[tamanho].y1=b;
		queue[tamanho].x2=c;
		queue[tamanho].y2=d;
		tamanho++;
	}
	sort(queue, queue+tamanho,&comparer);

	for (int i = 0; i < tamanho; ++i)
	{
		printf("%d\n", queue[i].x1);
	}

    return 0;
}
