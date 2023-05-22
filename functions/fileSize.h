bool fileSize(stringArray* args){
    if (args->length != 2) return false;

	ifstream file(args->array[1], ios::binary);

	if(!file){
		cout << "file not found" << std::endl;
		return false;
	}
	
	file.seekg(0, ios::end);
	std::cout << "Size of the file is" << " " << file.tellg() << " " << "bytes" << std::endl;
	file.close();
	return true;
}
