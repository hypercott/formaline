#include <stdlib.h>
#include <stdio.h>
#define BLANKS  fprintf(outfile,"\n\n");

int main() {

  FILE* outfile;
  int c;
  int i;

  outfile = fopen("formaline.c","w");

  fprintf(outfile,"#include <stdio.h>\n");
  fprintf(outfile,"#include <stdlib.h>\n");
  fprintf(outfile,"#include <sys/stat.h>\n");
  fprintf(outfile,"#include <sys/types.h>\n");
  fprintf(outfile,"#include <string.h>\n");

  BLANKS;

  fprintf(outfile,"void formaline_output(char *outdir) {\n");

  fprintf(outfile,"int mode = 0755;\n");

  fprintf(outfile,"int ignore = 0; //Used to suppress warning in sprintf\n");

  fprintf(outfile,"char stuff[] = {\n\t");

  i=0;

  while ( (c=fgetc(stdin)) != EOF ) {
    
    fprintf(outfile, "%3d, ",c);
    if(++i == 20) {
      fprintf(outfile,"\n\t");
      i = 0;
    }
  }
  fprintf(outfile,"};\n\n");
  
  fprintf(outfile,"FILE *outfile;\n");

  BLANKS;

  // strcat doesn't like dealing with static arrays. 
  // Make a copy first and fix fortran string length
  fprintf(outfile,"char copy[strlen(outdir)];\n");

  BLANKS;

  fprintf(outfile,"sprintf(copy,outdir,ignore);\n");

  BLANKS;

  fprintf(outfile,"mkdir(strcat(copy,\"/src\"),mode);\n");

  BLANKS;

  fprintf(outfile,"outfile=fopen(strcat(copy,\"/src.tar.gz\"),\"w\");\n");

  BLANKS;

  fprintf(outfile,"fwrite(stuff,1,sizeof(stuff),outfile);\n");

  BLANKS;

  fprintf(outfile,"fclose(outfile);\n");

  BLANKS;

  fprintf(outfile,"}\n");

  BLANKS;

  fprintf(outfile,"void formaline_output_(char *outdir) {\n");
  fprintf(outfile,"\t formaline_output(outdir);\n");
  fprintf(outfile,"}\n");
  
  BLANKS;

  fclose(outfile);

  return 0;

}
