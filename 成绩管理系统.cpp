#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100               /*һ������������*/
#define MAXM 10                /*���γ�����*/
char subject[MAXM][12];        /*�������пγ�����*/
char number[MAXN][12];         /*����ȫ��ѧ��*/
char name[MAXN][20];           /*����ȫ������*/
float score[MAXN][MAXM];       /*����ȫ�����пγ̳ɼ�*/
float sum[MAXN];               /*����ȫ���ܳɼ�*//*n��m����ȫ��ʵ�������Ϳγ���*/
int n,m;
void input();
void search();
void sort();
void save();
void load();
void print();
int main()
{
  int select;
  while(1)
  {

    printf("1.�ɼ�¼��\n");
    printf("2.�ɼ���ѯ\n");
    printf("3.�ɼ�����\n");
    printf("4.�ɼ�����\n");
    printf("5.�ɼ���ȡ\n");
    printf("6.�ɼ������ӡ\n");
    printf("0.�˳�\n");
    printf("\n����������ѡ����:\n");
    scanf("%d",&select);

    switch (select)
    {
     case 1: input(); break;
     case 2: search(); break;
     case 3: sort(); break;
     case 4: save(); break;
     case 5: load(); break;
     case 6: print(); break;
     case 0: printf("лл����ʹ��\n");
   }
 }

 return 0;
}

void input()                   /*����ɼ�ģ��*/
{
	int i,j;
  printf("������ȫ������:");
  scanf("%d",&n);
  printf("������γ�����:");
  scanf("%d",&m);
  printf("������%d�ſγ�����\n",m);
  for (j=0;j<m;j++)
  {
   printf("��%d�ſγ�����:",j+1);
   scanf("%s", subject[j]);
 }
 printf("������%d��ѧ������\n",n);
 for (i=0;i<n;i++)
 {
   printf("�������%d���˵�����\n",i+1);
   printf("ѧ��:");
   scanf("%s",number[i]);
   printf("����:");
   scanf("%s", name[i]);
   printf("%d�ſγ̵ĳɼ�:",m);
       sum[i]=0;                         /*�������ͳ���ܳɼ�*/
   for (j=0; j<m; j++)
   { 
    printf("%s:", subject[j]);
    scanf ("%f", &score[i][j]);
    sum[i]=sum[i]+score[i][j];
  } 
}
}


void search()                  /*��ѯ�ɼ�ģ��*/
{ 
	int j;
  int search1();
  int search2();
  int select, index;
  while (1)
  {
   printf("1.��ѧ�Ų�ѯ\n"); 
   printf("2.��������ѯ\n");
   printf("0.����\n");
   printf("����������ѡ����:\n");
   scanf("%d",&select);
   switch (select)
   {
     case 1: index=search1(); break;
     case 2: index=search2(); break;
     case 0: return;
   }
   if (index!=-1)
   {
     printf("ѧ��:%s\n",number[index]);
     printf("����:%s\n",name[index]);
     for (j=0;j<m;j++)
     {
       printf("%12s: ",subject[j]);
       printf("%5.lf\n",score[index][j]);}
       printf("\n�ܳɼ�: %10.2f",sum[index]);
       printf("ƽ���ɼ�: %10.2f\n",sum[index]/m);
     }
     else printf("û�����ͬѧ��\n");
   }
 }       
 
int search1()          /*��ѧ�Ų�ѯģ��*/
 {

  int i;
  char s_number[10];
  printf("������Ҫ��ѯ��ѧ��:");
  scanf("%s",s_number);
  for (i=0;i<n;i++)
  {
   if (strcmp(number[i],s_number)==0)
    break;
}
if (i<n)
 return i;
else 
  return -1;
}

int search2()                  /*��������ѯģ��*/
{
  int i;
  char s_name[10];
  printf("������Ҫ��ѯ������:");
  scanf("%s",s_name);

  for (i=0;i<n;i++)
    if (strcmp(name[i],s_name)==0)
      break;
    if (i<n)
     return i;
   else 
    return -1;
}


void sort()                    /*����ģ��*/
{
  void sort1();
  void sort2();
  void sort3();
  int select;
  while(1)
  {
    printf("1.��ѧ������\n");
    printf("2.����������\n");
    printf("3.���ܳɼ�����\n");
    printf("0.����\n");
    printf("\n����������ѡ����:\n");
    scanf("%d",&select);
    switch (select)
    {
     case 1: sort1(); break;
     case 2: sort2(); break; 
     case 3: sort3(); break;
     case 0: return;
   }
 }
} 

void sort1()                    /*��ѧ������ģ��*/
{
  int i,j,k;
  char x_number[10];
  char x_name[20];
  float x;
  for(i=0;i<n-1;i++)
  {
   k=i;
   for(j=i+1;j<n;j++){
     if (strcmp(number[j],number[k])<0)
      k=j;
  }
  if (k!=i)
  {
    strcpy(x_number,number[i]);
    strcpy(number[i],number[k]);
    strcpy(number[k],x_number);
    strcpy(x_name,name[i]);
    strcpy(name[i],name[k]);
    strcpy(name[k],x_name);
    
    for(j=0;j<m;j++)
    {
     x=score[i][j];
     score[i][j]=score[k][j];
     score[k][j]=x;
   }
   x=sum[i]; sum[i]=sum[k]; sum[k]=x;
 }
}
printf("������ϡ�\n");
}

