#include<stdio.h>
#include<vector>
#define Max 100000
using namespace std;
vector<int>vec[Max];
void create(int a[],int tree[],int start,int end,int node){
	if(start==end){
		tree[node]=start;
		return;
	}
	int mid=(start+end)/2;
	int left=(2*node);
	int right= left+1;
	create(a,tree,start,mid,left);
	create(a,tree,mid+1,end,right);
	tree[node]=(a[tree[left]]<a[tree[right]])?tree[right]:tree[left];
}
void update(int tree[],int a[],int node,int start,int end,int change_node){
	if(change_node>end || change_node<start || start==end){
		return;
	}
	int mid=(start+end)/2;
	int left=2*node;
	int right=left+1;
	update(tree,a,left,start,mid,change_node);
	update(tree,a,right,mid+1,end,change_node);
	tree[node]=(a[tree[left]]<a[tree[right]])?tree[right]:tree[left];
}
int main(){
	int n,m,tree[Max*3],i,x,y;
	scanf("%d%d",&n,&m);
	int a[n+1];
	for(i=0;i<=n;i++)
		a[i]=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		a[x]++;
		a[y]++;
	}
	create(a,tree,1,n,1);
	int u=tree[1],c=0,v;
	while(a[u]!=0){
		c++;
		for(i=0;i<vec[u].size();i++){
			v=vec[u][i];
			if(a[v]!=0){
				a[v]--;
				update(tree,a,1,1,n,v);
			}
		}
		a[u]=0;
		update(tree,a,1,1,n,u);
		u=tree[1];
	}
	printf("%d\n",c);
	return 0;
}