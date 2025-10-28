#include <iostream>

#include "graph.h"

struct Queue
{
    std::vector<Vertex*> vertices;

    void insert(Vertex *u);
    Vertex* extract_min();
};

void Queue::insert(Vertex *u)
{
    this->vertices.push_back(u);
}

Vertex* Queue::extract_min()
{
    size_t len = this->vertices.size();
    float tmp = INFINITY;
    size_t index = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (float dist = this->vertices[i]->distance; dist < tmp)
        {
            tmp = dist;
            index = i;
        }
    }
    Vertex* v = this->vertices[index];
    this->vertices.erase(this->vertices.begin() + index);
    return v;
}

int dijkstra(Graph *g, Vertex *source, std::vector<Vertex*> *out);



int main(int argc, char const *argv[])
{
    Graph g;
    std::vector<Vertex*> S;

    // generate default graph and dump contents
    add_dummy_graph(&g);
    g.dump_graph();

    // find distances with dijkstra and dump contents
    dijkstra(&g, &g.vertices[0], &S);
    g.dump_graph();

    return 0;
}

int dijkstra(Graph *g, Vertex *source, std::vector<Vertex*> *out)
{
    init_single_source(g, source);

    out->clear();
    Queue q;

    size_t vertices = g->vertices.size();
    for (size_t i = 0; i < vertices; i++)
    {
        q.insert(&g->vertices[i]);
    }

    while(!q.vertices.empty())
    {
        Vertex* u = q.extract_min();
        out->push_back(u);
        size_t adjacencies = u->adj.size();
        for (size_t i = 0; i < adjacencies; i++)
        {
            if(relax(u, u->adj[i].next) == -1)
            {
                std::cout << "wtf\n";
            }
        }
    }
    return 0;
}
