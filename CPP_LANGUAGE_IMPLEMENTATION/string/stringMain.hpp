#include <stdlib.h>

#define MAXLEN 255
#define CHUNKSIZE 80

// string stack
typedef struct{
    char ch[MAXLEN+1];
    int length;
}sString;

// string piece
typedef struct{
    char *ch;
    int length;
}hString;

// string link
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;
typedef struct{
    Chunk *head, *tail;
    int length;
}lString;

