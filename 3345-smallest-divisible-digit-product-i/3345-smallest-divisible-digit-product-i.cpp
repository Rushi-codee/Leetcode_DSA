class Solution {
    private:
        int getprod(int num ){
            int prod = 1;
            if(num == 0) return 0;
            while(num>0){
                prod*= (num%10);
                num/=10;

            }
            return prod;
        }
public:
    int smallestNumber(int n, int t) {
        int current = n;
        while(true){
            int prod = getprod(current);
            if(t!=0 && prod%t == 0){
                return current;
            }
            current ++;
        }
    }
};