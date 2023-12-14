#include "shell.h"

/**
 * checkpathcorrection - checks if the command exists
 *
 * @com: command to check
 *
 * Return: command path if it exists
 */
char *checkpathcorrection(const char *com)
{
    char *my_path, *newpath, *commandfull, *folder, *commanddub;
    int folderlength;
    int commandlength = strLen_func(com);
    struct stat buffaya;

    commanddub = strduplicate_func(com);
    my_path = path();
    if (my_path)
    {
        newpath = strduplicate_func(my_path);
        folder = strtok(newpath, ":");
        while (folder != NULL)
        {
            folderlength = strLen_func(folder);
            commandfull = malloc(sizeof(char) * (folderlength + commandlength + 2));
            strcopy_func(commandfull, folder);
            strconcat_func(commandfull, "/");
            strconcat_func(commandfull, commanddub);
            strconcat_func(commandfull, "\0");

            if (stat(commandfull, &buffaya) == 0)
            {
                free(newpath);
                free(commanddub);
                return commandfull;
            }
            else
            {
                free(commandfull);
                folder = strtok(NULL, ":");
            }
        }
        free(newpath);
        free(commanddub);
        return NULL;
    }
    free(commanddub);
    return NULL;
}

/**
 * exitfuncs - exits the shell if only exit provided
 *
 * @exitcommand: array of commands strings
 *
 * Return: -1
 */
int exitfuncs(char **exitcommand)
{
    if (stringcompare_func(exitcommand[0], "exit", 4) == 0)
    {
		long int exitStatus;
		
        if (!exitcommand[1])
        {
            all_command(exitcommand);
            exit(0);
        }

        exitStatus = stringtoint_func(exitcommand[1]);
        if (exitStatus != -1)
        {
            all_command(exitcommand);
            exit(exitStatus);
        }
		else if (stringcompare_func(exitcommand[0], "exit", 4) != 0)
		{
			return (1);
		}
		else
		{
			return (-1);
		}
    }

    return -1;
}
