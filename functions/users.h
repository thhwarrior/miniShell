bool getUsers(stringArray* args) {

	if(args->length != 2) return false;
    if (args->array[1] != "normal" && args->array[1] != "system") return false;

    while (true) {
        errno = 0; // so we can distinguish errors from no more entries
        passwd* entry = getpwent();
        if (!entry) {
            if (errno) {
                std::cout << "Error reading password database\n";
                return false;
            }
            break;
        }
        if (args->array[1] == "normal") {
            if (entry->pw_uid >= 1000)
                std::cout << entry->pw_name << '\n';
        }
        else if (args->array[1] == "system") {
            if (entry->pw_uid < 1000)
                std::cout << entry->pw_name << '\n';
        }
    }
    endpwent();
    return true;
}


