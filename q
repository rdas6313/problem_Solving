[33mcommit b6e8939cc8e7f277f72d23aef697fab000e3e83d[m
Author: rdas6313 <rdas6313@gmail.com>
Date:   Fri Aug 19 13:37:13 2016 +0530

    Hackerearth Strongly Connected Component Problm

[1mdiff --git a/walk.cpp b/walk.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..9cb9aa2[m
[1m--- /dev/null[m
[1m+++ b/walk.cpp[m
[36m@@ -0,0 +1,78 @@[m
[32m+[m[32m#include<stdio.h>[m
[32m+[m[32m#define Max 1000[m
[32m+[m[32m#include<vector>[m
[32m+[m[32musing namespace std;[m
[32m+[m[32mvector<int>vec[Max];[m
[32m+[m[32mvector<int>rev[Max];[m
[32m+[m[32mvoid init(int vis[],int n){[m
[32m+[m	[32mint i;[m
[32m+[m	[32mfor(i=0;i<=n;i++){[m
[32m+[m		[32mvis[i]=0;[m
[32m+[m	[32m}[m
[32m+[m[32m}[m
[32m+[m[32mint dfs(int vis[],int stack[],int top,int src){[m
[32m+[m	[32mvis[src]=1;[m
[32m+[m	[32mint i;[m
[32m+[m	[32mfor(i=0;i<vec[src].size();i++){[m
[32m+[m		[32mif(vis[vec[src][i]]==0){[m
[32m+[m			[32mtop=dfs(vis,stack,top,vec[src][i]);[m
[32m+[m		[32m}[m
[32m+[m	[32m}[m
[32m+[m	[32mstack[++top]=src;[m
[32m+[m	[32mreturn top;[m
[32m+[m[32m}[m
[32m+[m[32mint dfs2(int vis[],int src,int stack2[],int top){[m
[32m+[m	[32mvis[src]=1;[m
[32m+[m	[32mint i;[m
[32m+[m	[32mfor(i=0;i<rev[src].size();i++){[m
[32m+[m		[32mif(vis[rev[src][i]]==0){[m
[32m+[m			[32mtop=dfs2(vis,rev[src][i],stack2,top);[m
[32m+[m		[32m}[m
[32m+[m	[32m}[m
[32m+[m	[32mstack2[++top]=src;[m
[32m+[m	[32mreturn top;[m
[32m+[m[32m}[m
[32m+[m[32mvoid del(){[m
[32m+[m	[32mint i;[m
[32m+[m	[32mfor(i=0;i<Max;i++){[m
[32m+[m		[32mvec[i].clear();[m
[32m+[m		[32mrev[i].clear();[m
[32m+[m	[32m}[m
[32m+[m[32m}[m
[32m+[m[32mint main(){[m
[32m+[m	[32mint n,m,x,y,i,top=-1;[m
[32m+[m	[32mscanf("%d%d",&n,&m);[m
[32m+[m	[32mint vis[n+1],stack[n+1],out[n+1],stack2[n+1];[m
[32m+[m	[32minit(vis,n);[m
[32m+[m	[32mfor(i=0;i<m;i++){[m
[32m+[m		[32mscanf("%d%d",&x,&y);[m
[32m+[m		[32mvec[x].push_back(y);[m
[32m+[m		[32mrev[y].push_back(x);[m
[32m+[m	[32m}[m
[32m+[m	[32mfor(i=1;i<=n;i++){[m
[32m+[m		[32mif(vis[i]==0){[m
[32m+[m			[32mtop=dfs(vis,stack,top,i);[m
[32m+[m		[32m}[m
[32m+[m	[32m}[m
[32m+[m	[32minit(vis,n);[m
[32m+[m	[32minit(out,n);[m
[32m+[m	[32minit(stack2,n);[m
[32m+[m	[32mint top2;[m
[32m+[m	[32mwhile(top>=0){[m
[32m+[m		[32mint node=stack[top--];[m
[32m+[m		[32mtop2=-1;[m
[32m+[m		[32mif(vis[node]==0){[m
[32m+[m			[32mtop2=dfs2(vis,node,stack2,top2);[m
[32m+[m			[32mif(top2>0){[m
[32m+[m				[32mwhile(top2!=-1){[m
[32m+[m					[32mint tmp=stack2[top2--];[m
[32m+[m					[32mout[tmp]=1;[m
[32m+[m				[32m}[m
[32m+[m			[32m}[m
[32m+[m		[32m}[m
[32m+[m	[32m}[m
[32m+[m	[32mfor(i=1;i<=n;i++)[m
[32m+[m		[32mprintf("%d ",out[i]);[m
[32m+[m	[32mprintf("\n");[m
[32m+[m	[32mreturn 0;[m
[32m+[m[32m}[m
\ No newline at end of file[m
