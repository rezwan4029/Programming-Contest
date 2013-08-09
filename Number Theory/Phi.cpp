ll  phi ( ll  n ) {
	ll  i,res = n ;
	for (  i = 2 ; i * i <= n ; ++ i )
		if ( n % i == 0 ) {
			while ( n % i == 0 )
				n /= i ;
			res -= res / i ;
		}
	if ( n > 1 ) res -= res / n ;
	return res ;
}


Euler's phi function Or Euler Totient the totient of a positive integer n is defined to be
the number of positive integers less than or equal to n that are coprime to n.
return number of fractions of n

For example, the set of all basic fractions with denominator 12, before reduction to lowest terms, is

0 , 1 , 2 , 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12
-   -   -   -  -  -  -  -  -  -  -    -  -
12  12  12  12 12 12 12 12 12 12 12  12  12

Reduction yields

0 , 1 , 1 , 1, 1, 5, 1, 7, 2 ,3, 5, 11,
-   -   -   -  -  -  -  -  -  -  -    -  1
12  12  6   4  3  12 2 12  3  4  6  12

Hence there are only the following 4 irreducible basic fractions with denominator 12
1 , 5 ,7 ,11
-   -  -  --
12  12 12 12