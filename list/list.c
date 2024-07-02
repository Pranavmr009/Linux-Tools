#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"

int main(int argc, char **argv)
{
    struct dirent *de;
    
    DIR *d = opendir(".");

    if(d == NULL)
    {
        printf("Something is wrong");
    }


    while((de = readdir(d)) != NULL)
    {
        if(argc > 1 && (strcmp(argv[1], "-a")) == 0)
        {
            if (de->d_name[0] == '.')
            {
                printf(COLOR_RED "%s\n" COLOR_RESET, de->d_name);
            }

            else 
            {
                printf(COLOR_GREEN "%s\n" COLOR_RESET, de->d_name);
            }
        }

        else 
        {
            if(de->d_name[0] != '.')
            {
                printf(COLOR_GREEN "%s\n" COLOR_RESET, de->d_name);
            }
        }
    }


    closedir(d);

}