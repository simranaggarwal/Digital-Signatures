#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
long long int allprime[50];
long long int p,q,n,e,d, phi;
long long int gcd(long long int a,long long int b);
long long int modinv(long long int e);
void keys();
void SieveOfEratosthenes();
long long int modexp(long long int x, long long int y);
long long int retd();
long long int rete();
long long int retn();
#endif
