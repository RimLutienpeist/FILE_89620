#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct point  
{  
    int checkpoint;  
    int time;  
    struct point *Next;  
} Point;  
  
typedef struct graph  
{  
    int checkpoints;  
    int activities;  
    Point *points;  
    int *indegree;  
} Graph;  
  
Graph* createGraph(int checkpoints)  
{  
    Graph *graph = (Graph*)malloc(sizeof(Graph));  
    graph->checkpoints = checkpoints;  
    graph->activities = 0;  
    graph->points = (Point*)malloc(checkpoints * sizeof(Point));  
    graph->indegree = (int*)calloc(checkpoints, sizeof(int));  
    return graph;  
}  
  
void destroyGraph(Graph *graph)  
{  
    int i;  
    for (i = 0; i < graph->checkpoints; i++)  
    {  
        Point *current = graph->points[i];  
        while (current != NULL)  
        {  
            Point *temp = current;  
            current = current->Next;  
            free(temp);  
        }  
    }  
    free(graph->points);  
    free(graph->indegree);  
    free(graph);  
}  
  
void insertActivity(Graph *graph, int point1, int point2, int time)  
{  
    Point *temppoint = (Point*)malloc(sizeof(Point));  
    temppoint->checkpoint = point2;  
    temppoint->time = time;  
    temppoint->Next = graph->points[point1];  
    graph->points[point1] = temppoint;  
    graph->indegree[point2]++;  
    graph->activities++;  
}  
  
void topologicalSort(Graph *graph)  
{  
    int i, j, checkpoint, pointnumbers = 0, maxtime = 0;  
    int *time = (int*)calloc(graph->checkpoints, sizeof(int));  
    int *stack = (int*)malloc(graph->checkpoints * sizeof(int));  
    int top = -1;  
  
    for (i = 0; i < graph->checkpoints; i++)  
    {  
        if (graph->indegree[i] == 0)  
        {  
            stack[++top] = i;  
            graph->indegree[i]--;  
            pointnumbers++;  
        }  
    }  
  
    while (top >= 0)  
    {  
        int lasttop = top;  
        for (i = 0; i <= lasttop; i++)  
        {  
            checkpoint = stack[i];  
            Point *position = graph->points[checkpoint];  
            while (position != NULL)  
            {  
                int nextCheckpoint = position->checkpoint;  
                graph->indegree[nextCheckpoint]--;  
                if (time[nextCheckpoint] < position->time + time[checkpoint])  
                {  
                    time[nextCheckpoint] = position->time + time[checkpoint];  
                    if (time[nextCheckpoint] > maxtime)  
                        maxtime = time[nextCheckpoint];  
                }  
                if (graph->indegree[nextCheckpoint] == 0)  
                {  
                    stack[++top] = nextCheckpoint;  
                    graph->indegree[nextCheckpoint]--;  
                    pointnumbers++;  
                }  
                position = position->Next;  
            }  
        }  
        top -= lasttop + 1;  
    }  
  
    if (pointnumbers != graph->checkpoints)  
        printf("Impossible");  
    else  
        printf("%d", maxtime);  
  
    free(time);  
    free(stack);  
}  
  
int main()  
{  
    int i, checkpoints, activities;  
    scanf("%d %d", &checkpoints, &activities);  
    Graph *graph = createGraph(checkpoints);  
  
    for (i = 0; i < activities; i++)  
    {  
        int point1, point2, time;  
        scanf("%d %d %d", &point1, &point2, &time);  
        insertActivity(graph, point1, point2, time);  
    }  
  
    topologicalSort(graph);  
    destroyGraph(graph);  
    return 0;  
}  