/**
 * if buf is smaller then 800 and len = 800 then more memory then exists in the src will be copied into kbuf
*/

int copy_something(char *buf, int len){
    char kbuf[800]; // 800 char array
    if(len > sizeof(kbuf)){ // if int is greater then 800
        return -1;
    }
    /**
     *  dest − This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
     *  src − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
     *  n − This is the number of bytes to be copied.
    */
    return memcpy(kbuf, buf, len);
}