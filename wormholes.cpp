#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define MAX 10000000
using namespace std;
vector< pair<int,int> >vec;

int search(int a[],int n,int key,int f){

	int start=0,end=n-1,mid;
	while(start<=end){
		mid = (start+end)/2;
		if(key==a[mid]){
			return mid;
		}else if(key<a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	if(f)
		return start;
	else
		return end;
}
int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int i,a,b;
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		vec.push_back(make_pair(a,b));
	}
	int v[x],w[y];
	for(i=0;i<x;i++)
		scanf("%d",&v[i]);
	for(i=0;i<y;i++)
		scanf("%d",&w[i]);
	sort(v,v+x);
	sort(w,w+y);
	int min=MAX,start,end;
	for(i=0;i<vec.size();i++){
		if(vec[i].first<v[0] || vec[i].second>w[y-1])
			continue;
		start = search(v,x,vec[i].first,0);
		end = search(w,y,vec[i].second,1);
		//printf("%d %d\n",v[start],w[end]);
	
		if(((w[end]-v[start])+1)<min)
			min=((w[end]-v[start])+1);
	}
	printf("%d\n",min);
	return 0;
}