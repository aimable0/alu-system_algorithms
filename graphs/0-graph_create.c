#include "graphs.h"

graph_t *graph_create(void)
{
    graph_t *G = malloc(sizeof(graph_t));
    if (!G)
        return (NULL);

    G->nb_vertices = 0;
    G->vertices = NULL;

    return (G);
}
