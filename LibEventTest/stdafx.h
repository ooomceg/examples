#pragma once

#include <cstring>
#include <cerrno>
#include <cstdio>
#include <csignal>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <cmath>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <numeric>

#ifndef WIN32
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/inet.h>
# endif
#include <sys/socket.h>
#else
#include <WinSock2.h>
#endif

using namespace std;