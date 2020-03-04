#include <stdio.h>

void uplodFile(char path[],char distenation[]){
	FILE* fileptr = fopen(path,"rb");
        FILE* fileptr2 = fopen(distenation,"wb");
        int filesize;
        fseek(fileptr,0,SEEK_END);
        filesize = ftell(fileptr);
        int buffer[filesize];
	int size;
        size = sizeof(buffer)/sizeof(buffer[0]);
        fseek(fileptr, 0, SEEK_SET);
        fread(buffer,sizeof(int),size,fileptr);
	printf("buffer=%d",buffer);
        printf("size of buffer=%d\n",sizeof(buffer));
	printf("size of buffer array=%d\n",size);
        fwrite(buffer,sizeof(int),size,fileptr2);
	fclose(fileptr);
	fclose(fileptr2);
			
}

int main(){
   uplodFile("C:\\Users\\karam\\Desktop\\cool2.jpg","C:\\Users\\karam\\Desktop\\hello2.jpg");
   return 0;
}