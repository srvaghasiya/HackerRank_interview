#include<stdio.h>
#include<string.h>

// we are assuming that we have sufficient extra space available for extra characters

void URLify(char *str)
{
	int len = strlen(str);
	int nlen,i,cnt=0;
	for(int i=0;i<=len;i++)
	{
		if(str[i] == ' ')
			cnt++;
	}
	nlen = len + (cnt*2);
	while(nlen >= 0)
	{
		if(str[len] == ' ')
		{
			str[nlen]='0';
			str[nlen-1]='2';
			str[nlen-2]='%';
			nlen-=3;
		}
		else
		{
			str[nlen] = str[len];
			nlen--;
		}
		len--;
	}
	
	printf("string after URLify : %s",str);
	
	return;
}

int main()
{
	char str[100]={0};
	printf("Enter string : ");
	fgets(str,100,stdin);
	URLify(str);
	return 0;
}
