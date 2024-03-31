#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

static int handle_error(int input_file, int output_file, char *message){
	perror(message);
	close(input_file);
	close(output_file);
	return 1;
}

int is_block_zero(char *block, int size) {
	for (int i = 0; i < size; i++){
		if (block[i] != 0)
			return 0;
	}
	return 1;
}

void create_sparse_file(int input_file, int output_file, int block_size){
	char *block = malloc(block_size);
	if (block == NULL){
		handle_error(input_file, output_file, "Memory allocation error");
		return;
	}
	
	while (block_size = read(input_file, block, block_size)) {
		if (errno){
			handle_error(input_file, output_file, "Reading from input error");
			break;
		}
		if (is_block_zero(block, block_size)){
			lseek(output_file, block_size, SEEK_CUR);
			if (errno){
				handle_error(input_file, output_file, "lseek error");
				break;
			}
		}
		else {
			write(output_file, block, block_size);
			if (errno){
				handle_error(input_file, output_file, "Writing in output file error");
				break;
			}
		}
	}
	
	free(block);
}

int main(int argc, char *argv[]){
	int input_file = 0;
	int output_file;
	
	int block_size = 4096;
	
	if (argc > 2) {
		input_file = open(argv[1], O_RDONLY);
		output_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		if (argc == 4){
			block_size = atoi(argv[3]);
			if (block_size < 0)
				return handle_error(input_file, output_file, "Wrong block size");
		}
	}
	else {
		output_file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		if (argc < 2) {
			printf("Not enough arguments\n");
			return 0;
		}
	}
	if (errno)
		return handle_error(input_file, output_file, "Opening file error");
		
	create_sparse_file(input_file, output_file, block_size);
	close(input_file);
	close(output_file);
	
	return 0;
}
