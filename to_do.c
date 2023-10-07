#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task
{
    char *description;
    int completed;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *description)
{
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->description = (char *)malloc(strlen(description) + 1); // Allocate memory for description
    strcpy(new_task->description, description);                      // Copy the input string
    new_task->completed = 0;
    new_task->next = head;
    head = new_task;
}

void print_tasks()
{
    Task *temp = head;
    while (temp != NULL)
    {
        printf("%s\n", temp->description);
        temp = temp->next;
    }
}

void complete_task(char *description)
{
    Task *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->description, description) == 0)
        {
            temp->completed = 1;
            break;
        }
        temp = temp->next;
    }
}

void remove_task(char *description)
{
    Task *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->description, description) == 0)
        {
            if (prev != NULL)
            {
                prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            free(temp->description); // Free memory for the description
            free(temp);              // Free memory for the task
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main()
{
    char command[100], description[100];
    while (1)
    {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0)
        {
            printf("Enter task description: ");
            scanf("%s", description);
            add_task(description);
        }
        else if (strcmp(command, "print") == 0)
        {
            print_tasks();
        }
        else if (strcmp(command, "complete") == 0)
        {
            printf("Enter task description: ");
            scanf("%s", description);
            complete_task(description);
        }
        else if (strcmp(command, "remove") == 0)
        {
            printf("Enter task description: ");
            scanf("%s", description);
            remove_task(description);
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    // Clean up: Free all allocated memory
    while (head != NULL)
    {
        Task *temp = head;
        head = head->next;
        free(temp->description);
        free(temp);
    }

    return 0;
}
