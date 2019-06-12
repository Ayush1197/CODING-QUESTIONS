#include<stdio.h>

int a[50][50];
int visited[50];
int n;
int count=0;
void dfst();
void dfs(int v); 
int k=0;
int pop[50];
void dfst()
{
	int i;
		
	for(i=0;i<n;i++)
		if(visited[i]==0)
            {   dfs(i);
                pop[k]=i;
			  k++;
			  }
}
void dfs(int v)
{
	int i;
	count++;
	visited[v]=count;
	for(i=0;i<n;i++)
	{
		if(a[v][i]==1 && visited[i]==0)
			{dfs(i);
			  pop[k]=i;
			  k++;
			 }
	}
}	
  
int main()
{
	int i,j;
	printf("enter no.of nodes\n");
	scanf("%d",&n);
	printf("enter graph\n");
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	dfst();
	printf("visited order is\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\n",i,visited[i]);
                printf("topological order is\n");
		for(i=n-1;i>=0;i--)
		printf("%d-->",pop[i]);
		
	return 0;
}	
