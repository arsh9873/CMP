//add s1 and s2 and just return the ans
//will assume s1 is the bigger one
string add(string s1,string s2){
	string ans = "";
	int n1=s1.size(),n2=s2.size();
	if(n2>n1){
		string temp = s1;
		s1=s2;
		s2=temp;
		n1=s1.size();
		n2=s2.size();
	} 
	int p1,p2;
	p1=n1-1;
	p2=n2-1;
	int carry = 0;
	while(p1>=0){
		int sum;
		if(p2>=0){
			sum = (s1[p1]-'0')+(s2[p2]-'0')+0;
			sum+=carry;
			carry=sum/10;
			ans+=to_string(sum%10);
			p2--;
		}
		else {
			sum = (s1[p1]-'0')+0;
			sum+=carry;
			carry=sum/10;
			ans+=to_string(sum%10);	
		}
		p1--;
	}
	if(carry) ans+=to_string(carry);
	reverse(ans.begin(),ans.end());
	return ans;
}
//just doing a very big num * 1 digit
// just do 1 by 1
string mul(string s1,int m){
	int n=s1.size()-1;
	int carry=0;
	string ans = "";
	for(int i=n;i>=0;i--){
		int p = (s1[i]-'0')*m;
		p+=carry;
		carry = p/10;
		ans+=to_string(p%10);
	}
	if(carry) 	ans+=to_string(carry);
	reverse(ans.begin(),ans.end());
	return ans;
}


void solve(){
	string s1,s2;
	cin>>s1>>s2;
	int n1=s1.size(),n2=s2.size();
	vector<string> table;
	if(n1<=17){
		for(int i=1;i<=9;i++){
			table.push_back(to_string(stoull(s1)*i*1ULL));
		}
	} 
	else {
		for(int i=1;i<=9;i++){
			table.push_back(mul(s1,i));
		}
	}

	int ten=0;
	string ans="";
	for(int i=n2-1;i>=0;i--){
		string temp="";
		if(s2[i]!='0'){
			temp = table[(int)(s2[i]-'0')-1];
		}
		for(int j=0;j<ten;j++){
			temp+="0"; //appending the 0's
		}
		ans = add(temp,ans);
		ten++;
	}
	cout<<ans;
}	
