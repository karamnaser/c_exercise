#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* getMemoryAddres(){
	char* memoryaddres= (char*) malloc(6*sizeof(char));
	int number;
	char buffer[15]={'1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	for(int i=2;i<6;i++){
		number=(rand()%15);
		memoryaddres[i]=buffer[number];
		}
	return memoryaddres;
}

int main(){
   char* hex=getMemoryAddres();
   unsigned char* numberptr;
   int number=50;
   char buffer[6];
   hex[0]='0';
   hex[1]='x';
   for(int i=0;i<6;i++){
       buffer[i]=*(hex+i);
   }
   numberptr=buffer;
   *numberptr=number;
   printf("buffer=%s",buffer);
   printf("numberptr=%s",numberptr);
   printf("numberptr=%d",*numberptr);	
   free(hex);
   return 0;
}