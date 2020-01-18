#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long


/*
int main(){
    long long int t,c=1,mis;
    scanf("%d",&t);
    while(t--){
    string mains,sub;
    cin>>mains>>sub;
    scanf("%d",&mis);
    long long int  match=0;
    for(int i=0;i<mains.length()-sub.length()+1;i++){
         string s1=mains.substr(i,i+sub.length());

        /* for(int j=0;j<sub.length();j++){
             s1=s1+mains[i+j];
             //cout<<s1<<endl;
         }


         ll counter=0;
         //named (outer);
       for(int k=0;k<sub.length();k++){
            if(s1[k]!=sub[k]){

                counter++;
                //cout<<"hh"<<endl;
            }
            if(counter>mis) {
                break ;
            }
         }
         if(counter<=mis){
                match++;
                //cout<<s1<<endl;

         }

    }
  cout<<"Case "<<c<<":"<<" "<<match<<endl;

    c++;

    }
}
*/
/* min cost path
int main()
{

    int n ;
    cin>>n;
    int a[10][10]={0,0};
    for(int i = 0;i<n;i++)
    {

        for(int j = 0;j<n;j++)
        {
            cin>>a[i][j];
        }

        }

    int mincost[10][10];
  mincost[0][0] = a[0][0];

    for(int i = 1;i<n;i++)
    {

        mincost[i][0] = mincost[i-1][0] + a[i][0];
    }
    for(int j = 1;j<n;j++)
    {

        mincost[0][j] = mincost[0][j-1] + a[0][j];
    }
    for(int i = 1; i<n;i++)
    {

        for(int j = 1;j<n;j++)
        {
            mincost[i][j] = min(mincost[i-1][j],mincost[i][j-1])+a[i][j];
        }
    }
    cout<<mincost[n-1][n-1]<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
    int main()
    {
        int X,Y; //X:number of rows, Y: number of columns
        X = Y = 3; //assuming 10X10 matrix
        int Cost[X][Y];

        F(i,0,X-1)
        {
            F(j,0,Y-1)
            {
                //Take input the cost of visiting cell (i,j)
                cin>>Cost[i][j];
            }
        }

        int MinCost[X][Y]; //declare the minCost matrix

        MinCost[0][0] = Cost[0][0];

        // initialize first row of MinCost matrix
        F(j,1,Y-1)
            MinCost[0][j] = MinCost[0][j-1] + Cost[0][j];

        //Initialize first column of MinCost Matrix
        F(i,1,X-1)
            MinCost[i][0] = MinCost[i-1][0] + Cost[i][0];

        //This bottom-up approach ensures that all the sub-problems needed
        // have already been calculated.
        F(i,1,X-1)
        {
            F(j,1,Y-1)
            {
                //Calculate cost of visiting (i,j) using the
                //recurrence relation discussed above
                MinCost[i][j] = min(MinCost[i-1][j],MinCost[i][j-1]) + Cost[i][j];
            }
        }

        cout<<"Minimum cost from (0,0) to (X,Y) is "<<MinCost[X-1][Y-1];
        return 0;
    }
   The numways recurrence = numWays(i,j) = numWays(i-1,j) + numWays(i,j-1);

    */
    /*
    Problem Statement : A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid. Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

Input is three integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively. In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.

Solution : The code below explains how to proceed with the solution. The problem is same as the previous one, except for few extra checks(due to blocked cells.)

   #include <bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
    #define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
    #define MOD 1000000007
    int main()
    {
        int M,N,P,_i,_j;

        //Take input the number of rows, columns and blocked cells
        cin>>M>>N>>P;

        //declaring a Grid array which stores the number of paths
        ll Grid[M+1][N+1];

        //Note that we'll be using 1-based indexing here.
        //initialize all paths initially as 0
        memset(Grid, 0, sizeof(Grid));

        F(i,0,P-1)
        {
            //Take in the blocked cells and mark them with a special value(-1 here)
            cin>>_i>>_j;
            Grid[_i][_j] = -1;
        }

        // If the initial cell is blocked, there is no way of moving anywhere
        if(Grid[1][1] == -1)
        {
            printf("0");
            return 0;
        }


        // Initializing the leftmost column
        //Here, If we encounter a blocked cell, there is no way of visiting any cell
        //directly below it.(therefore the break)
        F(i,1,M)
        {
            if(Grid[i][1] == 0) Grid[i][1] = 1LL;
            else break;
        }


        //Similarly initialize the topmost row.
        F(i,2,N)
        {
            if(Grid[1][i] == 0) Grid[1][i] = 1LL;
            else break;
        }


        //Now the recurrence part
        //The only difference is that if a cell has been marked as -1,
        //simply ignore it and continue to the next iteration.
        F(i,2,M)
        {
            F(j,2,N)
            {
                if(Grid[i][j] == -1) continue;

                //While adding the number of ways from the left and top cells,
                //check that they are reachable,i.e. they aren't blocked

                if(Grid[i-1][j] > 0) Grid[i][j] = (Grid[i][j] + Grid[i-1][j] + MOD)%MOD;
                if(Grid[i][j-1] > 0) Grid[i][j] = (Grid[i][j] + Grid[i][j-1] + MOD)%MOD;
            }
        }


        //If the final cell is blocked, output 0, otherwise the answer
        printf("%lld",(Grid[M][N] >= 0 ? Grid[M][N] : 0));
        return 0;
    }
    */
    /*
    Edit Distance
Edit distance is a way of quantifying how dissimilar two strings are, i.e., how many operations (add, delete or replace character) it would take to transform one string to the other. This is one of the most common variants of edit distance, also called Levenshtein distance, named after Soviet computer scientist, Vladimir Levenshtein. There are 3 operations which can be applied to either string, namely: insertion, deletion and replacement.

 int editDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // for all i, j, dp[i][j] will hold the edit distance between the first
        // i characters of source string and first j characters of target string
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        // source can be transformed into target prefix by inserting
        // all of the characters in the prefix
        for (int i = 1; i <= n; i++) {
            dp[0][i] = i;
        }
        // source prefixes can be transformed into empty string by
        // by deleting all of the characters
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // no operation required as characters are the same
                }
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],    // substitution
                            min(dp[i][j - 1],     // insertion
                                dp[i - 1][j]));    // deletion
                }
            }
        }
        return dp[m][n];
    }
    */
