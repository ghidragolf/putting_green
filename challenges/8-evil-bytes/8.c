// find particular bytes in program

#include <stdio.h>
#include <string.h>

int file_open(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp != NULL) {
        printf("\nFile opened successfully\n");
        fclose(fp);
    } else {
        printf("\nError opening file\n");
    }
    return 0;
}

int file_create(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp != NULL) {
        printf("\nFile created successfully\n");
        fclose(fp);
    } else {
        printf("\nError creating file\n");
    }
    return 0;
}

int file_read(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp != NULL) {
        char c;
        printf("\nFile contents:\n");
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }
        fclose(fp);
    } else {
        printf("\nError reading file\n");
    }
    return 0;
}

int file_write(char *filename)
{
    FILE *fp;
    char evil[] = "evil";
    fp = fopen(filename, "w");
    if (fp != NULL) {
        printf("\nEnter the text to be written to the file: \n");
        char c;
        while ((c = getchar()) != EOF) {
            fputc(c, fp);
            for (int i = 0; i < 4; i++)
            {
                fputc((int)evil[i], fp);
            }
        }
        fclose(fp);
    } else {
        printf("\nError writing to file\n");
    }
    return 0;
}

int file_delete(char *filename)
{
    int status;
    status = remove(filename);
    if (status == 0) {
        printf("\nFile deleted successfully\n");
    } else {
        printf("\nError deleting file\n");
    }
    return 0;
}

int file_rename(char *filename, char *newfilename)
{
    int status;
    status = rename(filename, newfilename);
    if (status == 0) {
        printf("\nFile renamed successfully\n");
    } else {
        printf("\nError renaming file\n");
    }
    return 0;
}

int file_copy(char *filename, char *newfilename)
{
    FILE *fp1, *fp2;
    fp1 = fopen(filename, "r");
    fp2 = fopen(newfilename, "w");
    if (fp1 != NULL && fp2 != NULL) {
        char c;
        while ((c = fgetc(fp1)) != EOF) {
            fputc(c, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        printf("\nFile copied successfully\n");
    } else {
        printf("\nError copying file\n");
    }
    return 0;
}

int file_move(char *filename, char *newfilename)
{
    int status;
    status = rename(filename, newfilename);
    if (status == 0) {
        printf("\nFile moved successfully\n");
    } else {
        printf("\nError moving file\n");
    }
    return 0;
}

int main()
{
    int choice;
    char filename[100], newfilename[100];
    
    printf("Choose an option:\n");
    printf("1. Open a file\n");
    printf("2. Create a file\n");
    printf("3. Read from a file\n");
    printf("4. Write to a file\n");
    printf("5. Delete a file\n");
    printf("6. Rename a file\n");
    printf("7. Copy a file\n");
    printf("8. Move a file\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            file_open(filename);
            break;
        case 2:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            file_create(filename);
            break;
        case 3:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            file_read(filename);
            break;
        case 4:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            file_write(filename);
            break;
        case 5:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            file_delete(filename);
            break;
        case 6:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            printf("\nEnter the new file name: ");
            scanf("%s", newfilename);
            file_rename(filename, newfilename);
            break;
        case 7:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            printf("\nEnter the new file name: ");
            scanf("%s", newfilename);
            file_copy(filename, newfilename);
            break;
        case 8:
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            printf("\nEnter the new file name: ");
            scanf("%s", newfilename);
            file_move(filename, newfilename);
            break;
        default:
            printf("\nInvalid option chosen\n");
    }

    return 0;
}
