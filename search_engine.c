#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 1000000
struct node{
	struct node *link[26];
	int mark,big;
}*root;
struct node* create(){
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0;i<26;i++){
		tmp->link[i]=NULL;
	}
	tmp->mark=0;
	tmp->big=-1;
	return tmp;
}
void insert(char s[],int val){
	int i;
	struct node* tmp=root;
	int len=strlen(s);
	for(i=0;i<len;i++){
		int id=s[i]-'a';
		if(tmp->link[id]==NULL)
			tmp->link[id]=create();
		tmp->big=(tmp->big<val)?val:tmp->big;
		tmp=tmp->link[id];
	}
	tmp->mark=1;

}
/*
int all(struct node *tmp){
	int i,big=tmp->mark,val;
	for(i=0;i<26;i++){
		if(tmp->link[i]!=NULL){
			val=all(tmp->link[i]);
			big=(val>big)?val:big;
		}
		
	}
	return big;
}*/
int search(char s[]){
	int i,len=strlen(s),id;
	struct node *tmp=root;
	for(i=0;i<len;i++){
		 id=s[i]-'a';
		if(tmp->link[id]==NULL)
			return -1;
		tmp=tmp->link[id];
	}

	return tmp->big;

}
int main(){
	freopen("input.txt","r",stdin);
	int n,q,i,val;
	char s[Max];
	root=create();
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("\n%s%d",s,&val);
		insert(s,val);
	}
	for(i=0;i<q;i++){
		scanf("\n%s",s);
		int v=search(s);
		printf("%d\n",v);
	}
	return 0;
}