bool deleteFile(stringArray* args){
    if (args->length != 2) return false;

	char s[100];
	char*  c = getcwd(s, 100);

	strcat(c, "/");
	strcat(c, args->get(1));
	
 	int stat = remove(c);
 	if(stat == 0) return true;
 	else{
 		std::cout << "file delete unsuccessful" << endl;
 		return false;
 	}
}
