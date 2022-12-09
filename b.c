/**
 * A buffer overflow exists in the copy_something function.
 * If buf is smaller then 800, such as 0. Then the memcpy will try and copy a negative size.
 * This would lead to unexpected behavior with the memory contents.
*/

int copy_something(char *buf, int len){
    char kbuf[800]; // 800 char array
    if(len > sizeof(kbuf)){ // if int is greater then 800
        return -1;
    }

    return memcpy(kbuf, buf, len);
}