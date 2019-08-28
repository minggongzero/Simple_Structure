#ifndef GRAPHM_H_INCLUDED
#define GRAPHM_H_INCLUDED

//class Edge;
//class Graph;
#include "Edge.h"
//#include "Graph.h"
#define UNVISITED 0
#define VISITED 1

class Graphm/* : public Graph*/{
private:
    int** matrix;
    int numVertex;
    int numEdge;
    int* Mark;
    int* Indegree;
public:
    Graphm(int numVert);  //
    ~Graphm();  //
    int VerticesNum();
    int EdgesNum();
    Edge FirstEdge(int oneVertex);  //
    Edge NextEdge(Edge preEdge);  //
    bool setEdge(int fromVertex, int toVertex, int weight);  //
    bool delEdge(int fromVertex, int toVertex);
    bool IsEdge(Edge oneEdge);  //
    int FromVertex(Edge oneEdge);
    int ToVertex(Edge oneEdge);  //
    int weight(Edge oneEdge);

    void DFS(Graphm& G, int v);  //
    bool isAllVisited();  //
    int findmark();  //
    void doDFS(Graphm& G, int v);  //
    void Visit(Graphm& G, int v);  //
};

#endif // GRAPHM_H_INCLUDED
