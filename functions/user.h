bool currentUser(stringArray* args){
    if (args->length != 1) return false;
    char buffer[100];
    getlogin_r(buffer, 100);
    cout << buffer << endl;
    return true; 
}            

