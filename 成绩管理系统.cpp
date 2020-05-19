#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100               /*一个班最多的人数*/
#define MAXM 10                /*最多课程门数*/
char subject[MAXM][12];        /*保存所有课程名称*/
char number[MAXN][12];         /*保存全班学号*/
char name[MAXN][20];           /*保存全班姓名*/
float score[MAXN][MAXM];       /*保存全班所有课程成绩*/
float sum[MAXN];               /*保存全班总成绩*//*n、m保存全班实际人数和课程数*/
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

    printf("1.成绩录入\n");
    printf("2.成绩查询\n");
    printf("3.成绩排序\n");
    printf("4.成绩保存\n");
    printf("5.成绩读取\n");
    printf("6.成绩报表打印\n");
    printf("0.退出\n");
    printf("\n请输入您的选择编号:\n");
    scanf("%d",&select);

    switch (select)
    {
     case 1: input(); break;
     case 2: search(); break;
     case 3: sort(); break;
     case 4: save(); break;
     case 5: load(); break;
     case 6: print(); break;
     case 0: printf("谢谢您的使用\n");
   }
 }

 return 0;
}

void input()                   /*输入成绩模块*/
{
	int i,j;
  printf("请输入全班人数:");
  scanf("%d",&n);
  printf("请输入课程门数:");
  scanf("%d",&m);
  printf("请输入%d门课程名称\n",m);
  for (j=0;j<m;j++)
  {
   printf("第%d门课程名称:",j+1);
   scanf("%s", subject[j]);
 }
 printf("请输入%d个学生数据\n",n);
 for (i=0;i<n;i++)
 {
   printf("请输入第%d个人的数据\n",i+1);
   printf("学号:");
   scanf("%s",number[i]);
   printf("姓名:");
   scanf("%s", name[i]);
   printf("%d门课程的成绩:",m);
       sum[i]=0;                         /*边输入边统计总成绩*/
   for (j=0; j<m; j++)
   { 
    printf("%s:", subject[j]);
    scanf ("%f", &score[i][j]);
    sum[i]=sum[i]+score[i][j];
  } 
}
}


void search()                  /*查询成绩模块*/
{ 
	int j;
  int search1();
  int search2();
  int select, index;
  while (1)
  {
   printf("1.按学号查询\n"); 
   printf("2.按姓名查询\n");
   printf("0.返回\n");
   printf("请输入您的选择编号:\n");
   scanf("%d",&select);
   switch (select)
   {
     case 1: index=search1(); break;
     case 2: index=search2(); break;
     case 0: return;
   }
   if (index!=-1)
   {
     printf("学号:%s\n",number[index]);
     printf("姓名:%s\n",name[index]);
     for (j=0;j<m;j++)
     {
       printf("%12s: ",subject[j]);
       printf("%5.lf\n",score[index][j]);}
       printf("\n总成绩: %10.2f",sum[index]);
       printf("平均成绩: %10.2f\n",sum[index]/m);
     }
     else printf("没有这个同学。\n");
   }
 }       
 
int search1()          /*按学号查询模块*/
 {

  int i;
  char s_number[10];
  printf("请输入要查询的学号:");
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

int search2()                  /*按姓名查询模块*/
{
  int i;
  char s_name[10];
  printf("请输入要查询的姓名:");
  scanf("%s",s_name);

  for (i=0;i<n;i++)
    if (strcmp(name[i],s_name)==0)
      break;
    if (i<n)
     return i;
   else 
    return -1;
}


void sort()                    /*排序模块*/
{
  void sort1();
  void sort2();
  void sort3();
  int select;
  while(1)
  {
    printf("1.按学号排序\n");
    printf("2.按姓名排序\n");
    printf("3.按总成绩排序\n");
    printf("0.返回\n");
    printf("\n请输入您的选择编号:\n");
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

void sort1()                    /*按学号排序模块*/
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
printf("排序完毕。\n");
}

void sort2()                   /*按姓名排序模块*/
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
printf("排序完毕.\n");
}

void sort3()                   /*按总成绩排序模块*/
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
  printf("排序完毕.\n");
}


void save()             /*保存成绩模块*/
{
  FILE *fp;
  char filename[20];
  int i,j;
  printf("请输入文件名:");
  scanf("%s",filename);
  if ((fp=fopen(filename, "w"))==NULL)
  {
   printf("打开文件失败.\n");
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
printf("保存完毕.\n");
}


void load()         /*提取成绩模块*/
{
  FILE * fp;
  char filename[20];
  int i,j;
  printf("请输入文件名:");
  scanf("%s",filename);
  if ((fp=fopen(filename,"r"))==NULL)
  {
    printf("文件不存在.\n");
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
 printf("提取完毕\n");
}


void print()                   /*打印成绩报表模块*/
{
	void print1();
	void print2();
	int i,j,select;
	printf("1.屏幕显示报表\n");
	printf("2.打印机打印报表\n");
	printf("0.返回\n");
	printf("\n请输入你的编号:");
	scanf("%d",&select);
	switch(select)
	{
    case 1: print1(); break;
    case 2: print2(); break;
    case 0: return;
  }
}

void print1()                  /*屏幕显示报表模块*/    
{
  int i,j;
  printf("成绩总表\n");
  printf("学 号       姓 名  "); 
  for (j=0;j<m;j++)
    printf("  %-10s",subject[j]);
  printf("总成绩  平均成绩\n");
  for(i=0;i<n;i++)
  {
    printf("%-11s %-8s ",number[i],name[i]);
    for(j=0;j<m;j++)
      printf( "%-6.1f",score[i][j]);
    printf("    %-6.1f  %-6.2f\n",sum[i],sum[i]/m);
  }
  printf("显示完毕.\n");
}


void print2()                 /*打印机打印报表模块*/
{
  FILE *fp;
  int i,j;
  printf("请准备好打印机,按任意继续...\n");
  scanf( "% * c");
  if ((fp=fopen("prn","w"))==NULL)
  {
    printf("打印机没有准备好\n");
    return;
  }
  fprintf(fp,"成绩总表\n");
  fprintf(fp,"学号 姓名");
  for (j=0;j<m;j++)
    fprintf(fp,"%10s", subject[j]);
  fprintf(fp,"总成绩 平均成绩\n");
  for (i=0;i<n;i++)
  {
    fprintf(fp,"%8s %8s",number[i],name[i]);
    for(j=0;j<m;j++)
      fprintf(fp," %6.lf",score[i][j]);
    fprintf(fp,"%6.1f %6.2f\n",sum[i],sum[i]/m);
  }
  fclose(fp);
  printf("打印完毕.\n");
}
