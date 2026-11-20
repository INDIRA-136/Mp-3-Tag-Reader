#include "view.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("ERROR: ./a.out -v file.mp3\n");
        return 1;
    }

    if (strcmp(argv[1], "-v") == 0)
    {
        view(argv);
    }
    else
    {
        printf("Invalid option\n");
    }

    return 0;
}