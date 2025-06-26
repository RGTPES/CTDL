//PTIT_CNTT1_IT201_Session05_Bai05
#include <stdio.h>
#include <string.h>
void Palindrome(char a[100],int n,int i) {
 if (i==n/2) {
  printf("Palindrome valid");
  return;
 }
 if (a[i]==a[n-i-1]) {
  Palindrome(a,n,i+1);
 }else {
  printf("Palindrome invalid");
 }

}
 int main() {
char arr[100];
 int n;
 printf("Nhap so luong phan tu cho mang : ");
 scanf("%d",&n);
 for (int i=0;i<n;i++) {
  scanf("%s",&arr[i]);

 }
 Palindrome(arr,n,0);
 }