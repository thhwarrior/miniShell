using namespace std;

bool list(stringArray* args){

    if (args->length != 1) return false;

    DIR *dir;
    dirent *file;

    char s[100];
    char*  c = getcwd(s, 100);

    if((dir = opendir(c)) == NULL) return false; 
    
    while((file = readdir(dir)) != NULL) {
	    if(!strcmp(file->d_name,".") || !strcmp(file->d_name,"..")) continue;
	    std::cout << file->d_name << "\t";
    }
    std::cout << "\n";
	
    return true;
}
