#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *test(char *me)
{
    char *testme;
    testme = "hello";
    testme = me;
    return testme;
}

int main(){
    // test("hi");
    // printf("%s",test("hellomuhaiuhdia"));
    char* fileName = "hello.txt";
    char* fileNamee = "goodbye.txt";

    int fd = open(fileName, O_RDWR);
    int fdd = open(fileNamee,  vWR);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }

    char buffer[11];

    int bytesRead = read(fd, buffer, 1);
    bytesRead += read(fdd, buffer, 1);
    bytesRead += read(fd, buffer, 1);

    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);

    return 0;
}