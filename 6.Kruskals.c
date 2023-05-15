#include<stdio.h> 
#include<conio.h>
int a,b,u,v,n,i,j,ne=1; 
int visited[20]={0},min,mincost=0,cost[20][20],parent[20]; 
int infinity = 9999; 
int find(int i); 
int uni(int i,int j); 
void kruskals();
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
void kruskals()
{
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:"); scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=infinity;
		}
	}	
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=infinity;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{ 
				if(cost[i][j] <min)
				{
					min=cost[i][j];
					a=u=i; b=v=j;
				}
			}			
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("edge %d: (%d,%d) cost: %d\n",ne++,a,b,min);
			mincost += min;
		}
		cost[a][b]=cost[b][a]=infinity;
	}	
	printf("\nMinimum cost = %d\n",mincost);
}
int main()
{ 
   kruskals();
   getch();
   return 0;
}