#include <stdio.h>

int main(int argc,char *argv[]){
    if (argc < 2){
        printf("Usage: An argument of file path is required\n");
        return -1;
    }

    char *filename = argv[1];
    char *line = NULL;
    FILE *fptr;

    fptr = fopen(filename,"r");
    if (fptr == NULL){
        printf("Not able to open this file");
    }

    //while(fgets(contents,0,fptr)){
        //printf("%s",contents);
    //}
    ssize_t linecap = 0;
    ssize_t linelen;


    while((linelen = getline(&line,&linecap,fptr)) != -1){
        while(linelen > 0 && (line[linelen - 1] == '\n' ||
                    line[linelen - 1] = '\r'))
            linelen--;
        realloc(
    }

 //   printf("%s",contents);

    fclose(fptr);
    return 0;
}
