#include <stdio.h>
#include <ctype.h>

/* pointer to the first element in array */
char *words[] = {
    "abrakdabra",
    "blastoise",
    "clefairy",
    "dialga",
    "eevee",
    "flygon",
    "graveler",
    "ho-oh",
    "igglybuff",
    "jumpluff",
    "kechlion",
    "lugia",
    "magnamite",
    "nidoran",
    "onyx",
    "pikachu",
    "quagsire",
    "rapidash",
    "squirtle",
    "typhlosion",
    "umbrion",
    "venonat",
    "wartortle",
    "xernius",
    "yveltal",
    "zaptos"};

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: char <letter>\n");
    return -1;
  }
  printf("%c is for %s\n", argv[1][0], words[tolower(argv[1][0]) - 'a']);
}
