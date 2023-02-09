#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("hello world!\n");
    }
    else
    {
        char buffer[100];
        memcpy(buffer, argv[1], 99);
        printf("hello %s!\n", buffer);
    }

    return 0;
}