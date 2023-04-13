// dijksta algorithm using link list representaion of adjacency list with linear traversal for maintaining minimum distance

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10000

struct node
{
    int vertex;
    int weight;
    struct node *next;
};

struct Graph
{
    int num_vertices;
    struct node **adj_lists;
};

struct node *create_node(int v, int weight)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *create_graph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->num_vertices = vertices;

    graph->adj_lists = (struct node **)malloc(vertices * sizeof(struct node *));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adj_lists[i] = NULL;
    }

    return graph;
}

void add_edge(struct Graph *graph, int src, int dest, int weight)
{
    struct node *newNode = create_node(dest, weight);
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;

    // below part for undirected graphs
    // newNode = create_node(src, weight);
    // newNode->next = graph->adj_lists[dest];
    // graph->adj_lists[dest] = newNode;
}

void dijkstra(struct Graph *graph, int start_vertex, int *distances)
{
    int visited[MAX_VERTICES] = {0};
    int i;

    for (i = 0; i < graph->num_vertices; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[start_vertex] = 0;

    for (i = 0; i < graph->num_vertices - 1; i++)
    {
        int min_distance = INT_MAX;
        int current_vertex = -1;
        int j;

        for (j = 0; j < graph->num_vertices; j++)
        {
            if (!visited[j] && distances[j] < min_distance)
            {
                current_vertex = j;
                min_distance = distances[j];
            }
        }

        visited[current_vertex] = 1;
        struct node *temp = graph->adj_lists[current_vertex];

        while (temp != NULL)
        {
            int adj_vertex = temp->vertex;
            int weight = temp->weight;

            if (!visited[adj_vertex])
            {
                int new_distance = distances[current_vertex] + weight;

                if (new_distance < distances[adj_vertex])
                {
                    distances[adj_vertex] = new_distance;
                }
            }

            temp = temp->next;
        }
    }
}

int main()
{
    int num_vertices = 5;
    int start_vertex = 0;
    struct Graph *graph = create_graph(num_vertices);

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 3, 5);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 1, 3, 2);
    add_edge(graph, 2, 4, 4);
    add_edge(graph, 3, 1, 3);
    add_edge(graph, 3, 2, 9);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 4, 0, 7);
    add_edge(graph, 4, 2, 6);

    int distances[MAX_VERTICES];
    dijkstra(graph, start_vertex, distances);

    int i;
    printf("Shortest distances from vertex %d to :-\n");

    for (i = 0; i < num_vertices; i++)
        printf("%d : %d\n", i, distances[i]);

    return 0;
}