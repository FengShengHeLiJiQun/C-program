#include <stdio.h>

#include <stdlib.h>
#include <string.h>
int KMP(char s[],char t[]);
void Getnext(int next[],char t[]);



int main(int argc, char *argv[])

{

	
	//Read the file
	FILE *fp = fopen("/root/program/Android.log","r");	
	if(fp == NULL)

	{

		printf("Open error!");

		return 0;
	
	}


	
	//Read the string that the user wants to look up.
	printf("Please enter the number of strings of you want to find: \n");
	int x ;
	scanf("%d",&x);
	char str[x][100];
	for (int i = 0; i < x; i ++)
	{	
		printf("Please enter a string: \n");
		scanf("%s",&str[i]);

	}
	


	//Assigns the read to s and outouts it	
	char s[1000];

	int m = 1;	//row
	while(fgets(s,sizeof(s),fp))

	{



		//char t[] = "CameraService::connect";	
		for (int i = 0; i < x; i ++)
		{
			int n = 0;	//column

				
			n = KMP(s,str[i]);
			
			if (n != -1)
			{
				printf("%s is in the %d row %d column \n",str[i],m,n);
				printf("%s \n",s);


			}
	

		}

		m++;	//row +1
	}
	fclose(fp);	//close file
	return 0;

}







/*
KMP�㷨
�ؼ�����next,����λ��
���ߣ�QHH
ʱ�䣺2020.7.27
*/
int KMP(char s[],char t[])
{
	int i=0,j=0;
	int slen = strlen(s);
	int tlen = strlen(t);
	int next[tlen];					//next���鳤�����ַ���t�ȳ���
	Getnext(next,t);
	while(i < slen && j < tlen)
	{
		if(j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else 
		{
			j = next[j];	// j����
		}
	}
	if (j == tlen)
		return i - j;	//ƥ��ɹ��������Ӵ�λ��
	else
		return (-1);	//ƥ��ʧ��
}

void Getnext(int next[],char t[])
{
	int j = 0,k = -1;
	next[0] = -1;
	int tlen =strlen(t); 
	while(j < tlen -1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			if(t[j] == t[k])	//�������ַ���ͬʱ��������
				next[j] = next[k];
			else
				next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}

}

