#include "graphs.h"

void graph_delete(graph_t *graph) {

    vertex_t *vertex;

    if (!graph)
        return;

    vertex = graph->vertices;
    while(vertex) {
        vertex_t *next = vertex->next;
        printf(" ...Deleting vertex: %s\n", vertex->content);
        free(vertex->content);
        free(vertex);
        vertex = next;
        graph->nb_vertices -= 1;
        printf(" ...vertex remaining: %zu\n", graph->nb_vertices);
    }
    free(graph);
}
