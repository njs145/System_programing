#include "open.h"

static int write_file(void)
{
    int fd;

    if(!(fd = open("file_data", O_CREAT | O_WRONLY, 0777)))
    {
        printf("file open err\n");
    }

    dprintf(fd, "file open %d", 123);

    close(fd);
}

static int trunc_file(void)
{
    int fd;

    if(!(fd = open("file_data", O_CREAT | O_WRONLY | O_TRUNC, 0777)))
    {
        printf("file open err\n");
    }

    dprintf(fd, "file trunc %d", 456);

    close(fd);
}

static int append_file(void)
{
    int fd;

    if(!(fd = open("file_data", O_WRONLY | O_APPEND, 0777)))
    {
        printf("file append err\n");
    }

    dprintf(fd, "file append %d", 789);

    close(fd);
}

int open_main(void)
{
    int err;
    err = write_file();
    
    err = trunc_file();

    err = append_file();
    return err;
}