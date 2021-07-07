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
	string s;cin>>s;
	int l=s.size();
        int a[l],t,p,m=0,n=0,mx=1;
        for_each(a,a+l,[](int&i){i=1;});
        for(int i=l-2;i>=0;i--){
            p=0;
            for(int j=i+1;j<l;j++){
                t=a[j];
                a[j]=(s[i]==s[j])?p+2:0;
                if(a[j]>mx){
                    mx=a[j];
                    m=i;
                    n=j;
        //cout<<i<<":"<<j<<"-"<<s.substr(m,n-m)<<endl;
                }
                p=t;
		cout<<a[j]<<" ";
            }
	    cout<<endl;
        }
        cout<<s.substr(m,n-m+1)<<endl;


}

