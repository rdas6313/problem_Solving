#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	struct node *link[4];
	int mark;
}*root; 				//Trie Node Structure
struct node* create(){		//Trie Node creation
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	int i;
	for(i=0;i<4;i++)
		tmp->link[i]=NULL;
	tmp->mark=0;
	return tmp;
}
int insert(char s[],int big){ //Insertion of a string to a Trie.	
	struct node *tmp=root;
	int len=strlen(s),i,pos;
	for(i=0;i<len;i++){
	/*	if(s[i]=='A')
			pos=0;
		else if(s[i]=='C')
			pos=1;
		else if(s[i]=='G')
			pos=2;
		else
			pos=3;
	*/	
		pos=s[i]-'a';
		if(tmp->link[pos]==NULL)
			tmp->link[pos]=create();
		tmp=tmp->link[pos];

	/*	
		tmp->mark++;
		if(big < tmp->mark*(i+1))
			big=tmp->mark*(i+1);	*/
	}/*
	return big<len?len:big;
	*/
}
/*
int main(){
	//freopen("input.txt","r",stdin);
	int test,k=1;
	scanf("%d",&test);
	while(k<=test){
		int n,i,big=-1;
		root=create();
		char s[100];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",s);
			big=insert(s,big);
		}
		printf("Case %d: %d\n",k,big);
		k++;
	}
	return 0;
}*/