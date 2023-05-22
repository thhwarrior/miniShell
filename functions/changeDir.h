bool changeDir(stringArray* args){
    if (args->length != 2) return false;

    char a[100];
    char b[100];

    char* oldDir = getcwd(a,100);

    chdir(args->get(1));

    char* newDir = getcwd(b,100);

    return (strcmp(oldDir,newDir) != 0);
}

