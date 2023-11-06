#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
#include <string.h>

struct ConnectedComponentsData {
  int numberOfComponents;
  int componentArray[][];
};

struct ConnectedComponentsData findConnectedComponents(int graph[][]) {
    struct ConnectedComponentsData newData;
    
}

int main(char *argc, char* argv[]) {

    char x[99];
    char y[99];

    FILE *file;
    char* file_name = argv[1];
    // printf("%lu\n", sizeof(file_name)/sizeof(char));
    for (int i = 0; i < sizeof(file_name)/sizeof(char); i++) {
        // printf("%c", file_name[i]);
    }
    // printf("\n");
    file = fopen(argv[1], "r");

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