class Solution {
public:
    int fib(int n) {

        if(n<=1){
            return n;
        }
        int lst = fib(n-1);
        int sclst = fib(n-2);

        return lst + sclst;
    }
};