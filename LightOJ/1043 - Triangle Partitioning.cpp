#include <iostream>
#include <stdio.h>

using namespace std;

double abs(double num1, double num2)
{
	if (num1 >= num2)
		return (num1 - num2);
	return (num2 - num1);
}

double sqrt(double num)
{
	if (num > 0){
		double x = num;
		for (int i = 0; i <= 20; i++){
			x = (x + (num / x)) / 2;
		}
		return x;
	}
	return 0;
}

double TriangleRatio(double ab, double ac, double bc, double ad)
{
	double ae, de, s1, s2, ratio;

	ae = (ad*ac) / ab;
	de = (ad*bc) / ab;

	s1 = (ab + bc + ac) / 2.0;
	s2 = (ad + de + ae) / 2.0;

	double bigTriangle = sqrt(s1*(s1 - ab)*(s1 - bc)*(s1 - ac));
	double smallTriangle = sqrt(s2*(s2 - ad)*(s2 - de)*(s2 - ae));
	double rectangle = bigTriangle - smallTriangle;
	ratio = smallTriangle / rectangle;

	return ratio;
}

double bs(double ab, double ac, double bc, double ratio)
{
	double high, low, ad;
	double prev_ad = 0.0;
	low = 0.0;
	high = ab;
	while (true){
		ad = (high + low) / 2.0;
		if (TriangleRatio(ab, ac, bc, ad) > ratio)
			high = ad;
		else
			low = ad;

		if (abs(prev_ad, ad) <= 0.0000001)
			break;

		prev_ad = ad;
	}
	return ad;
}

int main()
{
	int tc;
	double ab, ac, bc, ratio, ans;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i++){
		scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &ratio);
		ans = bs(ab, ac, bc, ratio);
		ans = (int)(ans * 1000000);
		ans /= 1000000;
		printf("Case %d: %.6lf\n", i, ans);
	}

	return 0;
}