#include "settings.h"

// <summary>переворачивает введенное значение задом наперед (не по одной цифре)</summary>
// <param name="num">исходное число</param>
// <returns>число в противоположном порядке</returns>
int reverse(int num) {
	static int sum = 0, count_t = 0, count = 0, t = 1, v = 10;
	string str_num = to_string(num);
	int count_recurs = str_num.length();
	if (count_t < count_recurs - 1) {
		count_t++;
		t *= 10;
		reverse(num);
	}
	if (count < count_recurs) {
		count++;
		sum += (num % v) / (v / 10) * t;
		t /= 10;
		v *= 10;
		reverse(num);
	}
	else {
		return sum;
	}
}

// <summary>возводит число в степень</summary>
// <param name="n">число которое нужно возвести в степень</param>
// <param name="d">степень</param>
// <returns>n в степени d</returns>
int degree(int n, int d) {
	if (d == 0) {
		return 1;
	}
	else if (d == 1) {
		return n;
	}
	else {
		return degree(n, d - 1) * n;
	}
}

// <summary>вычисляет сумму всех чисел в диапазоне</summary>
// <param name="a">начало диапазона</param>
// <param name="b">конец диапазона</param>
// <returns>сумму каждого числа между a и b</returns>
int fact_sum(int a, int b) {
	if (b == a) {
		return a;
	}
	else {
		return fact_sum(a, b - 1) + b;
	}
}

// <summary>возвращает все числа от 1 до указанного конца</summary>
// <param name="num">конечное число расчета</param>
// <returns>нумерация от 1 до num</returns>
void plus_one(int num) {
	static int s_num = 1;
	if (num >= 1) {
		if (s_num != num + 1) {
			cout << s_num << " ";
			s_num++;
			plus_one(num);
		}
		else {
			cout << "\n\n";
		}
	}
	else {
		cout << "\n\n";
	}
}

// <summary>выводит все числа в диапазоне в порядке возрастания (если 1 число больше - то в порядке убывания)</summary>
// <param name="n1">начало диапазона</param>
// <param name="n2">конец диапазона</param>
// <returns>каждое число из диапазона в порядке убывания/возрастания</returns>
void numbering(static int n1, static int n2) {
	static int num = n1;
	if (n2 >= n1) {
		if (num != n2 + 1) {
			cout << num << " ";
			num++;
			numbering(n1, n2);
		}
		else {
			cout << "\n\n";
		}
	}
	if (n2 < n1) {
		if (num != n2 - 1) {
			cout << num << " ";
			num--;
			numbering(n1, n2);
		}
		else {
			cout << "\n\n";
		}
	}
}

// <summary>выводит YES если число является степенью 2, в противном случае NO</summary>
// <param name="num">число (предположительная степень)</param>
// <returns>YES (если число является степенью)/NO (если число не является степенью)</returns>
void degree_YN(static int num) {
	if (num > 0 && num != 1) {
		if (num % 2 == 0) {
			if (num == 2) {
				cout << "YES\n\n";
			}
			else {
				num /= 2;
				degree_YN(num);
			}
		}
		else {
			cout << "NO\n\n";
		}
	}
	else if (num == 1) {
		cout << "YES\n\n";
	}
	else {
		cout << "NO\n\n";
	}
}

// <summary>вычисляет сумму всех цифр числа по отдельности</summary>
// <param name="num">число</param>
// <returns>сумма цифр введенного числа</returns>
void sum(static int num) {
	static int summa = 0, first = 10, count = 0;
	summa += (num % first) / (first / 10);
	first *= 10;
	string str_num = to_string(num);
	int count_recurs = str_num.length();
	count += 1;
	if (count != count_recurs) {
		sum(num);
	}
	else {
		cout << summa << "\n\n";
	}
}

// <summary>выводит все цифры числа по отдельности через пробел в обратном порядке</summary>
// <param name="num">изначальное число</param>
// <returns>цифры введенного числа в обратном порядке разделенные пробелами</returns>
void back(int num) {
	static int count = 0, first = 10;
	string str_num = to_string(num);
	int count_recurs = str_num.length();
	if (count != count_recurs) {
		cout << (num % first) / (first / 10) << " ";
		first *= 10;
		count++;
		back(num);
	}
	else {
		cout << "\n\n";
	}
}

// <summary>выводит все цифры числа по отдельности через пробел</summary>
// <param name="num">изначальное число</param>
// <returns>цифры введенного числа разделенные пробелами</returns>
void front(int num) {
	static int count = 0;
	string str_num = to_string(num);
	int count_recurs = str_num.length();
	if (count != count_recurs) {
		cout << str_num[count] << " ";
		count++;
		front(num);
	}
	else {
		cout << "\n\n";
	}
}

int main()
{
	cout << "reverse - " << reverse(1792) << "\n\n";

	cout << "degree - " << degree(3, 4) << "\n\n";

	cout << "sum - " << fact_sum(1, 13) << "\n\n";

	plus_one(10);

	numbering(2, -5);

	degree_YN(64);

	sum(879001);

	back(42487);

	front(42487);

	Sleep(INFINITE);
}