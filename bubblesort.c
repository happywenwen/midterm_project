#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num;
struct person_t{
char name[100];
unsigned score;
}student[2000];

int cmpnum(struct person_t *array);
int cmpstr(struct person_t *array);
void bubblesort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *));

void main()
{
 clock_t start, end;
 start = clock();
 FILE *fin;
 fin=fopen("score.txt","rt");

 fscanf(fin,"%d",&num);

 for (int i = 0; i < num; i++)
 {
     fscanf(fin,"%s%d",student[i].name,&student[i].score);
 }

 bubblesort(student,num,sizeof(struct person_t),cmpnum);
 printf("score(from low to high)\n");
 for (int i = 0; i < num; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }

 bubblesort(student,num,sizeof(struct person_t),cmpstr);
 printf("name(in dictionary order)\n");
 for (int i = 0; i < num; i++)
 {
    printf("%s %d\n",student[i].name,student[i].score);
 }
 
 fclose(fin);
 end = clock();
    double diff = end - start; // ms
    printf(" %f  ms\n" , diff);
    printf(" %f  sec\n", diff / CLOCKS_PER_SEC );
}

int cmpnum(struct person_t *array)
{
 int n=num,c,d;
 struct person_t swap;
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (student[d].score > student[d+1].score) /* For decreasing order use '<' instead of '>' */
      {
        strcpy(swap.name,student[d].name);
        swap.score=student[d].score;
        strcpy(student[d].name,student[d+1].name);
        student[d].score=student[d+1].score;
        strcpy(student[d+1].name,swap.name);
        student[d+1].score=swap.score;
      }
    }
  }
    return 0;
}

int cmpstr(struct person_t *array)
{
 int n=num,c,d;
 struct person_t swap;
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (strcmp(student[d].name,student[d+1].name)>0) /* For decreasing order use '<' instead of '>' */
      {
        strcpy(swap.name,student[d].name);
        swap.score=student[d].score;
        strcpy(student[d].name,student[d+1].name);
        student[d].score=student[d+1].score;
        strcpy(student[d+1].name,swap.name);
        student[d+1].score=swap.score;
      }
    }
  }
  return 0;
}

void bubblesort(struct person_t *array,size_t __nel, size_t __width,int (*__compar)(struct person_t *))
{
   __compar(array);
}