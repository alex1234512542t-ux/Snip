#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include<string.h>
#include "./include/multiDirect.h"

int printDirect(){
    DIR *d;
    struct dirent *dir;
    char path[1000]="/Users/temp/Desktop";
    d = opendir(path);
    char full_path[1000];
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            //Condition to check regular file. [DT_REG] [DT_dir] means directory
                full_path[0]='\0';
                strcat(full_path,path);
                strcat(full_path,"/");
                strcat(full_path,dir->d_name);
                printf("%s\n",full_path);
        }
        closedir(d);
    }
    return(0);     
}
