#include<iostream>
using namespace std;
#define v 4

void sol(int color[]){
    cout << "Solution Exists:"
			" Following are the assigned colors \n";
	for (int i = 0; i < v; i++)
		cout << " " << color[i];
	cout << "\n";
}
bool check(bool graph[v][v],int color[]){
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
            if(graph[i][j]&& color[j]==color[i])
            return false;
        }
    }
    return true;
}
bool final(bool graph[v][v],int m,int ind,int color[v]){
    if(ind==v){
        if(check(graph,color)){
            sol(color);
            return true;
        }
        return false;
    }
    for(int j=1;j<=m;j++){
        color[ind]=j;
    
    if(final(graph,m,ind+1,color))
        return true;
        color[ind]=0;
    }
    return false;
}
int main(){
    bool graph[v][v] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3;
    int color[v];
	for (int i = 0; i < v; i++)
		color[i] = 0;

	if (!final(graph, m, 0, color))
		cout << "Solution does not exist";
	return 0;
}


#include <iostream>
using namespace std;

const int MAXN = 100;
int n, W, w[MAXN], v[MAXN], maxVal;

void backtrack(int i, int curW, int curVal) {
    if (curW > W) {
        return;
    }
    if (i == n) {
        maxVal = max(maxVal, curVal);
        return;
    }
    // not selecting item i
    backtrack(i+1, curW, curVal);
    // selecting item i
    backtrack(i+1, curW+w[i], curVal+v[i]);
}

int main() {
    cout<<"Enter no of objects"<<endl;
    cin>>n;
    cout<<"Capacity:"<<endl;
    cin>>W;
   
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    maxVal = 0;
    backtrack(0, 0, 0);
    cout << "Maximum value: " << maxVal << endl;
    return 0;
}



#include <iostream>
using namespace std;

const int MAXN = 100;
int n, sum, a[MAXN];
bool found;
bool selected[MAXN];

void backtrack(int i, int curSum) {
    if (curSum == sum) {
        found = true;
        cout << "Subset that sums to " << sum << ": ";
        for (int j = 0; j < i; j++) {
            if (selected[j]) {
                cout << a[j] << " ";
            }
        }
        cout << endl;
        return;
    }
    if (i == n || curSum > sum) {
        return;
    }
    selected[i] = false;
    backtrack(i+1, curSum); // not selecting a[i]
    selected[i] = true;
    backtrack(i+1, curSum+a[i]); // selecting a[i]
}
 
int main() {
    cin >> n >> sum;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    found = false;
    backtrack(0, 0);
    if (!found) {
        cout << "Impossible to find a subset that sums to " << sum << endl;
    }
    return 0;
}


#include <iostream>
using namespace std;
bool isSafe(int** arr, int x, int y, int n){
	for(int row=0;row<x;row++){
		if(arr[row][y]==1){
			return false;
		}
	}
	int row=x;
	int col=y;
	while(row>=0 && col>=0){
		if(arr[row][col]==1){
			return false;
		}
		row--;
		col--;
	}
	row=x;
	col=y;
	while(row>=0 && col<n){
		if(arr[row][col]==1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}
bool nQueen(int**arr, int x, int n){
	if(x>=n){
		return true;
	}
	for(int col=0;col<n;col++){
		if(isSafe(arr,x,col,n)){
			//14. place exist to put a queen //
			arr[x][col]=1;
			if(nQueen(arr,x+1,n)){
				//15. again line 14 //
				return true;
			}
			arr[x][col]=0;
			//16. backtracking //
		}
	}
	return false;
}
int main (){
	int n;
	cout<<" Enter number of Queen: "<<endl;
	cin>>n;
	int** arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int [n];
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	if(nQueen(arr,0,n)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}cout<<endl;
		}
	}
	return 0;	
}
