#include "graphs.h"

void graph_delete(graph_t *graph)
{
    vertex_t *vertex;

    if (!graph)
        return;

    vertex = graph->vertices;
    while (vertex)
    {
        vertex_t *next = vertex->next;
        free(vertex->content);
        free(vertex);
        vertex = next;
    }
    free(graph);
}
