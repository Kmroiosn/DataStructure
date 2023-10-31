#include <stdio.h>
#include "realize.h"

int interaction(void)
{
    printf("1. Create a graph\n");
    printf("2. Insert a vertex\n");
    printf("3. Insert an edge\n");
    printf("4. Delete a vertex\n");
    printf("5. Delete an edge\n");
    printf("6. Depth first search\n");
    printf("7. Breadth first search\n");
    printf("8. Topological sort\n");
    printf("9. Prim\n");
    printf("10. Kruskal\n");
    printf("11. Dijkstra\n");
    printf("12. Floyd\n");
    printf("13. Print the graph\n");
    printf("14. Exit\n");
    printf("Please input your choice: ");
    int t;
    scanf("%d", &t);
    return t;
}

void create_graph(graph_shape *shape)
{
    int weight = 0, height = 0;
    printf("Please input the weight of the graph: ");
    scanf("%hhu", &weight);
    printf("Please input the height of the graph: ");
    scanf("%hhu", &height);
    if (graph_init(shape, weight, height) == TRUE)
    {
        printf("Create a graph successfully!\n");
    }
    else
    {
        printf("Create a graph failed!\n");
    }
}

void insert_vertex(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the vertex: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_insert_vertex(shape, x, y) == TRUE)
    {
        printf("Insert a vertex successfully!\n");
    }
    else
    {
        printf("Insert a vertex failed!\n");
    }
}

void insert_edge(graph_shape *shape)
{
    int x = 0, y = 0, value = 0;
    printf("Please input the position of the edge: ");
    scanf("%hhu %hhu", &x, &y);
    printf("Please input the value of the edge: ");
    scanf("%hhu", &value);
    if (graph_insert_edge(shape, x, y, value) == TRUE)
    {
        printf("Insert an edge successfully!\n");
    }
    else
    {
        printf("Insert an edge failed!\n");
    }
}

void delete_vertex(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the vertex: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_delete_vertex(shape, x, y) == TRUE)
    {
        printf("Delete a vertex successfully!\n");
    }
    else
    {
        printf("Delete a vertex failed!\n");
    }
}

void delete_edge(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the edge: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_delete_edge(shape, x, y) == TRUE)
    {
        printf("Delete an edge successfully!\n");
    }
    else
    {
        printf("Delete an edge failed!\n");
    }
}

void depth_first_search(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the vertex: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_depth_first_search(shape, x, y) == TRUE)
    {
        printf("Depth first search successfully!\n");
    }
    else
    {
        printf("Depth first search failed!\n");
    }
}

void breadth_first_search(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the vertex: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_breadth_first_search(shape, x, y) == TRUE)
    {
        printf("Breadth first search successfully!\n");
    }
    else
    {
        printf("Breadth first search failed!\n");
    }
}

void topological_sort(graph_shape *shape)
{
    if (graph_topological_sort(shape) == TRUE)
    {
        printf("Topological sort successfully!\n");
    }
    else
    {
        printf("Topological sort failed!\n");
    }
}

void prim(graph_shape *shape)
{
    if (graph_prim(shape) == TRUE)
    {
        printf("Prim successfully!\n");
    }
    else
    {
        printf("Prim failed!\n");
    }
}

void kruskal(graph_shape *shape)
{
    if (graph_kruskal(shape) == TRUE)
    {
        printf("Kruskal successfully!\n");
    }
    else
    {
        printf("Kruskal failed!\n");
    }
}

void dijkstra(graph_shape *shape)
{
    int x = 0, y = 0;
    printf("Please input the position of the vertex: ");
    scanf("%hhu %hhu", &x, &y);
    if (graph_dijkstra(shape, x, y) == TRUE)
    {
        printf("Dijkstra successfully!\n");
    }
    else
    {
        printf("Dijkstra failed!\n");
    }
}

void floyd(graph_shape *shape)
{
    if (graph_floyd(shape) == TRUE)
    {
        printf("Floyd successfully!\n");
    }
    else
    {
        printf("Floyd failed!\n");
    }
}

void print_graph(graph_shape *shape)
{
    if (graph_print(shape) == TRUE)
    {
        printf("Print the graph successfully!\n");
    }
    else
    {
        printf("Print the graph failed!\n");
    }
}

void exit_graph(graph_shape *shape)
{
    if (graph_free(shape) == TRUE)
    {
        printf("Exit the graph successfully!\n");
    }
    else
    {
        printf("Exit the graph failed!\n");
    }
}

int main(){
    graph_shape shape;
    int choice = 0;
    while (1)
    {
        choice = interaction();
        switch (choice)
        {
        case 1:
            create_graph(&shape);
            break;
        case 2:
            insert_vertex(&shape);
            break;
        case 3:
            insert_edge(&shape);
            break;
        case 4:
            delete_vertex(&shape);
            break;
        case 5:
            delete_edge(&shape);
            break;
        case 6:
            depth_first_search(&shape);
            break;
        case 7:
            breadth_first_search(&shape);
            break;
        case 8:
            topological_sort(&shape);
            break;
        case 9:
            prim(&shape);
            break;
        case 10:
            kruskal(&shape);
            break;
        case 11:
            dijkstra(&shape);
            break;
        case 12:
            floyd(&shape);
            break;
        case 13:
            print_graph(&shape);
            break;
        case 14:
            exit_graph(&shape);
            return 0;
        default:
            printf("Please input the right choice!\n");
            break;
        }
    }
    return 0;
}
