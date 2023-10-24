#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void deleteNode(struct Graph* graph, int data) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* curr = graph->adjList[i];
        struct Node* prev = NULL;

        while (curr != NULL) {
            if (curr->data == data) {
                if (prev == NULL) {
                    graph->adjList[i] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("Adjacency list of vertex %d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V, choice, src, dest, data;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Add Edge\n");
        printf("2. Delete Node\n");
        printf("3. Print Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices for the edge: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter the node to delete: ");
                scanf("%d", &data);
                deleteNode(graph, data);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
