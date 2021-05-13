#include <stdio.h>
void Towers(int n, char fromPeg, char toPeg, char auxPeg)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", fromPeg, toPeg);
        return;
    }
    Towers(n - 1, fromPeg, auxPeg, toPeg);
    printf("Move disk %d from peg %c to peg %c\n", n, fromPeg, toPeg);
    Towers(n - 1, auxPeg, toPeg, fromPeg);
}
int main()
{
    Towers(5, 'A', 'C', 'B');
}