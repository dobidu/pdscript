/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   lapi_o;
    const int            lapi_oSize = 26792;

    extern const char*   lauxlib_o;
    const int            lauxlib_oSize = 21612;

    extern const char*   lbaselib_o;
    const int            lbaselib_oSize = 13052;

    extern const char*   lbitlib_o;
    const int            lbitlib_oSize = 5020;

    extern const char*   lcode_o;
    const int            lcode_oSize = 16776;

    extern const char*   lcorolib_o;
    const int            lcorolib_oSize = 4812;

    extern const char*   lctype_o;
    const int            lctype_oSize = 676;

    extern const char*   ldblib_o;
    const int            ldblib_oSize = 12580;

    extern const char*   ldebug_o;
    const int            ldebug_oSize = 9196;

    extern const char*   ldo_o;
    const int            ldo_oSize = 11372;

    extern const char*   ldump_o;
    const int            ldump_oSize = 3080;

    extern const char*   lfunc_o;
    const int            lfunc_oSize = 2576;

    extern const char*   lgc_o;
    const int            lgc_oSize = 12004;

    extern const char*   liblua_a;
    const int            liblua_aSize = 342264;

    extern const char*   liblua53_a;
    const int            liblua53_aSize = 343216;

    extern const char*   liblua53_dylib;
    const int            liblua53_dylibSize = 221008;

    extern const char*   linit_o;
    const int            linit_oSize = 1952;

    extern const char*   liolib_o;
    const int            liolib_oSize = 17120;

    extern const char*   llex_o;
    const int            llex_oSize = 15780;

    extern const char*   lmathlib_o;
    const int            lmathlib_oSize = 11032;

    extern const char*   lmem_o;
    const int            lmem_oSize = 1540;

    extern const char*   loadlib_o;
    const int            loadlib_oSize = 10592;

    extern const char*   lobject_o;
    const int            lobject_oSize = 8140;

    extern const char*   lopcodes_o;
    const int            lopcodes_oSize = 1720;

    extern const char*   loslib_o;
    const int            loslib_oSize = 8440;

    extern const char*   lparser_o;
    const int            lparser_oSize = 24180;

    extern const char*   lstate_o;
    const int            lstate_oSize = 5336;

    extern const char*   lstring_o;
    const int            lstring_oSize = 4092;

    extern const char*   lstrlib_o;
    const int            lstrlib_oSize = 27384;

    extern const char*   ltable_o;
    const int            ltable_oSize = 8260;

    extern const char*   ltablib_o;
    const int            ltablib_oSize = 8424;

    extern const char*   ltm_o;
    const int            ltm_oSize = 4388;

    extern const char*   lua;
    const int            luaSize = 225928;

    extern const char*   lua5_2_1outputredirect_patch;
    const int            lua5_2_1outputredirect_patchSize = 2981;

    extern const char*   lua_o;
    const int            lua_oSize = 10708;

    extern const char*   luac;
    const int            luacSize = 155312;

    extern const char*   luac_o;
    const int            luac_oSize = 10772;

    extern const char*   lundump_o;
    const int            lundump_oSize = 6032;

    extern const char*   lutf8lib_o;
    const int            lutf8lib_oSize = 5664;

    extern const char*   lvm_o;
    const int            lvm_oSize = 21920;

    extern const char*   lzio_o;
    const int            lzio_oSize = 1148;

    extern const char*   Makefile;
    const int            MakefileSize = 6874;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 42;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) noexcept;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8) noexcept;
}
