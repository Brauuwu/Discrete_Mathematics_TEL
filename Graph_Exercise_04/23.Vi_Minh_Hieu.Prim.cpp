#include<bits/stdc++.h>
#define List vector<pair<int,int>>
using namespace std;

List adj[1000];
int n;
bool used[1000];

struct Edge{
	int x, y, m;
};

void Prim(int u){
	vector<Edge> MST;
	int d=0;
	used[u]=true;
	while(MST.size()<n-1){
		int min_w = INT_MAX;
		int X,Y;
		for(int i=1;i<=n;i++){
			if(used[i]){
				for(pair<int,int> it:adj[i]){
					int j=it.first, sini=it.second;
					if(!used[j] && sini<min_w){
						min_w=sini;
						X=j; Y=i;
					}
				}
			}
		}
		MST.push_back({X,Y,min_w});
		d+=min_w;
		used[X]=true;
	}
	cout<<"\nDo dai cay khung nho nhat: "<<d<<endl;
	cout<<"Tap canh cua cay khung nho nhat:\n";
	for(Edge e:MST){
		cout<<e.x<<" "<<e.y<<" "<<e.m<<endl;
	}
}

int main(){
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap ma tran ke:\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int w; cin>>w;
			if(w){
				adj[i].push_back({j,w});
				adj[j].push_back({i,w});
			}
		}
	}
	memset(used,false,sizeof(used));
	cout<<"Nhap dinh xuat phat: ";
	int s; cin>>s;
	Prim(s);
	return 0;
}
