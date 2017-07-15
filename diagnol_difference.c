#include <stdio.h>
#include <string.h>
int main()
{
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    printf("%s",*time);
    return 0;
}
