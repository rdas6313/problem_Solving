#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
struct point{
	int index,x,y;
};
struct NODE{
	int u,v,min;
	bool operator<(const NODE &a)const{
		return (a.min==min)?1:(a.min<min);
	}
};
vector<struct point>x_sort;
vector<struct point>y_sort;
priority_queue<struct NODE>q;
bool x_sort_compare(const point &a,const point &b){
	return (a.x==b.x)?1:(a.x<b.x);
}
bool y_sort_compare(const point &a,const point &b){
	return (a.y==b.y)?1:(a.y<b.y);
}
int minimum(int a,int b){
	a=fabs(a);
	b=fabs(b);
	return (a==b)?a:(a<b)?a:b;
}
int find(int x,int par[]){
	if(x==par[x])
		return x;
	par[x]=find(par[x],par);
	return par[x];
}
int kruskal(int n){
	int par[n+1],sum=0,i;
	for(i=1;i<=n;i++)
		par[i]=i;
	while(!q.empty()){
		struct NODE tmp=q.top();
		q.pop();
		int a=find(tmp.u,par);
		int b=find(tmp.v,par);
		if(a!=b){
			par[b]=a;
			sum+=tmp.min;
		}
	}
	return sum;
}
int main(){
	int n,i,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		struct point tmp;
		tmp.x=x;
		tmp.y=y;
		tmp.index=i+1;
		x_sort.push_back(tmp);
		y_sort.push_back(tmp);
	}
	sort(x_sort.begin(),x_sort.end(),x_sort_compare);
	sort(y_sort.begin(),y_sort.end(),y_sort_compare);
	for(i=0;i<n-1;i++){
		struct NODE tmp;
		tmp.u=x_sort[i].index;
		tmp.v=x_sort[i+1].index;
		tmp.min=minimum(x_sort[i+1].x-x_sort[i].x,x_sort[i+1].y-x_sort[i].y);
		q.push(tmp);

		struct NODE temp;
		temp.u=y_sort[i].index;
		temp.v=y_sort[i+1].index;
		temp.min=minimum(y_sort[i+1].x-y_sort[i].x,y_sort[i+1].y-y_sort[i].y);
		q.push(temp);

	}
	int sum = kruskal(n);
	printf("%d\n",sum);
	return 0;
}