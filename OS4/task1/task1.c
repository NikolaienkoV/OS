#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]) {
	if (argc == 4) {
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		double c = atof(argv[3]);

		double d = pow(b, 2) - 4 * a * c;
		if (d < 0) printf("Discriminant is negative\n");
		else {
			double x1 = ((-b) + sqrt(d)) / 2;
			double x2 = ((-b) - sqrt(d)) / 2;
			printf("Equation\t %.1lfx^2+(%.1lfx)+(%.1lf) = 0\nx1 = %.1lf\tx2 = %.1lf\n", a, b, c, x1, x2);
		}
	}
	else {
		printf("Arguments are set incorrectly\n");
	}


	return EXIT_SUCCESS;
}
