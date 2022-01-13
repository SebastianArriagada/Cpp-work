
// constructing vectors
#include <iostream>
#include <vector>

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int *leavesWay;

    leavesWay = (int*)malloc((X + 2)*sizeof(int));

    int totalLeaves = A.size();

    int position = 0;

    for( int time = 0; time < (totalLeaves);  time++ ){

        leavesWay[ A[time] ] = 1;


        while (leavesWay[ position + 1 ] == 1){
            
            position += 1;

            if (position == X){
                free(leavesWay);
                return time;
            }
        }
    }

    return -1;

}

/*

Correctness: 100%
Performance: 100%
Total score: 100%

Detected time complexity:
O(N)

expand allExample tests

example test✔OK

expand allCorrectness tests

simple test✔OK
single element✔OK
frog never across the river✔OK
3 random permutation, X = 50✔OK
5 random permutation, X = 60✔OK
all leaves in the same place✔OK

expand allPerformance tests
6 and 2 random permutations, X = ~5,000✔OK
arithmetic sequences, X = 5,000✔OK
10 and 100 random permutation, X = ~10,000✔OK
permutation tests✔OK
arithmetic sequences, X = 30,000✔OK

*/