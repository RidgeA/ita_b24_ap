#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Forward declarations to avoid circular dependencies
typedef struct vertex vertex;
typedef struct edge edge;
typedef struct graph graph;

// Structure to represent a graph edge
struct edge
{
    vertex *source;
    vertex *target;
};

// Structure to represent a graph vertex
struct vertex
{
    int data;
    edge **edges;
    int edge_count;
};

// Structure to represent a graph
struct graph
{
    vertex **vertices;
    int vertex_count;
    edge **edges;
    int edge_count;
};

// Function to create a new vertex
vertex *create_vertex(int data)
{
    vertex *new_vertex = (vertex *)malloc(sizeof(vertex));
    if (new_vertex == NULL)
    {
        printf("Memory allocation error for vertex\n");
        exit(1);
    }

    new_vertex->data = data;
    new_vertex->edges = NULL;
    new_vertex->edge_count = 0;

    return new_vertex;
}

// Function to create a new edge
edge *create_edge(vertex *source, vertex *target)
{
    edge *new_edge = (edge *)malloc(sizeof(edge));
    if (new_edge == NULL)
    {
        printf("Memory allocation error for edge\n");
        exit(1);
    }

    new_edge->source = source;
    new_edge->target = target;

    return new_edge;
}

// Function to create a new graph
graph *create_graph()
{
    graph *new_graph = (graph *)malloc(sizeof(graph));
    if (new_graph == NULL)
    {
        printf("Memory allocation error for graph\n");
        exit(1);
    }

    new_graph->vertices = NULL;
    new_graph->vertex_count = 0;
    new_graph->edges = NULL;
    new_graph->edge_count = 0;

    return new_graph;
}

// Function to add a vertex to the graph
void add_vertex_to_graph(graph *graph_ptr, vertex *vertex_ptr)
{
    graph_ptr->vertex_count++;
    graph_ptr->vertices = (vertex **)realloc(graph_ptr->vertices,
                                             graph_ptr->vertex_count * sizeof(vertex *));
    if (graph_ptr->vertices == NULL)
    {
        printf("Error expanding vertex array\n");
        exit(1);
    }

    graph_ptr->vertices[graph_ptr->vertex_count - 1] = vertex_ptr;
}

// Function to add an edge to the graph (undirected)
void add_edge_to_graph(graph *graph_ptr, vertex *source, vertex *target)
{
    // Create a new edge
    edge *new_edge = create_edge(source, target);

    // Add the edge to the graph
    graph_ptr->edge_count++;
    graph_ptr->edges = (edge **)realloc(graph_ptr->edges,
                                        graph_ptr->edge_count * sizeof(edge *));
    if (graph_ptr->edges == NULL)
    {
        printf("Error expanding graph edge array\n");
        exit(1);
    }

    graph_ptr->edges[graph_ptr->edge_count - 1] = new_edge;

    // Add the edge to the source vertex
    source->edge_count++;
    source->edges = (edge **)realloc(source->edges,
                                     source->edge_count * sizeof(edge *));
    if (source->edges == NULL)
    {
        printf("Error expanding vertex edge array\n");
        exit(1);
    }

    source->edges[source->edge_count - 1] = new_edge;

    // Add the edge to the target vertex (since the graph is undirected)
    target->edge_count++;
    target->edges = (edge **)realloc(target->edges,
                                     target->edge_count * sizeof(edge *));
    if (target->edges == NULL)
    {
        printf("Error expanding vertex edge array\n");
        exit(1);
    }

    target->edges[target->edge_count - 1] = new_edge;
}

// Function to print vertex information
void print_vertex(vertex *vertex_ptr)
{
    printf("Vertex with data %d has %d edges\n",
           vertex_ptr->data, vertex_ptr->edge_count);

    for (int i = 0; i < vertex_ptr->edge_count; i++)
    {
        vertex *neighbor = (vertex_ptr->edges[i]->source == vertex_ptr) ? vertex_ptr->edges[i]->target : vertex_ptr->edges[i]->source;

        printf("  Connected to vertex with data %d\n", neighbor->data);
    }
}

// Function to print graph information
void print_graph(graph *graph_ptr)
{
    printf("Graph contains %d vertices and %d edges\n",
           graph_ptr->vertex_count, graph_ptr->edge_count);

    printf("\nVertex information:\n");
    for (int i = 0; i < graph_ptr->vertex_count; i++)
    {
        print_vertex(graph_ptr->vertices[i]);
    }

    printf("\nList of all edges:\n");
    for (int i = 0; i < graph_ptr->edge_count; i++)
    {
        printf("Edge %d: %d -> %d\n", i + 1,
               graph_ptr->edges[i]->source->data,
               graph_ptr->edges[i]->target->data);
    }
}

// Function to free the graph memory
void free_graph(graph *graph_ptr)
{
    if (graph_ptr == NULL)
    {
        return;
    }

    // Free all vertices
    for (int i = 0; i < graph_ptr->vertex_count; i++)
    {
        free(graph_ptr->vertices[i]->edges);
        free(graph_ptr->vertices[i]);
    }

    // Free all edges
    for (int i = 0; i < graph_ptr->edge_count; i++)
    {
        free(graph_ptr->edges[i]);
    }

    free(graph_ptr->vertices);
    free(graph_ptr->edges);
    free(graph_ptr);
}

