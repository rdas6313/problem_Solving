#include<stdio.h>
#include<queue>
#include<utility>
#define Max 1000
using namespace std;
int a[Max][Max],visit[Max][Max];
void init(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++){
			visit[i][j]=0;
		}
}
int BFS(int n,int x,int y){
	int i;
	queue<pair<int,int> >q;
	int fx[]={1,-1,0,0};
	int fy[]={0,0,+1,-1};
	visit[x][y]=1;
	int val=1;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int row=q.front().first;
		int col=q.front().second;
		q.pop();
		for(i=0;i<4;i++){
			if(row+fx[i]<n && fy[i]+col<n){
				if(visit[row+fx[i]][col+fy[i]]==0 && a[row+fx[i]][col+fy[i]]==1){
					q.push(make_pair(row+fx[i],col+fy[i]));
					visit[row+fx[i]][col+fy[i]]=1;
					val+=1;
			}
		}
		}
	}
	return val;
}
int main(){
	int n,val,big=-1,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(visit[i][j]==0 && a[i][j]==1){
				val=BFS(n,i,j);
				if(val>big)
					big=val;
			}
		}
	}
	printf("%d\n",big);
	return 0;
}