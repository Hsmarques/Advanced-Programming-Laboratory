/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

typedef struct Point {

    int first;
    int second;
    int third;

}Point;

struct classcomp {
  bool operator() (const Point& lhs, const Point& rhs) const
  {return lhs.first<rhs.first;}
};

Point carros[500001];
    	
int main() {

    register int n_points;
	register int i;

	set<Point,classcomp> tree_carros;
    set<Point>::iterator itup, it;
   	pair<set<Point>::iterator,bool> par; 

    while(scanf("%d",&n_points)!=EOF){
    	for(i=0;i<n_points;i++){
    		struct Point temp;
    		scanf("%d %d %d", &temp.first,&temp.second,&temp.third);
    		carros[temp.third]=temp;
    	}
    	struct Point temp;
    	temp.first=500001;
    	temp.second=0;
    	temp.third=500001;
    	tree_carros.insert(temp);
    }

    //percorre os pontos de cima (Z) até baixo
    for (i = n_points; i > 0; --i){
    	itup = tree_carros.upper_bound(carros[i]);
		Point p = *itup;
		
		if (carros[i].second > p.second){
			par=tree_carros.insert(carros[i]);
			printf("%d %d %d\n", carros[i].first, carros[i].second, carros[i].third);
			set<Point>::reverse_iterator reverse (par.first);
			for (;reverse != tree_carros.rend();){
				if (reverse->second < carros[i].second){
					tree_carros.erase(--reverse.base());
				}else{
					break;
				}
					
			}
		}
    }

    return 0;
}
