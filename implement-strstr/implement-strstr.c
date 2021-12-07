

int strStr(char * haystack, char * needle){
    char * x=strstr(haystack,needle);
    if(x==NULL)
        return -1;
    return -1*(haystack-x);
}