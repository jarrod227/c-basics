#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}

int main( ){
    int x = 142878241;
    if(isPalindrome(x)){
        printf("x = %d is Palindrome", x);
    }
    else{
        printf("x = %d is not Palindrome", x);
    }

    return 0;

}