/**
 * The get_two_vars function is vulnerable to a buffer overflow.
 * The size1 and size2 originate from the buf1, buf2. If the sizes are larger then the 512
 * this could overwrite memory causing a buffer overflow.
*/

int get_two_vars(int sock, char *out, int len){
    char buf1[512], buf2[512];
    unsigned int size1, size2;
    int size;
    if( recv(sock, buf1, sizeof(buf1), 0) < 0){
        return -1;
    }
    if(recv(sock, buf2, sizeof(buf2), 0) < 0){
        return -1;
    }
    /* packet begins with length information */
    memcpy(&size1, buf1, sizeof(int));
    memcpy(&size2, buf2, sizeof(int));
    size = size1 + size2;
    if(size > len){
        return -1;
    }

    memcpy(out, buf1, size1);
    memcpy(out + size1, buf2, size2);
    return size;
}