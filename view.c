#include "view.h"
//read and validate
//open files
//view
//display data
//close files
int view(char *argv[])
{
    ViewInfo viewInfo;

    viewInfo.mp3_fname = argv[2];

    if (open_file(&viewInfo) == 0)
    {
        printf("File opened successfully\n");

        if (view_tag(&viewInfo) == 0)
        {
            printf("View operation successful\n");
        }
        else
        {
            printf("View operation failed\n");
        }

        fclose(viewInfo.fptr_mp3);
    }
    else
    {
        printf("ERROR: File opening failed\n");
        return 1;
    }

    return 0;
}

int open_file(ViewInfo *viewInfo)
{
    viewInfo->fptr_mp3 = fopen(viewInfo->mp3_fname, "rb");

    if (viewInfo->fptr_mp3 == NULL)
    {
        return 1;
    }

    return 0;
}

int view_tag(ViewInfo *viewInfo)
{
    char header[10];
    char tag[5];
    int size;
    char data[100];

    fread(header, 1, 10, viewInfo->fptr_mp3);

    printf("\n----- MP3 TAG DETAILS -----\n");

    while (fread(tag, 1, 4, viewInfo->fptr_mp3) == 4)
    {
        tag[4] = '\0';

        fread(&size, 4, 1, viewInfo->fptr_mp3);

        // Big endian conversion
        size = ((size & 0xFF) << 24) |
               ((size & 0xFF00) << 8) |
               ((size & 0xFF0000) >> 8) |
               ((size >> 24) & 0xFF);

        fseek(viewInfo->fptr_mp3, 2, SEEK_CUR);
        if (size <= 0 || size >= 100)
        {
            break;
        }
        fread(data, 1, size, viewInfo->fptr_mp3);
        data[size] = '\0';
        printf("%s : %s\n", tag, data);
    }

    return 0;
}