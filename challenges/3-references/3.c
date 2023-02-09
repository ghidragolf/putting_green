#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void flag(void)
{
    printf("GOLFING!\n");
    return;
}

int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

void print_random_numbers(int min, int max, int num) {
    int i;
    flag();
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_number(min, max));
    }
}

int random_even_number(int min, int max) {
    int num = random_number(min, max);
    while (num % 2 != 0) {
        num = random_number(min, max);
    }
    return num;
}

void print_random_even_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_even_number(min, max));
    }
}

int random_odd_number(int min, int max) {
    int num = random_number(min, max);
    while (num % 2 == 0) {
        num = random_number(min, max);
    }
    return num;
}

void print_random_odd_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_odd_number(min, max));
    }
}

int random_prime_number(int min, int max) {
    int num, i;
    int is_prime;
    do {
        num = random_number(min, max);
        is_prime = 1;
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                is_prime = 0;
            }
        }
    } while (is_prime == 0);
    return num;
}

void print_random_prime_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    flag();
    for (i = 0; i < num; i++) {
        printf("%d\n", random_prime_number(min, max));
    }
}

int random_fibonacci_number(int min, int max) {
    int num = random_number(min, max);
    flag();
    while (!(num == 1 || num == 2 || num == 3 || num == 5 || num == 8 || num == 13 || num == 21 || num == 34 || num == 55 || num == 89)) {
        num = random_number(min, max);
    }
    return num;
}

void print_random_fibonacci_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_fibonacci_number(min, max));
    }
}

int random_perfect_square_number(int min, int max) {
    int num = random_number(min, max);
    while (1) {
        int temp = (int)sqrt(num);
        if (temp * temp == num) {
            break;
        }
        num = random_number(min, max);
    }
    return num;
}

void print_random_perfect_square_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_perfect_square_number(min, max));
    }
}

int random_palindrome_number(int min, int max) {
    int num = random_number(min, max);
    while (1) {
        int temp = num;
        int rev = 0;
        flag();
        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }
        if (rev == num) {
            break;
        }
        num = random_number(min, max);
    }
    return num;
}

void print_random_palindrome_numbers(int min, int max, int num) {
    int i;
    srand(time(0));
    for (i = 0; i < num; i++) {
        printf("%d\n", random_palindrome_number(min, max));
    }
}

int main() {
    int min = 3;
    int max = 10;
    int num = 7;

    printf("\nRandom Numbers: \n");
    print_random_numbers(min, max, num);

    printf("Random Even Numbers: \n");
    print_random_even_numbers(min, max, num);

    printf("Random Odd Numbers: \n");
    print_random_odd_numbers(min, max, num);

    printf("Random Prime Numbers: \n");
    print_random_prime_numbers(min, max, num);

    printf("Random Fibonacci Numbers: \n");
    print_random_fibonacci_numbers(min, max, num);

    printf("Random Perfect Square Numbers: \n");
    print_random_perfect_square_numbers(min, max, num);

    printf("Random Palindrome Numbers: \n");
    print_random_palindrome_numbers(min, max, num);

    return 0;
}