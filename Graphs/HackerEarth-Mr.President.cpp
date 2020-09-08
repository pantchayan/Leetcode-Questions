
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define lli long long int


int findPar(int vtx,vector<int>& par){
    if(par[vtx] == vtx) return vtx;

    return par[vtx] = findPar(par[vtx],par);
}

int main(){
	lli N,M,K;

	cin >> N;
	cin >> M;
	cin >> K;

	vector<vector<int>> roads;

	for(int i=0;i<M;i++){
		int u,v,w;
		cin >> u >> v >> w;
		vector<int> road = {u,v,w};
		roads.push_back(road);
	}

	std::sort(roads.begin(),
          roads.end(),
          [] (vector<int> &a, vector<int> &b)
          {
              return a[2] < b[2];
          });

	vector<int> par;

    for(int i=0;i<=N;i++){
        par.push_back(i);
    }
	vector<vector<int>> roadsMST;

    lli cost = 0;
    for(vector<int> road:roads){
        int p1 = findPar(road[0],par);
        int p2 = findPar(road[1],par);
         
        if(p1!=p2){
            par[p2] = p1;
            cost = cost + road[2];
			roadsMST.push_back(road);
        }
    }
	int Compo = 0;
	bool flag = false;
	for(int i=1;i<=N;i++){
		if(par[i]==i && ++Compo>1){
			cout << -1;
			flag = true;
		}
	}
	if(!flag){
	if(cost>K){
		int count = 0;
		for(int i=roadsMST.size()-1;i>=0;i--){
			cost = cost - roadsMST[i][2] +1;
			count++;
			if(cost<=K){
				cout << count;
				break;
			}
		}
		if(cost>K){
			cout << -1;
		}
	}
	else{
		cout << 0;
	}
	}

	return 0;
}
auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();



