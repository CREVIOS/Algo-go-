#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX (1+(1<<6))
#define inf 0x7fffffff

int arr[MAX];
int tree[MAX],tree1[MAX];

void build_tree(int node, int a, int b) {
    if(a > b) return;

  	if(a == b) {
    		tree[node] = arr[a];
    		tree1[node] = arr[a];
		return;
	}

	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);


	tree[node] = tree[node*2]+tree[node*2+1];
	tree1[node] = max(tree1[node*2],tree1[node*2+1]);
}

void update_tree(int node,int a,int b, int i, int j, int value) {
  	if(a == b) {
    		tree[node] = value;
    		tree1[node]=value;
    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

	tree[node] = tree[node*2]+tree[node*2+1];
	tree1[node] = max(tree1[node*2],tree1[node*2+1]);
}
void update_tree1(int node,int a, int b,int i, int j, int value) {

	if(a > b || a > j || b < i)
		return;

  	if(a == b) { // Leaf node
    		tree[node] = __gcd(tree[node],value);
    		tree1[node] = __gcd(tree[node],value);
    		return;
	}

	update_tree1(node*2, a, (a+b)/2, i, j, value);
	update_tree1(1+node*2, 1+(a+b)/2, b, i, j, value);

	tree[node] = tree[node*2]+tree[node*2+1];
	tree1[node] = max(tree1[node*2],tree1[node*2+1]);
}

/*int query_tree(int node,int a , int b,int i, int j) {

	if(a >= i && b <= j)
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
	int sum = q1+ q2;
	return sum;
}*/
int query_Tree(int x, int a, int b, int i, int j) {
	int mid = (a+b)/2;

	if(a >= i && b <= j) return tree[x];

	if(j <= mid) return query_Tree(x*2, a, mid, i, j);
	else if(i > mid) return query_Tree(x*2+1, mid+1, b, i, j);

	int left = query_Tree(x*2, a, mid, i, mid);
	int   right = query_Tree(x*2+1, mid+1, b, mid+1, j);

	return left+right;
}
int query_tree1(int node,int a,int b,int i, int j) {



	if(a >= i && b <= j)
		return tree1[node];

	int q1 = query_tree1(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree1(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1 , q2) ;

	return res;
}

int main() {
    int N,q;
    scanf("%d",&N);
    scanf("%d",&q);
	for(int i = 0; i < N; i++) scanf("%d",&arr[i]);

	build_tree(1, 0, N-1);

while(q--)
{
    int a;
scanf("%d",&a);
    if(a==1)
    {
        int l , r , x;
       scanf("%d%d%d",&l,&r,&x);
    update_tree(1,0,N-1, l-1, r-1, x);
    }
    else if(a==2)
    {
        int l,r,x;
         scanf("%d%d%d",&l,&r,&x);
         update_tree1(1,0,N-1, l-1, r-1, x);

    }
    else if(a==3)
    {
        int l , r;
         scanf("%d%d",&l,&r);
        cout << query_tree1(1,0,N-1, l-1, r-1) << endl;

    }
    else if(a==4){
        int l , r;
         scanf("%d%d",&l,&r);
        cout << query_Tree(1, 0,N-1,l-1, r-1) << endl;
    }
}
	return 0;


}
