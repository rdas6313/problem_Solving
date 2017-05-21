#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#define INF 1000000
#include<stack>
using namespace std;
stack<int>s;
map<int, vector<int> >mymap;
map<int, vector<int> >edge;
map<int, vector<int> >redge;
map<int, int>rec;
vector< pair<int, int > >vec;

void belu_da(int d[],int a[],int n){
	int i,j;
	d[1]=0;
	for(i=1;i<n;i++){
		for(j=0;j<vec.size();j++){
			int u = vec[j].first;
			int v = vec[j].second;
			int w = (a[v-1]-a[u-1]);
				w = w*w*w;
				//printf("%d-----%d----%d\n",u,w,v);
				//printf("%d-----%d----%d\n",d[u],w,d[v]);
				if(d[v] == d[u])
					continue;
			if((d[u]+w) < d[v]){
				d[v] = d[u]+w;
				//printf("%d-%d-%d\n",d[u],w,d[v]);
			}
		}
	}

	for(i=0;i<vec.size();i++){
		int u = vec[i].first;
		int v = vec[i].second;
		int w = (a[v-1]-a[u-1]);
			w = w*w*w;
			//printf("%d-----%d----%d\n",d[u],w,d[v]);
		if(d[u]+w < d[v]){
			int count = rec[v];
			for(j=0;j<mymap[count].size();j++){
				d[mymap[count][j]]=INF;
			}
		}
	}

}
void clear(int n,int count){
	int i;
	for(i=1;i<=n;i++){
		edge[i].clear();
		redge[i].clear();
		rec[i]=0;
	}
	for(i=1;i<count;i++){
		mymap[i].clear();
	}
	vec.clear();
}
void dfs1(int src,int vis[]){
	vis[src]=1;
	int i;
	for(i=0;i<edge[src].size();i++){
		if(vis[edge[src][i]]==0){
			dfs1(edge[src][i],vis);
		}
	}
	s.push(src);
}
void dfs2(int src,int vis[],int count){
	int i;
	vis[src]=1;
	for(i=0;i<redge[src].size();i++){
		if(vis[redge[src][i]]==0){
			dfs2(redge[src][i],vis,count);
		}
	}
	mymap[count].push_back(src);
	rec[src]=count;
}
int main(){
	int test,k=1;
	scanf("%d",&test);
	while(k<=test){
		int n;
		scanf("%d",&n);
		int i,a[n],d[n+1],visited[n+1],vis[n+1];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			d[i+1]=INF;
			visited[i+1]=0;
			vis[i+1]=0;
		}
		int e,x,y;
		scanf("%d",&e);
		for(i=0;i<e;i++){
			scanf("%d%d",&x,&y);
			edge[x].push_back(y);
			redge[y].push_back(x);
			vec.push_back(make_pair(x,y));
		}

		for(i=1;i<=n;i++){
			if(visited[i]==0){
				dfs1(i,visited);
			}
		}
		int j=1;
		while(!s.empty()){
			x = s.top();
			s.pop();
			if(vis[x]==0){
				dfs2(x,vis,j);
				j++;
			}
		}

		belu_da(d,a,n);
		int q;
		
		scanf("%d",&q);
		printf("Case %d:\n",k);
		while(q--){
			scanf("%d",&x);
			if(d[x]<3 || d[x]>=INF)
				printf("?\n");
			else
				printf("%d\n",d[x]);
		}

		clear(n,j);
		k++;
	}
	return 0;
}