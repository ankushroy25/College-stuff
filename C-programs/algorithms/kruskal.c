// Kruskal's algorithm using union find and disjoint set to find the MST for a given adjacency list.
#include <stdio.h>
#include <stdlib.h>
typedef struct Edge
{
    int src, dest, weight;
} Edge;

typedef struct Subset
{
    int parent, rank; // parent of current vertex, rank -> height of vertex in the tree
} Subset;

int find(Subset subsets[], int i)
{
    // Finds the parent of a vertex using path compression to make the tree more balanced
    // makes the parent of each vertex point directly to the root of the tree.
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    // Joins 2 components into a single components.
    // Attaches the smaller tree to the larger tree to keep the height balanceda
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void swap(Edge *a, Edge *b)
{
    Edge temp = *a;
    *a = *b;
    *b = temp;
}
void KruskalMST(Edge *edges, int num_vertices, int num_edges)
{
    int tot_cost = 0, i, j, src_parent, dest_parent, MST_size = 0;
    Edge *MST = (Edge *)calloc(sizeof(Edge), num_vertices);
    Subset *subsets = (Subset *)calloc(num_edges, sizeof(Subset));

    // Implicit MakeSet - initializing each vertex as its own parent(single component)
    for (int i = 0; i < num_vertices; ++i)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    // sorting by increasing order  of edge weights
    for (i = 0; i < num_edges; i++)
    {
        for (j = 0; j < num_edges - i - 1; j++)
        {
            if (edges[j + 1].weight < edges[j].weight)
            {
                swap(&edges[j], &edges[j + 1]);
            }
        }
    }

    for (i = 0; i < num_edges; i++)
    {
        src_parent = find(subsets, edges[i].src);
        dest_parent = find(subsets, edges[i].dest);
        if (src_parent != dest_parent)
        {
            MST[MST_size++] = edges[i];              // adding the edge to the MST if not cycle
            Union(subsets, src_parent, dest_parent); // adding the new edge component to the exisiting MST
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < MST_size; ++i)
    {
        printf("(%d -> %d) - %d\n", MST[i].src, MST[i].dest, MST[i].weight);
        tot_cost += MST[i].weight;
    }
    printf("Total cost: %d\n", tot_cost);
}
// ©️ Ankush Roy  - 22/03/23
int main()
{
    int num_vertices, num_edges = 0, garbage;
    FILE *fp = fopen("kruskalFile.txt", "r");
    fscanf(fp, "%d", &num_vertices);

    while (fscanf(fp, "%d %d %d", &garbage, &garbage, &garbage) != EOF)
    {
        num_edges++; // counting no. of edges for allocation of edge list
    }
    rewind(fp);
    fscanf(fp, "%d", &num_vertices);

    Edge *edgeList = (Edge *)calloc(num_edges, sizeof(Edge));

    // edge list value insertion from file
    for (int i = 0; i < num_edges; ++i)
    {
        int src, dest, weight;
        fscanf(fp, "%d %d %d", &src, &dest, &weight);
        edgeList[i].src = src;
        edgeList[i].dest = dest;
        edgeList[i].weight = weight;
    }
    KruskalMST(edgeList, num_vertices, num_edges);
    return 0;
}