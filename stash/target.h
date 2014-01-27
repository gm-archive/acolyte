// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license which can be found in the LICENSE file.

#if defined(__linux__)
# define TARGET_LINUX
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
# define TARGET_UNIX
#elif defined(_WIN32) || defined(_WIN64)
# define TARGET_WINDOWS
#endif
