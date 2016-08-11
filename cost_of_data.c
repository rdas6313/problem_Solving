#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
struct node{
	struct node* a[26];
	int mark;
}*root;
struct node* init(){
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0;i<26;i++)
		tmp->a[i]=NULL;
	tmp->mark=0;
	return tmp;
}
int insert(char s[]){
	int i,len=strlen(s),sum=0;
	struct node *p=root;
	for(i=0;i<len;i++){
		int id=s[i]-'a';
		if(p->a[id]==NULL){
			sum+=1;
			p->a[id]=init();
		}
		p=p->a[id];
	}
	return sum;
}
int main(){
	int n,i,sum=1;
	char s[Max];
	root=init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		sum+=insert(s);
	}
	printf("%d\n",sum);
	return 0;
}