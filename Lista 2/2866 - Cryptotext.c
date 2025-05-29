#include <stdio.h>
#include <stdlib.h>

int is_lower(char ch);
size_t get_len(const char* str);
int invert_string(char* src, char* dest, size_t size);
int strrev(char* str);

int main()
{
    int bufsize = 50;   // input buffer for all stdin chars
	char buf[bufsize];  // auxiliary buffer for storing lowercase chars

	int test_count;
	fgets(buf, bufsize, stdin);
	test_count = atoi(buf);

	char auxbuf[bufsize];

	for(int c=1; c<=test_count; c++) {
		fgets(buf, bufsize, stdin);
		
		for (int j=0,k=0; j<bufsize; j++) {
			if (is_lower(buf[j]))
				auxbuf[k++] = buf[j];

			if (buf[j] == '\0') {
				auxbuf[k] = '\0';
				break;
			}
		}
		strrev(auxbuf);
		printf("%s\n", auxbuf);
	}
	
	return 0;
}

int is_lower(char ch)
{
	return ch >= 97 && ch <= 122;
}

size_t get_len(const char* str)
{
	size_t c=0;
	while (str[c++] != '\0');
	
	return c;
}

int strrev(char* str)
{
    size_t i = 0;
    size_t j = get_len(str) - 2; // Securing against reading NULL character first
    
    while (i < j){
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
    
    str[get_len(str) - 1] = '\0'; // Securing against creating unterminated strings
    
    return 0;
}