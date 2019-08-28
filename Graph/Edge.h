#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

class Edge{
public:
    int from, to, weight;
    Edge(int f=-1, int t=-1, int w=0){from=f;to=t;weight=w;};
};

//Edge::Edge(int f, int t, int w) : from(f), to(t), weight(w){}

#endif // EDGE_H_INCLUDED
