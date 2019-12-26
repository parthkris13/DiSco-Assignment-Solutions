#include <stdio.h>
#include <string.h>
#define limit 100000
 
int main() {
    char str[limit + 1];
    scanf("%s ", str);
    int num_replacements;
    scanf("%d ", &num_replacements);
    char replacements[26] = {0}, c1, c2;
    while (num_replacements--) {
        scanf(" %c %c", &c1, &c2);
        replacements[c1 - 'a'] = c2;
    }
    int replacement;
    for (int i = 0; i < strlen(str); i++) {
        do {
            replacement = replacements[str[i] - 'a'];
            if (replacement) str[i] = replacement;
        } while (replacement);
    }
    printf("%s\n", str);
    return 0;
}