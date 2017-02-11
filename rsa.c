#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"rsa.h"
#define num 100000

//long long int allprime[50];
//long long int p,q,n,e,d, phi;
long long int gcd(long long int a,long long int b)
{
	if(a==b)
		return a;   
 	if(a>b)
		return gcd(a-b,b);
    return gcd(a,b-a);
}
long long int modinv(long long int e)
{
	long long int m0=phi,t,q,x0=0,x1=1;
	while(e>1)
	{
	q=e/m0;
	t=m0;
	m0=e%m0 ,e=t;
	t=x0;
	x0=x1-q*x0;
	x1=t;
	}
	if(x1<0)
	x1+=phi;
	return x1;	   
}
void keys()
{
	long long int i,a,b;
	d=0;
	while(!d) {
	e=rand()%(phi-1)+2;
	if(gcd(phi,e)==1)
	d=modinv(e);
	}
	//printf("%ld %ld\n",e,d);	
}
void SieveOfEratosthenes()
{
    int prime[100000];
   long long int i;
	srand(time(NULL));	
    for (p=2; p*p<=num-1; p++)
    {
        if (prime[p] == 0)
        {
            for (i=p*2; i<=num-1; i += p)
                prime[i] = 1;
        }
    }
    i=0;
    for (p=2; p<=num-1; p++)
       if (!prime[p])
          {
		allprime[i]=p;
		i++;
		if(i>=49)
		break;
	   }
	
allprime[49]=53;

do{ 
p=rand()%15+5;
q=rand()%15+5;
//printf("\n%ld %ld\n",p,q);
p=allprime[p];
q=allprime[q];
}while(p==0 || q==0);
n=p*q;
phi=(p-1)*(q-1);
//printf("\n%ld %ld blah\n",e,n);
keys();
}
long long int modexp(long long int x, long long int y)
{
	long long int res=1;
         x = x % n;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % n;
        y = y>>1;
        x = (x*x) % n; 
    }
	if(res>0)
    return res;
	else
	return res+n;
}


long long int retd()
{
return d;
}
long long int rete()
{
return e;
}
long long int retn()
{
return n;
}
























