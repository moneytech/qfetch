#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define CYAN    "\e[46m"
#define MAGENTA "\e[45m"
#define GREY    "\e[47m"
#define BLACK   "\e[40m"

#define CYAN_FG    "\e[36m"
#define MAGENTA_FG "\e[35m"

#define RESET   "\e[0m"

char hostname[1024]; // So we don't use 1 KiB of stack for a hostname.

int main(void) {
    // User and host.
    char *username = getpwuid(geteuid())->pw_name;
    gethostname(hostname, 1024);

    // Dashes.
    size_t dashes = strlen(username) + 1 + strlen(hostname);

    printf("    %s                                         %s\n", CYAN, RESET);
    printf("    %s                                         %s\n", CYAN, RESET);
    printf("    %s                                         %s\n", CYAN, RESET);
    printf("    %s      %s                             %s      %s\t%s%s%s@%s%s%s\n", CYAN, MAGENTA, CYAN, RESET, CYAN_FG, username, RESET, MAGENTA_FG, hostname, RESET);
    printf("    %s      %s                             %s %s     %s\t", CYAN, MAGENTA, BLACK, CYAN, RESET); for (size_t i=0; i<dashes; i++) putchar('-'); putchar('\n');
    printf("    %s      %s                             %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s                   %s     %s %s     %s\tOS: qword\n", CYAN, MAGENTA, BLACK, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s                  %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s        %s     %s     %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, GREY, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s     %s %s        %s     %s %s    %s     %s %s     %s\n", CYAN, MAGENTA, BLACK, CYAN, GREY, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s              %s     %s          %s %s     %s\n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s              %s     %s          %s %s     %s\n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s      %s              %s     %s          %s %s     %s\n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s       %s             %s     %s           %s     %s\n", CYAN, BLACK, GREY, BLACK, CYAN, RESET);
    printf("    %s                    %s     %s %s               %s\n", CYAN, GREY, BLACK, CYAN, RESET);
    printf("    %s                     %s     %s               %s\n", CYAN, BLACK, CYAN, RESET);
    printf("    %s                                         %s\n", CYAN, RESET);
    return 0;
}

/*
    printf("    %s                                     %s            \n", CYAN, RESET);
    printf("    %s                                     %s            \n", CYAN, RESET);
    printf("    %s                                     %s            \n", CYAN, RESET);
    printf("    %s                                     %s            \n", CYAN, RESET);
    printf("    %s    %s                             %s    %s        \n", CYAN, MAGENTA, CYAN, RESET);
    printf("    %s    %s                             %s %s   %s      \n", CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s                             %s %s   %s      \n", CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s                   %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s                  %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s        %s     %s     %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, GREY, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s     %s %s        %s     %s %s    %s     %s %s   %s\n", CYAN, MAGENTA, BLACK, CYAN, GREY, BLACK, CYAN, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s              %s     %s          %s %s   %s      \n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s              %s     %s          %s %s   %s      \n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s    %s              %s     %s          %s %s   %s      \n", CYAN, MAGENTA, GREY, MAGENTA, BLACK, CYAN, RESET);
    printf("    %s     %s             %s     %s           %s   %s\n", CYAN, BLACK, GREY, BLACK, CYAN, RESET);
    printf("    %s                  %s     %s %s             %s\n", CYAN, GREY, BLACK, CYAN, RESET);
    printf("    %s                   %s     %s             %s\n", CYAN, BLACK, CYAN, RESET);
    printf("    %s                                     %s            \n", CYAN, RESET);
    printf("    %s                                     %s            \n", CYAN, RESET); */
