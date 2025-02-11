#include<stdio.h>

// Function to calculate (base^pw) % mod
int power(int base, int pw, int mod) 
{
    int i, b = 1;
    for(i = 0; i < pw; i++) // Loop to multiply base 'pw' times
        b = b * base;
    return b % mod; // Return the result modulo 'mod'
}

int main() 
{
    int a, q, x1, y1, x2, y2;
    
    // Get prime number 'q' and primitive root 'a' as input
    printf("Enter the value of q and a: ");
    scanf("%d%d", &q, &a);

    // Get private key 'x1' for the first person
    printf("Enter the value of x1 for the first person : ");
    scanf("%d", &x1);
    y1 = power(a, x1, q); // Compute public key y1 = (a^x1) % q

    // Get private key 'x2' for the second person
    printf("Enter the value of x2 for the second person : ");
    scanf("%d", &x2);
    y2 = power(a, x2, q); // Compute public key y2 = (a^x2) % q

    // Compute shared secret keys
    printf("key for the first person is : %d\n", power(y1, x2, q)); // (y1^x2) % q
    printf("key for the second person is : %d\n", power(y2, x1, q)); // (y2^x1) % q

    return 0;
}