#include <stdio.h>
#include <stdlib.h>

#define STARTBUFSIZE 100

char *buf;
unsigned long int bufsize;

void copyStdin();
unsigned long int getLongestLineLength();

int main() {

	buf = (char *) malloc(STARTBUFSIZE);
	bufsize = STARTBUFSIZE;
	copyStdin();
	//puts(buf);
	printf("%ld\n", getLongestLineLength());

	return 0;
}

//copy stdin to buf, dynamically allocating more memory as needed
void copyStdin() {
	
	unsigned long int numchars = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (numchars >= (bufsize - 1)) {
			bufsize *= 2;
			buf = realloc(buf, bufsize * 2);
		}
		buf[numchars] = c;
		numchars++;
	}
	//printf("memory allocated: %ld bytes\n", bufsize);
	//printf("'''%s'''\n", buf);
}

//return length of longest line in buf
unsigned long int getLongestLineLength() {
	
	unsigned long int maxlen = 0;
	unsigned long int currentlen = 0;

	puts(buf);

	unsigned long int index = 0;
	for (index = 0; buf[index] != EOF; index++) {
		putchar(buf[index]);
	}
	return maxlen;
}
