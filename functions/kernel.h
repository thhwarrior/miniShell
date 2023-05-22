using namespace std;


void show_kernel_runtime_config()
{
	auto show_field= [](string const& label, string const& file)
	{
		cout << " [*] " 
				  << setw(40) << right << (label + " => ")
				  << setw(50) << left  << readFile(file)
				  << '\n';
	};

	cout << '\n';
	show_field("Machine Hostname",                "/proc/sys/kernel/hostname");
	show_field("Kernel Version",                  "/proc/sys/kernel/osrelease");	
	show_field("Os type",                         "/proc/sys/kernel/ostype");
	show_field("Boot unique ID identifier",       "/proc/sys/kernel/random/boot_id");
	show_field("Date which kernel was compiled",  "/proc/sys/kernel/version");
	show_field("Sysrq enabled (Emergency keys)",  "/proc/sys/kernel/sysrq");
	show_field("Max number of Cgroups namespaces", "/proc/sys/user/max_cgroup_namespaces");
	show_field("Max number of Mount namespaces",   "/proc/sys/user/max_net_namespaces");
}

bool kernelInfo(stringArray* args)
{
	if(args->length != 1) return false;
	cout << "\n" << "=====[Kernel]=====" << '\n';
	show_kernel_runtime_config();
    cout << endl;

	return true;
}

