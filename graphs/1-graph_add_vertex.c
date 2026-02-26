#include "graphs.h"
#include <string.h>
#include <stdlib.h>

/**
 * graph_add_vertex
 * @graph: graph in which to store the vertex
 * @str: content to store in vertex
 *
 * Return: vertex or NULL otherwise.
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{

    vertex_t *new;
    int str_size = 0;
    vertex_t *tail = graph->vertices;

    if (!str)
        return NULL;

    while (tail)
    {
        if (strcmp(tail->content, str) == 0)
            return (NULL);
        if (tail->next == NULL)
            break;
        tail = tail->next;
    }

    new = malloc(sizeof(vertex_t));
    if (!new)
    {
        perror("malloc");
        return (NULL);
    }

    new->index = graph->nb_vertices;
    graph->nb_vertices++;

    str_size = strlen(str) + 1; /* 1 for \0 */
    new->content = malloc(sizeof(char) * str_size);
    if (!new->content) {
        perror("malloc");
        free(new);
        return (NULL);
    }

    strcpy(new->content, str);
    new->nb_edges = 0;
    new->edges = NULL;
    new->next = NULL;
    if (tail)
        tail->next = new;
    else
        graph->vertices = new;

    return new;
}
