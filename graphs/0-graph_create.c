#include "graphs.h"

/**
 * graph_create - creates a graph object
 *
 * Return: graph or NULL otherwise.
 */
graph_t *graph_create(void)
{
    graph_t *G = malloc(sizeof(graph_t));
    if (!G)
        return (NULL);

    G->nb_vertices = 0;
    G->vertices = NULL;

    return (G);
}
