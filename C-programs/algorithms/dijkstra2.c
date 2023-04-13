// dijksta algorithm using array representaion of adjacency list with heap ds as priority queue for maintaining minimum distance
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10000

typedef struct node
{
    int vertex;
    int weight;
} Node;

typedef struct min_heap
{
    int vertex;
    int distance;
} MinHeap;

int heap_size = 0;

void swap(MinHeap *a, MinHeap *b)
{
    MinHeap temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap prq[], int idx)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < heap_size && prq[left].distance < prq[smallest].distance)
    {
        smallest = left;
    }

    if (right < heap_size && prq[right].distance < prq[smallest].distance)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swap(&prq[idx], &prq[smallest]);
        heapify(prq, smallest);
    }
}

void insert(MinHeap prq[], int vertex, int distance)
{
    prq[heap_size].vertex = vertex;
    prq[heap_size].distance = distance;

    int current = heap_size;
    while (current > 0 && prq[current].distance < prq[(current - 1) / 2].distance)
    {
        swap(&prq[current], &prq[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
    heap_size++;
}

MinHeap extract_min(MinHeap prq[])
{
    MinHeap min = prq[0];
    prq[0] = prq[heap_size - 1];
    heap_size--;
    heapify(prq, 0);
    return min;
}

int is_empty()
{
    return (heap_size == 0);
}
void dijkstra(Node **graph, int *distances, int *degree, int *parent, int src, int vertices)
{
    int visited[MAX] = {0};
    int i;

    for (i = 0; i < vertices; i++)
    {
        distances[i] = INT_MAX;
        parent[i] = -1;
    }
    distances[src] = 0;
    MinHeap prq[MAX];
    insert(prq, src, 0);

    while (!is_empty())
    {
        MinHeap min = extract_min(prq);
        int j, current_vertex = min.vertex;

        if (visited[current_vertex])
            continue;

        visited[current_vertex] = 1;

        for (j = 0; j < degree[current_vertex]; j++)
        {
            int adj_vertex = graph[current_vertex][j].vertex;
            int weight = graph[current_vertex][j].weight;

            if (!visited[adj_vertex])
            {
                int new_distance = distances[current_vertex] + weight;

                if (new_distance < distances[adj_vertex])
                {
                    distances[adj_vertex] = new_distance;
                    insert(prq, adj_vertex, new_distance);
                    parent[adj_vertex] = current_vertex;
                }
            }
        }
    }
}

int main()
{
    int i, j, vertices, start_vertex, src, dest, weight;

    FILE *fp = fopen("dijkstraFile.txt", "r");
    fscanf(fp, "%d", &vertices);

    Node **graph = (Node **)malloc(sizeof(Node *) * vertices);
    int *degree = calloc(sizeof(int), vertices);
    int *distances = calloc(sizeof(int), vertices);
    int *parent = calloc(sizeof(int), vertices);

    while (fscanf(fp, "%d %d %d", &src, &dest, &weight) != EOF)
    {
        degree[src]++;
    }
    rewind(fp);
    fscanf(fp, "%d", &vertices);

    for (i = 0; i < vertices; i++)
    {
        graph[i] = (Node *)malloc(sizeof(Node) * degree[i]);

        for (j = 0; j < degree[i]; j++)
        {
            fscanf(fp, "%d %d %d", &src, &dest, &weight);
            graph[i][j].vertex = dest;
            graph[i][j].weight = weight;
        }
    }

    printf("Adjacency list \n");
    for (i = 0; i < vertices; i++)
    {
        printf("%d :", i);
        for (j = 0; j < degree[i]; j++)
        {
            printf(" %d-%d ", graph[i][j].vertex, graph[i][j].weight);
        }
        printf("\n");
    }

    printf("Enter source vertex :");
    scanf("%d", &start_vertex);
    dijkstra(graph, distances, degree, parent, start_vertex, vertices);

    printf("Shortest distances \n");
    for (i = 0; i < vertices; i++)
    {
        if (start_vertex == i)
            continue;
        if (distances[i] == INT_MAX)
            printf("No path exists");
        else
        {
            printf("%d :", i);
            int *path = calloc(vertices, sizeof(int));
            int count = 0, current = i;
            while (current != start_vertex)
            {
                path[count] = current;
                count++;
                current = parent[current];
            }
            path[count] = start_vertex;
            for (j = count; j >= 0; j--)
            {
                printf("%d ", path[j]);
            }
            printf(", cost = %d\n", distances[i]);
        }
    }
    return 0;
}