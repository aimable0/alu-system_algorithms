#include "graphs.h"

void graph_delete(graph_t *graph) {
    if (!graph)
        return;
    vertex_t *vertex = graph->vertices;
    edge_t *edges;

    while(vertex) {
        edges = vertex->edges;
        while(edges) {
            edge_t *node = edges;
            edges = node->next;
            free(node);
        }
        graph->vertices = vertex->next;
        free(vertex);
        vertex = graph->vertices;
    }
    free(graph);
}
