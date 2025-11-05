#include <stdbool.h>
#include <stdio.h>
#include <time.h>

void set_time(const struct tm* time)
{
    printf("%d:%d:%d\n", time->tm_hour, time->tm_min, time->tm_sec);
}

int main() {
    struct tm current_time = {
        .tm_hour = 12,
        .tm_min = 24,
        .tm_sec = 56,
    };
    set_time(&current_time);
}