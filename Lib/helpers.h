#pragma once


#ifdef LIBRARY_EXPORTS
#    define LIBRARY_API __declspec(dllexport)
#else
#    define LIBRARY_API __declspec(dllimport)
#endif

#define IMPLEMENT_PLUGIN(Plugin,Impl) \
extern "C" LIBRARY_API inline Plugin* queryInterface() {return new Impl;}


