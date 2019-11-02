#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * readline(FILE *fp, char *buffer)
{
    int ch;
    int i = 0;
    size_t buff_len = 0;

    buffer = malloc(buff_len + 1);
    if (!buffer) return NULL;  // Out of memory

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
    {
        buff_len++;
        void *tmp = realloc(buffer, buff_len + 1);
        if (tmp == NULL)
        {
            free(buffer);
            return NULL; // Out of memory
        }
        buffer = tmp;

        buffer[i] = (char) ch;
        i++;
    }
    buffer[i] = '\0';

    // Detect end
    if (ch == EOF && (i == 0 || ferror(fp)))
    {
        free(buffer);
        return NULL;
    }
    return buffer;
}

void lineByline(FILE * file){
char *s;
while ((s = readline(file, 0)) != NULL)
{
    puts(s);
    free(s);
    // printf("\n");
}
}

int main()
{
    char *fileName = "biju.c";
    FILE* file = fopen(fileName, "r");
    lineByline(file);
    return 0;
}