#ifndef VIEW_H
#define VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    FILE *fptr_mp3;
    char *mp3_fname;
} ViewInfo;

int view(char *argv[]);
int open_file(ViewInfo *viewInfo);
int view_tag(ViewInfo *viewInfo);

#endif