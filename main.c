#include "get_next_line.h"

int main(void)
{
    // Hardcoded file path for testing
    const char *file_path = "test_file.txt";  // Change this to any file you'd like to test

    int fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error: could not open file\n", 27);
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line)
        {
            // Print the line and free the memory allocated for it
            // write(1, "[", 1);
            // write(1, line, ft_strlen(line));
            // write(1, "]", 1);
            printf("[%s]", line);
            free(line);
        }
    }

    close(fd);
    return (0);
}