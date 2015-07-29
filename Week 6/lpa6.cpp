/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string>


using namespace std;


static int array[30][30];
int mindistance=INT_MAX;
int n_centroids, nplaces;
static int is_centroid[30];

int distancia[30];

int bound (int is_max_centro){

	int i;
	int j;
	int temp_max=0;
	int temp_min = INT_MAX;



	for (i = 0;i<is_max_centro;i++)
		{
			temp_max=0;
			temp_min = INT_MAX;

			if (is_centroid[i] == 0 ){ 
				for (j=0;j<nplaces;j++){

					if (is_centroid[j] == 1 || j > is_max_centro){
						
						if (array[i][j] < temp_min){
							temp_min = array[i][j];
						}
					}
				}
				if (temp_max < temp_min ){
					temp_max = temp_min;
				}
			}
		}
		if (mindistance > temp_max){
			return 1;
			
		}
		return 0;
}
void getMinDistance(int position, int k_centroids){ 
	
	int i;
	int j;
	int temp_min = INT_MAX;
	

	int temp_max = 0;
		
	if (position >= nplaces && k_centroids != n_centroids){
		return ;
	}
	if (k_centroids == n_centroids ){ 
		
		memset(distancia,0,sizeof(int)*30);
		temp_max = 0;

		for (i = 0;i<nplaces;i++)
		{
			temp_min = INT_MAX;

			if (is_centroid[i] == 0 ){ 
				for (j=0;j<nplaces;j++){

					if (is_centroid[j] == 1){
						
						if (array[j][i] < temp){
							temp = array[j][i];
							
						}
					}
				}
				if (temp_max < temp ){
					temp_max = temp;
				}
			}
		}
		if (mindistance > temp_max){
			mindistance = temp_max;
			
		}

		return ;

	}else{

		if (bound(position) == 1){

			is_centroid[position]=1;
			getMinDistance(position +1, k_centroids +1); 
			is_centroid[position]=0; 
			getMinDistance(position+1,k_centroids);

		}
		
		
	}

	return ;
}

void getMinDistance(int position, int k_centroids){

	int distance, i, j;
	int temp_min= INT_MAX;
	int temp_max= 0;

	if (selectedCentroid >= nplaces && iterCentroid != n_centroids){
		return ;
	}
	if (iterCentroid == n_centroids ){ 

		
		memset(distancia,0,sizeof(int)*MAX_N);
		temp_max = 0;

		for (i = 0;i<nplaces;i++)
		{
			temp = 999999999;

			if (is_centroid[i] == 0 ){
				for (j=0;j<nplaces;j++){

					if (is_centroid[j] == 1){
						
						if (array[j][i] < temp){
							
							temp = array[j][i];
							
						}
					}
				}
				if (temp_max < temp ){
					temp_max = temp;
				}
			}
		}
		if (mindistance > temp_max){
			mindistance = temp_max;
			
		}

		return ;

	}else{

		if (bound(selectedCentroid,iterCentroid) == 1){


			is_centroid[selectedCentroid]=1;
			recursive(selectedCentroid +1, iterCentroid +1);
			is_centroid[selectedCentroid]=0; 
			recursive(selectedCentroid+1,iterCentroid);

		}
		
		
	}
	
	return;
}

void printarvore(){
	int i, j;
	for (i=0;i<nplaces;i++)
	{
		for (j=0;j<nplaces;j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

int main(){

    int a, b, i, nlines;
    int distance;
	static int centroids[22];
	cin >> nplaces;
	cin >> n_centroids;
	nlines=nplaces*(nplaces-1)/2;

	for(i=0;i<nlines;i++){
		scanf("%d %d %d",&a,&b, &distance);
		array[a-1][b-1]=distance;
		array[b-1][a-1]=distance;
	}
	//printarvore();
    getMinDistance(0,0);
    
	printf("%d\n",mindistance);
    
    return 0;
}
