#include <iostream>
#include <vector>
#include "AvlTree.h"
#include <algorithm>
#include <random>
 #include <set>
#include <time.h>
using namespace std;


int main()
{
        AvlTree<int> T;
	int a = 50000;
	clock_t start = clock();
	for (int b = 0;  b<a; b++)
	  T.insert(b);
	
      	int k1=10;
	  int k2=100000;
          T.printBetween( k1, k2 );
	  double duration = double(clock()-start)/CLOCKS_PER_SEC;
	  printf("Time:%.7f",duration);
	  cout<<endl;
	 
        return 0;
}
