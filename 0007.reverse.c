bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }

    int tmp;
    int palind = 0;
#define INT_MAX 0xefffffff
    while (x != 0) {
        tmp = x % 10;
        x /= 10;
        if ((palind > INT_MAX / 10) || ((palind == INT_MAX / 10) && (tmp > 7))) {
            return false;
        }
        palind = palind * 10 + tmp;
    }

    if (x == palind) {
        return true;
    }
    return false;
}