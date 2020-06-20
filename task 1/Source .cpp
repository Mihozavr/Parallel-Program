
#include <iostream>
#include <math.h>

double eps = 0.00001;


double fun_xy(double x, double y) {
	return (cos(x) + cos(y));
}



double fun_D(double x, double y) {
	double d;
	if ((x * x + y * y) < 1.0) d = 1.0;
	else d = 0.0;
	return d;
}


double calc_integral_1D(double x, double y1, double y2, int ny) {
	double sum = 0;
	double dy = (y2 - y1) / ny;
	for (int iy = 0; iy < ny; iy++) {
		double y = y1 + iy * dy + dy * .5; // central
		double f = fun_xy(x, y); 
		double d = fun_D(x, y);
		sum += f * d * dy;
	}
	return sum;
}


double calc_integral(double x1, double x2, double y1, double y2, int nx, int ny) {
	double dx = (x2 - x1) / nx;
	double sum = 0;
	for (int ix = 0; ix < nx; ix++) {


		double x = x1 + ix * dx + dx * .5; // central
		double integral_1D = calc_integral_1D(x, y1, y2, ny);
		sum += integral_1D * dx;

	}
	return sum;
}


int main(int argc, char** argv) {
	

	double x1, x2, y1, y2;
	x1 = -1;
	x2 = 1;
	y1 = -1;
	y2 = 1;
	

	double check_sum = calc_integral(x1, x2, y1, y2, 1000, 1000);
	std::cout << " check = " << check_sum << std::endl;
	return 0;

}

