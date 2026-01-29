#include <stdbool.h>
#include "graphs.h"

#include <stdbool.h>
#include <stdlib.h>
#include "graphs.h"

/**
 * dfs_traverse_rec - Recursively perform a depth-first traversal.
 * @v: Current vertex being visited.
 * @visited: Array tracking which vertex indices have been visited.
 * @depth: Current traversal depth from the start vertex.
 * @action: Callback executed on each visited vertex with its depth.
 *
 * Return: Maximum depth reached from this vertex.
 */
static size_t dfs_traverse_rec
(const vertex_t *v, bool *visited, size_t depth,
void (*action)(const vertex_t *, size_t))
{
	edge_t *e;
	size_t max_depth = depth;

	visited[v->index] = true;
	action(v, depth);

	for (e = v->edges; e; e = e->next)
	{
		if (e->dest && !visited[e->dest->index])
		{
			size_t curr_depth;

			curr_depth = dfs_traverse_rec(
				e->dest, visited, depth + 1, action);

			if (curr_depth > max_depth)
				max_depth = curr_depth;
		}
	}

	return (max_depth);
}

/**
 * depth_first_traverse - Traverse a graph in depth-first order.
 * @graph: Pointer to the graph to traverse.
 * @action: Callback executed on each visited vertex with its depth.
 *
 * Return: Maximum depth reached during traversal, or 0 on failure.
 */
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *, size_t))
{
	bool *visited;
	size_t depth;

	if (!graph || !action || !graph->nb_vertices)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (0);

	depth = dfs_traverse_rec(graph->vertices, visited, 0, action);

	free(visited);

	return (depth);
}