/*
You are given a N ∗ M matrix. You need to print the sum of all the numbers in the rectangle which has (1,1) as the top left corner and (X,Y) as the bottom right corner.
 MATRIX SUM USING Dynamic Programming
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y;
    long q;
    cin>>n>>m;
    long arr[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(i==1 && j!=1) arr[i][j]+= arr[i][j-1];
            else if(j==1 && i!=1) arr[i][j]+= arr[i-1][j];
            else if(i!= 1 && j!=1){
                arr[i][j]= arr[i][j]+ arr[i-1][j]+ arr[i][j-1]- arr[i-1][j-1];}  //every (i,j)th element of the array will be the sum of //all the elements in the rectangle from (1,1) to (i,j)
        }
    }

    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<arr[x][y]<<endl;
    }
    return 0;
}*/

/*
#include<iostream>
using namespace std;

int main(){
	int arr[5]={-4,-3, 3, 4, -1};
	int n= sizeof(arr)/sizeof(arr[0]);
	int local_max= arr[0];
	int global_max= arr[0];
	int start=0, end=0, temp=0;
	for(int i=1; i<n; i++){

		local_max= max(arr[i], local_max+arr[i]);
		if(local_max > global_max){
			global_max= local_max;
			start= temp;
			end= i;
		}
		if(local_max<0){
			local_max=0;
			temp= i+1;
		}
	}
	cout<<"The maximum sum subarray has the sum: "<<global_max;
	cout<<"\nThe index of sub-array is: "<<start<<", "<<end;
	return 0;
}
*/
/*
calculating the length of the longest common subsequence of two strings A and B of length N, would look like this:


int dp[N+1][N+1];
for (int i = 0; i <= N; ++i)
  dp[0][i] = dp[i][0] = 0;
for (int i = 1; i <= N; ++i)
  for (int j = 1; j <= N; ++j) {
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    if (A[i-1] == B[j-1])
      dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
  }
int answer = dp[N][N];
*/
/*
count how many subsets have sum of elements greater than or equal to a given value.

Algorithm is simple:

solve(set, set_size, val)
    count = 0
    for x = 0 to power(2, set_size)
        sum = 0
        for k = 0 to set_size
            if kth bit is set in x
                sum = sum + set[k]
        if sum >= val
             count = count + 1
    return count
    */
    /*
    The first line of this equation deals with a board modeled as squares indexed on 1 at the lowest bound and n at the highest bound. The second line specifies what happens at the last rank; providing a base case. The third line, the recursion, is the important part. It represents the A,B,C,D terms in the example. From this definition we can derive straightforward recursive code for q(i, j). In the following pseudocode, n is the size of the board, c(i, j) is the cost function, and min() returns the minimum of a number of values:
    function minCost(i, j)
    if j < 1 or j > n
        return infinity
    else if i = 1
        return c(i, j)
    else
        return min( minCost(i-1, j-1), minCost(i-1, j), minCost(i-1, j+1) ) + c(i, j)
        */
        /*
        To actually multiply the matrices using the proper splits, we need the following algorithm:

   function MatrixChainMultiply(chain from 1 to n)       // returns the final matrix, i.e. A1×A2×... ×An
      OptimalMatrixChainParenthesis(chain from 1 to n)   // this will produce s[ . ] and m[ . ] "tables"
      OptimalMatrixMultiplication(s, chain from 1 to n)  // actually multiply

   function OptimalMatrixMultiplication(s, i, j)   // returns the result of multiplying a chain of matrices from Ai to Aj in optimal way
      if i < j
         // keep on splitting the chain and multiplying the matrices in left and right sides
         LeftSide = OptimalMatrixMultiplication(s, i, s[i, j])
         RightSide = OptimalMatrixMultiplication(s, s[i, j] + 1, j)
         return MatrixMultiply(LeftSide, RightSide)
      else if i = j
         return Ai   // matrix at position i
      else
         print "error, i <= j must hold"

    function MatrixMultiply(A, B)    // function that multiplies two matrices
      if columns(A) = rows(B)
         for i = 1, rows(A)
            for j = 1, columns(B)
               C[i, j] = 0
               for k = 1, columns(A)
                   C[i, j] = C[i, j] + A[i, k]*B[k, j]
               return C
      else
          print "error, incompatible dimensions."

          */

