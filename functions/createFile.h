bool create(stringArray* args){
    if (args->length != 2) return false;

	ofstream file(args->array[1]);
	if(!file){
		cout << "file not created" << endl;
		return false;
	}
	file.close();
	return true;
}
