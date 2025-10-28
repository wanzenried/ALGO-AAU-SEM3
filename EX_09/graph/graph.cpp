#include "graph.h"

#include <iostream>
#include <iomanip>


void Graph::dump_graph()
{
    size_t len = this->vertices.size();
    std::cout << "Dump graph with " << len << " vertices\n";
    for (size_t i = 0; i < len; i++)
    {
        Vertex &v = vertices[i];
        std::cout << "Vertex: " << v.id << " | ";
        std::cout << " Dist: " << v.distance << " | ";
        std::cout << " Pred: ";
        if (v.predecessor)
        {
            std::cout << v.predecessor->id;
        }
        else
        {
            std::cout << "Null";
        }
        std::cout << "\n Adjacency: ";

        size_t adjacents = v.adj.size();
        for (size_t j = 0; j < adjacents; j++)
        {
            Edge &e = v.adj[j];
            std::cout << v.id << " -(" << e.weight << ")-> " << e.next->id << "   ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void add_dummy_graph(Graph *g)
{
    g->vertices.resize(6);

    for (size_t i = 0; i < 6; i++)
    {
        g->vertices[i].id = i;
    }
    
    g->vertices[0].adj.push_back({&g->vertices[1], 2.0});
    g->vertices[0].adj.push_back({&g->vertices[5], 1.0});

    g->vertices[1].adj.push_back({&g->vertices[2], 4.0});
    g->vertices[1].adj.push_back({&g->vertices[3], 3.0});

    g->vertices[2].adj.push_back({&g->vertices[0], 7.0});
    g->vertices[2].adj.push_back({&g->vertices[3], 7.0});
    g->vertices[2].adj.push_back({&g->vertices[5], 2.0});

    g->vertices[3].adj.push_back({&g->vertices[1], 1.0});
    g->vertices[3].adj.push_back({&g->vertices[4], 8.0});

    g->vertices[4].adj.push_back({&g->vertices[2], 1.0});
    g->vertices[4].adj.push_back({&g->vertices[5], 1.0});
}

void init_single_source(Graph *g, Vertex *source)
{
    size_t vertices = g->vertices.size();
    for (size_t i = 0; i < vertices; i++)
    {
        g->vertices[i].distance = INFINITY;
        g->vertices[i].predecessor = nullptr;
    }
    source->distance = 0;
}

int relax(Vertex *u, Vertex* v)
{
    float udist = u->distance;
    float vdist = v->distance;
    size_t adjacencies = u->adj.size();
    for (size_t i = 0; i < adjacencies; i++)
    {
        if (u->adj[i].next == v)
        {
            if (float dist = udist + u->adj[i].weight; vdist > dist)
            {
                v->distance = dist;
                v->predecessor = u;
                return 1;
            }
            return 0;
        }
    }

    return -1;  // u does not have an edge to v
}