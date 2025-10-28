#include <stdint.h>
#include <cmath>
#include <vector>

struct Edge;

struct Vertex
{
    uint id;
    std::vector<Edge> adj;

    float distance = INFINITY;
    Vertex *predecessor = nullptr;
};


struct Edge
{
    Vertex *next = nullptr;
    float weight = INFINITY;
};

struct Graph
{
    std::vector<Vertex> vertices;
    void dump_graph();
};

void add_dummy_graph(Graph *g);

void init_single_source(Graph *g, Vertex *source);

int relax(Vertex *u, Vertex* v);