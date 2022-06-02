//  main.c
//  behic_oytun_senkul_181213103
//  Created by Oytun Şenkul on 6/2/22.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
// fonksiyon kurarken bu sitenin konu anlatimindan faydalandim:
// https://www.sibervatan.org/makale/rsa-sifreleme/36
//rsa degerleri asaldir...cift olmasi durumunda program calismaz
//p -> ilk prime sayisi
//q -> ikinci prime sayisi
//t -> totient degeri, (p-1)*(q-1)
//n -> p*q degeridir
long int p,q,n,t;//tmp degerler ve sifreleme degerleri
long int flag;//yuksek degerler icin long olarak tanimladim
long int e[100],d[100],temp[100],j,m[100],en[100],i; //yuksek degerler icin long olarak tanimladim
void encrypt(); //sifreleme fonksiyonu...return deger olmadigi icin void tanimladim
void decrypt(); //sifre kirma fonksiyonu...return deger olmadigi icin void tanimladim
char psw[100]; //sifrelenecek olan metin
int primevalue(long int); //prime key hesaplma fonksiyonu
void ce();
long int cd(long int);
int main() //ANA FONKSİYON
{
    printf("Prime degeri girin:\n");
    scanf("%ld",&p);
    flag=primevalue(p);
    if(flag==0)//deger rsa icin gecersiz olursa program sonlandirilir
    {
        printf("\nGecersiz deger girildi...program sonlandiriliyor...\n");
        exit(1);
    }
    printf("Diger prime degeri girin:\n");
    scanf("%ld",&q);
    flag=primevalue(q);
    if(flag==0||p==q) //deger rsa icin gecersiz olursa program sonlandirilir
    {
        printf("\nGecersiz deger girildi...program sonlandiriliyor...\n");
        exit(1);
    }
    printf("\nSifrelenecek olan metini girin:\n"); //sifrelenecek olan metin girisi
    fflush(stdin);
    scanf("%s",psw);
    for(i=0;psw[i]!=NULL;i++)
        m[i]=psw[i];
    n=p*q;
    t=(p-1)*(q-1); //totient degeri
    ce();
    printf("\n \t  e ve d degerleri sunlardir:\n");
    for(i=0;i<j-1;i++)
        printf("\n ->%ld\t ->%ld",e[i],d[i]);
    encrypt(); //sifrelemme fonksiyonu aktif edilir
    decrypt(); //sifre kirma fonksiyonu aktif edilir
    return 0;
}
 
int primevalue(long int pr) //prime degerler hesaplanir
{
    int i;
    j=sqrt(pr);
    for(i=2;i<=j;i++)
    {
        if(pr%i==0)
            return 0;
    }
    return 1;
}
 
void ce()
{
    int k;
    k=0;
    for(i=2;i<t;i++)
        {
            if(t%i==0)
                continue;
                flag=primevalue(i);
            if(flag==1&&i!=p&&i!=q)
            {
                e[k]=i; flag=cd(e[k]);
                if(flag>0)
        {
            d[k]=flag;
            k++;
        }
        if(k==99)
            break;
        }
    }
}
 
long int cd(long int x) 
{
    long int k=1;
    while(1)
    {
        k=k+t;
        if(k%x==0)
            return(k/x);
    }
}
void encrypt() //sifreleme islemleri
{
    long int pt,ct,key=e[0],k,len;
    i=0;
    len=strlen(psw);
    while(i!=len)
    {
        pt=m[i];
        pt=pt-96;
        k=1;
        for(j=0;j<key;j++)
        {
            k=k*pt;
            k=k%n;
        }
        temp[i]=k;
        ct=k+96;
        en[i]=ct;
        i++;
    }
    en[i]=-1;
    printf("\nMetnin sifrelenmis hali sudur:\n");
    for(i=0;en[i]!=-1;i++)
        printf("%c",en[i]);
}
void decrypt() //sifre kirma islemleri
{
    long int pt,ct,key=d[0],k;
    i=0;
    while(en[i]!=-1)
    {
        ct=temp[i];
        k=1;
        for(j=0;j<key;j++)
        {
            k=k*ct;
            k=k%n;
        }
        pt=k+96;
        m[i]=pt;
        i++;
    }
    m[i]=-1;
    //sifrelenmis olarak cikti verildikten sonra sifrelenmemis halinin de ciktisi verilir
    printf("\nsifrenin cozulmus yani asil hali sudur:\n");
    for(i=0;m[i]!=-1;i++)
        printf("%c",m[i]);
}


