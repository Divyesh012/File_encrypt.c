#include <stdio.h>
#include <stdlib.h>
void encryptFile(const char *filename)
{
    FILE *f = fopen(filename, "r+");
    if (!f) {
        printf("File not found!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF) {
        fseek(f, -1, SEEK_CUR);
        fputc(ch + 3, f); // Caesar Cipher (+3)
    }

    fclose(f);
    printf("File encrypted successfully.\n");
}

void decryptFile(const char *filename) {
    FILE *f = fopen(filename, "r+");
    if (!f) {
        printf("File not found!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF)
      {
        fseek(f, -1, SEEK_CUR);
        fputc(ch - 3, f); // Caesar Cipher (-3)
    }

    fclose(f);
    printf("File decrypted successfully.\n");
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    int choice;
    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &choice);

    if (choice == 1)
        encryptFile(filename);
    else
        decryptFile(filename);
    return 0;
}
