#include <regex.h>
#include <stdio.h>

int main() {
    regex_t regex;
    const char* pattern = "^audit-[0-9]{8}_[0-9]{4}-\\.log$";
    const char* test_filename = "audit-20250211_1655.log";

    if (regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
        printf("Regex compilation failed!\n");
        return 1;
    }

    if (regexec(&regex, test_filename, 0, NULL, 0) == 0) {
        printf("Matched!\n");
    } else {
        printf("Did not match!\n");
    }

    regfree(&regex);
    return 0;
}
