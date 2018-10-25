#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

typedef struct {
	ino_t num;
	char names[128];
	nlink_t nLinks;
} EntryFile;

EntryFile newFileEntry(ino_t num, char *name) {
	EntryFile entry;
	entry.num = num;
	strcpy(entry.names, name);
	entry.nLinks = 1;
	return entry;
}

int main() {
	DIR *tmpDir = opendir("tmp");

	struct dirent *dirEntry;
	struct stat entryStat;
	EntryFile entries[128];
	unsigned int entryCount = 0;

    
	while ((dirEntry = readdir(tmpDir))) {
		char fileName[32];
		strcpy(fileName, "tmp/");
		strcat(fileName, dirEntry->d_name);

		char fl = 0;
		for (int i = 0; i < entryCount; ++i) {
			if (entries[i].num == entryStat.st_ino) {
				strcat(strcat(entries[i].names, ", "), dirEntry->d_name);
				entries[i].nLinks++;
				fl = 1;
				break;
			}
		}
		if (!fl) {
			if (entryCount >= 128) {
				return EAGAIN;
			}
			entries[entryCount] = newFileEntry(entryStat.st_ino, dirEntry->d_name);
			entryCount++;
		}
	}
	closedir(tmpDir);

	FILE *outFile = fopen("ex4.txt", "w");
	for (int j = 0; j < entryCount; ++j) {
		if (entries[j].nLinks > 1) {
			fprintf(outFile, "%lu have %lu link: ", entries[j].num, entries[j].nLinks);
			fprintf(outFile, "%s\n", entries[j].names);
		}
	}
	fclose(outFile);

	return 0;
}
