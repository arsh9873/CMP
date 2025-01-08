// TC is log(min(a,b)), as a%b is <= a/2(when a>=b)
// so halving every time
// always assumes a>=b, this is also why we swap, to 
// maintain this
int gcd(int a,int b){
	// what I am trying to reach
	if(b==0) return a;
	return gcd(b,a%b);
	// b is >=a%b so it goes first, a%b is just repeated
	// addition and gcd(a-b,b)=gcd(a,b) so this works

}
