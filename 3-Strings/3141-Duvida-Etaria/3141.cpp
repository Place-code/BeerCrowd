#include <cstdio>
#include <cstring>

int main() {
    char name[51];
	int date[6];
	fgets(name, 51, stdin);
	name[strcspn(name, "\n")] = '\0';
	scanf ("%d/%d/%d\n%d/%d/%d", &date[0], &date[1], &date[2], &date[3], &date[4], &date[5]);
	if (date[0] == date[3] && date[1] == date[4]) {
	    printf ("Feliz aniversario!\n");
	}
	if (date[1] == date[4] && date[0] < date[3] || date[1] < date[4]) {
	    printf ("Voce tem %d anos %s.\n", date[2] - date[5] - 1, name);
	}
	else {
	    printf ("Voce tem %d anos %s.\n", date[2] - date[5], name);
	}
	
	
	return 0;
}