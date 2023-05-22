bool slp(stringArray* args){
    if (args->length != 2) return false;
    int time;
    sscanf(args->get(1), "%d", &time);
    sleep(time);
    return true; 
}            

