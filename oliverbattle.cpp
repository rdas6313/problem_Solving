#include<stdio.h>
#include<queue>
#define Max 1020
using namespace std;
int visit[Max][Max],a[Max][Max];
int fx[]={+1,-1,0,0,+1,+1,-1,-1};
int fy[]={0,0,+1,-1,+1,-1,+1,-1};
int bfs(int src_i,int src_j,int n,int m){
	int i,count=0;
	queue< pair<int,int> >q;
	q.push(make_pair(src_i,src_j));
	visit[src_i][src_j]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		count++;
		for(i=0;i<8;i++){
			int tmp_x=x+fx[i];
			int tmp_y=y+fy[i];
			if((tmp_x>-1 && tmp_x<n) && (tmp_y>-1 && tmp_y<m)){
			    if(visit[tmp_x][tmp_y]==0 && a[tmp_x][tmp_y]!=0){
				visit[tmp_x][tmp_y]=1;
				q.push(make_pair(tmp_x,tmp_y));
			}
			}
		}
	}
	return count;
}
void init(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++){
			visit[i][j]=0;
			a[i][j]=0;
		}
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		init();
		int n,m,c,big=0,count=0,i,j;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				if(visit[i][j]==0 && a[i][j]!=0){
					c=bfs(i,j,n,m);
					if(c>big)
						big=c;
					count++;
				}
			}
		printf("%d %d\n",count,big);
	}
	return 0;
}