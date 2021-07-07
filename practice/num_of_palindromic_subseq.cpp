#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,b,e) for(int (i)=(b);(i)<(e);(i)++)

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}

void solve(){
	string str;cin>>str;
	 int l=str.size();
   int a[l],p,t;
   for_each(a,a+l,[](int& i){i=1;});
   for(int i=l-2;i>=0;i--){
       for(int j=i+1;j<l;j++){
           t=a[j];
           if(j==i+1){
               if(str[j]==str[i])a[j]=3;
               else a[j]=2;
           }
           else{
               a[j]+=a[j-1]-p;
               if(str[j]==str[i]){
                   a[j]+=p+1;
               }
           }
           p=t;
           cout<<a[j]<<" ";
       }
       cout<<endl;
   }
   cout<<a[l-1]<<endl;

}

