#include<stdio.h>
#include<stdlib.h>

int main( int argc , char * argv[] ) {

	char ch = 'a';
	int n = 0 , i = 0;
	int flag = 0;
	scanf("%d\n" , &n);
	while( n-- ) {
		i = 0;	
		flag = 0;
		while((ch = getchar()) != '\n') {
			//printf("ch = %d\n" , ch);
			
			/*while( (ch = getchar()) == '0' );*/
			//printf("AAYA %d" , ch);
			if( i == 0 && ch == '0' )
				continue;
			else
				flag = 1;

			switch(ch) {
				//printf("CASE %d \n" , ch);
				case 'A':
					printf("1010");
					break;
				case 'B':
					printf("1011");
					break;
				case 'C':
					printf("1100");
					break;
				case 'D':
					printf("1101");
					break;
				case 'E':
					printf("1110");
					break;
				case 'F':
					printf("1111");
					break;
				case '0':
					if(i != 0) {
						printf("0000");
					}
					else {
						printf("0");
					}
					break;
				case '1':
					//printf("1 ki case me \n");
					if(i != 0)printf("0001"); else printf("1");
					break;
				case '2':
					if(i != 0)printf("0010"); else printf("10");
					break;
				case '3':
					if(i != 0)printf("0011"); else printf("11");
					break;
				case '4':
					if(i != 0)printf("0100"); else printf("100");
					break;
				case '5':
					if(i != 0)printf("0101"); else printf("101");
					break;
				case '6':
					if(i != 0)printf("0110"); else printf("110");
					break;
				case '7':
					if(i != 0)printf("0111"); else printf("111");
					break;
				case '8':
					printf("1000");
					break;
				case '9':
					printf("1001");
					break;
			}
			if(flag == 1)
				i=1;
		}
		if(i == 0)
			printf("0");
		printf("\n");
	}

	return 0;
}
