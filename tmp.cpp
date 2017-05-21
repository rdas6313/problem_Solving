    #include<bits/stdc++.h>
    using namespace std;
     
    #define in(a) scanf("%d",&a)
    #define in2(a,b) scanf("%d%d",&a,&b)
    #define inl(a) scanf("%lld",&a)
    #define inl2(a,b) scanf("%lld%lld",&a,&b)
    #define mp make_pair
    #define pb push_back
    #define ll long long
    #define pii pair<int,int>
    #define F first
    #define S second
    #define nl printf("\n")
    #define rep(i,a,b) for(int i=a;i<b;i++)
    #define per(i,a,b) for(int i=a;i>=b;i--)
    #define vi vector<int>
    #define M 1000000007
     
    ll arr[100005];
    ll front[100005];
    ll back[100005];
    int even=1,n;
    int odd=0;
     
    int main(){
     cin >> n;
     ll sum=0;
     rep(i,0,n){
     	 cin >> arr[i];
     	 sum+=arr[i];
     	 if(sum&1){front[i]=odd;odd++;}
     	 else{front[i]=even;even++;}
     }
     int i;
     for(i=0;i<n;i++){
        printf("%lld ",front[i]);
     }
     printf("\n");
     even=1;odd=0;
     sum=0;
    per(i,n-1,0){
     	 sum+=arr[i];
     	 if(sum&1){back[i]=odd;odd++;}
     	 else{back[i]=even;even++;}
     }

     for(i=0;i<n;i++){
        printf("%lld ",back[i]);
     }
     printf("\n");

     per(i,n-2,0)
      back[i]+=back[i+1];
      ll ans=0;
     rep(i,0,n-1)ans=(ans%M + (front[i]%M*back[i+1]%M)%M);
     //rep(i,0,n)cout << front[i]<<" "<<endl;
     cout << ans << endl;
      return 0;
    }