// DFS (Depth-First Search) traversal
void dfs(graph *graph_ptr, vertex *start_vertex)
{
    // create 'visited'
    // dfs_rec(graph_ptr, current_vertex, visited)
}

void dfs_rec(graph *graph_ptr, vertex *current_vertex, vertex** visited) {

    // visit - print
    // for each neighbour vertex dfs_rec(graph_ptr, neighbour_vertex, visited)
}

bool contain(vertex **array, int size, vertex *target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return true;
        }
    }
    return false;
}
// BFS (Breadth-First Search) traversal
void bfs(graph *graph_ptr, vertex *start_vertex)
{
    vertex **queue = malloc(sizeof(vertex *) * graph_ptr->vertex_count);
    int bottom_of_queue = 1;
    int head_of_queue = 0;
    queue[head_of_queue] = start_vertex;

    while (head_of_queue != bottom_of_queue)
    {
        vertex *current_vertex = queue[head_of_queue];
        printf("%d\n", current_vertex->data);
        
        for (int i = 0; i < current_vertex->edge_count; i++)
        {
            if (!contain(queue, graph_ptr->vertex_count, current_vertex->edges[i]->target))
            {
                queue[bottom_of_queue] = current_vertex->edges[i]->target;
                bottom_of_queue++;
            }
            if (!contain(queue, graph_ptr->vertex_count, current_vertex->edges[i]->source))
            {
                queue[bottom_of_queue] = current_vertex->edges[i]->source;
                bottom_of_queue++;
            }
        }
        head_of_queue++;
        if (head_of_queue == 10) return;
    }

}


// Example usage
int main()
{
    // Create a graph
    graph *my_graph = create_graph();

    // Create vertices
    vertex *v1 = create_vertex(1);
    vertex *v2 = create_vertex(2);
    vertex *v3 = create_vertex(3);
    vertex *v4 = create_vertex(4);
    vertex *v5 = create_vertex(5);
    vertex *v6 = create_vertex(6);
    vertex *v7 = create_vertex(7);

    // Add vertices to the graph
    add_vertex_to_graph(my_graph, v1);
    add_vertex_to_graph(my_graph, v2);
    add_vertex_to_graph(my_graph, v3);
    add_vertex_to_graph(my_graph, v4);
    add_vertex_to_graph(my_graph, v5);
    add_vertex_to_graph(my_graph, v6);
    add_vertex_to_graph(my_graph, v7);

    // Add edges between vertices
    add_edge_to_graph(my_graph, v1, v2); // 1 -- 2
    add_edge_to_graph(my_graph, v1, v4); // 1 -- 4
    add_edge_to_graph(my_graph, v2, v3); // 2 -- 3
    add_edge_to_graph(my_graph, v2, v4); // 2 -- 4
    add_edge_to_graph(my_graph, v2, v5); // 2 -- 5
    add_edge_to_graph(my_graph, v3, v5); // 3 -- 5
    add_edge_to_graph(my_graph, v4, v6); // 4 -- 6
    add_edge_to_graph(my_graph, v5, v6); // 5 -- 6

    // Vertex 7 remains isolated

    printf("Graph structure:\n");
    printf("---------------\n");

    // Print graph information
    print_graph(my_graph);

    // Analyze vertex degrees
    printf("\nVertex degree analysis:\n");
    printf("----------------------\n");
    for (int i = 0; i < my_graph->vertex_count; i++)
    {
        vertex *current = my_graph->vertices[i];
        printf("Vertex %d has degree %d\n", current->data, current->edge_count);
    }

    // Check for isolated vertices
    printf("\nIsolated vertices:\n");
    printf("-----------------\n");
    bool has_isolated = false;

    for (int i = 0; i < my_graph->vertex_count; i++)
    {
        vertex *current = my_graph->vertices[i];
        if (current->edge_count == 0)
        {
            printf("Vertex %d is isolated\n", current->data);
            has_isolated = true;
        }
    }

    if (!has_isolated)
    {
        printf("No isolated vertices found\n");
    }

    // Verify adjacency lists
    printf("\nAdjacency list verification:\n");
    printf("--------------------------\n");
    for (int i = 0; i < my_graph->vertex_count; i++)
    {
        vertex *current = my_graph->vertices[i];
        if (current->edge_count > 0)
        {
            printf("Vertex %d neighbors: ", current->data);

            for (int j = 0; j < current->edge_count; j++)
            {
                vertex *neighbor;
                if (current->edges[j]->source == current)
                {
                    neighbor = current->edges[j]->target;
                }
                else
                {
                    neighbor = current->edges[j]->source;
                }
                printf("%d ", neighbor->data);
            }
            printf("\n");
        }
    }

    // Perform graph traversals
    printf("\nGraph traversals:\n");
    printf("----------------\n");
    // dfs(my_graph, v1);
    bfs(my_graph, v1);

    // dfs(my_graph, v2);
    // bfs(my_graph, v2);

    // Free graph memory
    free_graph(my_graph);

    return 0;
}