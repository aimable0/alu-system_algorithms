#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 200

// stuctures
typedef struct student_s {
    char *name;
    int id;
} student_t;

typedef struct queue_s {
    student_t *data[MAX];
    int tail;
    int head;
    int size;
    int max;
} queue_t;

// protos
student_t *add_student(char *name, int id);

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

void enqueue(queue_t *q, student_t *x) {
    if (is_full(q)) {
        perror("Overflow");
    } else {
        q->data[q->tail] = x;
        if (q->tail + 1 == q->max)
            q->tail = 0;
        else q->tail += 1;
        q->size++;
    }
}

student_t *dequeue(queue_t *q) {
    if (is_empty(q)) {
        perror("underflow");
        return NULL;
    } else {
        student_t *x = malloc(sizeof(student_t));
        if ((q->head + 1) == q->max) {
            q->head = 0;
        } else q->head += 1;
        q->size--;
        return x;
    }
}

queue_t *initialize_q() {
    queue_t *q = malloc(sizeof(queue_t));

    if (!q)
        return NULL;

    q->head = 0;
    q->size = 0;
    q->tail = 0;
    q->max = MAX;

    return q;
}

int main(void)
{
    student_t *student1 = add_student("Aimable", 1);
    student_t *student2 = add_student("Jack", 2);
    student_t *student3 = add_student("Anne", 3);
    student_t *student4 = add_student("Biggie", 4);
    student_t *student5 = add_student("Smally", 5);

    queue_t *q = initialize_q();

    enqueue(q, student1);
    enqueue(q, student2);
    enqueue(q, student3);
    enqueue(q, student4);

    for (int i = q->head; i < q->tail; i++) {
        printf("%s %d\n", q->data[i]->name, q->data[i]->id);
    }

    printf("Current size: %d\n", q->size);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Current size: %d\n", q->size);
    printf("Current q->head: %d\n", q->head);
    for (int i = q->head; i < q->tail; i++) {
        printf("%s %d\n", q->data[i]->name, q->data[i]->id);
    }

    return 0;
}

student_t *add_student(char *name, int id) {
    student_t *student = malloc(sizeof(student_t));

    if (!student) {
        perror("malloc");
        return NULL;
    }

    student->id = id;
    student->name = name;
    return student;
}
