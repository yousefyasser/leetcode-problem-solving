class Solution {
public:
    vector<bool> primes;
    
    int countPrimes(int n) {
        primes = vector<bool>(n, true);
        sieve();
        
        int primesLessThanN = 0;
        for(int i = 2; i < n; i++){
            if(primes[i])  
                primesLessThanN++;
        }
        
        return primesLessThanN;
    }
    
    void sieve(){
        for(int i = 2; i < primes.size(); i++){
            if(!primes[i])
                continue;
            
            for(int j = 2*i; j < primes.size(); j += i){
                primes[j] = false;
            }
        }
    }
};