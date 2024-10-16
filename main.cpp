


#include <iostream>
using namespace std;

int main(void)
{
	const double c = 299792458; // Speed of light in vacuum
	const double G = 6.674e-11; // Gravitational constant
	const double M = 1e41; // Galactic bulge mass

	const double start_distance = 6.1495e19; // Galactic bulge radius
	const double end_distance = start_distance*c;// 1e21; // just past the solar radius

	double v = sqrt(G * M / start_distance); // Speed with dark matter

	const size_t resolution = 1000;

	const double step_size = (end_distance - start_distance) / (resolution - 1);

	for (double r = start_distance; r <= end_distance; r += step_size)
	{
		const double v_N = sqrt(G * M / r); // Speed without dark matter

		if (v < v_N)
			v = v_N;

		const double D = 3.0 - log(v / v_N) / log(c);
		//const double D2 = 3.0 - log(pow(v / v_N, 1.0 / log(c)));

		const double G_a = v * v * r / M;

		cout << r << " " << G_a << endl;

//		cout << r << " " << D << endl;

	}

	return 0;
}