char g_result[1001];

size_t IsPalindrome(char* s, size_t len) {
    size_t i = 0;
    size_t j = len - 1;
    for (; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }

    return 1;
}

void StrCpy(char* src, char* dst, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        src[i] = dst[i];
    }
}

char * longestPalindrome(char * s){
    if (s == NULL) {
        printf("input is NULL!\n");
        return NULL;
    }

    size_t len = strlen(s);
    if (len == 0 || len == 1) {
        return s;
    }

    (void)memset(g_result, 0, sizeof(g_result));

    size_t maxLen = len;
    size_t i;
    for (; maxLen > 1; maxLen--) {
        for (i = 0; i + maxLen <= len; i++) {
            if (IsPalindrome(s + i, maxLen)) {
                StrCpy(g_result, s + i, maxLen);
                return g_result;
            }
        }
    }

    StrCpy(g_result, s, maxLen);

    return g_result;
}