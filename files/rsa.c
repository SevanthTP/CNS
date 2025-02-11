#include <stdio.h>
#include <string.h>

long int e, d, n;

long int mod_exp(long int base, long int exp, long int mod) {
    long int result = 1;
    for (int i = 0; i < exp; i++)
        result = (result * base) % mod;
    return result;
}

int gcd(long int a, long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void rsa_setup(long int p, long int q) {
    long int phi = (p - 1) * (q - 1);
    n = p * q;

    // Find public key 'e'
    for (e = 2; e < phi; e++)
        if (gcd(e, phi) == 1) break;

    // Find private key 'd'
    for (d = 1; (d * e) % phi != 1; d++);
}

void encode_decode(const char *text, long int *encoded, char *decoded) {
    for (int i = 0; text[i] != '\0'; i++) {
        encoded[i] = mod_exp(text[i], e, n);
        decoded[i] = mod_exp(encoded[i], d, n);
    }
    decoded[strlen(text)] = '\0';
}

void main() {
    long int p, q;
    char text[50], decoded[50];
    long int encoded[50];

    printf("\nEnter a prime number for p: ");
    scanf("%ld", &p);
    printf("Enter a prime number for q: ");
    scanf("%ld", &q);
    printf("Enter the text to be encoded: ");
    scanf("%s", text);

    rsa_setup(p, q);

    printf("\np=%ld\tq=%ld\tn=%ld\n", p, q, n);

    encode_decode(text, encoded, decoded);

    printf("Encoded Message:\n");
    for (int i = 0; text[i] != '\0'; i++)
        printf("%ld ", encoded[i]);
    printf("\nDecoded message is: %s\n\n", decoded);
}