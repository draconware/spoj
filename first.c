#include<stdio.h>
#include<stdlib.h>

struct folder{

int id;

struct folder subfolder;

};

int main()

{

struct folder f;

f.id = 10;

printf("%d ", f.id+20);

return 0;

}
