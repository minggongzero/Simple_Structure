#include "Graphm.h"
#include <limits.h>
#include <iostream>

Graphm::Graphm(int numVert)/* : Graph(numVert)*/{
    int i, j;
    numVertex = numVert;
    numEdge = 0;
    Indegree = new int[numVertex];
    Mark = new int[numVertex];
    for(i=0; i<numVertex; i++){
        Mark[i] = UNVISITED;
        Indegree[i] = 0;
    }
    matrix = (int**)new int*[numVert];
    for(i=0; i<numVert; i++){
        matrix[i] = new int[numVert];
    }
    for(i=0; i<numVert; i++)
        for(j=0; j<numVert; j++)
            matrix[i][j] = 0;
}

Graphm::~Graphm(){
    for(int i=0; i<numVertex; i++)
        delete[] matrix[i];
    delete matrix;
    delete[] Mark;
    delete[] Indegree;
}

int Graphm::VerticesNum(){
    return numVertex;
}

int Graphm::EdgesNum(){
    return numEdge;
}

Edge Graphm::FirstEdge(int oneVertex){
    Edge myEdge;
    myEdge.from = oneVertex;
    for(int i=0; i<numVertex; i++){
        if(matrix[oneVertex][i] != 0){
            myEdge.to = i;
            myEdge.weight = matrix[oneVertex][i];
            break;
        }
    }
    return myEdge;
}

Edge Graphm::NextEdge(Edge preEdge){
    Edge myEdge;
    myEdge.from = preEdge.from;
    if(preEdge.to < numVertex){
        for(int i=preEdge.to+1; i<numVertex; i++){
            if(matrix[preEdge.from][i] != 0){
                myEdge.to = i;
                myEdge.weight = matrix[preEdge.from][i];
                break;
            }
        }
    }
    return myEdge;
}

bool Graphm::setEdge(int fromVertex, int toVertex, int weight){
    if(matrix[fromVertex][toVertex] <= 0){
        numEdge++;
        Indegree[toVertex]++;
    }
    matrix[fromVertex][toVertex] = weight;
    return true;
}

bool Graphm::delEdge(int fromVertex, int toVertex){
    if(matrix[fromVertex][toVertex] > 0){
        numEdge--;
        Indegree[toVertex]--;
    }
    matrix[fromVertex][toVertex] = 0;
    return true;
}

bool Graphm::IsEdge(Edge oneEdge){
    if(oneEdge.weight>0 && oneEdge.weight<INT_MAX && oneEdge.to>=0)
        return true;
    return false;
}

int Graphm::FromVertex(Edge oneEdge){
    return oneEdge.from;
}

int Graphm::ToVertex(Edge oneEdge){
    return oneEdge.to;
}

int Graphm::weight(Edge oneEdge){
    return oneEdge.weight;
}

void Graphm::DFS(Graphm& G, int v){
    G.Mark[v] = VISITED;
    Visit(G, v);
    for(Edge e=G.FirstEdge(v); G.IsEdge(e); e=G.NextEdge(e))
        if(G.Mark[G.ToVertex(e)]==UNVISITED)
            DFS(G, G.ToVertex(e));
}

int Graphm::findmark(){
    int p;
    for(p=0; p<numVertex; p++)
        if(Mark[p] == UNVISITED) break;
    return p;
}

bool Graphm::isAllVisited(){
    return findmark()==numVertex ? true : false;
}

void Graphm::doDFS(Graphm& G, int v){
    G.DFS(G, v);
    while(!isAllVisited())
        G.DFS(G, findmark());
}

void Graphm::Visit(Graphm& G, int v){
    std::cout << v << '\t' << G.Mark[v] << std::endl;
}
