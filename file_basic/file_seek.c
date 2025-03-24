#include "file_seek.h"

static int create_file(void)
{
    FILE *fp;

    if(!(fp = fopen("datafile", "w")))
    {   
        perror("fopen fail");
        return -1;
    }

    printf("afer fopen(). offset=%ld\n", ftell(fp));
    fputs("hello world!\n", fp);
    fputs("hello world!!\n", fp);
    fputs("hello world!!!\n", fp);
    fputs("hello world!!!!\n", fp);
    printf("before fclose(). offset=%ld\n", ftell(fp));
    printf("------------------------------------------");

    fclose(fp);
    return 0;
}

static int read_file(void)
{
    FILE *fp;
    char buf[256];

    if(!(fp = fopen("datafile", "r+")))
    {   
        perror("fopen fail");
        return -1;
    }

    printf("afer fopen(). offset=%ld\n", ftell(fp));
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), fp);
    printf("after fgets(). offset=%ld\n", ftell(fp));

    fseek(fp, 0, SEEK_END);
    printf("atfer fseek(). offset=%ld\n", ftell(fp));
    fputs("final\n", fp);
    printf("before close(). offset=%ld\n", ftell(fp));
    printf("------------------------------------------");

    fclose(fp);
    return 0;
}

int file_seek_main(void)
{
    int err;

    err = create_file();
    err = read_file();
    return err;
}