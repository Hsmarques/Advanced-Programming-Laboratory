/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int array[250000];
int best=0;
int numRows, numCols;

void findMaxSum ()
{
	int tempSum=0, top, down, i;
	int temp[numCols];

	for (top = 0; top < numRows; top++){
		
		memset(temp,0,numCols*sizeof(int));

		for (down = top; down < numRows; down++){
		
			tempSum=0;
			for (i = 0; i < numCols; ++i){
				temp[i] += array[down*numCols+i];
				tempSum+=temp[i];

				if(tempSum<0) tempSum=0;
				
				if(tempSum>best) best = tempSum;
		
			}
		}
	}
}

int main(){

    int I, J;
    scanf("%d %d",&numRows,&numCols);
	if (numRows>numCols){
    	int change=numCols;
    	numCols=numRows;
    	numRows=change;
    	for (J = 0; J < numCols; ++J){
    		for(I = 0; I < numRows; ++I){
    			scanf("%d",&array[J+I*numCols]);
    		}
    	}
		
    }else{
    	for(I=0; I < numRows; ++I){
    		for(J=0; J < numCols; ++J){
    			scanf("%d",&array[I*numCols+J]);
    		}
    	}
    }

    

    findMaxSum();
    printf("%d\n",best);
   
    return 0;
}
