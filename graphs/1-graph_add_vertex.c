#include "graphs.h"

/**
 * graph_add_vertex
 * @graph: graph in which to store the vertex
 * @str: content to store in vertex
 *
 * Return: vertex or NULL otherwise.
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
    vertex_t *tail = graph->vertices;
    while (tail)
    {
        if (strcmp(tail->content, str) == 0)
            return (NULL);
        if (tail->next == NULL)
            break;
        tail = tail->next;
    }

    vertex_t *new = malloc(sizeof(vertex_t));
    if (!new)
    {
        perror("malloc");
        return (NULL);
    }

    new->index = graph->nb_vertices;
    graph->nb_vertices++;

    int size = strlen(str);
    new->content = malloc(sizeof(char) * size);
    if (!new->content) {
        perror("malloc");
        return (NULL);
    }
    strncpy(new->content, str, size);
    new->nb_edges = 0;
    new->edges = NULL;
    new->next = NULL;
    if (tail)
        tail->next = new;
    else
        graph->vertices = new;

    return new;
}
