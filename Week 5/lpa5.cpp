/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;


int array[1000];
int mintime=0;
int capacity, nshoes, timeprocessing;

bool comparer (int i,int j) { return (i<j); }

void getMinTime(){
    int resto=nshoes%capacity;
    int i=0;

    if(resto!=0){
        mintime=array[resto-1]+timeprocessing*2;
        nshoes-=resto;
        i+=resto;
    }else{
        mintime+=array[i+capacity-1]+timeprocessing*2;
        nshoes-=capacity;
        i+=capacity;
    }
	while(nshoes>0){
        if(mintime < array[i+capacity-1]){
            mintime=(array[i+capacity-1]+timeprocessing*2);
        }else{
            mintime+=timeprocessing*2;
        }
        nshoes-=capacity;
        i+=capacity;
	}
    mintime-=timeprocessing;

}

int main(){

    int i;
    while(cin >> capacity){
    	cin >> nshoes;
    	cin >> timeprocessing;
    	
    	for(i=0;i<nshoes;i++){
    		scanf("%d",&array[i]);
    	}
	    sort (array, array+nshoes, comparer);

	    getMinTime();
	    
		printf("%d\n",mintime);
        mintime=0;
   	}
    
    
    return 0;
}
