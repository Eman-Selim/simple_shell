#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcnt1.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>

/*  buffers sizes */
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/* chain macros */
#define CMD_CHAIN 3
#define CMD_OR    1
#define CMD_NORM  0
#define CMD_AND   2

/* case and signconverting indication */
#define CONVERT_UNSIGNED    2
#define CONVERT_LOWERCASE   1

/* getline indication */
#define USE_STRTOK     0
#define USE_GETLINE    0

#define HIST_MAX       4096
#define HIST_FILE      ".simple_shell_history"

extern char **environ;

