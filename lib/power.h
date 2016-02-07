/*
 * power.h - Biblioteca de Exponenciação em C
 *
 * Data: 07/02/2016
 * Autor: Wolfterro
 *
 */

#ifndef POWER_H
#define POWER_H

double power(int base, int expo) {

	double result = 0;

	if (expo > 0 && base != 0) {
		while (expo > 0) {
			result = base * base;
			expo = expo - 1;
			while (expo > 0) {
				result = result * base;
				expo = expo - 1;
			}
		}

		result = result / base;
	}

	else if (expo == 0 && base != 0) {
		result = 1;
	}

	else if (expo == 0 && base == 0) {
		result = 0.0 / 0.0;
	}

	else if (expo < 0 && base != 0) {
		int expop = expo * -1;
		result = power(base, expop);

		result = 1 / result;
	}

	return result;
}

#endif /* POWER_H */
