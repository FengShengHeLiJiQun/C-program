#include <stdio.h>
#include <string.h>
int KMP(char s[],char t[]);
void Getnext(int next[],char t[]);
int main()
{
 
  	char s[]= "ABCDe fgDe";
	char t[] = "gDe";
	int n = 0;
	n = KMP(s,t);
	if (n != -1)
	{
		printf("t在s中第一次出现的起始位置在 %d",n);
	}
	else
	{
		printf("t不是s的子字符串！");
	}
	return 0;
}

/*
KMP算法
关键在于next,回退位置
作者：QHH
时间：2020.7.27
*/
int KMP(char s[],char t[])
{
	int i=0,j=0;
	int slen = strlen(s);
	int tlen = strlen(t);
	int next[tlen];					//next数组长度与字符串t等长？
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
			j = next[j];	//j回退
		}
	}
	if (j == tlen)
		return i - j;	//匹配成功，返回子串位置
	else
		return (-1);	//匹配失败
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
			if(t[j] == t[k])	//当两个字符相同时，就跳过
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
