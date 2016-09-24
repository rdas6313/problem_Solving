#include<stdio.h>
struct NODE{
	int max,min,prop;
};
void create(int node,int start,int end,int a[],struct NODE tree[]){
	if(start==end){
		tree[node].max=a[start];
		tree[node].min=a[start];
		tree[node].prop=0;
		return;
	}
	int mid=(start+end)/2;
	int left=2*node;
	int right=left+1;
	create(left,start,mid,a,tree);
	create(right,mid+1,end,a,tree);
	tree[node].max=(tree[left].max<tree[right].max)?tree[right].max:tree[left].max;
	tree[node].min=(tree[left].min<tree[right].min)?tree[left].min:tree[right].min;
	tree[node].prop=0;
}
void update(int node,int start,int end,struct NODE tree[],int x,int carry){
	if((tree[node].max-carry)<=x)
		return;
	else if((tree[node].min-carry)>x){
		tree[node].prop+=1;
		//printf("%d--%d-----%d-%d\n",start,end,tree[node].min,carry);
		tree[node].min-=1;
		tree[node].max-=1;
		return;
	}
	int mid=(start+end)/2;
	int left=2*node;
	int right=left+1;
	update(left,start,mid,tree,x,carry+tree[node].prop);
	update(right,mid+1,end,tree,x,carry+tree[node].prop);
	tree[node].max=(tree[left].max<tree[right].max)?tree[right].max:tree[left].max;
	tree[node].min=(tree[left].min<tree[right].min)?tree[left].min:tree[right].min;
	tree[node].min-=tree[node].prop;
	tree[node].max-=tree[node].prop;
}
void dis(int node,int start,int end,int carry,struct NODE tree[]){
	if(start==end){
		int tmp=tree[node].max-carry;
		printf("%d ",tmp);
		return;
	}
	int mid=(start+end)/2;
	int left=2*node;
	int right=left+1;
	dis(left,start,mid,carry+tree[node].prop,tree);
	dis(right,mid+1,end,carry+tree[node].prop,tree);	
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;struct NODE tree[3*n+5];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int q,x;
	create(1,0,n-1,a,tree);
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&x);
		update(1,0,n-1,tree,x,0);
	}
	dis(1,0,n-1,0,tree);
	printf("\n");
	return 0;
}