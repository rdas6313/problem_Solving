#include<stdio.h>
int query(int idx,int tree[]){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
void update(int idx,int tree[],int val,int end){
	while(idx<=end){
		tree[idx]+=val;
		idx+=(idx & -idx);
	}
}
void insert(int x,int y,int z,int tree[],int val,int max,int n){
	int key=(x*(n*n))+(y*n)+z;
	update(key+1,tree,val,max);
}
int find(int x,int y,int z,int x1,int y1,int z1,int tree[],int n,int max){
	int a=(x*(n*n))+(y*n)+z;
	int b=(x1*(n*n))+(y1*n)+z1;
	int total=query(max,tree);
	int atotal=query(a+1,tree);
	int btotal=query(b+1,tree);
	return total-(btotal-atotal);
}
int main(){
	int n,q,i,a,x,y,z,val,x1,y1,z1;
	scanf("%d%d",&n,&q);
	int max=n*n*n+5;
	int tree[max];
	//create(0,0,n*n*n,tree);
	for(i=0;i<max;i++)
		tree[i]=0;
	for(i=0;i<q;i++){
		scanf("%d",&a);
		if(a==1){
			scanf("%d%d%d%d",&x,&y,&z,&val);
			insert(x,y,z,tree,val,max,n);
		}else{
			scanf("%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1);
			val=find(x,y,z,x1,y1,z1,tree,n,max);
			printf("%d\n",val);
		}
	}
	return 0;
}