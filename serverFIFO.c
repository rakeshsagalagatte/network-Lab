#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include <sys/types.h>

int main(){
   char fname[50], buffer[1025];
   int req, res,n,file;
   mkfifo("req.fifo", 0777);
   mkfifo("res.fifo", 0777);
   printf("server ready for connection.\n");
   req = open("req.fifo" , O_RDONLY);
   res = open("res.fifo" , O_WRONLY);
   printf("Connection established \n"); 
   read(req, fname , sizeof(fname));
   printf("Entered filename is %s \n", fname);
   file = open(fname , O_RDONLY);
   if(file < 0){
     write(res, "file not found", 14);
   } else{
          while((n = read(file, buffer , sizeof(buffer))) > 0){
             write(res, buffer , n);
          }
   }
   close(req);
   close(res);

   unlink("req.fifo");
   unlink("res.fifo");
   return 0;
}
