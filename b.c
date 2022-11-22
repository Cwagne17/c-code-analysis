int copy_something(char *buf, int len){
    char kbuf[800];
    if(len > sizeof(kbuf)){
        return -1;
    }
    return memcpy(kbuf, buf, len);
}