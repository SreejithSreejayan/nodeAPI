#include <stdio.h>
#define max 25
void main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];
    printf("                     BESTFIT MEMORY ALLOCATION\n");
    printf("                    ===========================\n");
    printf("Enter no. of blocks: ");
    scanf("%d", &nb);
    printf("Enter no. of files: ");
    scanf("%d", &nf);
    printf("Enter size of blocks\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter size of files\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
        if (ff[i] == 0)
            printf("\nFile of size %d should wait\n", f[i]);
    }
    printf("\nFile no \tFile size \tBlock no \tBlock size \tFragment");
    for (i = 1; i <= nf; i++)
        if (ff[i] != 0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n");
}
