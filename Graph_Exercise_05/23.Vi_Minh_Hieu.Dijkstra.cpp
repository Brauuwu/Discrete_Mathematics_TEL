#include<bits/stdc++.h>
#define oo 1e9
using namespace std;

int n, w[105][105], s, d[105], p[105], visited[105];
vector<int> V, path;

bool cmp(int a, int b){
	return d[a]>d[b];
}

void Input(void);
void Init(void);
void Dijkstra(void);
void Result(void);


int main(){
	Input();
	Init();
	Dijkstra();
	Result();
}

void Input(){
	cout<<"Nhap so dinh n: "; cin>>n;
	cout<<"Nhap ma tran ke co trong so:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>w[i][j];
			if(i==j) w[i][j]=0;
			else if(w[i][j]==0) w[i][j]=oo;
		}
	}
	cout<<"Nhap dinh xuat phat: "; cin>>s;
}

void Init(){
	for(int v=1; v<=n; v++){
		d[v] = w[s][v];
		p[v] = s;
		if(v!=s) V.push_back(v); 
	}
	d[s]=0; p[s]=s;
}

void Dijkstra(){
	while(!V.empty()){
		sort(V.begin(), V.end(), cmp);
		int u=V[V.size()-1]; V.pop_back();
		for(int v:V){
			if(d[v]>d[u]+w[u][v]){
				d[v]=d[u]+w[u][v];
				p[v]=u;
			}
		}
	}
}

void Result(){
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<"Duong di ngan nhat tu "<<s<<" den "<<i<<" va do dai duong di:\n";
		int u=i;
		while(u!=s){
			path.push_back(u);
			u=p[u];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int j=0; j<path.size(); j++){
			cout<<path[j]<<(j<path.size()-1 ? "->" : ": ");
		}
		cout<<d[i]<<endl;
		path.clear();
	}
}
