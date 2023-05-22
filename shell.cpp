#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <dirent.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>

#include "stringArray.h"

// include your implemented functions here
#include "functions/hardware.h"
#include "functions/kernel.h"
#include "functions/users.h"
#include "functions/user.h"
#include "functions/list.h"
#include "functions/changeDir.h"
#include "functions/deleteFile.h"
#include "functions/makeDir.h"
#include "functions/fileSize.h"
#include "functions/createFile.h"
#include "functions/searchFile.h"
#include "functions/writeToFile.h"
#include "functions/echo.h"
#include "functions/clear.h"
#include "functions/sleep.h"

using namespace std;

stringArray* split(string inputString) {
    int words = 1;
    for (int i = 0; i < inputString.length(); i++)
        	if (inputString[i] == ' ') words++;

    string* input = new string[words];

    int currentWordIndex = 0;
    for (int i = 0; i < inputString.length(); i++) {
	    if (inputString[i] != ' ')
		    input[currentWordIndex] += inputString[i];
	    else currentWordIndex++;
    }
    currentWordIndex++;

	return new stringArray(input, currentWordIndex);
}

int main()
{
	string inputString;
    bool success = false;

	while (true)
	{
		cout << "\033[1;36m\e[1m" << "Shell->" << "\e[0m\033[1;0m ";

		getline(cin, inputString);
		stringArray* input = split(inputString);

		string command = input->array[0];
        
        success = true;

		if      (command == "exit")     break;
		else if (command == "")         continue;

		else if (command == "hardware") success = getHardwareDetails(input);
        else if (command == "kernel")   success = kernelInfo(input);
        else if (command == "users")    success = getUsers(input);
        else if (command == "ls")       success = list(input);
        else if (command == "cd")       success = changeDir(input);
        else if (command == "del")      success = deleteFile(input);
        else if (command == "mkdir")    success = makeDir(input);
        else if (command == "sizeof")   success = fileSize(input);
        else if (command == "create")   success = create(input);
        else if (command == "search")   success = search(input);
        else if (command == "write")    success = write(input);
        else if (command == "echo")     success = print(input);
        else if (command == "sleep")    success = slp(input);
        else if (command == "clear")    success = clear(input);
        else if (command == "user")     success = currentUser(input);

        else cout << "This command has not been implemented" << endl;

        if (!success) cout << "Could not execute command. Check the syntax and try again" << endl;

        delete input;
	}
}

