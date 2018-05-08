#include <iostream>
#include <cstdio>
#define MAX 1000000
using namespace std;
int arcs[10][10];//邻接矩阵
int D[10];//保存最短路径长度
int path[10][10];//路径
int S[10];//若S[i] = 1则说明 顶点vi已在集合S中
int n = 0;//顶点个数
int v0 = 0;//源点
int v,w;
void ShortestPath_DIJ()
{

    for(v=0;v<n;++v)
    {
        S[v]=0;
        D[v]=arcs[v0][v];
        if(D[v]<MAX) path[v][v0]=v0;
        else path[v][v]=-1;
    }
    S[v0]=1;
    D[v0]=0;
    for(int i=1;i<n;++i)
    {
       int min=MAX;
        for(w=0;w<n;++w)
            if(!S[w]&&D[w]<min)
            {
                v=w;min=D[w];
            }
            S[v]=1;
        for(w=0;w<n;++w)
            if(!S[w]&&(D[v]+arcs[v][w]<D[w]))
            {
                D[w]=D[v]+arcs[v][w];
                path[w][w]=1;
            }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arcs[i][j];
        }
    }
    ShortestPath_DIJ();
    for (int i = 0; i < n; i++) printf("D[%d] = %d\n",i,D[i]);
    return 0;
}
