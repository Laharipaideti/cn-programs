#include <stdio.h>
#include <math.h>

int code[32];

int parity(int p, int n) {
    int i, count = 0;
    for(i = p-1; i < n; i += 2*p)
        for(int j = i; j < i + p && j < n; j++)
            count += code[j];
    return count % 2;
}

int main() {
    int d[32], i, j=0, n, r=0, N, error = 0;

    printf("Data bits: ");
    scanf("%d", &n);
    printf("Enter bits: ");
    for(i=0;i<n;i++) scanf("%d",&d[i]);

    while(n + r + 1 > pow(2, r)) r++;
    N = n + r;

    for(i=0;i<N;i++)
        if((i & (i+1)) == 0) code[i] = 0;
        else code[i] = d[j++];

    for(i=0;i<r;i++)
        code[(int)pow(2,i)-1] = parity(pow(2,i),N);

    printf("\nCodeword: ");
    for(i=0;i<N;i++) printf("%d",code[i]);

    printf("\n\nReceived: ");
    for(i=0;i<N;i++) scanf("%d",&code[i]);

    for(i=0;i<r;i++)
        if(parity(pow(2,i),N)) error += pow(2,i);

    if(error == 0) printf("No Error\n");
    else printf("Error at bit: %d\n", error);
}
