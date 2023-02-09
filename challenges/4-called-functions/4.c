// grab all function calls by code

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int secondMain()
{
    FILE *fp;
    char buffer[100];

    fp = fopen("file.txt", "r");

    fread(buffer, 1, 100, fp);

    printf("%s\n", buffer);

    fclose(fp);

    time_t now = time(NULL);

    long epoch = (long)now;

    printf("Epoch time is %ld\n", epoch);

    for (int i = 0; i < strlen(buffer); i++) {
        buffer[i] = tolower(buffer[i]);
    }

    printf("%s\n", buffer);

    fp = fopen("file.txt", "w");

    fwrite(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), fp);

    fclose(fp);

    return 0;
}

int main() 
{
    return secondMain();
}