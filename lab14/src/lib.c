#include "lib.h"

/**
* @file lib.c
* @brief Realization of function.
* @author Zozulia Igor.
* @date 07-dec-2020
* @version 1.0
*/

/**
 * @param directory - name of directory;
 * @param spaceCount - count of space;
 */

/**
function showFileStruct: show file structure.
*/

void showFileStruct(char *directory, int spaceCount)
{
	DIR *folder;

	folder = opendir(directory);
	if (folder != NULL) {
		struct dirent *entry;
		while ((entry = readdir(folder))) {
			if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
				printf("%*c", spaceCount, ' ');
				printf("%s\n", entry->d_name);
				char *fullIneName = (char *)calloc(strlen(directory) + 1 + strlen(entry->d_name), sizeof(char) + 1);
				strncat(fullIneName, directory, strlen(directory) + strlen(entry->d_name));
				strncat(fullIneName, "/", strlen(directory) + strlen(entry->d_name));
				strncat(fullIneName, entry->d_name, strlen(directory) + strlen(entry->d_name));
				showFileStruct(fullIneName, spaceCount + 2);
				free(fullIneName);
			}
		}
	}

	closedir(folder);
}

void showSize(char *directory)
{
	double sizeOfDir = findDirectorySize(directory);
	sizeOfDir /= 1024.0;
	char *sSizeOfDir = (char *)calloc(256, sizeof(char));
	sprintf(sSizeOfDir, "%3.2f", sizeOfDir);

	for (int i = 0; sSizeOfDir[i] != '.'; i++) {
		if (i > 2)
			sSizeOfDir[i] = '0';
	}

	printf("Size of '%s': %s Kb\n", directory, sSizeOfDir);
	free(sSizeOfDir);
}

double findDirectorySize(char *directory)
{
	double sizeOfDir = 0;

	DIR *folder;
	struct dirent *entry;

	folder = opendir(directory);
	if (folder == NULL) {
		FILE *file;
		file = fopen(directory, "r");

		if (file != NULL) {
			long int sPos = ftell(file);
			fseek(file, 0L, SEEK_END);
			long int sizeOfFile = ftell(file);
			fseek(file, sPos, SEEK_SET);
			sizeOfDir += (float)sizeOfFile;
			fclose(file);
		}
	} else {
		while ((entry = readdir(folder))) {
			if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
				char *fullDirName = (char *)calloc(strlen(directory) + 1 + strlen(entry->d_name), sizeof(char) + 1);
				strcat(fullDirName, directory);
				strcat(fullDirName, "/");
				strcat(fullDirName, entry->d_name);
				sizeOfDir += findDirectorySize(fullDirName);
				free(fullDirName);
			}
		}
	}
	closedir(folder);
	return sizeOfDir;
}
