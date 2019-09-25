#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[99],b[99];
	printf("digite  a primeira string:\n");
	scanf(" %[^\n]s",a);
	printf("digite  segunda string:\n");
	scanf(" %[^\n]s",b);

	//printf("%s\n%s",a,b);
	printf("\n");

	int ta,tb;
	ta=strlen(a);
	tb=strlen(b);
	int i,j, c=0,x;
	for(i=0;i<tb;i++){
		if(b[i]==a[0]){
			
			for(j=0;j<tb;j++){
				if(b[i++]==a[j])
					c++;
				else{
					if(c==ta){
						printf("A está contido em B\n");
						x=1;
						break;
					}
					else
						c=0;
				}
			}
		}
		if(x==1)
			break;

	}
	int c2=0,x2;
	for(i=0;i<ta;i++){
		if(a[i]==b[0]){
			for(j=0;j<ta;j++){
				if(a[i++]==b[j])
					c2++;
				else{
					if(c==tb){
						printf("B está contido em A\n");
						x2=1;
						break;
					}
					else
						c2=0;
				}
			}
		}
		if(x2==1)
			break;

	}
	if((c!=ta)&&(c2!=tb)){
		printf("As strings são incompativeis\n");
	}
}
