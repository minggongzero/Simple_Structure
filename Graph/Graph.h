#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class Edge;

class Graph{
public:
    int numVertex;
    int numEdge;
    int* Mark;
    int* Indegree;
public:
    Graph(int numVert);
    ~Graph();
    int VerticesNum();
    int EdgesNum();
    Edge FirstEdge(int oneVertex);
    Edge NextEdge(int preEdge);
    bool setEdge(int fromVertex, int toVertex, int weight);
    bool delEdge(int fromVertex, int toVertex);
    bool IsEdge(Edge oneEdge);
    int FromVertex(Edge oneEdge);
    int ToVertex(Edge oneEdge);
    int weight(Edge oneEdge);
};

#endif // GRAPH_H_INCLUDED
