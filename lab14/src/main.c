#include "lib.h"
/**
 * @file main.c
 * @return успішний код повернення з програми (0).
 * @brief Show the directory.
 * @author Zozulia Igor.
 * @date 07-dec-2020
 * @version 1.0
 */

/**
 * @param directory - directory name;
 * @return успішний код повернення з програми (0).
*/

/**
Function main: call function showFileStruct.
*/

int main()
{
	char *directory = (char *)malloc(256 * sizeof(char));
	printf("%s\n", "Laboratory 14. Author: Zozulia Igor. Show the directory.");
	printf("%s\n", "Enter name of directory using './': ");
	scanf("%256s", directory);
	showFileStruct(directory, 2);
	showSize(directory);
	showCount();
	free(directory);
	return 0;
}
