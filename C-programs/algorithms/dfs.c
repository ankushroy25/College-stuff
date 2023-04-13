#include <stdio.h>
#include <stdlib.h>

void dfs(int **graph, int *degree, int *visited, int vertices, int src)
{

    visited[src] = 1;
    // printf("%d ", src); -> print at first discover of node
    int i;

    for (i = 0; i < degree[src]; i++)
    {
        int nb = graph[src][i];
        if (!visited[nb])
        {
            dfs(graph, degree, visited, vertices, nb);
        }
    }
    printf("%d ", src); // print at pop when no more neighbour nodes left to discover
}

void dfsTraverse(int **graph, int *degree, int *visited, int vertices)
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        if (!visited[i])
            dfs(graph, degree, visited, vertices, i);
    }
}

int main()
{
    int vertices, src, i, j, v, nb;

    FILE *fp = fopen("dfsFile.txt", "r");
    fscanf(fp, "%d", &vertices);

    int **graph = (int **)malloc(vertices * sizeof(int *));
    int *degree = (int *)calloc(vertices, sizeof(int));
    int *visited = (int *)calloc(vertices, sizeof(int));

    while (fscanf(fp, "%d%d", &v, &nb) != EOF)
    {
        degree[v]++;
    }

    rewind(fp);
    fscanf(fp, "%d", &vertices);

    for (i = 0; i < vertices; i++)
    {
        graph[i] = (int *)calloc(degree[i], sizeof(int));

        for (j = 0; j < degree[i]; j++)
        {
            fscanf(fp, "%d%d", &v, &nb);
            graph[i][j] = nb;
        }
    }

    for (i = 0; i < vertices; i++)
    {
        printf("%d :", i);
        for (j = 0; j < degree[i]; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("DFS traversal : ");
    dfsTraverse(graph, degree, visited, vertices);
    printf("\n");

    return 0;
}
