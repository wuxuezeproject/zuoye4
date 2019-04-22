/*#include <iostream>
#include<stdlib.h>
using namespace std;
#define max 20
#define M 10000
/*typedef struct ArcNode
{
	int adjvex;
	int cost;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct Anode
{
	int date;
	ArcNode *firstarc;
}Anode;
typedef struct 
{
	Anode vertices[max];
	int vexnum,arcnum;
}Graph;


typedef struct ArcCell
{
	int adj;
}ArcCell;
typedef struct
{
	int vexs[max];
	ArcCell arcs[max][max];
	int vexnum;
	int arcnum;
}Graph;
typedef struct
{
	int adj[max];
	int n;
}visit;
void create(Graph &G)
{
	int m,n,cost;
	cin>>G.vexnum>>G.arcnum;
	for(int i=1;i<=G.arcnum;i++)
      for(int j=1;j<=G.arcnum;j++)
		G.arcs[i][j].adj=M;
	for(int i=1;i<=G.arcnum;i++)
	{
		cin>>m>>n>>cost;
        G.arcs[m][n].adj=G.arcs[n][m].adj=cost;
	}
}
void fun(Graph &G)
{
	int i,v,min,j,sum=0,y=0,x=0,n,N,k=0;
	visit V[max];
	for(i=1;i<=G.arcnum;i++)
	{
		for(j=0;j<G.vexnum;i++)
			V[i].adj[j]=0;
		V[i].n=0;
	}
	for(v=1;v<G.vexnum;v++)
	{
		min=M;
		n=0;
		k=0;
		for(i=1;i<=G.arcnum;i++)
		 for(j=1;j<=G.arcnum;j++)
			 if(G.arcs[i][j].adj<min)
			 {
				 min=G.arcs[i][j].adj;
				 x=i;
				 y=j;
			 }
			 for(i=y;V[i].adj[k];)
			 {
				 N=V[i].adj[k];
				 if(N==x)
				 {
					 n=1;
					 break;
				 }
				 if(N==y)
					 k++;
				 else if(V[N].adj[k]==i)
				 {
					 k++;
					 if(V[N].adj[k]!=0)
						 i=N;
				 }
				 else i=N;
			 }
			 if(n==0)
			 {
				 sum+=min;
				 V[x].adj[V[x].n]=y;
                 V[x].n++;
                 V[y].adj[V[y].n]=x;
                 V[y].n++;
			 }
			 else
				 v--;
			 G.arcs[x][y].adj=M;
             G.arcs[y][x].adj=M;
	}
	cout<<sum;
}

int main()
{
	Graph G;
	create(G);
	fun(G);
	system("pause");
	return 0;
}*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 20
#define M 100000
typedef struct
{
    int vexnum;
    int arcnum;
    char vex[MAX];
    int arc[MAX][MAX];
} MGraph;
typedef struct
{
    int adj[MAX];
    int n;
} Visit;
void Create_G(MGraph &G)
{
    int i,x,y,n,j;
    cin>>G.vexnum>>G.arcnum;
    for(i=1; i<=G.vexnum; i++)
        for(j=1; j<=G.vexnum; j++)
            G.arc[i][j]=M;
    for(i=0; i<G.arcnum; i++)
    {
        cin>>x>>y>>n;
        G.arc[x][y]=n;
        G.arc[y][x]=n;
    }
}
void kruskal(MGraph G)
{
    int i,v,min,j,sum=0,y=0,x=0,n,N,k=0;
    Visit V[MAX];
    for(i=1; i<=G.vexnum; i++)
    {
        for(j=0; j<G.vexnum; j++)
            V[i].adj[j]=0;
        V[i].n=0;
    }
    for(v=1; v<G.vexnum; v++)
    {
        min=M;
        n=0;
        k=0;
        for(i=1; i<=G.vexnum; i++)
            for(j=1; j<=G.vexnum; j++)
                if(G.arc[i][j]<min)
                {
                    min=G.arc[i][j];
                    x=i;
                    y=j;
                }
        for(i=y; V[i].adj[k];)
        {
            N=V[i].adj[k];
            if(N==x)
            {
                n=1;
                break;
            }
            if(N==y)
                k++;
            else if(V[N].adj[k]==i)
            {
                k++;
                if(V[N].adj[k]!=0)
                    i=N;
            }
            else
                i=N;
        }

        if(n==0)
        {
            sum+=min;
            V[x].adj[V[x].n]=y;
            V[x].n++;
            V[y].adj[V[y].n]=x;
            V[y].n++;
        }
        else
            v--;
        G.arc[x][y]=M;
        G.arc[y][x]=M;
    }
    cout<<sum;
}
int main()
{
    MGraph G;
    Create_G(G);
    kruskal(G);
    return 0;
}



