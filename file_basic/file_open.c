#include "file_open.h"

#define PUT_GET     0
#define WRITE_READ  1
#define OPEN_TYPE   WRITE_READ

static int fput_to_file(void)
{
    FILE *fp;
    char buf[256];
    fp = fopen("data", "w");
    if(fp == NULL)
    {
        perror("fopen error\n");
        return -1;
    }

    fputs("hello world..", fp);

    fclose(fp);

    return 0;
}

static int fget_to_file(void)
{
    FILE *fp;
    char buf[256];

    fp = fopen("data", "r");
    if(fp == NULL)
    {
        perror("fopen error\n");
        return -1;
    }

    memset(buf, 0, sizeof(buf));

    fgets(buf, sizeof(buf), fp);

    printf("%s\n", buf);
    fclose(fp);

    return 0;
}

static int fwrite_to_file(void)
{
    int err = 0;
    FILE *fp = NULL;
    user_info_t KIM_info = {
        .name = "KIM",
        .age = 20
    };

    user_info_t NAM_info = {
        .name = "NAM",
        .age = 21
    };

    if(!(fp = fopen("user_info", "w")))
    {
        printf("file open fail[%s, %d]\n",__func__, __LINE__);
        err = -1;
    }
    
    if(!(fwrite(&KIM_info, sizeof(user_info_t), 1, fp)))
    {
        printf("fwrite error! [%s, %d]",__func__, __LINE__);
        err = -1;
    }

    if(!(fwrite(&NAM_info, sizeof(user_info_t), 1, fp)))
    {
        printf("fwrite error! [%s, %d]",__func__, __LINE__);
        err = -1;
    }

    fclose(fp);
    return err;
}

static int fread_to_file(void)
{
    int err = 0;
    FILE *fp = NULL;
    user_info_t user_info[2];

    if(!(fp = fopen("user_info", "r")))
    {
        printf("file open fail[%s, %d]\n",__func__, __LINE__);
        err = -1;
    }

    if(!(fread(&user_info, sizeof(user_info_t), 2, fp)))
    {
        printf("file read fail[%s, %d]\n",__func__, __LINE__);
        err = -1;
    }

    printf("name: %s, age = %d\n",user_info[0].name, user_info[0].age);
    printf("name: %s, age = %d\n",user_info[1].name, user_info[1].age);

    fclose(fp);
    return err;
}

int file_open_main(void)
{
    int err = 0;
    #if(OPEN_TYPE == PUT_GET)
    if(fput_to_file())
    {
        perror("write to file\n");
        err = -1;
    }
    if(fget_to_file())
    {
        perror("read to file\n");
        err = -1;
    }    
    #else
    if(fwrite_to_file())
    {
        perror("write to file\n");
        err = -1;
    }
    if(fread_to_file())
    {
        perror("read to file\n");
        err = -1;
    }
    #endif

    return err;
}