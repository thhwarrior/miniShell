bool print(stringArray* args){
    if (args->length < 2) return false;
    for(int i = 1; i < args->length; i++) cout << args->array[i] << " ";
    cout << endl;
    return true;
}

