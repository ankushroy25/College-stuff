#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct queue
{
    int front;
    int rear;
    int *items;
} queue;

int is_empty(queue *q)
{
    return (q->front == -1);
}

int is_full(queue *q, int max_size)
{
    return ((q->rear + 1) % max_size == q->front);
}

void enqueue(queue *q, int value, int max_size)
{
    if (is_full(q, max_size))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (is_empty(q))
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % max_size;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q, int max_size)
{
    int value = -1;
    if (is_empty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        value = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % max_size;
        }
    }
    return value;
}

void bfs(int **graph, int num_vertices, int start_vertex)
{
    int *visited = (int *)calloc(num_vertices, sizeof(int));
    queue q;
    q.front = q.rear = -1;
    q.items = (int *)malloc(num_vertices * sizeof(int));

    // init_queue(&q, num_vertices);

    visited[start_vertex] = 1;
    enqueue(&q, start_vertex, num_vertices);
    while (!is_empty(&q))
    {
        int vertex = dequeue(&q, num_vertices);
        printf("%d ", vertex);
        for (int i = 0; i < num_vertices; i++)
        {
            if (graph[vertex][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(&q, i, num_vertices);
            }
        }
    }
}

int main()
{
    int num_vertices, start_vertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    int **graph = (int **)malloc(num_vertices * sizeof(int *));

    for (int i = 0; i < num_vertices; i++)
    {
        printf("Enter the number of neighbors for vertex %d: ", i);
        int num_neighbors;
        scanf("%d", &num_neighbors);
        graph[i] = (int *)calloc(num_vertices, sizeof(int));
        for (int j = 0; j < num_neighbors; j++)
        {
            printf("Enter the index of neighbor %d for vertex %d: ", j, i);
            int neighbor_index;
            scanf("%d", &neighbor_index);
            graph[i][neighbor_index] = 1;
        }
    }

    printf("Enter the index of the starting vertex: ");
    scanf("%d", &start_vertex);

    printf("BFS traversal starting from vertex %d: ", start_vertex);
    bfs(graph, num_vertices, start_vertex);
    printf("\n");

    return 0;
}