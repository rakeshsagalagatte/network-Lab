#include <bits/stdc++.h>

using namespace std;


char* get_remainder(const char* dividend,const char* divisor){ // performs binary division and returns the result
  int d_pos=0,dividend_length=strlen(dividend),divisor_length=strlen(divisor);
  char* div=(char*)malloc(sizeof(char)*(dividend_length+1));
  strcpy(div,dividend);
  int lpos=0,rlim=dividend_length-divisor_length,i;
  while(lpos<=rlim){
    for(i=lpos;i<lpos+divisor_length;i++)
      div[i]=div[i]==divisor[i-lpos]?'0':'1'; //XOR operation
    for(i=lpos+1;i<dividend_length;i++){
      if(div[i]=='1'){
	lpos=i;
	break;
      }
    }
    if(i==dividend_length)
      break;
  }
  char* remainder=malloc(sizeof(char)*divisor_length);
  strncpy(remainder,div+dividend_length-divisor_length+1,divisor_length-1);
  remainder[divisor_length-1]='\0';
  free(div);
  return remainder;
}
char* generate_message(const char* bitstring,const char* generator){ 
  int g=strlen(generator),b=strlen(bitstring);
  char* padded_bitstring=(char*)malloc((g+b)*sizeof(char));//1 extra character space for null character
  memset(padded_bitstring,'0',g+b);
  strncpy(padded_bitstring,bitstring,b);
  padded_bitstring[g+b-1]='\0';
  char* remainder=get_remainder(padded_bitstring,generator);
  printf("\nOriginal Message: %s\nCodeword to be appended: %s\n",bitstring,remainder);
  strncpy(padded_bitstring+b,remainder,g-1);
  return padded_bitstring;
}
char* check_message(char* message,char* generator){
  char* remainder=get_remainder(message,generator);
  int error=0,i;
  for(i=0;i<strlen(remainder);i++){
    if(remainder[i]=='1'){
      error=1;
      break;
    }
  }
  char* status=(char*)malloc(sizeof(char)*(strlen(message)*2+15));
  sprintf(status,"Remainder: %s %s",remainder,error?"Error Detected!":"No Error Detected!");
  return status;
}
int main(){
  char* bs="10111011000101101011"; //message to be encoded
  char* gen="1010101"; //generator
  char* message=generate_message(bs,gen);
  printf("Message: %s\n",message);
  printf("Result of checking: %s\n",check_message(message,gen));
  return 0;
}
