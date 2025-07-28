/*#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef int weightType;
typedef int Vertex;
typedef int DataType;
typedef struct GNode *ptrToGNode;
struct GNode{   
	int Nv;   
	int Ne;   
	weightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
}; 
typedef ptrToGNode MGraph;
typedef struct ENode *ptrToENode;
struct ENode{ 
	Vertex V1,V2;   
	weightType Weight;  
};
typedef ptrToENode Edge;


MGraph Create(int VertexNum){
	Vertex v,w;
	MGraph Graph;
	
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	
	for(v=0;v<VertexNum;v++)
		for(w=0;w<VertexNum;w++)
			Graph->G[v][w] = 0;
	return Graph;
}


MGraph Insert(MGraph Graph,Edge E){
	
	
	Graph->G[E->V1][E->V2] = E->Weight;
	
	
	Graph->G[E->V2][E->V1] = E->Weight;
	
} 


MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	scanf("%d",&Nv);   
	Graph = Create(Nv);
	scanf("%d",&(Graph->Ne));   
	if(Graph->Ne != 0){   
		E = (Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight); 
			Insert(Graph,E);
		}
	}
	return Graph;
}
*/ 

#include<stdio.h>
#include<stdlib.h>
#define MAXN 100
int G[MAXN][MAXN],Nv,Ne;

void BuildGraph(){
	int i,j,v1,v2,w;
	
	scanf("%d",&Nv);
	for(i=0;i<Nv;i++) 
		for(j=0;j<Nv;j++)
			G[i][j] = 0;
	scanf("%d",&Ne);
	for(i=0;i<Ne;i++){
		scanf("%d %d %d",&v1,&v2,&w);
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}


void print(){
	int i,j;
	for(i=0;i<Nv;i++){
		for(j=0;j<Nv;j++)
			printf("%d ",G[i][j]);
		printf("\n");
	}
} 

int main(){
	BuildGraph();
	print();
	return 0;
}