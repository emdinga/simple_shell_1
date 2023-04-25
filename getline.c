#include "shell.h"
/**
 * getline_custom - Main function to get new line
 * @get_char: pinter
 * @c: store direction for buffer pointer
 * Return: 0
 */
char *getline_custom(int (*get_char)(void), int c)
{
	char *line = NULL;
	size_t line_len = 0;

	while ((c = get_char()) != EOF && c != '\n')
	{
		if (buf_len + BUFFER_SIZE)
		{
			size_t new_len = line_len + buf_len + 1;

			line = realloc(line, new_len);
			if (!line)
			{
				perror("realloc error");
				return (NULL);
			}
			memcpy(line + line_len, buf, buf_len);
			buf_ptr = buf;
			buf_len = 0;
			line_len += buf_len;
		}
		*buf_ptr++ = c;
		buf_len++;
	}
	if (c == EOF && line_len == 0)
	{
		return (NULL);
	}
	size_t new_len = line_len + buf_len + 1;

	line = realloc(line, new_len);
	if (!line)
	{
		perror("realloc error");
		return (NULL);
	}
	memcpy(line + line_len, buf, buf_len);
	line[line_len + buf_len] = '\n';
	buf_ptr = buf;
	buf_len = 0;
	return (line);
}
