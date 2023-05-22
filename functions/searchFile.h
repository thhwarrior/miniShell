bool search(stringArray* args){
    if (args->length != 2) return false;

    DIR *dir;
    dirent *file;

    char s[100];
    char*  c = getcwd(s, 100);
  
    if((dir = opendir(c)) == NULL) return false; 
    
    while((file = readdir(dir)) != NULL) {
	    if(!strcmp(file->d_name,".") || !strcmp(file->d_name,".."))
	        continue;
	    else if(strcmp(file->d_name, args->get(1)) == 0){
		    cout << "file found" << endl;
		    return true;
	    }
    }
    cout << "file not found" << endl;
    return false;

}
