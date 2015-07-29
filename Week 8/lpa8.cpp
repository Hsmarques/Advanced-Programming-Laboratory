/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#include <vector>

#define MAX 5000

using namespace std;

int dfs[MAX];
static int stack[MAX];
static int low[MAX];
static int in_stack[MAX];
static int saldo_banco[MAX];
static int matrix[MAX][MAX];
int n_banks;
int max_value=INT_MIN;
int cluster_exists=0;
int ind=0;
int top_stack=-1;
int first=1;

void tarjan_algorithm(int indice){

	register int i;
	register int aux;
	register int count;
	register int temp_value;
	register int s;
	
	dfs[indice]=ind;
	low[indice]=ind;
	ind++;

	stack[++top_stack]=indice;
	in_stack[indice]=1;

	for(i=0;matrix[indice][i]!=0;i++){

		aux=matrix[indice][i]-1;
		
		if(dfs[aux]==-1){
			tarjan_algorithm(aux);
			if(low[aux]<low[indice])
				low[indice]=low[aux];
		}
		
		else if(in_stack[aux]==1){
			
			if(dfs[aux]<low[indice]){
				
				low[indice]=dfs[aux];
			}
		}
	}

	if(low[indice]==dfs[indice]){
		count = 0;
		temp_value = 0;
		do{
			s=stack[top_stack--];
			count++;
			temp_value+=saldo_banco[s];
			in_stack[s]=0;
		
		}while(s!=indice);

		if(count>1){
			
			cluster_exists=1;
			
			if(temp_value>max_value){
				max_value=temp_value;
			}
				
		}
	}

}

int main(){

	register int deve;
	register int banco;
	register int i;
	register int j;

	memset(dfs,-1,sizeof(int)*MAX);
		

	while(scanf("%d",&n_banks)!=EOF){

		for(i=0;i<n_banks;i++){
			
			scanf("%d",&banco);
			for(j=0;j<n_banks*2;j++){
				scanf("%d",&deve);
				if(deve==0){
					matrix[i][j]=0;
					break;
				}
				saldo_banco[i]-=deve;
				scanf("%d",&matrix[i][j]);
				saldo_banco[matrix[i][j]-1]+=deve;
			}
		}

		for(i=0;i<n_banks;i++){
			if(dfs[i]==-1)
				tarjan_algorithm(i);
		}

		if(cluster_exists==1){
			printf("%d\n", max_value);
		}
		else{
			printf("No cluster\n");
		}

		cluster_exists=0;
		ind=0;
		top_stack=-1;
		max_value=INT_MIN;

		memset(in_stack,0,sizeof(int)*MAX);
		memset(dfs,-1,sizeof(int)*MAX);
		memset(low,0,sizeof(int)*MAX);
		memset(saldo_banco,0,sizeof(int)*MAX);
		memset(stack,0,sizeof(int)*MAX);
	}

    return 0;
}
