class Solution {
public:
    int concatenatedBinaryFast(int n){ //very fast using binary opperations
        const int modulo = 1e9 + 7;
        long res = 0; //int and unsigned int has unexpected bahvior
        int bit_len = 0;

        for(int i = 1 ; i <= n; i++){
            if( (i & (i - 1)) == 0) //when nr is a power of 2, ex 01, 010, 0100 so we dont compute bit length for all nrs
                bit_len++;
            res = (res << bit_len) % modulo; //left-shift of bits of res, ex 01 -> 0100 if len=2, also works like pow of 2
            res = (res | i) % modulo; //concatenates
        }

        return res;
    }

    int concatenatedBinarySlow(int n) { //works for small test cases
        const int modulo = 1e9 + 7;

        long long res = 0, bin_pos = 0;
        for(int i = n; i > 0; i--){
            res += mod_mult(i, mod_pow(bin_pos, modulo), modulo) % modulo;
            bin_pos += bin_len(i);

        }

        return res % modulo;
    }

    int bin_len(int x){
        int len = 1;
        while( x >>= 1) //bit right-shift (divide by 2)
            len++;
        return len;
    }

    int mod_mult(int x, int mult, int modulo){
        int s = 0;
        while(x--){
            s += mult;
            s = s % modulo;
        }
        return s;
    }

    int mod_pow(int power, int modulo){
        int res = 1;
        while(power--){
            res *= 2;
            res = res % modulo;
        }
        return res;
    }

};