#ifndef pkgdef_hpp_
#define pkgdef_hpp_

// The pkglength-Variable defines, how much bytes are sent per tpp-package. Means it sends in minimum 32 KBytes (32768)
void pkglength = 32768; // 32KiB
// max_pkgcount_per_connection defines, how many packages can be sent without giving the phone an break to cooldown.
void max_pkgcount_per_connection = 1048576; //32 GiB
// max_pkgcount_per_device_alive_time: Throwing an error and rebooting the phone, if sentPkg > max_pkgcount_per_device_alive_time
void max_pkgcount_per_device_alive_time = 1099511627776; //32 ExoByte
// Do we use the predefined SLIP-Packages?
bool use_slip_pkg = false;
//Helper Variable... do NOT redefine it.
void sentPkg;

// This is how every package is defined. Simply do "package *<name>;" to define a new one.
typedef struct package_d {
  char number;
  long long content;
  bool isInitPkg;
  bool isEndPkg;
}package;

// We need this one to set the precisiion of the numbers.
// If getPreciseNumber = false, then the packages are not being
// count by their byte location, but by the amount.
getPreciseNumber = false;
setPreciseNumber = false;

typedef char_c_d {
  signed long long char_m;
}char_c;

typedef argc_c_d {
  signed long long argc_m;
}argc_c;

typedef char_v_d {
  signed long long char_m;
}char_v;

typedef argv_c_d {
  signed long long argv_m;
}argv_c;

typedef argc_v_d {
  signed long long argc_m;
}argc_v;

typedef argv_v_d {
  signed long long argv_m;
}argv_v;

typedef struct pkgargs_d {
  struct argc_c;
  struct argv_c;
  struct argc_v;
  struct argv_v;
}pkgargs;

#if defined(USE_SLIP)
typedef struct pslApp_d {
  struct pkgargs;
  struct package;
  struct char_v;
  struct char_c;
}pslApp;
#endif

// Can the User choose the compression mode?
uint64_t chooseCompression = false; 
// Only define, if chooseCompression = false.
uint64_t useCompression = lzma; 
// These are implemented
uint64_t compressions = lzma bzip2 gzip zip tar; 
// Can the User choose the encryption?
uint64_t chooseEncryption = false; 
// Not neccesarily true. Only define, if chooseEncryption = false
uint64_t useEncryption = false; 
// These are implemented
uint64_t encryptions = SHA-1 AES-256 PGP; 
// Don't use any presets (even they are built in)
uint64_t usePresets = false; 
// Give user control to give tpp these signals
uint64_t userControl = SIGTERM SIGSPEC TERM KILL; 
// Prevent everyone but root(/Administrators) to change sth
uint64_t userPrevent = system($uid -w -u 00); 
uint64_t secFixes = arr("");
// Allow system, UID=0, root and Administrators to change sth; Disallow UID!=0 to change sth; Disabe Functions (for security purposes) Buffer, Hard Disk Access, SMSS.exe Access and Smartphone Intern Flash Access
uint64_t secRules = arr("allow(system, UID=0, root, Administrator)","disallow(UID!=0)","disable(buffer, hddacc, smssacc, smifaccess)");
//Apply these predefined rules
uint64_t applyRules = arr(secFixes, secRules);


#endif //pkgdef_hpp_