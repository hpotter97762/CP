#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	c++;
	int x,y,s;
	int i,j,k;
	int f[c][101][101];
	memset(f,0,sizeof f);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&s);
		for(j=0;j<c;j++)
			f[j][x][y]+=(s+j)%c;
	}
	for(i=0;i<c;i++)
		for(j=1;j<=100;j++)
			for(k=1;k<=100;k++)
				f[i][j][k]+=f[i][j-1][k]+f[i][j][k-1]-f[i][j-1][k-1];
	int t,x1,y1,x2,y2;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t%=c;
		int ans=f[t][x2][y2]-f[t][x1-1][y2]-f[t][x2][y1-1]+f[t][x1-1][y1-1];
		printf("%d\n",ans);
	}
	return 0;
}