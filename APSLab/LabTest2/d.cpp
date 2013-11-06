#include <iostream>
#include <cstdio>
#include <list>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

int compar(const void * a , const void * b) {
        int x = *(int *)a;
        int y = *(int *)b;
        return y-x;
}

int main( int argc , char * argv[] ) {

	int n , m;

	scanf("%d%d" , &n , &m );

        int * degree = new int[n];

        memset( degree , 0 , sizeof(int) * n);

	for ( int i = 0 ; i < m ; i++ ) {
		int a,b;
		scanf("%d%d" , &a , &b);

		degree[a-1] ++;
                degree[b-1] ++;
		
	}

        qsort(degree , n , sizeof(int) , compar);

        if ( degree[0] == n-1 && degree[1] == 1 ) {
                /*int not_star = 0;
                for ( int i = 1 ; i < n ; i++) {
                        if ( degree[i] != 1 ) {
                                not_star = 1;
                                break;
                        }
                }
                if ( not_star == 0 ) {
                        cout << "star topology\n";
                        return 0;
                }*/
                cout << "star topology";
                return 0;
        }
        if ( degree[0] == degree[n-1] && degree[0] == 2 ) {
                /*int not_ring = 0;
                for ( int i = 0 ; i < n-1 ; i++) {
                        if ( degree[i] != degree[i+1] ) {
                                not_ring = 1;
                                break;
                        }
                }
                if ( not_ring == 0 ) {
                        cout << "ring topology\n";
                        return 0;
                }*/
                cout << "ring topology";
                return 0;
        }
        if ( (degree[n-1] == degree[n-2]) && degree[n-1] == 1 && degree[0] == 2 ) {
                /*int not_bus = 0;
                for ( int i = 0 ; i < n-2 ; i++) {
                        if ( degree[i] != 2 ) {
                                not_bus = 1;
                                break;
                        }
                }
                if ( not_bus == 0 ) {
                        cout << "bus topology\n";
                        return 0;
                }*/
                        cout << "bus topology";
                        return 0;
        }


        /*for ( int i = 0 ; i < n ; i++) {
                cout << degree[i] << " ";
        }
        cout << endl;
        
	return 0;*/
        cout << "unknown topology";
        return 0;
}
