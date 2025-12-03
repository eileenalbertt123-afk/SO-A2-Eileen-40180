#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int i = 0;

    /* execv membutuhkan array string untuk argumen.
       Untuk demo ini, kita menggunakan array argv yang sudah ada, 
       yang berisi nama program dan argumen yang mungkin diberikan. */
    execv ("/bin/echo", /* program yang dimuat - hanya full path */
           &argv[0] ); /* array argumen (termasuk argv[0]) */

    printf("EXEC Failed\n");
    /* Baris di atas akan dicetak saat terdapat kesalahan */
}
