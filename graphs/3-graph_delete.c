#include "graphs.h"

void graph_delete(graph_t *graph) {

    edge_t *edges;
    vertex_t *vertex;

    if (!graph)
        return;

    vertex = graph->vertices;
    while(vertex) {
        edges = vertex->edges;
        graph->vertices = vertex->next;
        free(vertex);
        vertex = graph->vertices;
    }
    free(graph);
}
