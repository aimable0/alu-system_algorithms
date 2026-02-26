#include "graphs.h"
#define MAX 200

/* Structures */
typedef struct queue_s {
    vertex_t *data[MAX];
    int max;
    int tail;
    int head;
} queue_t;


/* queue helper functions */
queue_t *initialize_q(void);

bool is_full(queue_t *q) {
    if (q->head == q->tail + 1)
        return true;
    return false;
}

bool is_empty(queue_t *q) {
    if (q->head == q->tail)
        return true;
    return false;
}

void enqueue(queue_t *q, vertex_t *x) {
    if (is_full(q)) {
        perror("Overflow");
        exit(0);
    }
    q->data[q->tail] = x;
    if (q->tail + 1 == q->max)
        q->tail = 0;
    else q->tail += 1;
}

vertex_t *dequeue(queue_t *q) {
    vertex_t *x;
    if (is_empty(q)) {
        perror("underflow");
        exit(0);
    }

    x = q->data[q->head];
    if (q->head + 1 == q->max)
        q->head = 0;
    else q->head += 1;

    return x;
}

queue_t *initialize_q(void) {
    queue_t *q = malloc(sizeof(queue_t));

    if (!q) {
        perror("malloc failed");
        return NULL;
    }

    q->head = 0;
    q->tail = 0;
    q->max = MAX;

    return q;
}


size_t breadth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
    size_t depth = 0;
    queue_t *Q;
    vertex_t *vertex;
    if (!graph)
        return 0;

    /* make all vertex white */
    vertex = graph->vertices;
    while(vertex) {
        char color[10] = "white";
        int str_size = strlen(color) + 1;

        vertex->color = malloc(sizeof(char) * str_size);
        if (vertex->color) {
            strcpy(vertex->color, color);
        }
        else {
            perror("malloc failed");
            exit(0);
        }
        vertex->depth = 0;
        vertex = vertex->next;
    }

    Q = initialize_q();
    enqueue(Q, graph->vertices);
    strcpy(graph->vertices->color, "grey");

    while(!is_empty(Q)) {
        vertex_t *x = dequeue(Q);
        edge_t *edges = x->edges;

        while(edges) {
            if (strcmp(edges->dest->color, "white") == 0) {
                enqueue(Q, edges->dest);
                strcpy(edges->dest->color, "grey");
                edges->dest->depth = x->depth + 1;
            }
            edges = edges->next;
        }

        if (x->depth > depth)
            depth = x->depth;

        strcpy(x->color, "black");
        action(x, x->depth);
    }

    return depth;
}
