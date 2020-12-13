#include<bits/stdc++.h>
#include<sys/resource.h>
#include<unistd.h>
using namespace std::chrono;
using namespace std;

fstream output_2;// for storing component information
int r=remove("output_2.txt");	

class Node{
public:
    int val;
    Node *next;
    Node(int x){
        val=x;
        next=nullptr;
    }
};

unordered_map<int,vector<int>> m; 
void DFS(int v, int par,bool visited[],Node* adj_list[],int &ab,fstream & output_2)
{
	ab++;
	output_2 <<v<<" ";
    // Mark the current node as visited and print it
    visited[v] = true;
    m[par].push_back(v);
    Node *t=adj_list[v];
    while(t){
    	if(visited[t->val]==false){
    		DFS(t->val,par,visited,adj_list,ab,output_2);
    	}
    	t=t->next;
    }

}


void lcsize(Node* adj_list[],int n)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[n];
    for (int v = 0; v < n; v++)
        visited[v] = false;
    int count=0;
    int c=1;
    int ans=1;
    int ab;
    output_2.open("output_2.txt",ios::app);
    for (int v = 0; v < n; v++) {
        if (visited[v] == false) {
        	output_2 <<"Component "<<c<<" : ";
        	ab=0;
            DFS(v,v, visited,adj_list,ab,output_2);
            c++;
            if(ans<ab) ans=ab;
            output_2 <<endl;
        }
    }
    
    output_2<<"The largest component has "<<ans<<" nodes";
    output_2.close();
    delete[] visited;	
}




void add_edge(Node * adj_list[], int u, int v) {    //add v into the list u, and u into list v
    Node *t=adj_list[u];
    if(!adj_list[u]){
        adj_list[u]=new Node(v);
    }
    else{
       while(t->next )
        t=t->next;
    	t->next=new Node(v); 
    }
    
    Node *t2=adj_list[v];
    if(!adj_list[v]){
        adj_list[v]=new Node(u);
    }
    else{
        while(t2->next )
        t2=t2->next;
    	t2->next=new Node(u);
    }

    
}

void displayAdjList(Node * adj_list[], int v) {
	
	ofstream output;// for storing adjacency list 
	output.open("output.txt");
	
   for(int i = 0; i<v; i++) {
      output << "Neighbors of "<< i << ":";
      Node *t=adj_list[i];
      while(t){
        output<<t->val<<" ";
        t=t->next;
      }
      output << endl;
      
   }
   output.close();
}

void getAdjList(int n)
{
	Node *adj_list[n]; //array of lists of size n
    for(int i=0;i<n;i++) adj_list[i]=nullptr;
	
	std::ifstream input("input.txt", std::ios_base::in); //for reading adjacency matrix 
	
	int p;
	for(int i=0;i<n-1;i++) //reading adjacency matrix from input file
	{
		for(int j=0;j<n-i-1;j++)
		{
			input>>p;
			if(p==1)
			{
				add_edge(adj_list, i, i+j+1);	
			}
			
		}
		
	}
	input.close();
	displayAdjList(adj_list, n);
	lcsize(adj_list,n);

}



int main()
{    
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
	cout<<n<<endl;
	ofstream input;
	input.open("input.txt");
	srand(time(0));
	int max=2;
	
	for(int i=0;i<n-1;i++) //storing adjacency matrix in input file
	{
		for(int j=n-1-i;j>0;j--)
		{
			input<<rand()%max <<" ";
		}
		input<<"\n";
	}
	input.close();
	auto start = high_resolution_clock::now();
     getAdjList(n);
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);

	 double ans = duration.count() / 1e6;
     
     //for complexity file
     cout<<"Psedocode of Modified DFS Algorithm having complexity of O(n+m)------>";
     cout<<"\n";
     cout<<"1) Declare a boolean visited array of size n and initialize all vertices as not visited";
     cout<<"\n";
     cout<<"2) Do following for every vertex 'v' ";
     cout<<"\n";
     cout<<"\t";
     cout<<"2.1) If 'v' is not visited before, call DFS(v) ";
     cout<<"\n";
     cout<<"	";
     
    cout<<"	DFS(v)";
    cout<<"\n";
    cout<<"		1) Mark 'v' as visited.";
    cout<<"\n";
    cout<<"		2) Print 'v' ";
    cout<<"\n";
    cout<<"		2) Do following for every adjacent 'u' of 'v' ";
    cout<<"\n";
    cout<<"\t";
    cout<<"		If 'u' is not visited, then recursively call DFS(u)";
    cout<<"\n";
    cout<<"	2.2) Print new line character "<<endl;
    cout<<"Print the size of largest Component "<<endl;
    cout<<endl;
    cout.precision(6);
    cout << "Time required to execute adj_list() and lcsize() is : " << fixed
				     << ans << " seconds" << endl;
	cout<<endl;
    cout << "The amount of space is used during running the program = Maximum resident set size (kbytes) [ ===> 36th line ]" << endl;
	cout << endl;
	
	cout << "Large size input data is handled by \'an Array of Linked List\' where data is read from input file and output is written back to 2 output files" << endl;
	cout << endl;


	cout << "Memory release statement is present from 50th line onwards " << endl;
	cout << endl;
	
    
    return 0;
}
