    #include<stdio.h>
    #include<math.h>
    #define Max 5000001
    using namespace std;
    long long int phitable[Max];
    void phi(){
    	int i,j;
    	for(i=0;i<Max;i++){
    		phitable[i]=0;
    	}
    	for(i=2;i<Max;i++){
    		if(phitable[i]==0){
    			phitable[i]=i-1;
    			for(j=2*i;j<Max;j+=i){
    				if(phitable[j]==0)
    					phitable[j]=j;
    				phitable[j]=phitable[j]-(phitable[j]/i);
    			}
    		}
    	}
     
    	phitable[1]=1;
    	for(i=2;i<Max;i++){
    		phitable[i]*=phitable[i];
    		phitable[i]+=phitable[i-1];
    	}
    }
    int main(){
    	int k=1,test,i;
    	phi();
    	scanf("%d",&test);
    	while(k<=test){
    		int a,b;unsigned long long int s=0;
    		scanf("%d%d",&a,&b);
    		s=phitable[b]-phitable[a-1];
    		printf("Case %d: %llu\n",k,s);
    		k++;
    	}
     
    	return 0;
    }