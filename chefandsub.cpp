#include<stdio.h>
#include<map>
using namespace std;
map<int, int>tree;
void create(int array[],int start,int end,int node){
	if(start==end){
		tree[node]=array[start];
		return;
	}
	int left=2*node;
	int right=left+1;
	int mid=(start+end)/2;
	create(array,start,mid,left);
	create(array,mid+1,end,right);
	tree[node]=(tree[left]<tree[right])?tree[right]:tree[left];
}
int query(int node,int start_search,int end_search,int left_index,int right_index){
	if(right_index<start_search || end_search<left_index)
		return 0;
	else if(start_search<=left_index && right_index<=end_search){
		return tree[node];
	}else{
		int left = 2*node;
		int right = left+1;
		int mid = (left_index+right_index)/2;
		int x = query(left,start_search,end_search,left_index,mid);
		int y = query(right,start_search,end_search,mid+1,right_index);
		return (x<y)?y:x;
	}
}
int main(){
	int n,p,k;
	scanf("%d%d%d",&n,&k,&p);
	k=(n<k)?n:k;
	int i,a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int input[2*n],sum[2*n];
	for(i=0;i<2*n;i++)
		input[i]=a[i%n];
	sum[0]=input[0];
	for(i=1;i<2*n;i++)
		sum[i]=sum[i-1]+input[i];
	int array[2*n];
	array[0]=sum[k-1];
	for(i=1;i<2*n;i++){
		if((i+k-1)<2*n)
			array[i]=sum[i+k-1]-sum[i-1];
		else
			array[i]=0;
	}
	create(array,0,(2*n-1),1);
	char s[p+1];
	scanf("%s",s);
	int shift=0;
	for(i=0;i<p;i++){
		if(s[i]=='?'){
			int start = n-shift;
			int end = start+n-k;
			int tmp = query(1,start,end,0,(2*n-1));
			printf("%d\n",tmp);
		}else{
			shift=(shift+1)%n;
		}
	}
	return 0;
}
