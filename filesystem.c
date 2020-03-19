#include <stdlib.h>
#include <stdio.h>
#include  <string.h>

typedef struct fileblock{
  char buffer[512];
}Fileblock;

typedef struct fatblock{
  int status;
  int block_number;
  Fileblock* file_buffer;
}FATBlock;

typedef struct directoryblock{
  char filename[20];
  int start_block;
}Directoryblock;

int main(){
   int starting_index;
   char *p,*p2,*p3;
   char find_file[20];
   Fileblock chunck,chunck2,chunck3;
   Directoryblock directorytable[]={{"/filefragmentation",1}};
   FATBlock fattable[]={{0,1,&chunck},{0,2,&chunck2},{0,3,&chunck3}};
   int directorey_size=sizeof(directorytable)/sizeof(Directoryblock);
   int fileblock_size=sizeof(fattable)/sizeof(FATBlock);
   printf("enter the required file name");
   scanf("%s",find_file);
   for(int i=0;i<directorey_size;i++){
       if(directorytable[i].filename==find_file);
       starting_index=directorytable[i].start_block;
   }
   strcpy(chunck.buffer,"hello world");
   strcpy(chunck2.buffer," this is ");
   strcpy(chunck3.buffer," my first file fragmentation test");
   for(int i=0;i<fileblock_size;i++){
      printf("%s",fattable[starting_index++].file_buffer->buffer);
   }
             
}


