#include<bits/stdc++.h>
#define List vector<int>
using namespace std;

int a[100][100], visited[1000], parent[1000];
List Adj[1000];

void Adj_Matrix(){
	cout<<endl;
	cout<<"Nhap so dinh: ";
	int n; cin>>n;
	cout<<"Nhap ma tran ke:\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) Adj[i].push_back(j);
		}
	}
}

void Edge_List(){
	cout<<endl;
	cout<<"Nhap so canh: ";
	int m; cin>>m;
	cout<<"Nhap danh sach canh:\n";
	for(int i=1;i<=m;i++){
		int x,y; cin>>x>>y;
		Adj[x].push_back(y);
		Adj[y].push_back(x);
	}
}

void Adj_List(){
	cout<<endl;
	cout<<"Nhap so dinh: ";
	int n; cin>>n;
	cout<<"Nhap danh sach ke:\n";
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s; getline(cin,s);
		stringstream ss(s);
		string temp;
		while(ss>>temp){
			if(isdigit(temp[0]) && isdigit(temp[temp.size()-1])){
				int x=stoi(temp);
				Adj[i].push_back(x);
			}
		}
	}
}

void Input(){
	cout<<endl;
	cout<<"1. Ma tran ke\n";
	cout<<"2. Danh sach canh\n";
	cout<<"3. Danh sach ke\n";
	cout<<"Chon phuong an nhap: ";
	int x; cin>>x;
	switch(x){
		case 1:
			Adj_Matrix();
			break;
		case 2:
			Edge_List();
			break;
		case 3:
			Adj_List();
			break;
	}
}

void DFS(int v){
	visited[v]=1;
	for(int x:Adj[v]){
		if(!visited[x]){
			parent[x]=v;
			DFS(x);
		}
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u]=1;
	while(!q.empty()){
		int v=q.front(); q.pop();
		for(int x:Adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x]=1;
				parent[x]=v;
			}
		}
	}
}

void Path(int s, int t){
	if(!parent[t]){
		cout<<"Khong co duong di tu "<<s<<" den "<<t;
		return;
	}
	else{
		vector<int> path;
		path.push_back(t);
		int u=parent[t];
		while(u!=s){
			path.push_back(u);
			u=parent[u];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		cout<<"Duong di: ";
		for(int x:path) cout<<x<<" ";
	}
}

int main(){
	memset(visited,0,sizeof(visited));
	memset(parent,0,sizeof(parent));
	cout<<"1. BFS\n";
	cout<<"2. DFS\n";
	cout<<"Chon thuat toan: ";
	int x, Selection;
	cin>>x;
	switch(x){
		case 1:
			Selection=1;
			break;
		case 2:
			Selection=2;
			break;
		default: return 0;
	}
	Input();
	cout<<"Nhap dinh bat dau: ";
	int s; cin>>s;
	cout<<"Nhap dinh ket thuc: ";
	int t; cin>>t;
	
	switch(Selection){
		case 1:
			BFS(s);
			break;
		case 2:
			DFS(s);
			break;
		default: return 0;
	}
	Path(s,t);
	return 0;
}
