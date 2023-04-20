#include "shell.h"

char *get_path_location(char *command)
{
  char *pth, *pth_cp, *pth_tok, *file_pth;
  int cmd_len, dir_len;
  struct stat buff;


  pth = getenv("PATH");

  if (pth)
    {
      pth_cp = strdup(pth);

      cmd_len = strlen(command);

      pth_tok = strtok(pth_cp, ":");

      while (pth_tok != NULL)
	{
	  dir_len = strlen(pth_tok);

	  file_pth = malloc(cmd_len + dir_len + 2);

	  strcpy(file_pth, pth_tok);

	  strcat(file_pth, "/");

	  strcat(file_pth, command);

	  strcat(file_pth, "\0");

	  if (stat(file_pth, &buff) == 0)
	    {
	      free(pth_cp);

	      return (file_pth);
	    }
	    else
	    {
	     free(file_pth);

	     pth_tok = strtok(NULL, ":");

	    }

	    }

	  free(pth_cp);

	  if (stat(command, &buff) == 0)
	    {
	      return (command);

	    }

	    return (NULL);

	    }

	  return (NULL);
}
