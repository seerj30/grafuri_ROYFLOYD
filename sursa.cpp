#include<iostream>
#include<fstream>
using namespace std;
ofstream g("dmin.out");

void citire(int &n,int &m,int &k,int a[101][101])
{
	int x,y,i,j,p;
	ifstream f("dmin.in");
	f>>n>>m;
	for(i=1;i<=m;i++)
	{
		f>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(p=1;p<=n;p++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][p] && a[p][j] && i!=j && (a[i][j]==0 || a[i][j]>a[i][p]+a[p][j]))
					a[i][j]=a[i][p]+a[p][j];
	f>>k;
	for(i=1;i<=k;i++)
	{
		f>>x>>y;
		g<<a[x][y]<<"\n";
	}
}


int main()
{
	int n,a[101][101]={},m,k;
	citire(n,m,k,a);
	return 0;
}
