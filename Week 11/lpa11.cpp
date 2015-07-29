/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>


/*The first line of each test case gives the number of streets (m) 
and number of street junctions, intersections and/or dead ends (n). 
Then, m lines follow. Each line describes a street by two integers, 
which correspond to the indices of its ends. 
The hotel is at location one and King's Cross St Pancras station is at location n. 
There are at most 70000 streets and 600 street intersections / dead ends.*/

using namespace std;

static int matriz[600][600];
static int rmatriz[600][600];
int max_result;
int min_result; 

bool bfs(int n, int parent[])
{

    bool visited[n];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && rmatriz[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[n-1] == true);
}
 
int main()
{
    int m, n;
    register int i, j, max_flow, a, b;

    while(scanf("%d %d",&m, &n)!=EOF){
        max_result=0;
        min_result=0;
        for (i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            matriz[a-1][b-1]=1;
            matriz[b-1][a-1]=1;
            rmatriz[a-1][b-1]=1;
            rmatriz[b-1][a-1]=1;
            (b==n)?max_result++:0;
            (b==1)?min_result++:0;

        }
        
        int parent[n];
        
        max_flow = 0;
        
        while (bfs(n,parent)){

            int path_flow = INT_MAX;
            for (j=n-1; j!=0; j=parent[j])
            {
                i = parent[j];
                (path_flow<rmatriz[i][j])?path_flow=path_flow:path_flow=rmatriz[i][j];
            }
        
            for (j=n-1; j != 0; j=parent[j])
            {
                i = parent[j];
                rmatriz[i][j] -= path_flow;
                rmatriz[j][i] += path_flow;
            }
            
            max_flow += path_flow;

            if(max_flow==max_result){
                break;
            }
            if(max_flow==max_result){
                break;
            }
        }

        cout << max_flow << endl;
        
        memset(matriz,0,sizeof(matriz));
        memset(rmatriz,0,sizeof(rmatriz));
    }

 
    return 0;
}