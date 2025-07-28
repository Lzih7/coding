void reverse(Stack* S){
    char c=getchar();
    while(c!='.'){
        push(S,c);
        c=getchar();
    }
    while(!empty(S)){
        char output=pop(S);
        putchar(output);
    }
    return;
}
