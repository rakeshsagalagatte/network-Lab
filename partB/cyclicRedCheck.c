#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void divisionM(char *padded, const char *gen){
    int i=0,j=0,k=0,a=0,p=0;
    for(i=0;i < strlen(padded) && (strlen(padded) - i ) >= strlen(gen) ; i++){
	j=i;
	while(padded[j] == 0){
	   j++;
	}
	i=j;
       for(k=0;k < strlen(gen) ; k++,j++){
       	   if( padded[j] == gen[k]){
		   padded[j] = '0';
		   if(p == 0)
		      a += 1;
	   }else{ 
		   p = 1;
		   padded[j] = '1';
	   }
       } 
       i = i + a -1;
       a=0;
       p=0;
    } 
}

char * getRemainder(const char *message, const char *generator){
     int msgLen = strlen(message) , genLen = strlen(generator);
     char *messagePadding = (char *) malloc( (msgLen + genLen - 1) * sizeof(char));
     memset(messagePadding, '0' , msgLen + genLen - 1);
     strcpy(messagePadding , message);
     messagePadding[msgLen] = '0';
     divisionM(messagePadding , generator);
     return messagePadding;
}

char * check_message(const char * message, const char *gen, const char *rem){
     int msgLen= strlen(message) , genLen = strlen(gen);
     char *padding = (char *)malloc((msgLen + genLen - 1) * sizeof(char));
     strcpy(padding , message);
     int i=0;
     for(i=0;i< strlen(rem) ;i++)
	     padding[msgLen + i] = rem[i];
     divisionM(padding,gen);
     return padding;
}

int main(){
   char message[1024],transmissionMSG[1024]; // = "11010111111100";
   char generator[1024]; // = "1011";
   printf("Enter the message (only 0's and 1's) : ");
   scanf("%s",message);
   printf("Enter the generator (only 0's and 1's) : ");
   scanf("%s", generator);
   printf("Enter the transmission message (same as original msg) : ");
  scanf("%s",transmissionMSG); 
   char *remainder = getRemainder(message,generator);   // remainder bits start from  number of generator bits + 1  
   char *check = check_message(transmissionMSG, generator ,  remainder + (strlen(remainder) - strlen(generator) + 1));  // If all are 0's no error.
   int i=0;
   for(i=0;i < strlen(check) ; i++){
      if(check[i] != '0'){
         printf("Error detected ....!\n");
	 free(remainder);
	 free(check);
	 return 0;
      }
   }
   free(remainder);
   free(check);
   printf("No error in the bits.\n", check);
   return 0;
}
