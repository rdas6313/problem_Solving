#include<stdio.h>
#include<queue>
#define VAL 100000
using namespace std;
queue<int>q;
int bfs(int root,int key,int a[],int n){
	int level[VAL+1],i;
	for(i=0;i<=VAL;i++)
		level[i]=-1;
	level[root]=0;
	q.push(root);
	while(!q.empty() && level[key]==-1){
		long long int temp=q.front();
		q.pop();
		for(i=0;i<n;i++){
			int r=((temp%VAL)*(a[i]%VAL))%VAL;
			if(level[r]==-1){
				level[r]=level[temp]+1;
				q.push(r);
			}
		}
	}
	return level[key];
}
int main(){
	int mykey,key,n;
	scanf("%d%d",&mykey,&key);
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int v=bfs(mykey,key,a,n);
	printf("%d\n",v);
	return 0;
}