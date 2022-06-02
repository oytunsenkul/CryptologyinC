//
//  main.c
//  behic_oytun_senkul_181213103
//
//  Created by Oytun Şenkul on 15.03.2022.
//  Licensed by Oytun Şenkul on 15.03.2022.
//

#include <stdio.h>
//RECURSIVE FONKSYION ILE YAPILDI
//hesap fonksiyonunda return dondurme yapmak icin  int kullandım
int euclid_gcd_func(int n1, int n2, int *x, int *y){//fonksiyon hem gcd hem de x-y degerlerini bulmaktadır
    if(n1==0){ //ilk sayı 0 olunca sadece n2 kullanılarak islem yurutulur
        //birden cok deger ile kontrol yapılması icin pointer kullandım
        *x=0;
        *y=1;
        return n2;
    }else{
    int x2, y2;
    int total = euclid_gcd_func(n2%n1, n1, &x2, &y2);//Hesaplanan verilerek cikis verilmesi icin gcd e aktarıldı
    *x= y2 - (n2/n1)*x2;
    *y=x2;
    return total;
    }
}
int main(){//ANA FONKSIYON
    int a,b;
    int x,y;
    printf("'a' degerini girin: ");
    scanf("%d",&a);
    printf("'b' degerini girin: ");
    scanf("%d",&b);
    printf("%d ile %d nin GCD sonucu: %d \n",a,b,euclid_gcd_func(a, b, &x, &y));
    printf("x = %d ve y = %d\n",x,y);
    printf("İslemin genel sonucu [gcd(a,b)=ax+ay] cinsinden\n");
    printf("gcd(%d,%d)= %d.%d + %d.%d\n",a,b,x,a,y,b);
}
