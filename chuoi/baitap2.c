#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
   char string[100];
   printf("Nhap chuoi bat ky: ");
   gets(string);
   strupr(string);
   printf("Chuoi in hoa la: %s", string);
getch();
}