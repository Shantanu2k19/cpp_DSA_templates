#include<bits/stdc++.h>
using namespace std;
template<typename T>

//class
class graph{
	//adj list
	map<T, list<T>> adjlist;

	int V;

	public:
	graph(int v){
		this->V = v;
	}

	void addEdge(T x, T y, bool bidir=false){
		adjlist[x].push_back(y);
		if(bidir) adjlist[y].push_back(y);
	}

	void printAdjLis(){
		for(auto x: adjlist){
			cout<<x.first<<"->";
			for(auto y: x.second){
				cout<<y<<",";
			}
			cout<<endl;
		}
	}

	void dfs(int source){
		map<int, bool> visited;
		dfsHelper(source, visited);
	}

	void dfsHelper(int node, map<int, bool> &visited){
		visited[node]=true;
		cout<<node<<",";
		for(int nbr: adjlist[node]){
			if(!visited[nbr]){
				dfsHelper(nbr, visited);
			}
		}
	}

	void dfsStack(int node){
		// map<int, bool> & visited;
		vector<bool> visited(V, false);
		stack<int> stk;

		stk.push(node);

		while(!stk.empty()){
			int s = stk.top();
			stk.pop();

			if(!visited[s]){
				cout<<s<<",";
				visited[s]=true;
			}

			for(auto x: adjlist[node]){
				if(!visited[x]){
					stk.push(x);
				}
			}
		}

	}

	void bfs(int node){
		vector<bool> visited(V,false);
		list<int> queue;

		visited[node]=true;
		queue.push_back(node);
		
		while(!queue.empty()){
			node = queue.front();
			cout<<node<<",";
			queue.pop_front();

			for(auto x: adjlist[node]){
				if(!visited[x]){
					visited[x]=true;
					queue.push_back(x);
				}
			}
		}
	}
};

int main(){
	graph<int> g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,5);

	// g.printAdjLis();
	g.dfsStack(0);
	cout<<endl;
	g.dfs(0);
	cout<<endl;
	g.bfs(0);
	
	cout<<"\n_____________________________\n";
}                                       