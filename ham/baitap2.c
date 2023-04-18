#define SIZE 100
#include <stdio.h>
#include <conio.h>

//ham kiem tra chan le
int check(int n)
    {
    if(n % 2 == 0) return 1;
    else return 0;  
    }
//ham main
void main() 
{
int a[SIZE]; /*khai báo mảng gồm SIZE phần tử kiểu int*/
int n; // Lưu số phần tử thực có của mảng
int i;
do {
printf("Nhap so phan tu:"); 
scanf("%d", &n);
} while(n < 1 || n > SIZE);

// Nhập dữ liệu cho mảng
for(i = 0; i < n; i++)
{ 
printf("pt thu %d:", i);
scanf("%d", &a[i]); 
}
// dem so chan le
    int demchan=0,demle=0;                
    for(int i=0;i<n;i++)
    {
        if(check(a[i]) ==1 )          
            demchan++;
        else demle++;     
    }
     
    printf("\nSo luong so chan la: %d", demchan);
    printf("\nSo luong so le la: %d", demle);
//dem so chia het cho 3
printf("\nSo chia het cho 3 la:     ");
for(i=0; i < n; i++)
{
    if (a[i]%3==0) printf("%d\t",a[i]);
}
//dem so phan tu
    int chuan = a[0];
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]==chuan)
		{
			dem++;
		}
		if (chuan!=a[i])
		{
			printf("\nPhan tu %d xuat hien %d lan", a[i - 1], dem);
			chuan = a[i];
			dem = 1;
		}
		if (i==n-1)
		printf("\nPhan tu %d xuat hien %d lan",a[i],dem);
}
getch();
}