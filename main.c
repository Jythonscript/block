#include <stdio.h>
#include <stdlib.h>

//constants
#define STARTBUFSIZE 100

//globals
char *buf;
unsigned long int bufsize;

//functions
void copyStdin();
unsigned long int getLongestLineLength();
void padBuf(unsigned long int n, const char pad);

int main() {

	buf = (char *) malloc(STARTBUFSIZE);
	bufsize = STARTBUFSIZE;
	copyStdin();
	//printf("%ld\n", getLongestLineLength());
	padBuf(getLongestLineLength(), ' ');

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
	buf[numchars] = '\0';
	//printf("memory allocated: %ld bytes\n", bufsize);
	//printf("'''%s'''\n", buf);
}

//return length of longest line in buf
unsigned long int getLongestLineLength() {
	
	unsigned long int maxlen = 0;
	unsigned long int currentlen = 0;

	unsigned long int index = 0;
	for (index = 0; buf[index] != '\0' && buf[index] != EOF; index++) {

		//printf("%ld\t%ld\n", currentlen, maxlen);
		if (buf[index] == '\n' || buf[index] == '\0' || buf[index] == EOF) {
			if (currentlen >= maxlen) {
				maxlen = currentlen;
			}
			currentlen = 0;
		}
		else {
			currentlen++;
		}
	} //end for
	if (buf[index] == '\n' || buf[index] == '\0' || buf[index] == EOF) {
		if (currentlen >= maxlen) {
			maxlen = currentlen;
		}
	}

	return maxlen;
}

//print buf with lines padded with n chars
void padBuf(unsigned long int n, const char pad) {
	
	//current character
	char c;
	//iterate through the whole buffer
	unsigned long int i = 0;
	//number of characters in the current line
	unsigned long int count = 0;

	//TODO - double-check bounds
	while ((c = buf[i]) != '\0') {
		if (c == '\n' ) {
			for (; count < n; count++) {
				putchar(pad);
			}
			putchar('\n');
			count = 0;
		}
		else {
			putchar(c);
			count++;
		}
		i++;
	}
	
}
