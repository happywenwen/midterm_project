#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define N 2000
#define base 2199

int* getRand(int,int,int);  

void main()
{
  FILE *fin,*fout;
  fin=fopen("namedata.txt","rt");
  fout=fopen("score.txt","w+t");

  srand(time(NULL));

  typedef struct {
    char name[100];
    unsigned score;} person_t;
  person_t student[base],list[N];
  for (int i = 0; i < base; i++)
 {
    fscanf(fin,"%s",student[i].name);
 }
 
 int *randNum;
 randNum = getRand(1,2199,N);
 
  for (int i = 0; i < N; i++)
  {
    list[i]=student[*(randNum+i)];
    list[i].score=(rand() % 100) +1;
  }
  

  fprintf(fout,"%d\n",N);
  for (int i = 0; i < N; i++)
  {
    printf("%s %d\n",list[i].name,list[i].score);
    fprintf(fout,"%s %d\n",list[i].name,list[i].score);
  }
  
  fclose(fin);
  fclose(fout);

  return;
}

int* getRand(int min, int max, int num){
    int tol = max - min +1;  //算出總數
    int a[30000];  //放min~max的所有數字 
    static int b[30000];  //放取出的亂數 
    int i,j;
    for(i=0;i<tol;i++){  //跟電腦要記憶格放數字，從小排到大放進a[0]~a[tol-1] 
        *(a+i) = min+i;
    }
    srand(time(0));
    int ctr;  //這只是個容器，拿來裝a[n]裡的n，而這個n是用亂數製造的 
    for(i=0;i<num;i++){
        ctr = rand()%(tol-i);
        b[i] = a[ctr];  //把抓好的亂數丟到b裡面 
        for(j=ctr;j<(tol-1-i);j++){  //這是整個不重複亂數函數的經髓所在！
            a[j] = a[j+1];  //很微妙的通通往前移動一格 
        }
    }
    return b;
}