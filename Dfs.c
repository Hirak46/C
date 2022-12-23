#include<stdio.h>
#include<conio.h>
int a[20][20],r[20],h;
void dfs(int v) {
	int i;
	r[v]=1;
	for (i=1;i<=h;i++)
	  if(a[v][i] && !r[i]) {
		printf("\n %d->%d",v,i);
		dfs(i);
	}
}
void main() {
	int i,j,k=0;
	printf("\n Enter number of vertices:");
	scanf("%d",&h);
	for (i=1;i<=h;i++) {
		r[i]=0;
		for (j=1;j<=h;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=h;i++)
	  for (j=1;j<=h;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=h;i++) {
		if(r[i])
		   k++;
	}
	if(k==h)
	  printf("\n Graph is connected"); else
	  printf("\n Graph is not connected");
	getch();
}

