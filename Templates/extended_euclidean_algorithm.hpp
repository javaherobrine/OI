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
		//���ȣ�gcd(a,b)=gcd(b,a)��ζ��s��t������
		swap(s,t);
		//��Σ�gcd(b,a)=gcd(b,a-bp)��ζ�Ž���ˣ�as+bt=(a-bp)s'+bt'
		//�������������һ����н�
		//a(s-s')+b(t-t'+ps')=0
		//һ�����s=s' t=t'-ps'
		t-=p*s;
		return g;
	}
	//a��b����������gcd(a,b)=b��һ�����s=0 t=1
	s=0;
	t=1;
	return b;
}
