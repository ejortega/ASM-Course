// Function prototypes
extern "C"
{
    size_t first_func(char *, char, size_t);
    size_t second_func(char *, char *, size_t);
    size_t third_func(char *);
}

#define PRINT_COLOR(x) "\x1b[" x "m"
#define COLOR_NORMAL PRINT_COLOR("0")
#define COLOR_RED PRINT_COLOR("31")
#define COLOR_GREEN PRINT_COLOR("32")

#define printf_color(fmt, args...)             \
    do                                         \
    {                                          \
        printf(fmt "\n" COLOR_NORMAL, ##args); \
    } while (0)

#define success(fmt, args...)                  \
    do                                         \
    {                                          \
        printf_color(COLOR_GREEN fmt, ##args); \
    } while (0)

#define danger(fmt, args...)                 \
    do                                       \
    {                                        \
        printf_color(COLOR_RED fmt, ##args); \
    } while (0)

// Macro for checking equality
// Macro for checking equality
#define EQ(x, y)                                                                  \
    do                                                                            \
    {                                                                             \
        if (x == y)                                                               \
            success("[*] Success! Values are equal!\n");                          \
        else                                                                      \
            danger("[x] Test Failed! Value %u does not match value %u!\n", x, y); \
    } while (0)

#define EQ_C(x, y)                                                                \
    do                                                                            \
    {                                                                             \
        if (x == y)                                                               \
            success("[*] Success! Values are equal!\n");                          \
        else                                                                      \
            danger("[x] Test Failed! Value %c does not match value %c!\n", x, y); \
    } while (0)
