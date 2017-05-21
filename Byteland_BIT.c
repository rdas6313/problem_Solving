#include<stdio.h>
#define Max 1000
int BIT[Max][Max][Max];
void init(){
	int i,j,k;
	for(i=0;i<Max;i++)
		for(j=0;j<Max;j++)
			for(k=0;k<Max;k++)
				BIT[i][j][k]=0;

}

int main(){
	int n,q,c;
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d",&c);
		switch(c){
			case 1:
				scanf("%d%d%d%d",&x,&y,&z,&val);
				update(x,y,z,val);
				break;
			case 2:
				break;
		}
	}
	return 0;
}