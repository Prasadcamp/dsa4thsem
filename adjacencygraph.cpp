#include<iostream>
#include<vector>
using namesapace std;
int main()
{

	int m,n;
	cout << "Enter teh no. of vertices and edges";
	cin>>m>>n;
	vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
	
	cout << "Enter the edges (u, v):" << endl;
    for(int i=0;i<m;i++) 
    {
        int u,v;
        cin>>u>>v;
        adjMat[u][v] =1;
        adjMat[v][u] =1;
    }
    
    cout<< "\nAdjacency Matrix:" << endl;
    cout<< "  ";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout << endl;

    for(int i = 1;i<= n; i++) 
    {
        cout<<i<<" ";
        for(int j = 1; j <= n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
	
	
	return 0;
}
