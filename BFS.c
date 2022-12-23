#include<stdio.h>
#include<conio.h>
int a[20][20],k[20],visited[20],h,i,j,f=0,r=-1;
void bfs(int v) {
	for (i=1;i<=h;i++)
	  if(a[v][i] && !visited[i])
	   k[++r]=i;
	if(f<=r) {
		visited[k[f]]=1;
		bfs(k[f++]);
	}
}
void main() {
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&h);
	for (i=1;i<=h;i++) {
		k[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=h;i++)
	  for (j=1;j<=h;j++)
	   scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	for (i=1;i<=h;i++)
	  if(visited[i])
	   printf("%d\t",i);
	   else
	   printf("\n Bfs is not possible");
	getch();
}
