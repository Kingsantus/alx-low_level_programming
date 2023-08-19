#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char username[20];
	char password[20];

	if (argc != 2)
	{
		printf("Usage: %s <username>\n", argv[0]);
		return (1);
	}

	strcpy(username, argv[1]);
	printf("Enter password: ");
	fgets(password, sizeof(password), stdin);
	password[strcspn(password, "\n")] = '\0';

	if (strcmp(username, "julien") == 0 && strcmp(password, "javascript") == 0)
	{
		printf("Congrats!.\n");
	}
	else
	{
		printf("Segmentation fault (core dumped)\n");
	}

	return (0);
}
