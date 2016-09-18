    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #define Max 1000005
    struct node{
    	struct node *link[26];
    	int mark;
    	long long int count,sum;
    }*root;
    struct node* new(){
    	struct node *tmp=(struct node*)malloc(sizeof(struct node));
    	int i;
    	for(i=0;i<26;i++)
    		tmp->link[i]=NULL;
    	tmp->mark=0;
    	tmp->count=0;
    	tmp->sum=0;
    	return tmp;
    }
    void insert(char s[],int len){
    	struct node *tmp=root;
    	int i;
    	for(i=0;i<len;i++){
    		int index=s[i]-'a';
    		if(tmp->link[index]==NULL)
    			tmp->link[index]=new();
    		tmp=tmp->link[index];
    	}
    	tmp->mark=1;
    	tmp->sum+=tmp->count*1;
    	tmp->count+=1;
     
    }
    long long int dfs(struct node *tmp,int l,long long int store[]){
    	int i;long long int val,p;
    	for(i=0;i<26;i++){
    		 if(tmp->link[i]!=NULL){
    		 	val=dfs(tmp->link[i],l+1,store);
    		 	p=tmp->count*val;
    		 	store[l]+=p;
    		 	tmp->count+=val;
    		 }
    	}
    	store[l]+=tmp->sum;
    	return tmp->count;
    }
    int main(){
    	int n,len,max=0,i;
    	char s[Max];
        
    	root=new();
    	scanf("%d",&n);
    	while(n--){
    		scanf("%s",s);
    		len=strlen(s);
    		max=(len>max)?len:max;
    		insert(s,len);
    	}
    	long long int store[max+1];
    	for(i=0;i<=max;i++)
    		store[i]=0;
    	long long int tmp=dfs(root,0,store);
    	for(i=0;i<=max;i++)
    		printf("%lld ",store[i]);
    	printf("\n");
    	return 0;
    }

Language: C