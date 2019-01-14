#include <bits/stdc++.h>
#include "testlib.h"

typedef double ld;

FILE *inFile;
FILE *outFile;
FILE *ansFile;
FILE *scoreFile;
FILE *infoFile;
std::string message;
double score;

int T, K, time_, vis[2111], ans_tot, out_tot, cor_tot;
struct P {
	ld x[13];
	P() {for (int i = 0; i <= K; ++i)x[i] = 0;}
	friend ld dis2(const P&a, const P&b) {ld sum = 0; for (int i = 1; i <= K; ++i)sum += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]); return sum;}
};
struct Ans {
	P p[13];
	bool operator==(const Ans&ths)const {
		ld sum = 0; for (int i = 1; i <= K; ++i)sum += dis2(p[i], ths.p[i]);
		return sum < 1e-12;
	}
} answer[2111], now;

double Judge()
{
	double sum = 0;
	int all_right = 1, all_wrong = 1;
	fscanf(inFile, "%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		time_++; cor_tot = 0;
		//inFile
		fscanf(inFile, "%d", &K);
		for (int j = 1; j <= K; ++j)
			for (int k = 0; k <= K; ++k)
				fscanf(inFile, "%*lf");
		//ansFile
		fscanf(ansFile, "%d", &ans_tot);
		for (int i = 1; i <= ans_tot; ++i)
		{
			for (int j = 1; j <= K; ++j)
				for (int k = 1; k <= K; ++k)
					fscanf(ansFile, "%lf", &answer[i].p[j].x[k]);
		}
		//outFile
		char tot_tmp[100];
		fscanf(outFile, "%s", tot_tmp);
		if (strstr(tot_tmp, ".") || strstr(tot_tmp, "-"))
		{
			message = "Your number of answers is illegal!";
			return 0;
		}
		out_tot = std::atoi(tot_tmp);
		if (out_tot < 0 || out_tot > 2 * ans_tot)
		{
			message = "Your number of answers is out of range!";
			return 0;
		}
		for (; out_tot--;)
		{
			for (int i = 1; i <= K; ++i)
			{
				for (int j = 1; j <= K; ++j)
				{
					if (fscanf(outFile, "%lf", &now.p[i].x[j]) != 1 || !std::isfinite(now.p[i].x[j]))
					{
						message = "Invalid number (NaN, Inf, ...)";
						return 0;
					}
				}
			}
			for (int i = 1; i <= ans_tot; ++i)
				if (vis[i] != time_ && now == answer[i])
				{
					vis[i] = time_;
					cor_tot++;
					break;
				}
		}
		if (cor_tot > 0)
			all_wrong = 0;
		if (cor_tot < ans_tot)
			all_right = 0;
		//calc rate_i
		double rate = 1.*cor_tot / ans_tot;
		sum += sqrt(rate);
	}
	double score;
	fscanf(ansFile,"%lf",&score);
	if (all_wrong)
		return 0;
	if (all_right)
		return 1;
	int res = round(sum * score / T);
	if (res == 0)res++;
	else if (res == score)res--;
	return 1.*res/score;
}

void ret(double result, const char* info){
	fprintf(infoFile, "%s\n", info);	//Arbiter only allow to read EXACTLY one line info, no less and no more, and must BEFORE score
	fprintf(scoreFile, "%.6f\n", result * score);
	exit(0);
}

int main(int argc, char **argv) {
	switch (argc) {
	case 4:		//Arbiter
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		scoreFile = infoFile = fopen("/tmp/_eval.score", "w");
		score = 10;
		break;
	case 5:		//Tsinsen OJ
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		scoreFile = fopen(argv[4], "w");
		infoFile = fopen("tmp", "w");		//Tsinsen doesn't use this file
		score = 1;
		break;
	case 7:		//Lemon and TUOJ
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		FILE *fs = fopen(argv[4], "r");
		if (fs)
			fscanf(fs, "%lf", &score);		//Current TUOJ
		else
			sscanf(argv[4], "%lf", &score);	//Lemon and future TUOJ
		scoreFile = fopen(argv[5], "w");
		infoFile = fopen(argv[6], "w");
		break;
	}
	ret(Judge(), message.c_str());
	return 0;
}
