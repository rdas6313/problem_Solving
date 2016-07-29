#include<stdio.h>
#include<math.h>
#include<set>
#include<utility>
using namespace std;
/*
struct cmp{
	bool  operator()(  const pair <int,int>& a, const pair <int,int>& b){
		if(a.second<b.second) return true;
		else if(a.second==b.second){
			if(a.first==b.first) return true;
            return a.first<b.first;
		}
		else return false;
	}
};*/
set< pair<int,int> >s;

void start(int par[],int size[],int n){
	int i;
	for(i=1;i<=n;i++){
		par[i]=i;
		size[i]=1;
		//printf("%d ",i);
		s.insert(make_pair(1,i));
	}
	/*
	set< pair<int,int> >::iterator it;
	for(it=s.begin();it!=s.end();it++){
		printf("%d--%d\n",(*it).first,(*it).second);

}
	*/
	
}
int find(int par[],int node){
	if(par[node]==node)
		return node;
	par[node]=find(par,par[node]);
	return par[node];
}
void merge(int par[],int size[],int x,int y){
		s.erase(s.find(make_pair(size[x],x)));
		s.erase(s.find(make_pair(size[y],y)));
		par[y]=x;
		size[x]+=size[y];
		
		s.insert(make_pair(size[x],x));
	
}
int main(){
	freopen("input.txt","r",stdin);
	int n,q,i,a,b;
	
	scanf("%d%d",&n,&q);
	int par[n+1],size[n+1];
	start(par,size,n);
	
	
	for(i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		int x=find(par,a);
		int y=find(par,b);
		if(x!=y)
			merge(par,size,x,y);
		int big=(*(s.rbegin())).second;
		int small=(*(s.begin())).second;
		int diff=fabs(small-big);
		printf("%d\n",diff);
		
	}
	return 0;
}