#include <stdio.h>
#include <math.h>

main () {
	float n;
	
	printf("Digite um n�mero: ");
	scanf(" %f", &n);
	printf("O log de %.2f � %.2f", n, log10(n));
}

