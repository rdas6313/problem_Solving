#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define Max 26
#include<vector>
#include<string>
using namespace std;
vector<string>vec;
vector<string>result;
struct node{
	int mark,unblocked,done_push;
	struct node *link[26];
}*root;
struct node* make(){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0;i<Max;i++)
		tmp->link[i]='\0';
	tmp->mark=0;
	tmp->unblocked=0;
	tmp->done_push=0;
	return tmp;
}
void insert(string s,int flag){
	int len = s.length();
	int i;
	struct node *tmp=root;
	for(i=0;i<len;i++){
		int id=s[i]-'a';
		if(tmp->link[id]=='\0')
			tmp->link[id]=make();
		tmp=tmp->link[id];
		if(tmp->unblocked==0)
			tmp->unblocked=flag;
	}
	tmp->mark=1;
}
int check(string s){
	int len = s.length(),i;
	struct node* tmp = root;
	for(i=0;i<len;i++){
		int id = s[i]-'a';
		tmp = tmp->link[id];
		if(tmp->unblocked==0){
			if(tmp->done_push==0){
				tmp->done_push = 1;
				result.push_back(s.substr(0,i+1));
			}
			return 0;
		}
	}
	return 1;
}
int main(){
	root=make();
	int n;
	scanf("%d",&n);
	int i;
	char c; string s;
	for(i=0;i<n;i++){
		scanf("\n%c ",&c);
		cin>>s;
		if(c=='+')
			insert(s,1);
		else{
			insert(s,0);
			vec.push_back(s);
		}
		
	}
	int sum = 0;
	for(i=0;i<vec.size();i++){
		sum+=check(vec[i]);
	}
	int rsize = result.size();
	if(sum>0)
		printf("-1\n");
	else{
		sort(result.begin(),result.end());
		printf("%d\n",rsize);
		for(i=0;i<rsize;i++){
			cout<<result[i];
			cout<<"\n";
		}
	}
	return 0;
}