/*
void shiftByK(char S[], char shiftedS[], int N, int K) {
    // Iterate through the length of given string
    for(int i=0; i<N; i++) {
        // Find the index for this current character in shiftedS[]
        int idx = (i+K) % N;
        // Copy that character at the found index idx
        shiftedS[idx] = S[i];
    }
    // Add a NULL character to mark the end of string
    shiftedS[N] = '\0';
}
*/
int build(int at,int l , int r)
{

    suma[at] = 0;
    if(l==r)
    {

        return ;
    }
    int mid = (l+r) / 2 ;
    build(at*2,l,mid);
    build(at*2+1,mid+1,r);

    sum[at] = sum[at*2] + sum[at*2+1];
}
int update(int at,  int l , int r , int pos ,int u)
{

    if(l==r)
    {

        sum[pos]+=u;
        return ;
    }
    int mid = (l+r) / 2 ;
    if(pos<=mid)
    {
        update(at*2,l,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,r,pos, u);
    }
    sum[at] = sum[at*2] + sum[at*2+1];
}
int query(int at, int L, int R , int l, int r)
{

    if(r<L||R<l) return 0;
    if(l<=L&&R<=r) truen sum[at];

    int mid = (l+ r) / 2 ;
    int x = query(at*2,L,mid,l,r);
    int y = query(at*2,mid+1,R,l,r);

    return x+y;
}
