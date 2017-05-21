#include<stdio.h>
#include<queue>
#define Max 1009
using namespace std;
int vis[Max][Max],a[Max][Max];
queue< pair<int,int> >q;
int fx[]={1,-1,0,0};
int fy[]={0,0,+1,-1};
void clear(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++){
			vis[i][j]=0;
		}
}
int bfs(int x,int y,int n,int m){
	int node=0,i;
	q.push(make_pair(x,y));
	vis[x][y]=1;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		node++;
		q.pop();
		for(i=0;i<4;i++){
			if((1<=y+fx[i] && y+fx[i]<=m && 1<=x+fy[i] && x+fy[i]<=n)&& vis[x+fy[i]][y+fx[i]]==0 && a[x+fy[i]][y+fx[i]]==1){
				vis[x+fy[i]][y+fx[i]]=1;
				q.push(make_pair(x+fy[i],y+fx[i]));
			}
		}
	}
	return node;
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int i,j,total=0;
	clear();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1)
				total+=1;
		}
	}
	
	int x,y,effected=0;
	for(i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		if(a[x][y]==1 && vis[x][y]==0)
			effected+=bfs(x,y,n,m);
		printf("%d\n",total-effected);
	}
	return 0;
}