#include <iostream>

const long long M = 1e9 + 7;
long long q;

struct Number{
    long long a, b;

    inline Number(long long aa = 0, long long bb = 0){
        a = aa;
        b = bb;
    }

    void operator*=(Number oth){
        long long aa = a * oth.a + (b * oth.b % M) * q;
        long long bb = a * oth.b + b * oth.a;
        a = aa % M;
        b = bb % M;
    }
};

Number power(Number nmb, int k){
    Number ans(1, 0);

    while(k){
        if(k % 2) ans *= nmb;
        nmb *= nmb;
        k /= 2;
    }

    return ans;
}

int z;
Number nmb;
int k;

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> z;
    while(z--){
        std::cin >> nmb.a >> nmb.b >> q >> k;
        nmb = power(nmb, k);
        std::cout << nmb.a << " " << nmb.b << "\n";
    }

    return 0;
}