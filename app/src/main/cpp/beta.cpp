#include <cstdio>

extern const char* hello_gamma();

__attribute__ ((visibility ("default"))) const char *hello_beta() {
    return hello_gamma();
}