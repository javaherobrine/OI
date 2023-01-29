void swap(int &x,int& y){
	int temp=y;
	y=x;
	x=temp;
}
int exgcd(int a,int b,int& s,int& t){//as+bt=gcd(a,b)
	if(a%b){
		int g=exgcd(b,a%b,s,t);
		int p=a/b;
		//gcd(a,b)=gcd(b,a)=gcd(b,a-bp)
		//首先，gcd(a,b)=gcd(b,a)意味着s和t互换了
		swap(s,t);
		//其次，gcd(b,a)=gcd(b,a-bp)意味着解变了，as+bt=(a-bp)s'+bt'
		//这个方程我们找一组可行解
		//a(s-s')+b(t-t'+ps')=0
		//一组解是s=s' t=t'-ps'
		t-=p*s;
		return g;
	}
	//a是b的整数倍，gcd(a,b)=b，一组解是s=0 t=1
	s=0;
	t=1;
	return b;
}
