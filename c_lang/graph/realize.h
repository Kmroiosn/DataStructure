#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_EDGE 1000

typedef struct graph_node
{
    int id;
    int data;
    char script[100];
} graph_node;

typedef struct graph_shape
{
    int graph_shape_weight;
    int graph_shape_height;
    graph_node *graph;
    int edges[MAX_EDGE][MAX_EDGE];
} graph_shape;

int graph_init(graph_shape *shape, int weight, int height)
{
    if (weight > 0 && height > 0)
    {
        shape->graph_shape_weight = weight;
        shape->graph_shape_height = height;
        shape->graph = (graph_node *)malloc(sizeof(graph_node) * weight * height);
        return TRUE;
    }
    return FALSE;
}

int graph_free(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        free(shape->graph);
        return TRUE;
    }
    return FALSE;
}

int graph_insert_vertex(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->graph[x * shape->graph_shape_height + y].data = 1;
        return TRUE;
    }
    return FALSE;
}

int graph_insert_edge(graph_shape *shape, int x, int y, int value)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->edge[x][y] = value;
        return TRUE;
    }
    return FALSE;
}

int graph_delete_vertex(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->graph[x * shape->graph_shape_height + y].data = 0;
        return TRUE;
    }
    return FALSE;
}

int graph_delete_edge(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->edge[x][y] = 0;
        return TRUE;
    }
    return FALSE;
}

int graph_print(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            for (int j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", shape->edge[i][j]);
            }
            printf("\n");
        }
        return TRUE;
    }
    return FALSE;
}

int graph_depth_first_search(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        if (shape->graph[x * shape->graph_shape_height + y].data == 1)
        {
            printf("%hhu ", shape->edge[x][y]);
            shape->graph[x * shape->graph_shape_height + y].data = 0;
            if (x - 1 >= 0)
            {
                graph_depth_first_search(shape, x - 1, y);
            }
            if (x + 1 < shape->graph_shape_weight)
            {
                graph_depth_first_search(shape, x + 1, y);
            }
            if (y - 1 >= 0)
            {
                graph_depth_first_search(shape, x, y - 1);
            }
            if (y + 1 < shape->graph_shape_height)
            {
                graph_depth_first_search(shape, x, y + 1);
            }
            return TRUE;
        }
    }
    return FALSE;
}

int graph_breadth_first_search(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        if (shape->graph[x * shape->graph_shape_height + y].data == 1)
        {
            printf("%hhu ", shape->edge[x][y]);
            shape->graph[x * shape->graph_shape_height + y].data = 0;
            if (x - 1 >= 0)
            {
                graph_breadth_first_search(shape, x - 1, y);
            }
            if (x + 1 < shape->graph_shape_weight)
            {
                graph_breadth_first_search(shape, x + 1, y);
            }
            if (y - 1 >= 0)
            {
                graph_breadth_first_search(shape, x, y - 1);
            }
            if (y + 1 < shape->graph_shape_height)
            {
                graph_breadth_first_search(shape, x, y + 1);
            }
            return TRUE;
        }
    }
    return FALSE;
}

int graph_topological_sort(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        int *in_degree = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            in_degree[i] = 0;
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            for (int j = 0; j < shape->graph_shape_height; j++)
            {
                if (shape->edge[i][j] == 1)
                {
                    in_degree[j]++;
                }
            }
        }
        int *queue = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        int front = 0, rear = 0;
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            if (in_degree[i] == 0)
            {
                queue[rear++] = i;
            }
        }
        while (front != rear)
        {
            int temp = queue[front++];
            printf("%hhu ", temp);
            for (int i = 0; i < shape->graph_shape_height; i++)
            {
                if (shape->edge[temp][i] == 1)
                {
                    in_degree[i]--;
                    if (in_degree[i] == 0)
                    {
                        queue[rear++] = i;
                    }
                }
            }
        }
        free(in_degree);
        free(queue);
        return TRUE;
    }
    return FALSE;
}

int graph_prim(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        int *low_cost = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        int *adjvex = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        int *s = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            low_cost[i] = shape->edge[0][i];
            adjvex[i] = 0;
            s[i] = 0;
        }
        s[0] = 1;
        for (int i = 1; i < shape->graph_shape_weight; i++)
        {
            int min = 0;
            for (int j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && low_cost[j] < low_cost[min])
                {
                    min = j;
                }
            }
            printf("%hhu %hhu\n", adjvex[min], min);
            s[min] = 1;
            for (int j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && shape->edge[min][j] < low_cost[j])
                {
                    low_cost[j] = shape->edge[min][j];
                    adjvex[j] = min;
                }
            }
        }
        free(low_cost);
        free(adjvex);
        free(s);
        return TRUE;
    }
    return FALSE;
}

int graph_kruskal(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        int *parent = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            parent[i] = 0;
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            int min = 0;
            for (int j = 1; j < shape->graph_shape_weight; j++)
            {
                if (shape->edge[i][j] < shape->edge[min][parent[min]])
                {
                    min = j;
                }
            }
            printf("%hhu %hhu\n", min, parent[min]);
            parent[min] = min;
        }
        free(parent);
        return TRUE;
    }
    return FALSE;
}

int graph_dijkstra(graph_shape *shape, int x, int y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        int *dist = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        int *path = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        int *s = (int *)malloc(sizeof(int) * shape->graph_shape_weight);
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            dist[i] = shape->edge[x][i];
            path[i] = x;
            s[i] = 0;
        }
        s[x] = 1;
        for (int i = 1; i < shape->graph_shape_weight; i++)
        {
            int min = 0;
            for (int j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && dist[j] < dist[min])
                {
                    min = j;
                }
            }
            s[min] = 1;
            for (int j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && dist[min] + shape->edge[min][j] < dist[j])
                {
                    dist[j] = dist[min] + shape->edge[min][j];
                    path[j] = min;
                }
            }
        }
        printf("%hhu ", dist[y]);
        int temp = y;
        while (temp != x)
        {
            printf("%hhu ", temp);
            temp = path[temp];
        }
        printf("%hhu ", x);
        free(dist);
        free(path);
        free(s);
        return TRUE;
    }
    return FALSE;
}

int graph_floyd(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        int **dist = (int **)malloc(sizeof(int *) * shape->graph_shape_weight);
        int **path = (int **)malloc(sizeof(int *) * shape->graph_shape_weight);
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            dist[i] = (int *)malloc(sizeof(int) * shape->graph_shape_height);
            path[i] = (int *)malloc(sizeof(int) * shape->graph_shape_height);
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            for (int j = 0; j < shape->graph_shape_height; j++)
            {
                dist[i][j] = shape->edge[i][j];
                path[i][j] = j;
            }
        }
        for (int k = 0; k < shape->graph_shape_weight; k++)
        {
            for (int i = 0; i < shape->graph_shape_weight; i++)
            {
                for (int j = 0; j < shape->graph_shape_height; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            for (int j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", dist[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            for (int j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", path[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < shape->graph_shape_weight; i++)
        {
            free(dist[i]);
            free(path[i]);
        }
        free(dist);
        free(path);
        return TRUE;
    }
    return FALSE;
}
