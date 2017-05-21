#include<stdio.h>
#define Max 1000
int total,n,dp[Max][Max],array[Max][Max];
int max(int a,int b){
	return (a<b)?b:a;
}
int solve(int row,int col){
	if(row>total || col>n || col<1)
		return 0;
	if(dp[row][col]==-1){
			int tmp=-1,i;
		if(row<n){
			for(i=col;i<=col+1;i++){
				tmp = max(tmp,solve(row+1,i));
				//printf("row < n -----%d\n",tmp);
			}
		}else{
			for(i=col;i>col-2;i--){
				tmp = max(tmp,solve(row+1,i));
			}
		}
		dp[row][col] = tmp+array[row][col];
	}
	return dp[row][col];
}
void clear(){
	int i,j;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++){
			dp[i][j]=-1;
			array[i][j]=0;
		}
}
int main(){
	int test,k=1;
	scanf("%d",&test);
	for(;k<=test;k++){
		clear();
		scanf("%d",&n);
		total = n+(n-1);
		int i,j;
		for(i=1;i<=total;i++){
			if(i<=n){
				for(j=1;j<=i;j++){
					scanf("%d",&array[i][j]);
				}
			}else{
				for(j=1;j<=(total-i)+1;j++){
					scanf("%d",&array[i][j]);
				}	
			}
		}
		dp[total][1]=array[total][1];
		int tmp = solve(1,1);
		printf("Case %d: %d\n",k,tmp);
	}
	return 0;
}