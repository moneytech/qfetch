#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define CYAN    "\e[46m"
#define MAGENTA "\e[45m"
#define GREY    "\e[47m"
#define BLACK   "\e[40m"

#define CYAN_CHAR    'c'
#define MAGENTA_CHAR 'y'
#define GREY_CHAR    'W'
#define BLACK_CHAR   'N'

#define CYAN_FG    "\e[36m"
#define MAGENTA_FG "\e[35m"

#define RESET   "\e[0m"

void img_printf(const char* img, const char* message, ...);
void cpuid(unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx);

// Logo.
const char* line1 = "   cccccccccccccccccccccccccccccccccccccccccc    ";
const char* line2 = "   cccccccccccccccccccccccccccccccccccccccccc    ";
const char* line3 = "   cccccccccccccccccccccccccccccccccccccccccc    ";
const char* line4 = "   ccccccyyyyyyyyyyyyyyyyyyyyyyyyyyyyyycccccc    ";
const char* line5 = "   ccccccyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyNccccc    ";
const char* line6 = "   ccccccyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyNccccc    ";
const char* line7 = "   ccccccyyyyyNNNNNNNNNNNNNNNNNNNNyyyyyNccccc    ";
const char* line8 = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* line9 = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* lineA = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* lineB = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* lineC = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* lineD = "   ccccccyyyyyNcccccccccccccccccccyyyyyNccccc    ";
const char* lineE = "   ccccccyyyyyNcccccccccWWWWWcccccyyyyyNccccc    ";
const char* lineF = "   ccccccyyyyyNcccccccccWWWWWNccccyyyyyNccccc    ";
const char* lineG = "   ccccccyyyyyyyyyyyyyyyWWWWWyyyyyyyyyyNccccc    ";
const char* lineH = "   ccccccyyyyyyyyyyyyyyyWWWWWyyyyyyyyyyNccccc    ";
const char* lineI = "   ccccccyyyyyyyyyyyyyyyWWWWWyyyyyyyyyyNccccc    ";
const char* lineJ = "   cccccccNNNNNNNNNNNNNNWWWWWNNNNNNNNNNNccccc    ";
const char* lineK = "   cccccccccccccccccccccWWWWWNccccccccccccccc    ";
const char* lineL = "   cccccccccccccccccccccNNNNNNccccccccccccccc    ";
const char* lineM = "   cccccccccccccccccccccccccccccccccccccccccc    ";

char hostname[1024] = {0}; // So we don't use 1 KiB of stack for a hostname.
char dashes[1024]   = {0}; // Ditto.

int main(void) {
    // User and host.
    char* username = getpwuid(geteuid())->pw_name;
    gethostname(hostname, 1024);

    // Dashes
    size_t dashes_length = strlen(username) + strlen(hostname) + 1;

    for (size_t i = 0; i != dashes_length; i++)
        strcat(dashes, "-");

    // Terminal.
    char* tty_name = ttyname(STDIN_FILENO);

    // Shell detection.
    char* shell = getpwuid(geteuid())->pw_shell;

    // Print the info and logo.
    img_printf(line1, "");
    img_printf(line2, "");
    img_printf(line3, "");
    img_printf(line4, "%s%s%s@%s%s%s", CYAN_FG, username, RESET, MAGENTA_FG, hostname, RESET);
    img_printf(line5, "%s", dashes);
    img_printf(line6, "");
    img_printf(line7, "%sOS%s: qword", MAGENTA_FG, RESET);
    img_printf(line8, "%sTerminal%s: %s", MAGENTA_FG, RESET, tty_name);
    img_printf(line9, "%sShell%s: %s", MAGENTA_FG, RESET, shell);
    img_printf(lineA, "%sResolution%s: %s", MAGENTA_FG, RESET, "Unknown");
    img_printf(lineB, "%sCPU%s: %s", MAGENTA_FG, RESET, "Generic x86_64");
    img_printf(lineC, "%sGPU%s: %s", MAGENTA_FG, RESET, "Generic VESA device");
    img_printf(lineD, "");
    img_printf(lineE, "");
    img_printf(lineF, "");
    img_printf(lineG, "");
    img_printf(lineH, "");
    img_printf(lineI, "");
    img_printf(lineJ, "");
    img_printf(lineK, "");
    img_printf(lineL, "");
    img_printf(lineM, "");

    return 0;
}

void img_printf(const char* img, const char* message, ...) {
    va_list args;

    va_start(args, message);

    for (size_t i = 0; img[i]; i++) {
        switch (img[i]) {
            case CYAN_CHAR:
                printf("%s %s", CYAN, RESET);
                break;
            case MAGENTA_CHAR:
                printf("%s %s", MAGENTA, RESET);
                break;
            case GREY_CHAR:
                printf("%s %s", GREY, RESET);
                break;
            case BLACK_CHAR:
                printf("%s %s", BLACK, RESET);
                break;
            default:
                putchar(img[i]);
        }
    }

    vprintf(message, args);
    putchar('\n');
    va_end(args);
}
