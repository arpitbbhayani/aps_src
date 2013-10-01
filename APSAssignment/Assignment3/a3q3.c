#include <stdio.h>

int readline ( char *str , int * all_9) {
	int i = 1;
	char ch;
	while ( ( ch = getchar() ) != '\n' ) {
		str[i] = ch;
		if ( str[i] != '9' )
			*all_9 = 0;
		i++;
	}
	str[0] = '0';
	str[i] = 0;
	return i;
}

int main ( int argc , char * argv[] ) {

	int t , len = 0 , i = 0 ;
	char array[1000010];
	int carry = 0;
	int a , b;
	int all_9 = 1;

	scanf("%d" , &t);
	getchar();

	while ( t-- ) {

		len = readline ( array , &all_9 );

		if ( all_9 == 1 ) {
			printf("1");
			for ( i = 1 ; i < len-1 ; i++ ) {
				printf("0");
			}
			printf("1\n");
			continue;
		}

		carry = 0;

		int mid = ((len+1)/2) - 1;

		a = mid;
		b = len - a;

		while ( a > 0 && b < len && array[a] == array[b] ) {
			a--;
			b++;
		}

		int flag = 0;
		if ( (array[a]-'0') < (array[b]-'0') || a == 0) {
			flag = 1;
		}

		for ( i = mid ; i > 0 ; i-- ) {
			a = i;
			b = len - i;
			array[b] = array[a];
		}

		if ( flag == 1 ) {
			carry = 1;
			if ( (len-1) & 1 ) {
				array[mid+1] = (array[mid+1] - '0') + carry + '0';
				carry = (array[mid+1] - '0') / 10;
				array[mid+1] = ((array[mid+1] - '0') % 10) + '0';
			}
			for ( i = mid ;  i > 0 ; i -- ) {
				int _a = i;
				int _b = len - i;
				array[_a] = (array[_a] - '0') + carry + '0';
				carry = (array[_a] - '0') / 10;
				array[_a] = ((array[_a] - '0') % 10) + '0';
				array[_b] = array[_a];
				if ( carry == 0 ) 
					break;
			}
		}

		if ( carry == 1 ) {
			array[0] = '1';
			array[len - 1 ] = '1';
		}

		array[len] = '\0';
		if ( array[0] != '0' ) 
			printf("%s\n" , array );
		else
			printf("%s\n" , &array[1]);
		//for ( i = 1 ; i < len ; i++ ) {
		//	printf("%d" , array[i]);
		//}
		//printf("\n");
	}

	return 0;
}
