#include<stdio.h>
#include<string.h>

char* makeFancyString(char* s) {
    int n = strlen(s);
    char *result = (char*)malloc((n + 1) * sizeof(char));
    int count = 0;
    
    for(int i = 0; i<n; i++){
        if(count > 2 && result[count-2]==s[i] && result[count-2]==s[i]){
            continue;
        }
        count++;
        result[count] = s[i];
    }

    result[count] = "/0";
    return result;
}