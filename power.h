#ifndef POWER_H
#define POWER_H

long long power(int base, int exp) {
	if (base == 0 && exp == 0) return 1;
	if (base == 0)	return 0;
	if (exp == 0) return 1;
	int e = 1;
	for (int _ = 1; _ <= exp; _++)
		e = e * base;
	return base;
}

long long power_recursive(int base, int exp){
	if (base == 0 && exp == 0) return 1;
	if (base == 0) 	return 0;
	if (exp  == 0)	return 1;

	return base * power_recursive(base, exp-1);
}

#endif
