#include<stdio.h>
#include <iostream>
#include<map>
#define INF 1000000000
using namespace std;
map<string, int>h;
int main(){
	int n,m,i,x,j,k,q;
	scanf("%d%d",&n,&m);
	int matrix[n+1][n+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(i==j)
				matrix[i][j]=0;
			else
				matrix[i][j]=INF;
	}
	
	char s[10000],s1[10000];
	for(i=1;i<=n;i++){
		cin>>s;
		h[s]=i;
	}
	for(i=0;i<m;i++){
		cin>>s>>s1;
		scanf("%d",&x);
		matrix[h[s]][h[s1]]=x;
		matrix[h[s1]][h[s]]=x;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(matrix[i][k]+matrix[k][j]<matrix[i][j]){
					matrix[i][j] = matrix[i][k]+matrix[k][j];
					matrix[j][i] = matrix[i][k]+matrix[k][j];
				}
			}

	scanf("%d",&q);
	for(i=0;i<q;i++){
		cin>>s>>s1;
		printf("%d\n",matrix[h[s]][h[s1]]);
	}
	return 0;
}