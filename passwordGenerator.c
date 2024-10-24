#include <stdio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <string.h>
void handleErrors(){
    ERR_print_errors_fp(stderr);
    abort();
}

int stringToInt(char* string){
    int result;
    if(sscanf(string, "%d", &result) == 1)
        return result;
    else
        return 0;
}

int main(int argc, char** argv){

    unsigned char* randBytes;

    int passLength;
    const unsigned char* charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$^&*()-_=+[]{}|;:,.<>?";
    
    int charsetSize = strlen(charset) - 1;
    printf("Charset size: %d\n", charsetSize);

    if(argc == 1){
        passLength = 16;
        printf("Default length: %d\n", passLength);
    } else {
        int newLength = stringToInt(argv[1]);
        if(newLength < 5 && newLength > 30){
            printf("Insert a length between 5 and 30\n");
            return -1;
        }
        passLength = newLength;

    printf("Manually inserted password length: %d\n", passLength);

    }
    if(!RAND_bytes(randBytes, passLength))
        handleErrors();

    printf("Charset size: %d\n", charsetSize);
    
    printf("Password length: %d\n", passLength);
    for(int i = 0; i < passLength; i++){
        printf("%c",charset[randBytes[i] % charsetSize]);

    }
    printf("\n");

}