void sort2()                   /*����������ģ��*/
{
  int i,j,k;
  char x_number[10];
  char x_name[20];
  float x;
  for(i=0;i<n-1;i++)
  {
   k=i;
   for (j=i+1;j<n;j++)
    if(strcmp(name[j],name[k])<0)
     k=j;
   if (k!=i)
   {
     strcpy(x_number,number[i]);
     strcpy(number[i],number[k]);
     strcpy(number[k],x_number);
     strcpy(x_name,name[i]);
     strcpy(name[i],name[k]);
     strcpy(name[k],x_name);
     for (j=0;j<m;j++)
     {
      x=score[i][j];
      score[i][j]=score[k][j];
      score[k][j]=x;
    }
    x=sum[i]; sum[i]=sum[k]; sum[k]=x;
  }
}
printf("�������.\n");
}

void sort3()                   /*���ܳɼ�����ģ��*/
{
  int i,j,k;
  char x_number[10];
  char x_name[20];
  float x;
  for (i=0;i<n-1;i++){
    k=i;
    for(j=i+1;j<n;j++)
     if(sum[j]<sum[k])
     	k=j;
     if(k!=i)
     {
       strcpy(x_number,number[i]);
       strcpy(number[i],number[k]);
       strcpy(number[k], x_number);
       strcpy(x_name,name[i]);
       strcpy(name[i],name[k]);
       strcpy(name[k],x_name);
       for(j=0;j<m;j++)
       {
        x=score[i][j];
        score[i][j]=score[k][j];
        score[k][j]=x;
      }
      x=sum[i]; sum[i]=sum[k]; sum[k]=x;
    }
  }
  printf("�������.\n");
}


void save()             /*����ɼ�ģ��*/
{
  FILE *fp;
  char filename[20];
  int i,j;
  printf("�������ļ���:");
  scanf("%s",filename);
  if ((fp=fopen(filename, "w"))==NULL)
  {
   printf("���ļ�ʧ��.\n");
   return;
 }
 fprintf(fp,"%d %d ",n,m);
 for(j=0;j<m;j++)
   fprintf(fp,"%s ",subject[j]);
 for(i=0;i<n;i++)
 {
  fprintf(fp,"%s %s ",number[i],name[i]);
  for(j=0;j<m;j++)
    fprintf(fp,"%5.lf ",score[i][j]);
}
fclose(fp);
printf("�������.\n");
}


void load()         /*��ȡ�ɼ�ģ��*/
{
  FILE * fp;
  char filename[20];
  int i,j;
  printf("�������ļ���:");
  scanf("%s",filename);
  if ((fp=fopen(filename,"r"))==NULL)
  {
    printf("�ļ�������.\n");
    return;
  }
  fscanf(fp,"%d%d",&n,&m);
  for(j=0;j<m;j++)
   fscanf(fp,"%s",subject[j]);
 for(i=0;i<n;i++)
 {
   fscanf(fp,"%s%s", number[i], name[i]);
   sum[i]=0;
   for(j=0;j<m;j++)
   {
     fscanf(fp,"fr",&score[i][j]);
     sum[i]=sum[i]+score[i][j];
   }   
 }
 fclose(fp);
 printf("��ȡ���\n");
}


void print()                   /*��ӡ�ɼ�����ģ��*/
{
	void print1();
	void print2();
	int i,j,select;
	printf("1.��Ļ��ʾ����\n");
	printf("2.��ӡ����ӡ����\n");
	printf("0.����\n");
	printf("\n��������ı��:");
	scanf("%d",&select);
	switch(select)
	{
    case 1: print1(); break;
    case 2: print2(); break;
    case 0: return;
  }
}

void print1()                  /*��Ļ��ʾ����ģ��*/    
{
  int i,j;
  printf("�ɼ��ܱ�\n");
  printf("ѧ ��       �� ��  "); 
  for (j=0;j<m;j++)
    printf("  %-10s",subject[j]);
  printf("�ܳɼ�  ƽ���ɼ�\n");
  for(i=0;i<n;i++)
  {
    printf("%-11s %-8s ",number[i],name[i]);
    for(j=0;j<m;j++)
      printf( "%-6.1f",score[i][j]);
    printf("    %-6.1f  %-6.2f\n",sum[i],sum[i]/m);
  }
  printf("��ʾ���.\n");
}


void print2()                 /*��ӡ����ӡ����ģ��*/
{
  FILE *fp;
  int i,j;
  printf("��׼���ô�ӡ��,���������...\n");
  scanf( "% * c");
  if ((fp=fopen("prn","w"))==NULL)
  {
    printf("��ӡ��û��׼����\n");
    return;
  }
  fprintf(fp,"�ɼ��ܱ�\n");
  fprintf(fp,"ѧ�� ����");
  for (j=0;j<m;j++)
    fprintf(fp,"%10s", subject[j]);
  fprintf(fp,"�ܳɼ� ƽ���ɼ�\n");
  for (i=0;i<n;i++)
  {
    fprintf(fp,"%8s %8s",number[i],name[i]);
    for(j=0;j<m;j++)
      fprintf(fp," %6.lf",score[i][j]);
    fprintf(fp,"%6.1f %6.2f\n",sum[i],sum[i]/m);
  }
  fclose(fp);
  printf("��ӡ���.\n");
}
