#include <stdlib.h>

#define MAXLEN 255
#define CHUNKSIZE 80

typedef struct
// string stack
{
    char ch[MAXLEN + 1];
    int length;
} sString;

typedef struct
// string piece
{
    char *ch;
    int length;
} hString;

typedef struct Chunk
// string link
{
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;
typedef struct
{
    Chunk *head, *tail;
    int length;
} lString;
