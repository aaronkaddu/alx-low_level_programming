#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the file name
 * @letters: the number of letters it should read and print
 *
 * Return: the actual nb of letters it should read and print,
 * 0 if file cannot be opened or read
 * 0 if file name is NULL
 * 0 if write fails or doesnt write the expected amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff = NULL;
	int fd;
	ssize_t to_read;
	ssize_t to_write;

	/* open file in read only */
	if (!(filename && letters))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);
	/* read the file */
	to_read = read(fd, buff, letters);
	close(fd);
	if (to_read < 0)
	{
		free(buff);
		return (0);
	}
	if (!to_read)
		to_read = letters;
	to_write = write(STDOUT_FILENO, buff, to_read);
	free(buff);

	if (to_write < 0)
		return (0);

	return (to_write);


}
