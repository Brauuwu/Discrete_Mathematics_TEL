#include<bits/stdc++.h>
using namespace std;
int A[500][500];

bool check_dx(int a[][500], int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i][j]!=a[j][i]) return false;
		}
	}
	return true;
}

void Adj_Matrix_To_Edge_List_1(){
	cout<<endl;
	memset(A,0,sizeof(A));
	cout<<"Nhap kich thuoc ma tran nxn: ";
	int n; cin >> n;
	cout<<"Nhap ma tran "<<n<<"x"<<n<<":\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>A[i][j];
	}
	if(!check_dx(A,n)){
		cout<<"Ma tran khong doi xung. Vui long nhap lai!\n";
		Adj_Matrix_To_Edge_List_1();
	}
	else{
		cout<<"Danh sach canh cua do thi:\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j>i&&A[i][j]==1) cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
}

void Edge_List_To_Adj_Matrix_1(){
	cout<<endl;
	memset(A,0,sizeof(A));
	cout<<"Nhap so dinh V: ";
	int V; cin>>V;
	cout<<"Nhap so canh E: ";
	int E; cin>>E;
	cout<<"Nhap danh sach canh:\n";
	while(E--){
		int i,j; cin>>i>>j;
		if(A[j-1][i-1]==1){
			cout<<"Canh bi lap lai. Vui long nhap lai!\n";
			Edge_List_To_Adj_Matrix_1();
		}
		A[i-1][j-1]=A[j-1][i-1]=1;
	}
	cout<<"Ma tran ke cua do thi:\n";
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
}

void Adj_Matrix_To_Edge_List_2(){
	cout<<endl;
	memset(A,0,sizeof(A));
	cout<<"Nhap kich thuoc ma tran nxn: ";
	int n; cin >> n;
	cout<<"Nhap ma tran "<<n<<"x"<<n<<":\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>A[i][j];
	}
	cout<<"Danh sach canh cua do thi:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>i&&A[i][j]==1) cout<<i+1<<" "<<j+1<<endl;
		}
	}
}

void Edge_List_To_Adj_Matrix_2(){
	cout<<endl;
	memset(A,0,sizeof(A));
	cout<<"Nhap so dinh V: ";
	int V; cin>>V;
	cout<<"Nhap so canh E: ";
	int E; cin>>E;
	cout<<"Nhap danh sach canh:\n";
	while(E--){
		int i,j; cin>>i>>j;
		A[i-1][j-1]=1;
	}
	cout<<"Ma tran ke cua do thi:\n";
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
}

void Selection_1(){
	cout<<endl;
	cout<<"1. Ma tran ke -> Danh sach canh\n";
	cout<<"2. Danh sach canh -> Ma tran ke\n";
	cout<<"Chon truong hop: ";
	int x; cin>>x;
	switch(x){
		case 1:
			Adj_Matrix_To_Edge_List_1();
			break;
		case 2:
			Edge_List_To_Adj_Matrix_1();
			break;
		default:
			cout<<"Vui long chon lai!\n";
			Selection_1();
	}
}

void Selection_2(){
	cout<<endl;
	cout<<"1. Ma tran ke -> Danh sach canh\n";
	cout<<"2. Danh sach canh -> Ma tran ke\n";
	cout<<"Chon truong hop: ";
	int x; cin>>x;
	switch(x){
		case 1:
			Adj_Matrix_To_Edge_List_2();
			break;
		case 2:
			Edge_List_To_Adj_Matrix_2();
			break;
		default:
			cout<<"Vui long chon lai!\n";
			Selection_1();
	}
}

int main(){
	cout<<"1. Do thi vo huong\n";
	cout<<"2. Do thi co huong\n";
	cout<<"Chon loai do thi: ";
	int n; cin>>n;
	switch(n){
		case 1:
			Selection_1();
			break;
		case 2:
			Selection_2();
			break;
		default: 
			cout<<"Vui long chon lai!\n";
	}
	cout<<endl;
	return 0;
}
