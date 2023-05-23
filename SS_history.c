#include "shell.h"

/**
 * get_history_file - this function construct path to the history file
 * @info: parameter struct containing potential argument
 * Return: 0 if successful
 */
char *get_history_file(info_t *info)
{
    char *buf, *dir;

    dir = _getenv(info, "HOME=");
    if (!dir)
        return NULL;

    buf = malloc(sizeof(char) * (strlen(dir) + strlen(HIST_FILE) + 2));
    if (!buf)
    {
        free(dir);
        return NULL;
    }

    sprintf(buf, "%s/%s", dir, HIST_FILE);
    free(dir);
    return buf;
}

/**
 * write_history - this function write the cmd history to a file
 * @info: the parameter struct containing potential argument
 * Return: 1 if successful
 */
int write_history(info_t *info)
{
    int ret = -1;
    FILE *file;
    char *filename = get_history_file(info);
    list_t *node;

    if (!filename)
        return -1;

    file = fopen(filename, "w");
    free(filename);
    if (!file)
        return -1;

    for (node = info->history; node; node = node->next)
    {
        fprintf(file, "%s\n", node->str);
    }

    if (fclose(file) == 0)
        ret = 1;

    return ret;
}
/**
 * read_history - this function read the cmd history from a file
 * @info: the parameter struct containing potential argument
 * Return: 0 if successful
 */
int read_history(info_t *info)
{
    int linecount = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file;
    char *filename = get_history_file(info);

    if (!filename)
        return 0;

    file = fopen(filename, "r");
    free(filename);
    if (!file)
        return 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        build_history_list(info, line, linecount++);
    }

    free(line);

    if (fclose(file) != 0)
        return 0;

    info->histcount = linecount;
    while (info->histcount >= HIST_MAX)
        delete_node_at_index(&(info->history), 0);

    renumber_history(info);

    return info->histcount;
}
/**
 * build_history_list - this function adds entry to a history linked list
 * @info: function parameter of a Structure containing potential argument
 * @buf: parameter showing a buffer
 * @linecount: parameter of the history linecount, histcount
 * Return: 0 if zero
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
    list_t *node = malloc(sizeof(list_t));

    if (!node)
        return 0;

    node->str = strdup(buf);
    node->num = linecount;
    node->next = NULL;

    if (!info->history)
    {
        info->history = node;
    }
    else
    {
        list_t *current = info->history;
        while (current->next)
            current = current->next;
        current->next = node;
    }

    return 1;
}
/**
 * renumber_history - this function renumbers the history linked list changes
 * @info: function parameter Structure containing potential arguments.
 * Return: 0 if successful
 */
int renumber_history(info_t *info)
{
    list_t *node = info->history;
    int i = 0;

    while (node)
    {
        node->num = i++;
        node = node->next;
    }

    info->histcount = i;

    return info->histcount;
}

