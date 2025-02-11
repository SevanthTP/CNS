#include <stdio.h>
#include <string.h>

void matrixMult(int a[100][2], int b[2][2], int res[100][2], int len) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < 2; j++) {
            res[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % 26;
            if (res[i][j] < 0) res[i][j] += 26; // Ensure non-negative values
        }
}

void encryption(int msg[100][2], int key[2][2], int cipher[100][2], int len) {
    matrixMult(msg, key, cipher, len);
    for (int i = 0; i < len; i++)
        printf("%c%c", cipher[i][0] + 'a', cipher[i][1] + 'a');
    printf("\n");
}

void decryption(int cipher[100][2], int key[2][2], int len) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26;
    
    int inv_det = -1;
    for (int i = 1; i < 26; i++)
        if ((det * i) % 26 == 1) {
            inv_det = i;
            break;
        }
    
    if (inv_det == -1) {
        printf("Invalid key! Cannot decrypt.\n");
        return;
    }

    int invKey[2][2] = {
        {(key[1][1] * inv_det) % 26, (-key[0][1] * inv_det) % 26},
        {(-key[1][0] * inv_det) % 26, (key[0][0] * inv_det) % 26}
    };

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (invKey[i][j] < 0) invKey[i][j] += 26;

    int decrypt[100][2];
    matrixMult(cipher, invKey, decrypt, len);

    for (int i = 0; i < len; i++)
        printf("%c%c", decrypt[i][0] + 'a', decrypt[i][1] + 'a');
    printf("\n");
}

int main() {
    char message[100];
    int key[2][2], msg[100][2] = {0}, cipher[100][2], len;

    printf("Enter the message: ");
    scanf("%s",&message);
    printf("Enter the 2x2 key matrix:\n");
    scanf("%d%d%d%d", &key[0][0], &key[0][1], &key[1][0], &key[1][1]);

    len = strlen(message);
    int len1 = (len % 2 == 0) ? len / 2 : (len / 2) + 1;

    for (int i = 0, c = 0; i < len1; i++) {
        msg[i][0] = (c < len) ? message[c++] - 'a' : 'x' - 'a';
        msg[i][1] = (c < len) ? message[c++] - 'a' : 'x' - 'a';
    }

    printf("Encryption: ");
    encryption(msg, key, cipher, len1);

    printf("Decryption: ");
    decryption(cipher, key, len1);

    return 0;
}