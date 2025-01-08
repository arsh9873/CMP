// TC: sqrt(x)/logx, we are only iterating through the 
// primes, and we are only iterating the for loop till 
// sqrt(x). The tc is because from 1 to n there are 
// sqrt(n)/logn primes. So we are going to sqrt(x) hence
// the numerator and we are only doing on primes hence
// divide by logx
vector<int> prime_factors(int x){
	vector<int> ret;
	// needs a precomputed list of primes to work
	for(int p:primes){
		if(p*p>x){
			if(x>1){
				ret.push_back(x);
				//x=1;//to exit out the main loop, could use break as well
				break;
			}
		} else {
			while(x%p == 0){
				ret.push_back(p);
				x = x/p;
			}
		}
	}
	return ret;
}
