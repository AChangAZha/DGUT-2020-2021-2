#include "SeqList.h"
#include "SeqCQueue.h"
typedef struct
{
    SeqList Vertices;
    int edge[MaxVertices][MaxVertices];
    int numOfEdges;
} AdjMGraph;

typedef struct
{
    int V1;
    int V2;
    int weight; //权值
} RowColWeight;

typedef struct Node
{
    int dest;
    int cost;
    struct Node *next;
} Edge;

typedef struct
{
    ElemType data;
    int source;
    Edge *adj;
} AdjLHeight;

typedef struct
{
    AdjLHeight a[MaxVertices];
    int numOfVerts;
    int numOfEdges;
} AdjLGraph;

typedef struct
{
    VerT start;
    VerT end;
    int weight;
} MinSpanTree;

typedef struct
{
    int start;
    int weight;
} lowCost;

void readFile(FILE *fp, ElemType V[], int *n, RowColWeight E[], int *e)
{
    char ch;
    int V1, V2, weight;
    while (1)
    {
        if ((fscanf(fp, "%c", &ch)) == EOF)
            return;
        if (ch == '\n')
            break;
        V[*n] = ch;
        (*n)++;
    }
    while ((fscanf(fp, "%d%d%d", &V1, &V2, &weight)) != EOF)
    {
        E[*e].V1 = V1;
        E[*e].V2 = V2;
        E[*e].weight = weight;
        (*e)++;
    }
}

void CreatAdjMGraph(AdjMGraph *G, ElemType V[], int n, RowColWeight E[], int e)
{
    ListInitiate(&G->Vertices);
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i == j)
                G->edge[i][j] = 0;
            else
                G->edge[i][j] = MaxWeight;
        }
    G->numOfEdges = 0;
    for (i = 0; i < n; i++)
        ListInsert(&G->Vertices, G->Vertices.size, V[i]);
    for (i = 0; i < e; i++)
    {
        G->edge[E[i].V1][E[i].V2] = E[i].weight;
        // G->edge[E[i].V2][E[i].V1] = E[i].weight;
        G->numOfEdges++;
    }
}

void PrintAdjMGraph(AdjMGraph G)
{
    int i, j;
    for (i = 0; i < G.Vertices.size; i++)
    {
        printf("%c   ", G.Vertices.list[i]);
        for (j = 0; j < G.Vertices.size; j++)
            if (G.edge[i][j] != MaxWeight)
                printf("%4d", G.edge[i][j]);
            else
                printf("%4s", "∞");
        printf("\n");
    }
}

void CreatAdjLGraph(AdjLGraph *G, ElemType V[], int n, RowColWeight E[], int e)
{
    int i;
    G->numOfEdges = 0;
    G->numOfVerts = 0;
    for (i = 0; i < MaxVertices; i++)
    {
        G->a[i].source = i;
        G->a[i].adj = NULL;
    }
    for (i = 0; i < n; i++)
    {
        G->a[i].data = V[i];
        G->numOfVerts++;
    }
    for (i = 0; i < e; i++)
    {
        Edge *p, *q;
        p = (Edge *)malloc(sizeof(Edge));
        p->dest = E[i].V2;
        p->cost = E[i].weight;
        p->next = G->a[E[i].V1].adj;
        G->a[E[i].V1].adj = p;

        // q = (Edge *)malloc(sizeof(Edge));
        // q->dest = E[i].V1;
        // q->cost = E[i].weight;
        // q->next = G->a[E[i].V2].adj;
        // G->a[E[i].V2].adj = q;

        G->numOfEdges++;
    }
}

void PrintAdjLGraph(AdjLGraph G)
{
    Edge *p;
    int i;
    printf("%-5s%-7s%-7s%-5s%-5s%-5s\n", "data", "source", "adj", "dest", "cost", "next");
    for (i = 0; i < G.numOfVerts; i++)
    {
        printf("%-5c%-7d", G.a[i].data, G.a[i].source);
        if (G.a[i].adj == NULL)
            printf("%-7s", "---");
        else
        {
            printf("%-7s", "-->");
            p = G.a[i].adj;
            while (p != NULL)
            {
                printf("%-5d%-5d", p->dest, p->cost);
                if (p->next != NULL)
                    printf("%-5s", "-->");
                else
                    printf("%-5s", "---");
                p = p->next;
            }
        }
        printf("\n");
    }
}

