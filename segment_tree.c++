#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define rep(s, e)  for(int i=s; i<e; ++i) 
#define arrin(string, n)   rep(0, n){ cin>>string[i];}
#define arrout(string, n)  rep(0, n){cout<<string[i]<<" ";} cout<<endl;
#define vecout(string)  rep(0, string.size()){cout<<string[i]<<" ";} cout<<endl;
#define ff(x) cout << "debug: " << #x << ": " << (x) <<endl;
#define yes cout<<"YES"<<endl;
#define pb push_back
#define no cout<<"NO"<<endl;
#define out(x) cout<<x<<endl;
#define ed  cout<<endl;
#define dout(x, y)  cout<<x<<" "<<y<<endl;
#define pii  pair<int,int>
#define F first
#define S second
#define ll long long

const int N = 100000;
int a[N];
int tree[N*3];

void init(int node, int b, int e){
	if(e == b){
		tree[node] = a[e];
		return;
	}
	int l = node * 2, r = node * 2 + 1;
	int mid = (b + e)/2;
	init(l, b, mid);
	init(r, mid + 1, e);
	tree[node] = tree[l] + tree[r];
}

int query(int node, int b, int e, int i, int j){
	if(j < b || i > e) return 0;
	if(b >= i && e <= j) return tree[node];
	int l = node * 2, r = node * 2 + 1;
	int mid = (b + e)/2;
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}


void update(int node, int b, int e, int i, int x){
	if(i > e || i < b) return;
	if(b >= i && e <= i){
		tree[node] = x;
		return;
	}
	int l = node * 2, r = node * 2 + 1;
	int mid = (b + e)/2;
	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);
	tree[node] = tree[l] + tree[r];
}

void test(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	init(1, 1, n);
    update(1, 1, n, 5, 10);
    cout << query(1, 1, n, 5 , 5) << endl;



}

int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
            test();
    }
     
        return 0;
}
