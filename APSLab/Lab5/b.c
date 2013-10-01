#include<stdio.h>

struct stack_t {
	int stack[500000];
	int top;
};

int is_empty( struct stack_t * s ) {
	if ( s->top > -1 ) {
		return 0;
	}
	return 1;
}

int get_top ( struct stack_t * s ) {
	return s->stack[ s->top ];
}

void init ( struct stack_t * s ) {
	s->top = -1;
}

int main ( int argc , char * argv[] ) {

	struct stack_t s;

	int temp , _top , first_ele;
	long int i , size , t;
	long long int count;

	scanf ("%ld" , &t );

	while ( t-- ) {
		
		scanf("%ld" , &size );

		count = 0;
		init ( &s );

		for ( i = 0 ; i < size ; i++ ) {

			scanf ( "%d" , &first_ele ); 

			while ( (!is_empty(&s))  && first_ele > get_top ( &s ) ) {

				temp = get_top ( &s );
				_top = s.top ;

				while ( !is_empty( &s ) && ( temp == get_top( &s ) )) {
					count += size -1 - i;
					s.top --;
				}
				
				if ( ! is_empty( &s ) ) {
					count += ( _top - s.top ) * ( s.top );
				}
			}

			s.stack[++s.top] = first_ele;
		}
		
		while ( !is_empty( &s ) ) {

			temp = get_top ( &s );
			_top = s.top;

			while ( !is_empty( &s ) && ( temp == get_top ( &s ) ) )
				s.top --;	
			
			if ( !is_empty( &s ) )
				count += ( _top - s.top ) * ( s.top );
		}
		
		printf("%lld\n" , count);
		
	}

	return 0;
}
