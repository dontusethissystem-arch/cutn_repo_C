/*

*/

#ifndef FACT_H
#define FACT_H

long long __factorial(int __n){
	if (__n == 0) return 1;
	long long __fact = 1;
	while(__n > 0){
		__fact = __fact * (n);
		--__n;
	}
	return __fact;
}
#endif
