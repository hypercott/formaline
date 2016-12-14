#include <stdio.h>

// declare formaline output function
void formaline_output(char *outdir);

int main()
{
    printf("This is a Formaline test.\n");
    // call the Formaline output function
    formaline_output("./");
}
