#include <cstdio>
#include <cstdlib>

FILE *inFile;
FILE *outFile;
FILE *ansFile;
FILE *scoreFile;
FILE *infoFile;
double score;

void ret(double result, const char* info){
	fprintf(infoFile, "%s\n", info);	//Arbiter only allow to read EXACTLY one line info, no less and no more, and must BEFORE score
	fprintf(scoreFile, "%d\n", int(result * score + 0.5));
	exit(0);
}

int main(int argc, char **argv){
	switch(argc){
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
			if(fs)
				fscanf(fs, "%lf", &score);		//Current TUOJ
			else
				sscanf(argv[4], "%lf", &score);	//Lemon and future TUOJ
			scoreFile = fopen(argv[5], "w");
			infoFile = fopen(argv[6], "w");
			break;
	}
	int testcase = 5;
	bool flag1 = true, flag2 = true;
	for (int i = 1; i <= testcase; i++) {
		int a, b, aa, bb;
		if(fscanf(outFile, "%d%d", &a, &b) != 2)
			ret(0, "Can\'t read the integer.");
		fscanf(ansFile, "%d%d", &aa, &bb);
		if (a != aa) flag1 = false;
		if (b != bb) flag2 = false;
	}
	if (flag1 && flag2)
		ret(1, "Correct.");
	else if (flag1 && !flag2) {
		int testid;
		fscanf(ansFile, "%d", &testid);
		if (testid <= 10) 
			ret(0.8, "Partial Correct.");
		else 
			ret(0.6, "Partial Correct.");

	}
	else
		ret(0, "Wrong answer.");
	return 0;
}