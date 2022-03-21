 // Jan Zakrzewski - algorytm szybkiego potegowania

typedef unsigned long long u64;

// szybkie potegowanie
u64 pow(u64 a, u64 k, u64 M) {
    u64 ans = 1;
    while(k) {
        if(k % 2) ans = ans * a % M;
        a = a * a % M;
        k /= 2;
    }
    return ans;
}

inline void __fib_combine(u64 f[3], const u64 g[3], u64 M) {
    u64 sth[3];
    sth[0] = f[0] * g[0];
    sth[1] = f[1] * g[1];
    sth[2] = f[2] * g[2];
    f[0] = (sth[0] + sth[1])         % M;
    f[1] = (sth[2] - sth[0] + M * M) % M;
    f[2] = (sth[1] + sth[2])         % M;
}

// liczby fibonacciego (bez macierzy)
u64 fib1(u64 k, u64 M) {
    // note: M can be max 3 037 000 500
    u64 ans[3] = {1, 0, 1};
    u64 xyz[3] = {0, 1, 1};
    while(k) {
        if(k % 2) __fib_combine(ans, xyz, M);
        __fib_combine(xyz, xyz, M);
        k /= 2;
    }
    return ans[1];
}

// operacje na macierzach 2 x 2
inline void mov_matrix2d(u64 A[2][2], u64 B[2][2]) {
    A[0][0] = B[0][0];
    A[0][1] = B[0][1];
    A[1][0] = B[1][0];
    A[1][1] = B[1][1];
}
inline void add_matrix2d(u64 A[2][2], u64 B[2][2]) {
    A[0][0] += B[0][0];
    A[0][1] += B[0][1];
    A[1][0] += B[1][0];
    A[1][1] += B[1][1];
}
inline void mul_matrix2d(u64 A[2][2], u64 B[2][2]) {
    u64 Z[2][2];
    Z[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    Z[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    Z[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    Z[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    mov_matrix2d(A, Z);
}
inline void mod_matrix2d(u64 A[2][2], u64 M) {
    A[0][0] %= M;
    A[0][1] %= M;
    A[1][0] %= M;
    A[1][1] %= M;
}

//liczby fibonacciego (z uzyciem macierzy)
u64 fib(u64 k, u64 M) {    
    u64 ans[2][2] = {{1, 0}, {0, 1}};
    u64 mat[2][2] = {{1, 1}, {1, 0}};
    while(k) {
        if(k % 2) {
            mul_matrix2d(ans, mat);
            mod_matrix2d(ans, M);
        }
        mul_matrix2d(mat, mat);
        mod_matrix2d(mat, M);
        k /= 2;
    }
    return ans[1][0];
}