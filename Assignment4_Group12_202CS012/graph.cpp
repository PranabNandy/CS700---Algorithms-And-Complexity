#include<bits/stdc++.h>

/*SUBMIITED BY GROUP NO 12
Himanshu Kashyap 202CS012 (Group Leader)
Pranab Nandy 202CS019
Rakeshwar Verma 202CS021
Ankush Ravindra Dhamanwar 202CS002
Satyam Prakash 202CS027
*/

using namespace std;


void printGraph(vector<vector<int>> &G,int n){

	ofstream output;
	output.open("output.txt");
	output<<"The graph is: "<<endl;
		for(int i=0;i<n;i++){
			output<<"City "<<i<<" -- ";
			for(int a:G[i])
				output<<a<<" ";
			output<<endl;
		}

}

void dfs(vector<vector<int>> &G,int v,vector<int> &vis){

	vis[v]=v;

	for(int a:G[v]){
		if(vis[a]==-1){
			dfs(G,a,vis);
		}
	}
	
}

void build_highways(vector<vector<int>> &G){

		std::ofstream output("output.txt", std::ios_base::app);
		output<<endl;
		int n=G.size();
		vector<int> vis(n,-1);
		dfs(G,0,vis);
		int c=0;
		for(int i=1;i<n;i++){
			
			if(vis[i]!=-1){
					//DSVDF
			}
			else{
				c++;
				if(c==1){
					output<<"Building highways: "<<endl;
				}
				dfs(G,i,vis);
				G[0].push_back(i);
				output<<"Between City 0 and City "<<i<<endl;
			}
		}


}
//BFS(G, u, visited)
void BFS(vector<vector<int>> &G,int u,vector<int> &vis){
	queue<int> q1,q2,q3;
	q1.push(u);
	while(q1.empty()==0){
		int x=q1.front();
		q1.pop();
		vis[x]=x;
		for(int a:G[x]){
			if(vis[a]==-1)
			q2.push(a);
		}
		if(q1.empty()==1){
			q1=q2;
			q2=q3;
		}
	}

}
void check_connectivity(vector<vector<int>> &G){

	std::ofstream output("output.txt", std::ios_base::app);
	output<<endl;
	int n=G.size();
	vector<int> vis(n,-1);
	BFS(G,0,vis);
	int flag=1;
	for(int i=0;i<n;i++){
		if(vis[i]==-1){
			flag=0;
			break;
		}
	}
	if(flag==1){
		output<<"All cities are connected by highways"<<endl;
	}
	else{
		output<<"Not all cities are connected by highways "<<endl;
	}


}
vector<vector<int>> read_graph(){
	int n,m;
	ofstream input;
	input.open("input.txt");
	srand(time(0));
	cout<<"Enter number of vertices : "<<endl;
	cin>>n;
	cout<<"Enter the number of edges : "<<endl;
	cin>>m;
	
	/*int max=25;
	n=rand() % max;
	max=(n*(n-1))/2;
	m=rand() % max;
	
	input << n << "\n"; 
	input << m << "\n";
	*/
	for(int i=1;i<=m;i++){
	input <<rand() % n << " ";
	input << rand() % n << "\n"; 
	}
	
	input.close();
	
	std::ifstream out("input.txt", std::ios_base::in);
	int temp;
	//out>>temp;
	//out>>temp;
	
	vector<vector<int>> G;
	G.resize(n);
	
	for(int i=1;i<=m;i++){
		int x,y;
		out >>x>>y;
		if(x==y) continue;
		int flag=1;
		for(int a:G[x]){
			if(a==y){
				flag=0;
				break;
			}
		}
		if(flag==0) continue;

		G[x].push_back(y);
		G[y].push_back(x);
	}
	return G;
}
int main(){
	
	//vector<int> G[n];
	vector<vector<int>> G;
	G=read_graph();
	int n=G.size();
	
	printGraph(G,n);

	check_connectivity(G);

	build_highways(G);

	check_connectivity(G);
	
}
