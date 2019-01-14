#include <bits/stdc++.h>

typedef long double ld;

const ld DELTA[13] = {0, 0.057, -0.067, 0.081, 0.025, -0.101, -0.133, 0.251, 0.135, 0.124, -0.131};

ld x[13][26], r[13], r0[13];
int ans_tot, K;
struct P {
	ld x[13];
	P() {for (int i = 0; i <= K; ++i)x[i] = 0;}
	friend ld dis2(const P&a, const P&b) {ld sum = 0; for (int i = 1; i <= K; ++i)sum += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]); return sum;}
	bool operator==(const P&a)const {return dis2(*this, a) <= 1e-7;}
	bool operator<(const P&a)const {for (int i = 1; i <= K; ++i)if (std::abs(a.x[i] - x[i]) > 1e-8)return x[i] < a.x[i]; return x[K] < a.x[K];}
	P operator+(const P&a)const {P tmp; for (int i = 1; i <= K; ++i) tmp.x[i] = x[i] + a.x[i]; return tmp;}
	P operator-(const P&a)const {P tmp; for (int i = 1; i <= K; ++i) tmp.x[i] = x[i] - a.x[i]; return tmp;}
	P operator*(ld p)const {P tmp; for (int i = 1; i <= K; ++i)tmp.x[i] = x[i] * p; return tmp;}
	friend ld dot(const P&a, const P&b) {ld sum = 0; for (int i = 1; i <= K; ++i)sum += b.x[i] * a.x[i]; return sum;}
};
struct Ans {
	P p[13];
	bool operator==(const Ans&ths)const {ld sum = 0; for (int i = 1; i <= K; ++i)sum += dis2(p[i], ths.p[i]); return sum < 1e-6;}
	bool operator<(const Ans&ths)const {for (int i = 1; i <= K; ++i)if (!(p[i] == ths.p[i]))return p[i] < ths.p[i]; return p[K] < ths.p[K];}
} answer[2111];
void work()
{
	P circ[13];
	for (int i = 1; i <= K; ++i)
	{
		double aa;
		for (int j = 1; j <= K; ++j)
		{
			scanf("%lf", &aa);
			circ[i].x[j] = x[i][j] = aa - DELTA[j];
			x[i][j + K] = (i == j);
		}
		scanf("%lf", &aa);
		r0[i] = aa;
	}
	//[X|I]->[I|X^-1]
	for (int i = 1; i <= K; ++i)
	{
		ld max_ = 0;
		int idx = 0;
		for (int j = i; j <= K; ++j)
			if (std::abs(x[j][i]) > max_)
			{
				max_ = std::abs(x[j][i]);
				idx = j;
			}
		if (idx != i)
			for (int j = 1; j <= K + K; ++j)
				std::swap(x[i][j], x[idx][j]);
		for (int j = i + 1; j <= K; ++j)
		{
			ld tmp = x[j][i] / x[i][i];
			for (int k = i; k <= K + K; ++k)
				x[j][k] -= x[i][k] * tmp;
		}
	}
	for (int i = K; i; --i)
	{
		for (int j = K + 1; j <= K + K; ++j)
			x[i][j] /= x[i][i];
		for (int j = 1; j < i; ++j)
			for (int k = K + 1; k <= K + K; ++k)
				x[j][k] -= x[j][i] * x[i][k];
	}
	P ad;
	for (int i = 1; i <= K; ++i)
		for (int j = 1; j <= K; ++j)
		{
			x[i][j] = x[i][j + K];
			x[i][j + K] = 0;
			ad.x[i] += x[i][j];
		}
	/*
		for (int i = 1; i <= K; ++i, puts(""))
			for (int j = 1; j <= K; ++j)
				printf("%lf ", x[i][j]);
	*/
	//a1x1+a2x2+...+aKxK-d=0
	//A: (a1,...,aK)
	//a1^2+a2^2+...+aK^2=1
	//[X][A]-d=[r]
	//[A]=[X^-1][d+[+-r]]
	for (int S = 0; S < 1 << K; S++)
	{
		P ar, a;
		for (int i = 1, T = S; i <= K; ++i, T >>= 1)
			r[i] = r0[i] * (T & 1 ? 1 : -1);
		for (int i = 1; i <= K; ++i)
			for (int j = 1; j <= K; ++j)
				ar.x[i] += x[i][j] * r[j];
		ld A = 0, B = 0, C = -1;
		for (int i = 1; i <= K; ++i)
		{
			A += ad.x[i] * ad.x[i];
			B += 2 * ad.x[i] * ar.x[i];
			C += ar.x[i] * ar.x[i];
		}
		ld D = B * B - 4 * A * C, d;
		if (D < -1e-6)continue;
		if (D < 0)D = 0;
		//add new ans
		d = (-B + sqrt(D)) / 2 / A;
		a = ad * d + ar;
		ans_tot++;
		for (int i = 1; i <= K; ++i)
		{
			P tmp1 = circ[i] + a * r0[i];
			P tmp2 = circ[i] - a * r0[i];
			if (std::min(std::abs(dot(tmp1, a) - d), std::abs(dot(tmp2, a) - d)) > 1e-6)
			{
				ans_tot--;
				break;
			}
			if (std::abs(dot(tmp1, a) - d) < std::abs(dot(tmp2, a) - d))
				answer[ans_tot].p[i] = tmp1;
			else answer[ans_tot].p[i] = tmp2;
		}
		d = (-B - sqrt(D)) / 2 / A;
		a = ad * d + ar;
		ans_tot++;
		for (int i = 1; i <= K; ++i)
		{
			P tmp1 = circ[i] + a * r0[i];
			P tmp2 = circ[i] - a * r0[i];
			if (std::min(std::abs(dot(tmp1, a) - d), std::abs(dot(tmp2, a) - d)) > 1e-6)
			{
				ans_tot--;
				break;
			}
			if (std::abs(dot(tmp1, a) - d) < std::abs(dot(tmp2, a) - d))
				answer[ans_tot].p[i] = tmp1;
			else answer[ans_tot].p[i] = tmp2;
		}
	}
	std::sort(answer + 1, answer + 1 + ans_tot);
	ans_tot = std::unique(answer + 1, answer + 1 + ans_tot) - 1 - answer;
	printf("%d\n", ans_tot);
	for (int i = 1; i <= ans_tot; ++i)
		for (int j = 1; j <= K; ++j, puts(""))
			for (int k = 1; k <= K; ++k)
			{
				double aa = answer[i].p[j].x[k] + DELTA[k];
				if (std::abs(aa) < 1e-6 && aa < 0)aa = -aa;
				printf("%.10lf ", aa);
			}
	puts("");
}

int main(int argc, char const *argv[])
{
	int T;
	for (scanf("%d", &T); T--; work())
		scanf("%d", &K), ans_tot = 0;
	return !puts("by n+e");
}