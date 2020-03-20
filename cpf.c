#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{

    int input, output, rFile;

    if (argc <= 2)
    {
        exit (2);
    }
    
    char buffer[256];

    output = open(argv[2], O_CREAT | O_APPEND | O_RDWR);
    
    
    input = open(argv[1], O_RDONLY);

    if (input == -1)
    {
        printf("no existant inputfile");
        exit (2);
    }

    while (0 < (rFile = read(input, buffer , sizeof(buffer))))
    {
        write(output, buffer, sizeof(buffer));
    }

    close(input);
    close(output);
}