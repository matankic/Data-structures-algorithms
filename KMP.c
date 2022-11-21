#include <stdio.h>

int KMP(char *, char *, int *);

int main(){
	char * T = "ABCABAB ABABABAABAC";
	char * P = "ABABAABA";
	int LPS[] = {0, 0, 1, 2, 3, 1, 2, 3};

	int index = KMP(T, P , LPS);
	if (index == -1)
		printf("No match");
	else // Assuming no index OVF
		printf("A match at index %d", index);
	return 0;
}

int KMP(char *TEXT, char *PATTERN, int *LPS){
	int j = 0, i = 0;

	while (PATTERN[j] != '\0' && TEXT[i] != '\0'){
		if (TEXT[i] != PATTERN[j]){
			if (j != 0)
				j = LPS[j-1];
			else
				i++;
		}
		else{
			j++;
			i++;
		}
	}

	if (PATTERN[j] == '\0')
		return i - j;

	// not found
	return -1;
}
