#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int left;
    int forward;
    int right;
} InterSection;
typedef struct
{
    int mazeSize;
    InterSection *intSec;
    int Exit;
} Maze;
int TravMaze(Maze *m, int currSetValue)
{
    if (currSetValue > 0)
    {
        if (currSetValue == m->Exit)
        {
            printf("%d <== ", currSetValue);
            return 1;
        }
        else if (TravMaze(m, m->intSec[currSetValue].left) == 1)
        {
            printf("%d <== ", currSetValue);
            return 1;
        }
        else if (TravMaze(m, m->intSec[currSetValue].forward) == 1)
        {
            printf("%d <== ", currSetValue);
            return 1;
        }
        else if (TravMaze(m, m->intSec[currSetValue].right) == 1)
        {
            printf("%d <== ", currSetValue);
            return 1;
        }
    }
    return 0;
}
void CreatMaze(char *filename, Maze *m)
{
    FILE *fp;
    int i;
    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("数据文件无法打开！");
        return;
    }
    fscanf(fp, "%d", &m->mazeSize);
    m->intSec = (InterSection *)malloc(sizeof(InterSection) * (m->mazeSize + 1));
    for (i = 1; i <= m->mazeSize; i++)
    {
        fscanf(fp, "%d%d%d", &m->intSec[i].left, &m->intSec[i].forward, &m->intSec[i].right);
    }
    fscanf(fp, "%d", &m->Exit);
    fclose(fp);
}
int main()
{
    Maze m;
    int start = 1;
    CreatMaze("Mazel.txt", &m);
    if (!TravMaze(&m, start))
        printf("\n此迷宫无通路！");
}