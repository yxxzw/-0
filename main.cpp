#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
int iCount;struct student
{	
 int stuID;                             
 char Name[100];                  	
 char Remove[100];               
 struct student *next;           
};
 struct student* create()                
{	
 char str1;	
 struct student* pHead = NULL;  	
 struct student* pNew, *pEnd;    
 iCount = 0;                                	
 pEnd = pNew = (struct student*)malloc(sizeof(struct student));	
 printf("请输入学生姓名:");          	
 scanf("%s", &pNew->Name);	getchar();	printf("请输入学生学号:");	
 scanf("%d", &pNew->stuID);	printf("请输入学生班级:");	
 scanf("%s", &pNew->Remove);	
 getchar();	pNew->next = pHead;	
 pEnd = pNew;	
 pHead = pNew;
 iCount++;
 printf("是否继续输入y/n:");	
 scanf("%c", &str1);	printf("\n");	
 while (str1!='n')	
 {		
  iCount++;                      	
  pNew = (struct student*)malloc(sizeof(struct student));		
  printf("请输入学生姓名:");      		
  scanf("%s", &pNew->Name);	
  getchar();	
  printf("请输入学生学号:");	
  scanf("%d", &pNew->stuID);		
  printf("请输入学生班级:");	
  scanf("%s", &pNew->Remove);
  getchar();	
  pNew->next = NULL;	
  pEnd->next = pNew;	
  pEnd = pNew;	
  printf("是否继续输入y/n:");	
  scanf("%c", &str1);		
  printf("\n");
 }	
 return pHead;}void Print(struct student* pHead)  
{
 struct student *pTemp;	
 int iIndex = 1;	
 printf("the List has %d members:----\n", iCount);	
 printf("\n");
 pTemp = pHead;
 while (pTemp != NULL)	
 {	
  printf("班级:%-15s 姓名:%-10s 学号:%-10d\n", pTemp->Remove, pTemp->Name, pTemp->stuID);
  pTemp = pTemp->next;	
  iIndex++;	
  }	
  printf("\n");
}
void _delete(struct student* pHead)     
{	
 int id,r=1,i;

 struct student *pTemp;  
 struct student *pPre;            	
 pTemp = pHead;                   
 pPre = pTemp;	
 printf("请输入要删除学号");	
 scanf("%d", &id);
 getchar();	
 while (1)
 {


  if ( pTemp->stuID!=id)
  {			
  r++;		
}		
else		
{			
pTemp = pHead; break;	
	}		
printf("%d\n", r);		
pTemp = pTemp->next;	
		}	
for (i = 1; i < r; i++)	
{		
 pPre = pTemp;	
 pTemp = pTemp->next;
}
 pPre->next = pTemp->next;	free(pTemp);
 iCount--;	printf("---删除成功---\n");
}
void find(struct student* pHead)    
{	
 int _id,j=0;	struct student *pTemp;           	
 pTemp = pHead;
 printf("请输入你要查询的学生学号：");	
 scanf("%d", &_id);
 while (pTemp->stuID != NULL)
 {		
  if (pTemp->stuID == _id)		
   {			
     printf("班级:%-15s 姓名:%-10s 学号:%-10d\n\n", pTemp->Remove, pTemp->Name, pTemp->stuID);
       j++;  
      break;
   }	
  else if (j == 0)	
   {			
     printf("---没有查询到信息---\n\n"); 
     break;	
   }				
    pTemp = pTemp->next;	
  }
	
  }
int main()
{
int b;
struct student* pHead;
while(1)	
 {	
   printf("删除信息输入 1\n");		
   printf("添加信息输入 2\n");		
   printf("输出信息输入 3\n");		
   printf("查询信息输入 4\n");		
   scanf("%d", &b);		
   getchar();		
   switch (b)		
   {		
    case 1:_delete(pHead);   break;    		
    case 2:pHead = create(); break;    		
    case 3:Print(pHead);     break;      		
    case 4:find(pHead);      break;      		
    }	
   }		
   return 0;
}