/*  Defined colors for foreground and background for terminal
    https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

    Examples:
        printf("%s%sTest\n", BOLD, FG_YELLOW);
        printf("%s%sTest\n", BOLD, FG_DISTRO_DEFAULT);
        printf("%sTest\n", RESET);
        printf("%sThis is invisible%s and this is visible\n", HIDDEN_TEXT, RESET_HIDDEN_TEXT);
        printf("%sThis is underlined%s and this is not not underlined\n", UNDERLINE, RESET_UNDERLINE);

*/

// Reset codes
#define RESET                   "\033[0m"       // Reset all
#define FG_DISTRO_DEFAULT       "\033[39m"      // Fallback to distro's default foreground
#define BG_DISTRO_DEFAULT       "\033[49m"      // Fallback to distro's default background

// Color codes
#define FG_BLACK                "\033[30m"
#define BG_BLACK                "\033[40m"
#define FG_RED                  "\033[31m"
#define BG_RED                  "\033[41m"
#define FG_GREEN                "\033[32m"
#define BG_GREEN                "\033[42m"
#define FG_YELLOW               "\033[33m"
#define BG_YELLOW               "\033[43m"
#define FG_BLUE                 "\033[34m"
#define BG_BLUE                 "\033[44m"
#define FG_MAGNETA              "\033[35m"
#define BG_MAGNETA              "\033[45m"
#define FG_CYAN                 "\033[36m"
#define BG_CYAN                 "\033[46m"
#define FG_WHITE                "\033[37m"
#define BG_WHITE                "\033[47m"
#define FG_DEAFLUT_COLOR        "\033[39m"
#define BG_DEAFLUT_COLOR        "\033[49m"
#define FG_BRIGHT_BLACK         "\033[90m"
#define BG_BRIGHT_BLACK         "\033[100m"
#define FG_BRIGHT_RED           "\033[91m"
#define BG_BRIGHT_RED           "\033[101m"
#define FG_BRIGHT_GREEN         "\033[92m"
#define BG_BRIGHT_GREEN         "\033[102m"
#define FG_BRIGHT_YELLOW        "\033[93m"
#define BG_BRIGHT_YELLOW        "\033[103m"
#define FG_BRIGHT_BLUE          "\033[94m"
#define BG_BRIGHT_BLUE          "\033[104m"
#define FG_BRIGHT_MAGNETA       "\033[95m"
#define BG_BRIGHT_MAGNETA       "\033[105m"
#define FG_BRIGHT_CYAN          "\033[96m"
#define BG_BRIGHT_CYAN          "\033[106m"
#define FG_BRIGHT_WHITE         "\033[97m"
#define BG_BRIGHT_WHITE         "\033[107m"

// Graphics mode
#define BOLD                    "\033[1m"       // Bold text
#define RESET_BOLD              "\033[22m"      // Reset bold
#define ITALIC                  "\033[3m"       // Italic text
#define RESET_ITALIC            "\033[23m"      // Reset italic
#define UNDERLINE               "\033[4m"       // Underline mode
#define RESET_UNDERLINE         "\033[24m"      // Reset underline mode
#define BLINKING_MODE           "\033[5m"       // Blinking mode
#define RESET_BLINKING          "\033[25m"      // Reset blinking mode
#define HIDDEN_TEXT             "\033[8m"       // Hidden/invisible mode
#define RESET_HIDDEN_TEXT       "\033[28m"      // Hidden/invisible mode
