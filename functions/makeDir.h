bool makeDir(stringArray* args){
    if (args->length != 2) return false;

	char s[100];
	char*  c = getcwd(s, 100);

	strcat(c, "/");
	strcat(c, args->get(1));

	int command_status = mkdir(c, 0777);

	if (command_status < 0){
		std::cout << "directory not created" << endl;
		return false;
	}
	std::cout << "directory created" << endl;
	return true;
}

