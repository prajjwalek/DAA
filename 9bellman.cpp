#include <iostream>
using namespace std;

int src[1000],dest[1000],wt[1000],dist[1000];
int u,v,w;
int V,E,source;

void bellmanford(int v, int e, int source){
	for(int i=1;i<=v;i++){
		dist[i]=999;
	}
	dist[source]=0;
	
	for(int i=1;i<v;i++){
		for(int j=0;j<e;j++){
			u=src[j];
			v=dest[j];
			w=wt[j];
			
			if(dist[u] != 999 && dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				cout<<"\nRelaxation"<<i<<": "<<u<<"->"<<v<<", New Distance: "<<dist[v];
			}
		}
	}
	
	cout<<"\nFinal Distances: "<<endl;
	for(int i=1;i<=v;i++){
		cout<<"Vertex: "<<i<<": "<<dist[i]<<endl;
	}
}

int main(){
	cout<<"Enter number of vertices: ";
	cin>>V;
	cout<<"Enter number of edges: ";
	cin>>E;
	
	for(int i=0;i<E;i++){
		cout<<"Enter edge (source,destination,weight): ";
		cin>> u >> v >> w;
		src[i]=u;
		dest[i]=v;
		wt[i]=w;
	}
	
	cout<<"Enter source vertex: ";
	cin>>source;
	
	bellmanford(V,E,source);
	return 0;
}
