#include "graphs.h"


int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type) {
    vertex_t *vertices_l = NULL;
    vertex_t *ptr_src = NULL;
    vertex_t *ptr_dest = NULL;

    if (!graph)
        return 0;
    if (!src)
        return 0;
    if (!dest)
        return 0;

    vertices_l = graph->vertices;
    while(vertices_l) {
        if (strcmp(vertices_l->content, src) == 0) {
            ptr_src = vertices_l;
        }
        else if (strcmp(vertices_l->content, dest) == 0) {
            ptr_dest = vertices_l;
        }
        vertices_l = vertices_l->next;
    }

    if (ptr_src && ptr_dest) {

        edge_t *edges = ptr_src->edges;
        edge_t *edge = malloc(sizeof(edge_t));
        if (!edge) {
            perror("malloc failed");
            return 0;
        }
        edge->dest = ptr_dest;
        edge->next = NULL;

        if (edges) {
            while(edges) {
                if (edges->next == NULL)
                    break;
                edges = edges->next;
            }
            /* add new edge to the list*/
            edges->next = edge;
        }
        else {
            ptr_src->edges = edge;
        }

        ptr_src->nb_edges += 1;

        if (type) {
            /* we can reduce redudancy here .. */
            edge_t *edges = ptr_dest->edges;
            edge_t *edge = malloc(sizeof(edge_t));
            if (!edge) {
                perror("malloc failed");
                return 0;
            }
            edge->dest = ptr_src;
            edge->next = NULL;

            if (edges) {
                while(edges) {
                    if (edges->next == NULL)
                        break;
                    edges = edges->next;
                }
                edges->next = edge;
            }
            else {
                ptr_dest->edges = edge;
            }
            ptr_dest->nb_edges += 1;
        }

        return 1;
    }
    else {
        return 0;
    }
}