void DestroyAdjLGraph(AdjLGraph *G)
{
    Edge *p, *tmp;
    int i;
    for (i = 0; i < G->numOfVerts; i++)
    {
        p = G->a[i].adj;
        while (p != NULL)
        {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
}

int GetFirstVex(AdjMGraph G, int v)
{
    int col;
    for (col = 0; col < G.Vertices.size; col++)
        if (G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight)
            return col;
    return -1;
}

int GetNextVex(AdjMGraph G, int v1, int v2)
{
    int col;
    for (col = v2 + 1; col <= G.Vertices.size; col++)
        if (G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight)
            return col;
    return -1;
}

void DepthFSearch(AdjMGraph G, int v, int visited[])
{
    int w;
    printf("%c  ", G.Vertices.list[v]);
    visited[v] = 1;
    w = GetFirstVex(G, v);
    while (w != -1)
    {
        if (!visited[w])
            DepthFSearch(G, w, visited);
        w = GetNextVex(G, v, w);
    }
}

void DepthFirstSearch(AdjMGraph G)
{
    int i;
    int *visited = (int *)malloc(sizeof(int) * G.Vertices.size);
    for (i = 0; i < G.Vertices.size; i++)
        visited[i] = 0;
    for (i = 0; i < G.Vertices.size; i++)
        if (!visited[i])
            DepthFSearch(G, i, visited);
    free(visited);
}

void BroadFSearch(AdjMGraph G, int v, int visited[])
{
    int u, w;
    SeqCQueue queue;
    printf("%c  ", G.Vertices.list[v]);
    visited[v] = 1;
    QueueInitiate(&queue);
    QueueAppend(&queue, v);
    while (QueueNotEmpty(queue))
    {
        QueueDelete(&queue, &u);
        w = GetFirstVex(G, u);
        while (w != -1)
        {
            if (!visited[w])
            {
                printf("%c  ", G.Vertices.list[w]);
                visited[w] = 1;
                QueueAppend(&queue, w);
            }
            w = GetNextVex(G, u, w);
        }
    }
}

void BroadFirstSearch(AdjMGraph G)
{
    int i;
    int *visited = (int *)malloc(sizeof(int) * G.Vertices.size);
    for (i = 0; i < G.Vertices.size; i++)
        visited[i] = 0;
    for (i = 0; i < G.Vertices.size; i++)
        if (!visited[i])
            BroadFSearch(G, i, visited);
    free(visited);
}

void Prim(AdjMGraph G, MinSpanTree MinSpanTreeEdge[], int start)
{
    VerT x;
    int i, j, k;
    int n = G.Vertices.size, minCost;
    if (start >= n)
        return;
    lowCost *Vertices = (lowCost *)malloc(sizeof(lowCost) * n);
    for (i = 0; i < n; i++)
    {
        Vertices[i].start = start;
        Vertices[i].weight = G.edge[start][i];
    }
    Vertices[start].weight = -1;
    for (i = 0; i < n - 1; i++)
    {
        minCost = MaxWeight;
        for (j = 0; j < n; j++)
        {
            if (Vertices[j].weight < minCost && Vertices[j].weight > 0)
            {
                minCost = Vertices[j].weight;
                k = j;
            }
        }
        if (minCost == MaxWeight)
        {
            printf("该图不是连通图，无最小生成树!\n");
            free(MinSpanTreeEdge);
            free(Vertices);
            return;
        }
        ListGet(G.Vertices, k, &x);
        MinSpanTreeEdge[i].end = x;
        ListGet(G.Vertices, Vertices[k].start, &x);
        MinSpanTreeEdge[i].start = x;
        MinSpanTreeEdge[i].weight = minCost;
        Vertices[k].weight = -1;
        for (j = 0; j < n; j++)
        {
            if (G.edge[k][j] < Vertices[j].weight)
            {
                Vertices[j].start = k;
                Vertices[j].weight = G.edge[k][j];
            }
        }
    }
    for (i = 0; i < n - 1; i++)
        printf("%c-%c-%d\n", MinSpanTreeEdge[i].start, MinSpanTreeEdge[i].end, MinSpanTreeEdge[i].weight);
    free(MinSpanTreeEdge);
    free(Vertices);
}

void Ppath(AdjMGraph G, int path[], int i)
{
    char ch;
    if (path[i] == -1)
        return;
    Ppath(G, path, path[i]);
    ListGet(G.Vertices, path[i], &ch);
    printf("%c ", ch);
}

void Dispath(AdjMGraph G, int distance[], int path[], int v)
{
    char start, end;
    int i;
    ListGet(G.Vertices, v, &start);
    for (i = 0; i < G.Vertices.size; i++)
    {
        if (i == v)
            continue;
        ListGet(G.Vertices, i, &end);
        if (distance[i] == MaxWeight)
        {
            printf("从%c到%c无通路\n", start, end);
            continue;
        }
        printf("从%c到%c的最短路径长度为:%d\t路径为:", start, end, distance[i]);
        Ppath(G, path, i);
        printf("%c\n", end);
    }
}

void Dijkstra(AdjMGraph G, int v0)
{
    int n = G.Vertices.size;
    int minDis, i, j, u;
    int s[MaxVertices];
    int distance[MaxVertices];
    int path[MaxVertices];
    if (v0 >= G.Vertices.size)
        return;
    for (i = 0; i < n; i++)
    {
        distance[i] = G.edge[v0][i];
        s[i] = 0;
        if (i != v0 && distance[i] < MaxWeight)
            path[i] = v0;
        else
            path[i] = -1;
    }
    s[v0] = 1;
    for (i = 1; i < n; i++)
    {
        minDis = MaxWeight;
        for (j = 0; j < n; j++)
            if (s[j] == 0 && distance[j] < minDis)
            {
                u = j;
                minDis = distance[j];
            }
        if (minDis == MaxWeight)
            break;
        s[u] = 1;
        for (j = 0; j < n; j++)
            if (s[j] == 0 && G.edge[u][j] < MaxWeight && distance[u] + G.edge[u][j] < distance[j])
            {
                distance[j] = distance[u] + G.edge[u][j];
                path[j] = u;
            }
    }
    Dispath(G, distance, path, v0);
}

void Degree(AdjMGraph G)
{
    int Indegree[MaxVertices] = {0};
    int Outdegree;
    char ch;
    int i, j;
    for (i = 0; i < G.Vertices.size; i++)
    {
        Outdegree = 0;
        ListGet(G.Vertices, i, &ch);
        for (j = 0; j < G.Vertices.size; j++)
        {
            if (j != i && G.edge[i][j] < MaxWeight)
            {
                Outdegree++;
                Indegree[j]++;
            }
        }
        printf("顶点%c的出度为：%d\n", ch, Outdegree);
    }
    for (i = 0; i < G.Vertices.size; i++)
    {
        ListGet(G.Vertices, i, &ch);
        printf("顶点%c的入度为：%d\n", ch, Indegree[i]);
    }
}