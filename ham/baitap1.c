/*10. Viết các hàm thực hiện các chức năng sau:
a. Đếm số phần tử có chữ số tận cùng là 6 và chia hết cho 6.
b. Đếm số phần tử là số hoàn chỉnh/số nguyên tố/số đối xứng.
c. Đếm số phần tử là số hoàn chỉnh/số nguyên tố/số đối xứng phân biệt, các phần tử là số
hoàn chỉnh/số nguyên tố/số đối xứng trùng nhau chỉ đếm một lần.
d. Đấm tần suất xuất hiện của các phần tử. Chẳng hạn với mảng gồm các phần tử: 12 34 12 
34 43 12 5 thì tần suất xuất hiện các phần tử là 12 (3 lần), 34 (2 lần), 12 (2 lần), 5 (1 
lần).*/
#include <stdio.h>
#include <math.h>
#include <conio.h>

int sotancung6(int a[], int x)
{
    int dem=0;
    for(int i=0;i<x;i++){
        if(a[i]%10==6) dem++;
        else if(a[i]%100==6) dem++;
    }
    return dem;
}

int sochiahetcho6(int a[], int x)
{
    int dem1=0;
    for(int i=0;i<x;i++){
    if (a[i]%6==0) dem1++;
    }
    return dem1;
}

int ktrasotrungnhau(int a[], int x, int in)
{
    for(int i = in-1; i >= 0; i--){
        if(a[i] == a[in]) return 0;
    }
    return 1;
}

int ktrasohoanchinh(int x)
{
    int tong=0;
    for (int i=1;i<x;i++){
        if(x%i==0) tong=tong+i;
    }
    if (tong==x) return 1;
    else return 0;
}

int demsohoanchinh(int a[], int x)
{
    int dem2=0;
    for (int i=0;i<x;i++){
        int ktra=ktrasotrungnhau(a,x,i);
        if(ktra==1){
            if(ktrasohoanchinh(a[i])==1) dem2++;
        }
    }
    return dem2;
}

int ktrasonguyento(int x)
{   
    if(x<2) return 0;
    else if(x>2){
        if(x%2==0) return 0;
    }
    for (int i=3;i<=sqrt(x);i+=2){
        if(x%i==0) return 0;
    }
    return 1;
}

int demsonguyento(int a[], int x)
{
    int dem3=0;
    for(int i=0;i<x;i++){
        int ktra=ktrasotrungnhau(a,x,i);
        if(ktra==1){
        if(ktrasonguyento(a[i])==1) dem3++;
        }
    }
    return dem3;
}

int demsodoixung(int a[], int x)
{
    int dem4=0;
    for(int i=1;i<x;i++){
        int ktra=ktrasotrungnhau(a,x,i);
        if(ktra==1){
        if((a[i]%10)==(a[i]/10)) dem4++;
        else if((a[i]%10)==(a[i]/10)) dem4++; 
        }
    }
    return dem4;      
}

int demsolanlap(int a[], int x)
{
    int dem5=1;
    for(int i = 0; i < x; i++){
        if(a[i] == a[i+1]) dem5++;
        if(a[i] != a[i+1]){
            printf("\nPT %d Xuat Hien  %d lan ",a[i],dem5);
            dem5=1;
        } 
    }
}

void main()
{
    //xuatnhapmang
    int a[1000],n,b;
    printf("Nhap so phan tu:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
    printf("pt thu %d:", i);
    scanf("%d", &a[i]);
    }
    //tangdan
    for(int j=1;j<=n;j++) {
        for(int i = 1; i < n; i++) {
            if(a[i-1] > a[i]){
                b = a[i-1];
                a[i-1] = a[i];
                a[i] = b;
            }
        }
    }
//xuatketqua
    int ketqua=sotancung6(a,n);
printf("\nCo %d So Co Chu So Tan Cung La 6", ketqua);
    int ketqua1=sochiahetcho6(a,n);
       printf("\nCo %d So Chia Het Cho 6\n", ketqua1);
    int ketqua2=demsohoanchinh(a,n); 
       printf("\nCo %d So Hoan Chinh \n", ketqua2);
    int ketqua3=demsonguyento(a,n);
       printf("\nCo %d So Nguyen To \n", ketqua3);
    int ketqua4=demsodoixung(a,n);
       printf("\nCo %d So Doi Xung \n", ketqua4);
    demsolanlap(a,n);
getch();
}