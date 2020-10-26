//Ford-Fulkerson algorithm to solve maximum flow problems
//Complexity - O(f * (V+E)) - flow times DFS

#include <bits/stdc++.h>
using namespace std;

const int M = 1005; //Amount of edges
const int N = 105; //Amount of vertices

int vist[N];
int cur = 0, tempo;

struct ed {
	int to, f, c;
	ed(){
		to = f = c = 0;
	}
	ed(int x, int y, int z){
		to = x, f = y, c = z;
	}
}edges[2*M]; //times 2 because of the returning edges

vector < int > g[N]; //Store the position of each edge on array 'edges'

void add_edge(int u, int v, int c, int rc){ //'rc' is usually 0
	edges[cur] = ed(v, 0, c);
	g[u].push_back(cur++);
	edges[cur] = ed(u, 0, rc);
	g[v].push_back(cur++);
}

int dfs(int u, int dest, int f){
	if(u == dest) return f; 	//found a way to 'dest'
	vist[u] = tempo;
	for (int e : g[u]){			//iterate over the edges on the adjacency list
		int v = edges[e].to, cap = edges[e].c - edges[e].f;
		if(vist[v] < tempo && cap > 0) {		//if the vertex has not been visited and I can pass flow here
			if(int a = dfs(v, dest, min(f, cap))){
				edges[e].f += a;
				edges[e^1].f -= a;
				return a;
			}
		}
	}
	return 0;		//return 0 if this is not a path to 'dest'
}

int mf(int s, int t){
	int flow = 0;
	tempo = 1;
	while (int a = dfs(s, t, INT_MAX)){				//while there is an augmenting path we increase the flow by the smaller capacity in the path
		flow += a;
		tempo++;
	}
	return flow;
}

int main(){

}
