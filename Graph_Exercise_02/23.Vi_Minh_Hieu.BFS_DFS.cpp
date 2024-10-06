#include<bits/stdc++.h>
#define List vector<int>
using namespace std;

List Adj[1000];
int n, m, visited[1000];
int a[500][500];

void Adj_Matrix(){
	cout<<endl;
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap so canh: "; cin>>m;
	cout<<"Nhap ma tran "<<n<<"x"<<n<<":\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) Adj[i].push_back(j);
		}
	}
}

void Edge_List(){
	cout<<endl;
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap so canh: "; cin>>m;
	cout<<"Nhap danh sach "<<m<<" canh:\n";
	while(m--){
		int x,y; cin>>x>>y;
		Adj[x].push_back(y);
		Adj[y].push_back(x);
	}
}

void Adj_List(){
	cout<<endl;
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap so canh: "; cin>>m;
	cout<<"Nhap danh sach ke cua "<<n<<" dinh:\n";
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s,tmp; getline(cin,s);
		stringstream ss(s);
		while(ss>>tmp){
			if(isdigit(tmp[0])){
				int x=stoi(tmp);
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

void BFS(){
	Input();
	cout<<endl;
	cout<<"Ket qua tim kiem bang BFS: ";
	queue<int> q;
	q.push(1);
	visited[1]=1;
	cout<<1<<" ";
	while(!q.empty()){
		int v=q.front(); q.pop();
		for(int x:Adj[v]){
			if(!visited[x]){
				visited[x]=1;
				cout<<x<<" ";
				q.push(x);
			}
		}
	}
}

void DFS(){
	Input();
	cout<<endl;
	cout<<"Ket qua tim kiem bang DFS: ";
	stack<int> st;
	st.push(1);
	visited[1]=1;
	cout<<1<<" ";
	while(!st.empty()){
		int v=st.top(); st.pop();
		for(int x:Adj[v]){
			if(!visited[x]){
				visited[x]=1;
				cout<<x<<" ";
				st.push(v);
				st.push(x);
				break;
			}
		}
	}
}

int main(){
	memset(visited,0,sizeof(visited));
	cout<<"1. BFS\n";
	cout<<"2. DFS\n";
	cout<<"Chon thuat toan: ";
	
	int x; cin>>x;
	switch(x){
		case 1:
			BFS();
			break;
		case 2:
			DFS();
			break;
	}
}
