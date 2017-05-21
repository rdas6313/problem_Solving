#include<stdio.h>
#include<algorithm>
#define Max 1000000+2
using namespace std;
int BIT[Max];
void update(int idx,int val){
	if(idx==0){
		BIT[idx]+=val;
		return;
	}else{
	while(idx<Max){
		BIT[idx]+=val;
		idx+=idx & -idx;
	}
}
}
int query(int idx){
	int sum=0;
	while(idx>0){
		sum+=BIT[idx];
		idx-=idx & -idx;
	}
	return sum+BIT[0];
}
int bsearch(long long int b[],int n,int val){
	int start=0,end=n-1,pos;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(b[mid]==val){
			pos=mid;
			end=mid-1;
		}else if(b[mid]<val){
			start=mid+1;
		}else
			end=mid-1;
	}
	return pos;
}
int main(){
	int n,k,pos,temp,tmp,max,i;
	scanf("%d%d",&n,&k);
	long long int a[n],b[n],array[n],total=0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	for(i=0;i<Max;i++)
		BIT[i]=0;
	sort(b,b+n);
	for(i=0;i<n;i++){
		pos=bsearch(b,n,a[i]);
		temp=n-(i+1);
		tmp=n-(pos+1);
		array[i]=(temp<tmp)?temp:tmp;
		
		update(array[i],1);
	}
	for(i=0;i<n;i++){
		update(array[i],-1);
		int sub=k-array[i];
		if(sub>=Max)
			continue;
		total+=query(Max-1)-query(sub-1);
		
	}
	
	printf("%lld\n",total);

	return 0;
}