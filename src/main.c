#include <stdio.h>
#include "util.h"
#include "stretchy_buffer.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return -1;
	}
	// we dont need to do anything else to find the length, because its already 1 charcter, 1 byte = 1 character.
	u32 src_size = 0;
	char* src = read_entire_file(argv[1], &src_size);
	
	// Start the lexing process.
	char* tok_chars = 0;

	for (int i = 0; i < src_size; i++)
	{
		sb_push(tok_chars, src[i]);
		printf("%s\n", tok_chars);
	}

	sb_free(tok_chars);
	
	return 0;
}