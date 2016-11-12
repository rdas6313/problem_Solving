#include<stdio.h>
//#define add(n,a) int i;for(i=0;i<n;i++)a[i]+=1;
void heapify(int root,long long int a[],int n){
	int left=root*2+1;
	int right=left+1;
	int min;
	if(left<n && a[root]>a[left]){
		min=left;
	}else{
		min=root;
	}
	if(right<n && a[right]<a[min]){
		min=right;
	}
	if(root!=min){
		long long int tmp=a[root];
		a[root]=a[min];
		a[min]=tmp;
		heapify(min,a,n);
	}
}

void add(int n,long long int a[]){
	int i;
	for(i=0;i<n;i++){
		a[i]+=1;
	}
}
int compute(int n,int k,long long int row[],long long int col[]){
	int i;long long int s=0;
	int p=(n-1)/2;
	for(i=p;i>=0;i--){
		heapify(i,row,n);
		heapify(i,col,n);
	}
	for(i=0;i<k;i++){
		if(row[0]<col[0]){
			s+=row[0];
			row[0]+=n;
			add(n,col);
		}else{
			s+=col[0];
			col[0]+=n;
			add(n,row);
		}
		heapify(0,row,n);
		heapify(0,col,n);
	}
	return s;
}
int main(){
	int test,x;
	scanf("%d",&test);
	while(test--){
		int n,k,i,j;
		scanf("%d%d",&n,&k);
		long long int  row[n],col[n];
		for(i=0;i<n;i++){
			row[i]=0;
			col[i]=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&x);
				row[i]+=x;
				col[j]+=x;
			}
		}

		long long int s=compute(n,k,row,col);
		printf("%lld\n",s);

	}
	return 0;
}