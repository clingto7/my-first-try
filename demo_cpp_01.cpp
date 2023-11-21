#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
double power(double x, int n) { //get power
	double value = 1.0;
	while (n--)
		value = value * x;
	return value;
}
double power(int x, int n) {
	int value = 1;
	while (n--)
		value = value * x;
	return value;
}
double arctanx(double x) {    //arctanx
	double a = 0.000000000000001;
		double value = 0;
		for (int i = 1; i >= 1; i++) {
			if (power(x, 2 * i - 1) /( 2 * i - 1) >a)
				value += power(-1, i+1) * power(x, 2 * i - 1) / (2 * i - 1);
			else
				break;
		}
		return value;

	}
int accu(int n) {   //阶乘
	int value = 1;
	for (int i = 1; i <= n; i++)
		value *= i;
	return value;

}
double sinx(double x) {    //sinx
	double a = 0.0000000001;
	double value = 0;
	for (int i = 1; i >= 1; i++) {
		if (power(x, 2 * i - 1) / accu(2 * i - 1) >= a)
			value += power(-1, i + 1) * power(x, 2 * i - 1) / accu(2 * i - 1);
		else
			break;
	}
	return value;

}int powerplus(int x,int y) {   //平方和
	int powersum;
	powersum = power(x, 2) + power(y, 2);
	return powersum;


}
int multiply(int a, int b) {          //multiply
	int multiple;
	multiple = a * b;
	return multiple;
}
double PI(double a=1/239.0) {                  //Pi
	double Pi;           
	Pi = 16 * arctanx(0.2) - 4 * arctanx(a);
	//cout << "Pi=" << Pi << endl;
	return Pi;
}
bool symm(unsigned n) {          //symmetric
	unsigned i = n;
	unsigned m = 0;
	while (i > 0) {
		m = m * 10 + i % 10;
		i /= 10;
	}
	return m == n;
}
unsigned fac(unsigned n) {         //solve n!
	unsigned f;
	if (n == 0)
		f = 1;
	else
		f = fac(n - 1) * n;
	return f;
}
int sum(int n) {                //求和
	int m;
	if (n == 1)
		m = 1;
	else
		m = sum(n - 1) + n;
	return m;

}
int fibonacci(int n) {       //fibonacci
	int m, p = n - 2;
	if (n == 1 || n == 2)
		m = 1;
	else
		m = fibonacci(n - 1) + fibonacci(n - 2);
	return m;
}
int P_n(int n, int x) {      //勒让德多项式
	int m;
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else if (n > 1) {
		m = ((2 * n - 1) * x * P_n(n - 1, x) - (n - 1) * P_n(n - 2, x)) / n;
		return m;

	}
class Clock {
public:
	Clock(int newH, int newM, int newS,int newMON,int newD);
	Clock();
    void showtime();
	void setime(int H,int M,int S);
	void setime(int MON, int DAY);
	void showdate();
private:
	int hour, minute, second, month, day;
};
Clock::Clock (int newH， int newM, int newS,int newMON,int newD) :hour(newH), minute(newM), 
second(newS),month(newMON),day(newD) {
	
}


inline  void Clock::showtime()
{
	cout << "the time is " << hour << ":" << minute << ":" << second << endl;
}
inline void Clock::showdate() {
	cout << "today is " << month << "th month " << day << "th day" << endl;
}
void Clock::setime(int H,int M,int S) {
	
	hour = H;
	minute = M;
	second = S;
}
void Clock::setime(int MON, int DAY) {
	month = MON;
	day = DAY;
}
class circle {
public:
	circle(double R);
	double getC();
	double getS();
private:
	double r;
};
double circle::getC() {
	double C;
	C = PI() * 2 * r;
	return C;
}
double circle::getS() {
	double S;
	S = PI() * r * r;
	return S;
}
circle::circle(double R) :r(R) {

}
int main() {

	/*double r, s;
	double k;
	cout << "please enter your r and s" << endl;
	cin >> r>>s;
	if (power(r, 2) <= power(s, 2))
		k = sqrt(power(sinx(r), 2) + power(sinx(s), 2));
	else
		k = sinx(r * s) / 2;
	cout << "k=" << k << endl;
	cout << sinx(Pi/2) << endl;*/
	/*int flag = 1, n = 2, b = 2;
	while (n <= 100) {
		int k = sqrt(n);
		while (b <= k) {
			if (n % b == 0) {
				flag = 0;
				break;
			}
			b++;

		}
		if (flag == 1)
			cout << n<<" is zhi" << endl;
		n++;
	}*/
	cout << PI() << endl << sinx(PI() / 2) << endl;
	double radius;
	cout << "please enter the radius" << endl;
	cin >> radius;
	circle pool(radius);
	circle road(radius + 3);
	cout << "the price of the fence is " << road.getC() * 35 << endl;
	cout << "the price of the road is " << (road.getS() - pool.getS()) * 20 << endl;
	
	system("pause");
    return 0;
}