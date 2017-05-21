#include<stdio.h>
void update(int tree[],int idx,int n,int b){
	while(idx<=n){
		if(b==1)
			tree[idx]+=1;
		else if(b==0)
			tree[idx]-=1;
		idx+=idx & -idx;
	}
}
int query(int tree[],int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main(){
	int n,q,i,c,x,y,tmp;
	scanf("%d",&n);
	int eventree[n+1],oddtree[n+1],a[n+1];
	for(i=0;i<=n;i++){
		eventree[i]=0;
		oddtree[i]=0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2==0)
			update(eventree,i,n,1);
		else
			update(oddtree,i,n,1);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d",&c,&x,&y);
		switch(c){
			case 1:
				tmp=query(eventree,y)-query(eventree,x-1);
				printf("%d\n",tmp);
				break;
			case 2:
				tmp=query(oddtree,y)-query(oddtree,x-1);
				printf("%d\n",tmp);
				break;
			case 0:
				if(y%2==0){
					if(a[x]%2!=0){
						update(oddtree,x,n,0);
						update(eventree,x,n,1);
					}
					a[x]=y;
				}
				else{
					if(a[x]%2==0){
						update(eventree,x,n,0);
						update(oddtree,x,n,1);
					}
					a[x]=y;
				}
				break;
		}
	}
	return 0;
}