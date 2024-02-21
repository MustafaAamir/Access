#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc != 3) { 
		printf("Usage: %s -mode filename\n", argv[0]); 
		return 1;
	}
	int mode = 0;
	char *option = argv[1];
	if (option[0] != '-') {
		printf("Invalid mode option: %s\n", option);
		return 1;
	}
	for (int i = 1; option[i] != '\0'; i++) {
		switch (option[i]) {
			case 'r':
				mode |= R_OK;
				break;
			case 'w':
				mode |= W_OK;
				break;
			case 'f':
				mode |= F_OK;
				break;
			case 'x':
				mode |= X_OK;
				break;
			default: 
				printf("Unknown option: %s\n", option);
				break;
		}
	}
	char *file = argv[2];
	if (access(file, mode) == 0) {
		printf("Access granted: %s\n", file);
	}
	else {
		printf("Access Denied: %s\n", file);
	}
	return 0;
}
