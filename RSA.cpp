#include <bits/stdc++.h>
#include <cmath.h>

using namespace std;

int DKey = 0,n=0;

long long int* keyAssign(char *message){
       long long int *msgKey = new long long int[strlen(message)];
        for(int i=0; i < strlen(message) ; i++){
            msgKey[i] = (int) message[i]; 
           // cout << (int) message[i] << endl;
         }
        return msgKey;;
}

int howmanyDigit(long long int msgkey){
   int c= 0;
    while(msgkey > 0){
        msgkey /= 10;
        c++;
    }
    return c;
}


int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
}
int encrypt(long long int *msgKeys, int len){
 
     int p, q;
      cout << "Enter the P and Q : ";
      cin >> p >> q;
     n = p * q;
     int fi = (p-1) * (q-1);
     int e = 2,k=2 ;
     while (e < fi) 
    { 

        if (gcd(e, fi)==1) 
            break; 
        else
            e++; 
    } 
     //cout << "Enter the encryption key : ";
    // cin >> k;
      
     // To find Decryption key
     DKey= ((k * fi) + 1) / e;
       // Msg encrytption ;
      long long int c= msgKeys[0];
     for(int i=1; i < len ; i++){
         int digit = howmanyDigit(msgKeys[i]);
          // cout << digit << endl;
           c = c * (digit==2 ?100:1000);
         c +=  msgKeys[i];
     }
    int msgEncr = pow(c,k);
    msgEncr %= n;
    cout << msgEncr << endl;
    // cout << c << endl;
    return msgEncr;
}

 
void decryption(int msgEncr){
  long long int msgKey = pow(msgEncr , DKey) ;
  msgKey = fmod(msgKey,n);
  cout << msgKey << endl;
}

int main(){
    char message[50];
    cout << "Enter the message : ";
    cin >> message;
   // keyAssign(message);
    long long int *msgKeys = keyAssign(message);
    int msgEncr = encrypt(msgKeys , strlen(message));
    decryption(msgEncr);
    return 0;  
}
