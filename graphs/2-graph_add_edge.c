#include "graphs.h"
// rapWrite a function that adds an edge between two vertices to an existing graph

// Prototype: int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);
// Where:
// graph is a pointer to the graph to add the edge to
// src is the string identifying the vertex to make the connection from
// dest is the string identifying the vertex to connect to
// type is the type of edge
// UNIDIRECTIONAL: Only one edge is created connecting src to dest
// BIDIRECTIONAL: Two edges are created, connecting src to dest AND dest to src.
// Your function must return 1 on success, or 0 on failure. On failure, no edge must have be created, and there must be no memory leak.
// If either src or dest are not found in any vertex of graph, your function must fail, and there must be no leak
// NOTE: We will use our own graph_create and graph_add_vertex functions during the correction, meaning that your files 0-graph_create.c and 1-graph_add_vertex.c WON’T be compiled.

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type) {
    
}