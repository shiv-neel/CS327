#include <stdio.h>

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
    fprintf(stderr, "Usage: char <letter>");
    return -1;
  }
  printf("%c is for %s\n", argv[1][0], words[argv[1][0] - 'a']);
}
