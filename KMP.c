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
		printf("t��s�е�һ�γ��ֵ���ʼλ���� %d",n);
	}
	else
	{
		printf("t����s�����ַ�����");
	}
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
			j = next[j];	//j����
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
