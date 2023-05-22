using namespace std;

void        get_memory_info();
void        show_sysinfo1();
void        show_uptime();
void        show_mount_points();
void 		show_kernel_runtime_config();
void        getCPUinfo();
string      readFile(string const& file);

bool getHardwareDetails(stringArray* args)
{
	if(args->length != 1) return false;
	
    cout << "\n" <<  "=====[Memory]=====" << '\n';
    get_memory_info();
    cout << endl;

	cout << "=====[System]=====" << '\n';
	show_sysinfo1();
    cout << endl;

    cout << "=====[CPU]=====" << '\n';
    getCPUinfo();
    cout << endl;

	return true;
}

void get_memory_info()
{
	constexpr const char* meminfo_file 		= "/proc/meminfo";
	// factor = 1 Gigabytes = 1024 * 1024 kbytes 
	constexpr double factor = 1024 * 1024;
	
	auto ifs = ifstream{meminfo_file};
	if(!ifs.good()){
		throw runtime_error("Error: unable to memory-info file.");
	}
	string line, label;
	uint64_t value; 
	while( getline(ifs, line) )
	{		
		stringstream ss{line};	
		ss >> label >> value;

		if(label == "MemTotal:")
			cout << "     Total memory (Gb) = " << (value / factor) << '\n';

		if(label == "MemAvailable:")		
			cout << " Memory Available (Gb) = " << (value / factor) << '\n';
	}
}

void show_sysinfo1()
{
	struct sysinfo info;
	::sysinfo(&info);

	// 1 Gigabyte = 1024 megabytes = 1024 * 1024 kbytes = 1024 * 1024 * 1024 bytes;
	constexpr double factor = 1024 * 1024 * 1024;
	constexpr uint64_t one_day_to_seconds = 24 * 60 * 60;

	cout << " [*] System uptime since boot (seconds) = " << info.uptime << '\n'
		   	  << " [*] System uptime since boot    (days) = " << info.uptime    / one_day_to_seconds << '\n'
		  	  << " [*]              Total RAM memory (Gb) = " << info.totalram  / factor << '\n'
			  << " [*]              Free  RAM memory (Gb) = " << info.freeram   / factor << '\n'
			  << " [*]                    Total SWAP (Gb) = " << info.totalswap / factor << '\n'				  
			  << " [*]                     Free SWAP (Gb) = " << info.freeswap  / factor << '\n'				  				  
			  << " [*]        Number of processes running = " << info.procs << '\n'
			  << '\n';
}

void getCPUinfo(){
    auto ifs = ifstream("/proc/cpuinfo");
    string line;
    while(getline(ifs, line))
        cout << line << '\n';
}

string readFile(string const& file) 
{
    ifstream is(file);
    if( !is.good() ) throw runtime_error("Error: stream has errors.");
    stringstream ss;
    ss << is.rdbuf();	
	string m;
	// Remove ending line character '\n' or '\r\n'.
	getline(ss, m);
    return m;
} 

