#include <stdlib.h>

#define u_8 unsigned char
#define TRUE 1
#define FALSE 0

typedef struct graph_node
{
    u_8 data;
    char script[];
} graph_node;

typedef struct graph_shape
{
    u_8 graph_shape_weight;
    u_8 graph_shape_height;
    graph_node *graph;
    u_8 **edge;
} graph_shape;

u_8 graph_init(graph_shape *shape, u_8 weight, u_8 height)
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

u_8 graph_edge_init(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        shape->edge = (u_8 **)malloc(sizeof(u_8 *) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            shape->edge[i] = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_height);
        }
        return TRUE;
    }
    return FALSE;
}

u_8 graph_edge_set(graph_shape *shape, u_8 x, u_8 y, u_8 value)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->edge[x][y] = value;
        return TRUE;
    }
    return FALSE;
}

u_8 graph_edge_get(graph_shape *shape, u_8 x, u_8 y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        return shape->edge[x][y];
    }
    return FALSE;
}

u_8 graph_edge_free(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            free(shape->edge[i]);
        }
        free(shape->edge);
        return TRUE;
    }
    return FALSE;
}

u_8 graph_free(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        free(shape->graph);
        return TRUE;
    }
    return FALSE;
}

u_8 graph_insert_vertex(graph_shape *shape, u_8 x, u_8 y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->graph[x * shape->graph_shape_height + y].data = 1;
        return TRUE;
    }
    return FALSE;
}

u_8 graph_insert_edge(graph_shape *shape, u_8 x, u_8 y, u_8 value)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->edge[x][y] = value;
        return TRUE;
    }
    return FALSE;
}

u_8 graph_delete_vertex(graph_shape *shape, u_8 x, u_8 y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->graph[x * shape->graph_shape_height + y].data = 0;
        return TRUE;
    }
    return FALSE;
}

u_8 graph_delete_edge(graph_shape *shape, u_8 x, u_8 y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        shape->edge[x][y] = 0;
        return TRUE;
    }
    return FALSE;
}

u_8 graph_print(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            for (u_8 j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", shape->edge[i][j]);
            }
            printf("\n");
        }
        return TRUE;
    }
    return FALSE;
}

u_8 graph_depth_first_search(graph_shape *shape, u_8 x, u_8 y)
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

u_8 graph_breadth_first_search(graph_shape *shape, u_8 x, u_8 y)
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

u_8 graph_topological_sort(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        u_8 *in_degree = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            in_degree[i] = 0;
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            for (u_8 j = 0; j < shape->graph_shape_height; j++)
            {
                if (shape->edge[i][j] == 1)
                {
                    in_degree[j]++;
                }
            }
        }
        u_8 *queue = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        u_8 front = 0, rear = 0;
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            if (in_degree[i] == 0)
            {
                queue[rear++] = i;
            }
        }
        while (front != rear)
        {
            u_8 temp = queue[front++];
            printf("%hhu ", temp);
            for (u_8 i = 0; i < shape->graph_shape_height; i++)
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

u_8 graph_prim(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        u_8 *low_cost = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        u_8 *adjvex = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        u_8 *s = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            low_cost[i] = shape->edge[0][i];
            adjvex[i] = 0;
            s[i] = 0;
        }
        s[0] = 1;
        for (u_8 i = 1; i < shape->graph_shape_weight; i++)
        {
            u_8 min = 0;
            for (u_8 j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && low_cost[j] < low_cost[min])
                {
                    min = j;
                }
            }
            printf("%hhu %hhu\n", adjvex[min], min);
            s[min] = 1;
            for (u_8 j = 1; j < shape->graph_shape_weight; j++)
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

u_8 graph_kruskal(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        u_8 *parent = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            parent[i] = 0;
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            u_8 min = 0;
            for (u_8 j = 1; j < shape->graph_shape_weight; j++)
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

u_8 graph_dijkstra(graph_shape *shape, u_8 x, u_8 y)
{
    if (x < shape->graph_shape_weight && y < shape->graph_shape_height)
    {
        u_8 *dist = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        u_8 *path = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        u_8 *s = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            dist[i] = shape->edge[x][i];
            path[i] = x;
            s[i] = 0;
        }
        s[x] = 1;
        for (u_8 i = 1; i < shape->graph_shape_weight; i++)
        {
            u_8 min = 0;
            for (u_8 j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && dist[j] < dist[min])
                {
                    min = j;
                }
            }
            s[min] = 1;
            for (u_8 j = 1; j < shape->graph_shape_weight; j++)
            {
                if (s[j] == 0 && dist[min] + shape->edge[min][j] < dist[j])
                {
                    dist[j] = dist[min] + shape->edge[min][j];
                    path[j] = min;
                }
            }
        }
        printf("%hhu ", dist[y]);
        u_8 temp = y;
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

u_8 graph_floyd(graph_shape *shape)
{
    if (shape->graph_shape_weight > 0 && shape->graph_shape_height > 0)
    {
        u_8 **dist = (u_8 **)malloc(sizeof(u_8 *) * shape->graph_shape_weight);
        u_8 **path = (u_8 **)malloc(sizeof(u_8 *) * shape->graph_shape_weight);
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            dist[i] = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_height);
            path[i] = (u_8 *)malloc(sizeof(u_8) * shape->graph_shape_height);
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            for (u_8 j = 0; j < shape->graph_shape_height; j++)
            {
                dist[i][j] = shape->edge[i][j];
                path[i][j] = j;
            }
        }
        for (u_8 k = 0; k < shape->graph_shape_weight; k++)
        {
            for (u_8 i = 0; i < shape->graph_shape_weight; i++)
            {
                for (u_8 j = 0; j < shape->graph_shape_height; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = path[i][k];
                    }
                }
            }
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            for (u_8 j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", dist[i][j]);
            }
            printf("\n");
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
        {
            for (u_8 j = 0; j < shape->graph_shape_height; j++)
            {
                printf("%hhu ", path[i][j]);
            }
            printf("\n");
        }
        for (u_8 i = 0; i < shape->graph_shape_weight; i++)
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
