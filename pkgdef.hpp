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

typedef struct package {
  char number;
  int content;
  bool isInitPkg;
  bool isEndPkg;
}package;

#endif //pkgdef_hpp_