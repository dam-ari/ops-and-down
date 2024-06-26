#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
	int in, out;
	char* grep_args[] = {"grep", "Villanova", NULL};

	// open input and output files
	in = open("scores", O_RDONLY);
	out = open("out", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWGRP | S_IWUSR);

	// replace standard input with input file
	dup2(in, 0);

	// replace standard output with output file
	dup2(out, 1);

	// close unused file descriptors
	close(in);
	close(out);

	// execute grep
	execvp("grep", grep_args);
}
