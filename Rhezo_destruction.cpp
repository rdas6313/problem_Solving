#include<stdio.h>
#include<vector>
#define Max 100000
using namespace std;
vector<int>vec[Max];
void articulation_point(int src,int vis[],int dis[],int low[],int t,int arti[],int par[]){
	vis[src]=1;
	dis[src]=low[src]=t;
	int child=0,i;
	for(i=0;i<vec[src].size();i++){
		int tmp=vec[src][i];
		child++;
		if(!vis[tmp]){
			par[tmp]=src;
			articulation_point(tmp,vis,dis,low,t+1,arti,par);
			low[src]=(low[src]<low[tmp])?low[src]:low[tmp];
			if(dis[src]<=low[tmp] && par[src]!=0){
				arti[src]=1;
			}else if(par[src]==0 && child>1 && dis[src]<low[tmp]){
				arti[src]=1;
			}
		}else if(par[src]!=tmp){
			low[src]=(low[src]<dis[tmp])?low[src]:dis[tmp];
		}
	}
}
int main(){
	int node,edge,i,x,y;
	scanf("%d%d",&node,&edge);
	int vis[node+1],dis[node+1],low[node+1],arti[node+1],par[node+1],size[node+1];
	for(i=0;i<=node;i++)
		vis[i]=dis[i]=low[i]=arti[i]=par[i]=size[i]=0;
	for(i=0;i<edge;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		size[x]++;
		size[y]++;
	}
	for(i=1;i<=node;i++){
		if(!vis[i]){
			articulation_point(i,vis,dis,low,0,arti,par);
		}
	}
	int q;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&x);
		if(arti[x]!=0){
			printf("Satisfied %d\n",size[x]);
		}
		else
			printf("Not Satisfied\n");
	}
	return 0;
}