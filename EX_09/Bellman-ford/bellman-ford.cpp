#include <iostream>

#include "graph.h"


bool bellman_ford(Graph *g, Vertex *source);



int main(int argc, char const *argv[])
{
    Graph g;

    // generate default graph and dump contents
    add_dummy_graph(&g);
    g.dump_graph();

    // find distances with Bellman-ford and dump contents
    if(bellman_ford(&g, &g.vertices[0]))
    {
        std::cout << "no reachable negative cycles\n";
    }
    else
    {
        std::cout << "reachable negative cycles\n";
    }
    g.dump_graph();

    return 0;
}

bool bellman_ford(Graph *g, Vertex *source)
{
    init_single_source(g, source);

    for (size_t i = 1; i < g->vertices.size(); i++)
    {
        for (size_t j = 0; j < g->vertices.size(); j++)
        {
            Vertex *u = &g->vertices[j];
            for (size_t k = 0; k < u->adj.size(); k++)
            {
                relax(u, u->adj[k].next);
            }
        }
    }

    for (size_t i = 0; i < g->vertices.size(); i++)
    {
        Vertex *u = &g->vertices[i];
        for (size_t j = 0; j < u->adj.size(); j++)
        {
            if (u->adj[j].next->distance > (u->distance + u->adj[j].weight))
            {
                return false;
            }
        }
    }
    return true;
    
    
}

