#include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,ne=1; 
int visited[20]={0},min,mincost=0,cost[20][20],parent[20]; 
int infinity = 9999; 
int find(int i); 
int uni(int i,int j); 
void kruskals(); 
void prims();
int find(int i)
{
	while(parent[i])
		i=parent[i];
		return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{ 
		parent[j]=i;
		return 1;
	}
   return 0;
}
void prims()
{
	printf("\n\tImplementation of prims's algorithm\n");
	printf("\nEnter the number of vertices:");
	scanf("%d",&n); 
	printf("\nEnter the adjacency matrix:\n"); 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	}
	visited[1]=1;
	printf("\n");
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=infinity;i<=n;i++)
			for(j=1;j<=n;j++) 
				if(cost[i][j]<min) if(visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i; 
					b=v=j;
				}
				if(visited[u]==0 || visited[v]==0)
				{
					printf("\nEdge %d:(%d %d) cost:%d",ne++,a,b,min);
					mincost+=min; visited[b]=1;
				}
				cost[a][b]=cost[b][a]=infinity;
	}
	printf("\nMinimun cost=%d\n",mincost);
}
int main()
{
	prims();
	getch();
	return 0;
}