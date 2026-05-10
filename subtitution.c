#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int b,i,a = 0;
	int c=0;
	char key[26];
	char msg[100];
	
	
	printf("enter key: ");
	for(i=0; i<26; i++)
		scanf(" %c", &key[i]);
	
	printf("\nenter msg: ");
	scanf("\n");
	gets(msg);
	
	a = strlen(msg);
	
	for(b = 0; b < a; b++)
	{
			if(isalpha(msg[b]))
			{
				if(isupper(msg[b]))
				{
					msg[b] = msg[b] - 65;
					c = msg[b];		
					msg[b] = key[c];
				}
				else
				{
					msg[b] = msg[b] - 97;
					c = msg[b];
					msg[b] = tolower(key[c]);
				}
			}
	}
	
	printf("\n%s", msg);
		
	return 0;
}
