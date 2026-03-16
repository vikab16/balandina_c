#include <stdio.h>

int main() {
    long long seconds;
    if (scanf("%lld", &seconds) != 1) return 0;

    seconds %= 86400;
    if (seconds < 0) seconds += 86400;

    int hh = (int)(seconds / 3600);
    int mm = (int)((seconds % 3600) / 60);
    int ss = (int)(seconds % 60);

    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}