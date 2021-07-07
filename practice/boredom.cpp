#include<bits/stdc++.h>
using namespace std;

typedef int ll;
typedef unsigned long long ull;

#define F first
#define S second

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
	int n,t;
	cin>>n;
	map<int,int> counts;
	vector<pair<int,int>> cnts;
	for(int i=0;i<n;i++){
		cin>>t;
		counts[t]++;
	}
	for(auto c:counts){
		cnts.push_back(c);
	}
	counts.clear();
	int s=cnts.size();
	ll score[s][s];
	for(int i=0;i<s;i++){
		score[i][i]=cnts[i].F*cnts[i].S;
	}
	for(int l=2;l<=s;l++){
		for(int i=0;i<=(s-l);i++){
			int j=i+l-1;
			ll m=-1;
			for(int k=i;k<=j;k++){
				ll left=0,right=0;
				int lj=k-1,ri=k+1;
				if(lj>=i){
					if(cnts[lj].F==cnts[k].F-1)lj--;
				}
				if(ri<=j){
					if(cnts[ri].F==cnts[k].F+1)ri++;
				}
				if(lj>=i)left=score[i][lj];
				if(ri<=j)right=score[ri][j];
				if(m<(left+right+(cnts[k].F*cnts[k].S))){
					m=(left+right+(cnts[k].F*cnts[k].S));
				}
			}
			score[i][j]=m;
		}
	}
	cout<<score[0][s-1]<<endl;
}

