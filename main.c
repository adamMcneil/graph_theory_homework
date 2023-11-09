#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#include <string.h>

int static WHITE = 0;
int static GRAY = 1;
int static BLACK = 2;
int time = 0;

struct Edge {
    int source;
    int destination;
    int weight;
};

struct ConnectedComponentsData {
  int numberOfComponents;
  int componentArray[][];
};

struct Digraph {
    int numberOfNodes;
    int numberOfEdges;
    int** graph;
};

struct Digraph* digraphBuilder(int numberOfNodes, int numberOfEdges) {
    struct Digraph* digraph = (struct Digraph*)malloc(sizeof(struct Digraph));
    digraph->numberOfNodes = numberOfNodes;
    digraph->numberOfEdges = numberOfEdges;
    digraph->graph = malloc(sizeof(int) * numberOfNodes * numberOfNodes);
    return digraph;
}

struct DepthData {
    int* discoveryTime;
    int* finishTime;
    int* predecessors;
};

struct DepthData* depthDataBuilder(int numberOfNodes) {
    struct DepthData* depthData = (struct DepthData*)malloc(sizeof(struct DepthData));
    depthData->discoveryTime = malloc(sizeof(int) * numberOfNodes);
    depthData->finishTime = malloc(sizeof(int) * numberOfNodes);

}

struct DepthData* depthSearch(struct Digraph* digraph) {
    int* colorArray[digraph->numberOfNodes];
    struct DepthData* depthData = depthDataBuilder(digraph->numberOfNodes);
    for (int i = 0; i < digraph->numberOfNodes; i++) {
        colorArray[i] = WHITE;
        depthData->predecessors[i] = NULL;
    }

    time = 0;
    for (int i = 0; i < digraph->numberOfNodes; i++) {
        if (colorArray[i] == WHITE) {
            depthSearchVisit(digraph, i, depthData, colorArray);    
        }
    }
    return depthData;
}

void depthSearchVisit(struct Digraph* digraph, int i, struct DepthData* depthData, int* colorArray) {
    time++;
    depthData->discoveryTime[i] = time;
    colorArray[i] = GRAY;
    for (int j = 0; j < digraph->numberOfNodes; j++) {
        if (digraph->graph[i][j] != 0 && colorArray[j] == WHITE) {
            depthData->predecessors[j] = i;
            depthSearchVisit(digraph, j, depthData, colorArray);
        } 
    }
    colorArray[i] = BLACK;
    time++;
    depthData->finishTime[i] = time;
}

struct Digraph* readInputFile(char* fileName) {
    int numberOfNodes;
    int numberOfEdges;
    
    FILE *file;
    file = fopen(fileName, "r");
    fscanf(file, "(%d, %d)", numberOfNodes, numberOfEdges);
    struct Digraph* digraph = digraphBuilder(numberOfNodes, numberOfEdges);
    for (int i = 0; i < numberOfNodes; i++) {
        for (int  j = 0; j < numberOfNodes; j++) {
            fscanf(file, "%d", digraph->graph[i][j]);
        }
    }
    return digraph;
}

struct ConnectedComponentsData findConnectedComponents(struct Digraph* graph) {
    struct ConnectedComponentsData* newData;

}

// void dijkstraArray(struct Digraph* digraph) {
//     int* 
// }



int main(char *argc, char* argv[]) {

    char x[99];
    char y[99];

    char* file_name = argv[1];
    // printf("%lu\n", sizeof(file_name)/sizeof(char));
    for (int i = 0; i < sizeof(file_name)/sizeof(char); i++) {
        // printf("%c", file_name[i]);
    }
    // printf("\n");

    fscanf(file, "%s", x);
    int x_length = strlen(x);
    // printf("%u\n", x_length);
    fscanf(file, "%s", y);
    int y_length = strlen(y);
    // printf("%u\n", y_length);

    // fclose(file);


    FILE *fp;
    fp = fopen(argv[2], "w+");


    char* answer = longest_common_subsequence(y, y_length, x, x_length);
    int answer_length = strlen(answer);
    fprintf(fp, "%u\n", answer_length);
    for (int i = 0; i < answer_length; i++)
    {
        fprintf(fp, "%c", answer[i]);
    }
    
    return 0;
}