#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>

#define FILE_DIR "/tmp/test.txt"

int main(void)
{

/* test semihost call: open, read, close */

    FILE *fd;
    unsigned char buff[100];
    char str[20] = "Hello World!!!";
    fd = fopen(FILE_DIR, "w");
    if(fd == NULL){
        printf("error\n\r");
        return 0;
    }//End of if

    printf("the string \"%s\" is write into file: %s\n\r",str,FILE_DIR );
    fprintf(fd, "%s", &str);
    fclose(fd);

    fd = fopen(FILE_DIR, "r");
    if(fd == NULL){
        printf("error\n\r");
        return 0;
    }
    fread(buff, sizeof(buff),1,fd);
    printf("\"%s\" is read from: %s\n\r", buff, FILE_DIR);
    fclose(fd);
    
    return 0;
}
