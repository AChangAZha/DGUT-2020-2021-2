typedef struct Node
{
    int dest; /*邻接边的弧头顶点序号*/
    struct Node *next;
} Edge;

typedef struct
{
    DataType data; /*顶点数据元素*/
    int source;    /*邻接边的弧尾顶点序号*/
    Edge *adj;     /*邻接边的头指针*/
} AdjLHeight;      /*数组的数据元素类型结构体*/

typedef struct
{
    AdjLHeight a[MaxVertices]; /*邻接表数组*/
    int numOfVerts;            /*顶点个数*/
    int numOfEdges;            /*边个数*/
} AdjLGraph;

void AdjInitiate(AdjLGraph *G)
{
    int i;
    G->numOfEdges = 0;
    G->numOfVerts = 0;
    for (i = 0; i < MaxVertices; i++)
    {
        G->a[i].source = i;
        G->a[i].adj = NULL;
    }
}

int InsertVertex(AdjLGraph *G, int i, DataType vertex)
{
    if (i >= 0 && i < MaxVertices)
    {
        G->a[i].data = vertex;
        G->numOfVerts++;
        return 1;
    }
    else
    {
        printf("顶点越界!\n");
        return 0;
    }
}

int InsertEdge(AdjLGraph *G, int v1, int v2, int weight)
{
    Edge *p;
    if (v1 < 0 || v1 >= G->numOfVerts || v2 < 0 || v2 >= G->numOfVerts)
    {
        printf("参数v1或v2出错!");
        return 0;
    }
    p = (Edge *)malloc(sizeof(Edge));
    p->dest = v2;
    p->next = G->a[v1].adj;
    G->a[v1].adj = p;
    G->numOfEdges++;
    return 1;
}
