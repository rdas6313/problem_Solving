//Hackerearth Tree Problem solution
#include<stdio.h>
#define Max 100001
void init(int tree[][2]){
	int i;
	for(i=0;i<Max;i++){
		tree[i][0]=0;
		tree[i][1]=0;
	}
}
void preorder(int tree[][2],int node){
	if(node==0)
		return;
	printf("%d ",node);
	preorder(tree,tree[node][0]);
	preorder(tree,tree[node][1]);
}
int main(){
	freopen("input.txt","r",stdin);
	int test;
	scanf("%d",&test);
	while(test--){
		int n,tree[Max][2],i,root,x,y,z;
		init(tree);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			tree[x][0]=y;
			tree[x][1]=z;
			if(i==0)
				root=x;
		}
		preorder(tree,root);
		printf("\n");
	}
}
