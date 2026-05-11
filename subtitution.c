#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int h,w,d;
	int j,r,b,i,a = 0,s = 0;
	int c=0, p=0,t, l =0,m,n;
	
	char alphaL[26];
	char alphaU[26];
	char key[26];
	char msg[100];
	char msg1[100];
	char option;
	
	for(h = 0; h < 28;h++)
		printf("=");
	printf("\n");
	for(w=0;w<4;w++)
	{
		printf("| |");
			for(d=0;d<23;d++)
			{
				if(w == 1 && d == 2)
					printf("  Encryption Machine  ");
				else if(w == 2 && d == 2 )
					printf("       Ver. 1.0       ");
				else if(w != 2 && w != 1 && d != 20)
					printf(" ");
			}
		printf("| |\n");
	}
	for(h = 0; h < 28;h++)
		printf("=");
	printf("\n");
	
	do
	{
		printf("\n****** MAIN MENU ******\n");
		printf("[1] Enter key\n");
		printf("[2] Encrypt message\n");
		printf("[3] Decrypt message\n");
		printf("[4] Exit\n");

		printf("\nEnter your choice: ");
		scanf(" %c", &option);
		
		switch(option)
		{
			case '1':
				point:
				printf("\nPlease enter the key: ");
				scanf("\n");
				gets(key);
				s = strlen(key);
				if(strlen(key) < 26 || strlen(key) > 26)
				{
					printf("ERROR: Key must contain 26 characters.\n");
					goto point;
				}
				else
					for(i = 0; i < 26; i++)
					{
						if(i > 0)
						{
							for(r=0;r < i; r++)
								if(key[i] == key[r - 1])
								{
									printf("ERROR: Key must not contain repeated characters.\n");
									goto point;
								}
								else if(!isalpha(key[i]))
								{
									printf("ERROR: Key must contain only alphabetic characters.\n");
									goto point;
								}
						}
					}
				break;
			case '2':
				if(s == 0)
				{
						printf("ERROR: Please enter the key first.\n");
						break;
				}
				else
				printf("\nEnter a plain text (max 100 characters): ");
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
				printf("\nThe cipher text is: %s", msg);
				printf("\n");
				break;
			case '3':
				if(s == 0)
				{
					printf("ERROR: Please enter the key first.\n");
					break;
				}
				else	
				printf("\nEnter a cipher text (max 100 characters): ");
				scanf("\n");
				gets(msg1);
				p = strlen(msg1);
				
				for(m = 0; m < 26;m++)
					alphaU[m] = 65 + m;
				for(n = 0; n < 26; n++)
					alphaL[n] = 97 + n;
					
				for(t = 0; t < p; t++)
				{
					if(isupper(msg1[t]))
					{
						msg1[t] = msg1[t] - 65;
						l = msg1[t];
						msg1[t] = alphaU[l];
					}
					else
					{
						msg1[t] = msg1[t] - 97;
						l = msg[t];
						msg1[t] = alphaL[l];
					}			
				}
				printf("\nThe plain text is: %s", msg1);
				printf("\n");
				break;
			default:
				printf("\nExiting program...");
				return 0;				
		}
		
	}while(option != 4);
	
	return 0;
}
