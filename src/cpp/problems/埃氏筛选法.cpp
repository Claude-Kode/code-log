bool st[1000001] ;// false质数 true合数
                  //这个数组的下标就是数字（代表你要判断是不是素数的数字）   
int prime[1000001];//专门装已经判断成素数的数字
int m ;//比如题里说 “求1到m有几个素数？”
cin >> m ;
int count = 0 ;//素数的个数，可以用来当下标，题里要是求那更好了
for ( int i = 2 ; i <= m ; i ++ ) {
	if( !st[i] ) prime[count++] = i ;//false说明已经是素数，存到prime里面
	for ( int p : prime ) {
		if ( ( i * p ) > m ) break ;//相乘爆范围就break，换下一个i接着乘
		st[i*p] = true ;//乘完一定是合数，把他标记成合数
	}
}
