#include <iostream>
#include <vector>

////////Алгоритм Евклида 
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int q, r;
	while (b > 0)
	{
		q = a / b;
		r = a % b;
		a = b; b = r;
	}
	return a;
}

////////Расширенный алгоритм Евклида 
int gcdex(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	int x1(0), y1(1), x2(1), y2(0);
	int r, q;
	while (b > 0)
	{
		q = a / b;
		r = a % b;
		x = x2 - q * x1;
		y = y2 - q * y1;
		a = b; b = r;
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;
	}
	x = x2; y = y2;
	return a;
}

////////Обратный элемент a кольца по модулю n
void inverse(int a, int n)
{
	int x, y;
	if (gcdex(a, n, x, y) == 1)
		std::cout << x << std::endl;
	else
		std::cout << "inverse element doesn't exist" << std::endl;
}

////////Итераторы
template <typename T>
void swap(T &a, T &b)
{
	T c(a);
	a = b;
	b = c;
}

template <typename T>
void rotate(T begin, T end, int k)
{
	int difference = end - begin;
	if (begin != end--)
	{
		if (k > 0)
		{
			for (size_t i = 1; i <= k % difference; i++)
			{
				T temp(begin);
				while (begin != end)
				{
					swap(*begin++, *end);
				}
				begin = temp;
			}
		}
		else if (k < 0)
		{
			for (size_t i = 1; i <= abs(k) % difference; i++)
			{
				T temp(end);
				while (begin != end)
				{
					swap(*begin, *end--);
				}
				end = temp;
			}
		}
	}
}

int main()
{
	int k;
	std::cin >> k;
	int n = 15;
	int *a = new int[n];
	for (size_t i = 0; i < n; i++)
		a[i] = i + 1;
	for (size_t i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	rotate(a + 0, a + n, k);
	for (size_t i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	std::vector<double> c(6);
	for (size_t i = 0; i < 6; i++)
		c[i] = i + 1;
	for (const auto &d : c)
		std::cout << d << " ";
	std::cout << std::endl;
	rotate(c.begin(), c.end(), k);
	for (const auto &d : c)
		std::cout << d << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}