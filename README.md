# C-Password-Generator

This C program generates a random password of specified length using OpenSSL's `RAND_bytes` function. It allows the user to either specify a custom password length (between 5 and 30 characters) or use the default length of 16 characters.

## Prerequisites

To compile and run this program, you will need:

- A C compiler (e.g., `gcc`)
- OpenSSL library installed on your system

### Installing OpenSSL (if not installed)

#### For Ubuntu/Debian:
```bash
sudo apt update
sudo apt install libssl-dev

```
##### How to compile:
```bash
gcc -o passwordGenerator.exe passwordGenerator.c -lcrypto
```
###### How to Run:
The program can be executed with an optional command-line argument to specify the desired password length. If no argument is provided, the default length is 16 characters.

```bash
./passwordGenerator.exe [desired passlength]
```
