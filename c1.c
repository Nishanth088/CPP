#include <stdio.h>
#include<string.h>
// void printArray(int nums[][3],int n){
//      for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             printf("%d \t",nums[i][j]);

//         }printf("\n");
//     } 
// }
// int main(){
//     int arr[3][3]=
//     {{10,20,30},
//     {40,50,60},
//     {70,80,90}};
//    printArray(arr,3);
//} 
int main(){


// int arr[]={1,50,1,90,40,60};
// int max=1;
// for(int i=0;i<6;i++){
//     if (max<=arr[i]){
//         max=arr[i];
//     }
//     else{
//         continue;
//     }

// }
// printf("max element :%d",max);

// char name[10]={"Nishanth"};
// printf("%s ",name);
// for(int i=0;i<10;i++){
//     printf("%n ,",name[i]);
// }printf("\n");
// void demonstrate_string_functions(){
    char str[8]="Nishanth";
    char copy_target[10];
    printf("Length of str1: %lu\n",strlen(str));
    strcpy(copy_target,str);
    printf("After strcpy,copy_target contains:%s\n",copy_target );
    
}

