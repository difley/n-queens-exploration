//n-queens Sept 2009
//Questions:  Is there a polynomial time algorithm for finding at least one solution to the n queens problem?  What is the algorithm?
//Can we estimate the number of solutions to the n-queens problem as a function of n?  An analytical expression for the exact number of solutions is desirable.
//Can any n-queens solution be constructed by extending an m-queens solution (where m<n and the m original queens are not moved relative to one another)?

#include <cstdio>
#include <cstdlib>

bool nqueens(const int n, int* a, const bool init);
bool collision(int* a, int i);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <number_of_queens> <guess>\n",argv[0]);
        return 1;
    }
    int n = atoi(argv[1]); 
    if (n < 4) {
        printf("Solutions for number of queens less than 4 are not available in this code\n");
        return 1;
    }
    int* a = new int [n];
    if (argc == 3) {
        nqueens(atoi(argv[2]),a,true);
    }
    if (nqueens(n,a, argc < 3)) {
        if (n < 100){
            for (int j = 0; j < n; j++) {
                for (int k = 0;k < a[j]; k++)
                    printf("*");
                printf("+");
                for (int k = 0;k < n - a[j] - 1; k++)
                    printf("*");
                printf("\n");
            }
        }
        else {
            for (int j = 0;j < n;j++)
                printf("%i ",a[j]);
            printf("\n");
        }
    }
    else {
        printf("No solution to the %i-queens problem\n",n);
    }
    delete[] a;
    return 0;
}

bool nqueens(const int n,int* a,const bool init) {    
    int i = 0;
    if (init) {
        for (int j = 0; j < n; j++) {
            a[j] = 0;
        }
        for (int j = 0; j < n/2; j++) {
            a[j] = 2*j + 1;
        }
    }
    while (true) {
        while (collision(a,i) && (a[i] < n)) {
            a[i] += 1;
        };
        if (a[i] == n) {
            a[i] = 0;
            i -= 1;
            if (i < 0)
                return false;
            a[i] += 1;
        } 
        else {
            i += 1;
            if (i == n)
                return true;
        }
    };
}

bool collision(int* a,int i) {
    for (int j = 0; j < i; j++) {
        if (a[i] == a[j] || (a[i]-a[j] - i + j == 0) || (a[i]-a[j] - j + i == 0))
            return true;
    }
    return false;
}
