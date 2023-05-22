bool write(stringArray* args){
    if (args->length < 2) return false;

	ofstream file(args->array[1]);
	
	if(!file){
		cout << "file not found" << endl;
		return false;
	}
	
	for(int i = 2; i < args->length; i++){
		file << args->array[i];
		file << " ";
	}
	file << "\n";
	
	file.close();
	return true;
}
