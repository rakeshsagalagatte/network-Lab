#include<bits/stdc++.h>

using namespace std;

long int gcd(long int a , long int b){
    if (a ==0){
       return b;
    }
    if(b==0)
	    return a;
    return gcd(b,a%b);
}

int isPrime(long int a){
     for(long int i=0; i < pow(a,1/2);i++){
        if(a%i == 0)
		return 0;
     }
     return 1;
}

long int encrypt(char ch, long int n, long int e){

    long int temp = ch;
    for(int i =0; i < e ; i++){
       temp = (temp * ch) % n;
    }
    return temp;
}

char decrypt(long int ch, long int n, long int d){

    long int temp = ch;
    for(int i=0; i < d ; i++){
        temp = (temp * ch) % n;
    }
    return temp;
}

int main(){

    long int p,e,q,n,d,phi,cipher[50];
    char text[50];
    cout << "Enter the message : ";
    cin.getline(text, sizeof(text));
    do{
        p = rand() % 30;
    }while(! isPrime(p));
    do{
        q = rand()%30;
    }while(! isPrime(q));

    n = p * q;
    phi = (p-1) * (q-1);
    do{
       e = rand()%phi;
    }while(gcd(phi,e) != 1);
    do{
       d = rand()%phi;
    }while(((d * e)%phi) != 1);

    cout << "Encryption " << endl;
    int len = strlen(text);
    for(int i=0;i < len;i++){
       cipher[i] = encrypt(text[i],n,e);
    }
    cout << "cipher : " << cipher << endl;
    for(int i=0; i < len;i++){
        text[i] = decrypt(cipher[i], n , d);
    }
    cout << "Text : " << text << endl;
    return 0;
}
