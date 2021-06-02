#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef int DataType;
typedef char VerT;
#define MaxSize 10
#define MaxQueueSize 10
#define MaxVertices 10
#define MaxWeight 10000
#include "3.h"

int main()
{
    int n = 0, e = 0;
    AdjMGraph MGraph;
    AdjLGraph LGraph;
    MinSpanTree *MinSpanTreeEdge;
    ElemType V[MaxVertices];
    RowColWeight rcw[MaxVertices * MaxVertices];
    FILE *fp;
    if ((fp = fopen("Graph.txt", "r")) == NULL)
    {
        printf("数据文件无法打开！");
        return 0;
    }
    readFile(fp, V, &n, rcw, &e);
    fclose(fp);
    CreatAdjMGraph(&MGraph, V, n, rcw, e);
    // printf("图G的邻接矩阵：\n");
    // PrintAdjMGraph(MGraph);
    // printf("\n");
    // CreatAdjLGraph(&LGraph, V, n, rcw, e);
    // printf("图G的邻接表：\n");
    // PrintAdjLGraph(LGraph);
    // DestroyAdjLGraph(&LGraph);
    // printf("\n");
    // printf("按DFS算法输出图G中顶点的遍历序列：");
    // DepthFirstSearch(MGraph);
    // printf("\n");
    // printf("\n");
    // printf("按BFS算法输出图G中顶点的遍历序列：");
    // BroadFirstSearch(MGraph);
    // printf("\n");
    // printf("\n");
    // printf("最小生成树：\n");
    // MinSpanTreeEdge = (MinSpanTree *)malloc(sizeof(MinSpanTree) * (n - 1));
    // Prim(MGraph, MinSpanTreeEdge, 4);
    Dijkstra(MGraph, 3);
    Degree(MGraph);
    system("pause");
    return 0;
}