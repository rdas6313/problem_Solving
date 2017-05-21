#include<stdio.h>
#include<queue>
#define Max 1020
#define MOD 1000000007
using namespace std;
int visit[Max][Max],a[Max][Max];
int fx[]={+2,+2,-2,-2,+1,-1,+1,-1};
int fy[]={+1,-1,+1,-1,+2,+2,-2,-2};
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
			if((tmp_x>0 && tmp_x<=n) && (tmp_y>0 && tmp_y<=m)){
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
long long int fac(int n){
    
    int i;long long int s=1;
    for(i=1;i<=n;i++){
        s=((s%MOD)*(i%MOD))%MOD;
    
    }
      //  printf("FAC--%d\n",s);
    return s;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		init();
		int n,m,q,x,y,i,j;long long int c,s=1;
		scanf("%d%d%d",&n,&m,&q);
		for(i=0;i<q;i++){
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				if(visit[i][j]==0 && a[i][j]==1){
					x=bfs(i,j,n,m);
					//printf("%d\n",x);
					c=fac(x);
				//	printf("%lld\n",c);
					s=((s%MOD)*(c%MOD))%MOD;
				}
			}
		
		printf("%lld\n",s);
	}
	return 0;
}