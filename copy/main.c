#include <stdio.h>

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("Not enough arguments");
        return 1;
    }

    FILE *f =  fopen(argv[1], "r");

    if(f == NULL)
    {
        perror("Error Message: ");
        return 1;
    }

    

    FILE *f2 = fopen(argv[2], "w");

    if(f2 == NULL)
    {
        perror("Error Message: ");
        return 1;
    }

    char buffer[1024] = {0};
    size_t bufferRead;

    // fread(buffer, 1, sizeof(buffer), f);
    FILE *f3 = fopen("myfile.txt", "w");
    // printf("%zu bytes read", bufferRead);
    printf("%s", buffer);
    fwrite(buffer, 1, 1024, f3);
    
    while((bufferRead = fread(buffer, 1, sizeof(buffer), f)) > 0)
    {
        fwrite(buffer, 1, bufferRead, f2);
    }

    fclose(f);
    fclose(f2);
}