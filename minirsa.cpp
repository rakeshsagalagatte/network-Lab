#include <bits/stdc++.h>


using namespace std;

double DKey = 0,n=0;

double* keyAssign(char *message){
       double *msgKey = new double[strlen(message)];
        for(int i=0; i < strlen(message) ; i++){
            msgKey[i] = message[i] - 96; 
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
double encrypt(double *msgKeys, int len){
 
     double p, q;
      cout << "Enter the P and Q : ";
      cin >> p >> q;
     n = p * q;
     double fi = (p-1) * (q-1);
     double e = 2,k=2 ;
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
      double c= msgKeys[0];
     for(int i=1; i < len ; i++){
         int digit = howmanyDigit(msgKeys[i]);
          // cout << digit << endl;
           c = c * (digit==1 ? 10 : digit== 2 ? 100:1000);
           cout << digit << endl;
         c +=  msgKeys[i];
     }
    int msgEncr = pow(c,k);
    msgEncr = fmod(msgEncr, n);
    cout << msgEncr << endl;
    // cout << c << endl;
    return msgEncr;
}

 
void decryption(int msgEncr){
  double msgKey = pow(msgEncr , DKey) ;
  msgKey = fmod(msgKey,n);
  cout << msgKey << endl;
}

int main(){
    char message[50];
    cout << "Enter the message : ";
    cin >> message;
   // keyAssign(message);
    double *msgKeys = keyAssign(message);
    double  msgEncr = encrypt(msgKeys , strlen(message));
    decryption(msgEncr);
    return 0;  
}
