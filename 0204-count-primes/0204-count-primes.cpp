class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        
        int primesLessThanN = 0;
        for(int i = 2; i < primes.size(); i++){
            if(!primes[i])
                continue;
            
            primesLessThanN++;
            for(int j = 2*i; j < primes.size(); j += i){
                primes[j] = false;
            }
        }
        
        return primesLessThanN;
    }
};