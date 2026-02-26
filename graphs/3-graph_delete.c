#include "graphs.h"

void graph_delete(graph_t *graph)
{
    vertex_t *vertex;
    edge_t *edges;

    if (!graph)
        return;

    vertex = graph->vertices;
    while (vertex)
    {
        edges = vertex->edges;
        vertex_t *next = vertex->next;
        while(edges) {
            edge_t *node = edges;
            edges = node->next;
            free(node);
        }
        free(vertex->content);
        free(vertex);
        vertex = next;
    }
    free(graph);
}
