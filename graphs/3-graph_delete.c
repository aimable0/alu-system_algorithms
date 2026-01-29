#include "graphs.h"

/**
 * graph_delete - completely deallocates a graph_t
 * @graph: pointer to the graph_t to be deleted
 */
void graph_delete(graph_t *graph)
{
	vertex_t *v;
	edge_t *e;

	if (!graph)
		return;

	while ((v = graph->vertices))
	{
		graph->vertices = v->next;

		while ((e = v->edges))
		{
			v->edges = e->next;
			free(e);
		}

		free(v->content);
		free(v);
	}

	free(graph);
}
