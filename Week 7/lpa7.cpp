/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

int nr_nbhoods;
int min_afected;
int nr_weeks=0;

static int array2d[1000][1003];
static int arrayPPL[1000];
std::vector<int> queue;

void spread_the_virus(){
	register int i;
	register int spread_it;
	register int spread_it_son;

	queue.push_back(0);
	array2d[0][1002]=1;
	array2d[0][1003]=1;
	min_afected-=arrayPPL[0];
	nr_weeks++;

	while(queue.size()>0 && min_afected>0){
		spread_it=queue.at(0);
		queue.erase(queue.begin());
		
		for(i=0;i<array2d[spread_it][1001];i++){
			spread_it_son=array2d[spread_it][i];
			if (array2d[spread_it_son][1002]!=1){
				array2d[spread_it_son][1002]=1;
				array2d[spread_it_son][1003]=array2d[spread_it][1003] + 1;
				queue.push_back(spread_it_son);
				min_afected-=arrayPPL[spread_it_son];

				if (nr_weeks<array2d[spread_it_son][1003]) nr_weeks=array2d[spread_it_son][1003];
			
				if (min_afected<=0) break;
			}
			
		}

	}
}

int main(){

	register int n_adjacentes;
	register int i;
	register int j;

	scanf("%d %d",&nr_nbhoods,&min_afected);

	do{
		for(i=0;i<nr_nbhoods;i++){
			scanf("%d %d", &arrayPPL[i],&n_adjacentes);
			array2d[i][1001]=n_adjacentes;
			for (j = 0; j < n_adjacentes; ++j){
				scanf("%d",&array2d[i][j]);
			}
		}
		queue.reserve(nr_nbhoods);
		spread_the_virus();
		(min_afected>0)?printf("Safe!\n"):printf("%d\n",nr_weeks);
		nr_weeks=0;
		queue.resize(0);

	}while(scanf("%d %d",&nr_nbhoods,&min_afected)!=EOF);

    return 0;
}
