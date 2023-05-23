#include "shell.h"

/**
 * free_string_array - Frees a string array and its contents
 * @array: The string array to free
 */
void free_string_array(char **array)
{
    size_t i;
    if (array)
    {
        for (i = 0; array[i]; i++)
        {
            free(array[i]);
        }
        free(array);
    }
}

/**
 * create_string_array - Creates a string array from a linked list
 * @head: The head of the linked list
 * Return: The created string array
 */
char **create_string_array(list_t *head)
{
    size_t size = 0;
    list_t *node = head;
    char **array = NULL;
    size_t i;
    while (node)
    {
        size++;
        node = node->next;
    }

    array = malloc((size + 1) * sizeof(char *));
    if (!array)
        return NULL;

    node = head;
    for (i = 0; i < size; i++)
    {
        array[i] = _strdup(node->str);
        if (!array[i])
        {
            free_string_array(array);
            return NULL;
        }
        node = node->next;
    }

    array[size] = NULL;

    return array;
}

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: The string array copy of the environ
 */
char **get_environ(info_t *info)
{
        char **environ_copy;

        if (!info->environ || info->env_changed)
        {
                free_string_array(info->environ);
                environ_copy = create_string_array(info->env);
                info->environ = environ_copy;
                info->env_changed = 0;
        }

        return info->environ;
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The string env var property
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
        list_t *node = info->env;
        size_t i = 0;
        char *p;

        if (!node || !var)
                return 0;

        while (node)
        {
                p = starts_with(node->str, var);
                if (p && *p == '=')
                {
                        info->env_changed = delete_node_at_index(&(info->env), i);
                        i = 0;
                        node = info->env;
                        continue;
                }
                node = node->next;
                i++;
        }
        return info->env_changed;
}

/**
 * _setenv - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: The string env var property
 * @value: The string env var value
 * Return: 0 on success, 1 on failure
 */
int _setenv(info_t *info, char *var, char *value)
{
        char *new_env;
        list_t *node;
        char *p;

        if (!var || !value)
                return 1;

        new_env = malloc(_strlen(var) + _strlen(value) + 2);
        if (!new_env)
                return 1;
        _strcpy(new_env, var);
        _strcat(new_env, "=");
        _strcat(new_env, value);

        node = info->env;
        while (node)
        {
                p = starts_with(node->str, var);
                if (p && *p == '=')
                {
                        free(node->str);
                        node->str = new_env;
                        info->env_changed = 1;
                        return 0;
                }
                node = node->next;
        }

        add_node_end(&(info->env), new_env, 0);
        info->env_changed = 1;
        return 0;
}

