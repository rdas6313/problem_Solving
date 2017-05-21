#include<stdio.h>
#include<queue>
using namespace std;
struct node{
	int u,w;
	bool operator<(const node &a)const{
		if(w<a.w)
			return true;
		return false;
	}
};
priority_queue<struct node>q;
int main(){
	int i,x,y;
	for(i=0;i<5;i++){
		scanf("%d%d",&x,&y);
		struct node tmp;
		tmp.u=x;
		tmp.w=y;
		q.push(tmp);
	}
	while(!q.empty()){
		struct node tmp=q.top();
		q.pop();
		printf("%d-%d\n",tmp.u,tmp.w);
	}
	return 0;
}