#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ex1 = open("ex1.txt", O_RDONLY);
	int ex1_memcpy = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);

	size_t size = lseek(ex1, 0, SEEK_END);

	ftruncate(ex1_memcpy, size);

	char *addr_ex1 = mmap(NULL, size, PROT_READ, MAP_PRIVATE, ex1, 0);
	char *addr_ex1_memcpy = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, ex1_memcpy, 0);

	memcpy(addr_ex1, addr_ex1_memcpy, size);
	munmap(addr_ex1, size);
	munmap(addr_ex1_memcpy, size);

	close(ex1);
	close(ex1_memcpy);
	return 0;
}
