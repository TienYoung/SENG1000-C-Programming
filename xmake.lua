add_rules("mode.debug", "mode.release")
set_languages("c89")

if is_plat("windows") then
    set_toolchains("msvc")
    add_cxxflags("/TC")
elseif is_plat("macosx") then
    set_toolchains("clang")
    add_cxxflags("-x c")
else 
    set_toolchains("gcc")
    add_cxxflags("-x c")
end 

target("test")
    set_kind("binary")
    add_files("src/Test/*.cpp")

target("f1")
    set_kind("binary")
    add_files("src/Focused 1/*.cpp")

target("f2")
    set_kind("binary")
    add_files("src/Focused 2/*.cpp")
    
target("f3")
    set_kind("binary")
    add_files("src/Focused 3/*.cpp")

target("f4")
    set_kind("binary")
    add_files("src/Focused 4/*.cpp")

target("f5")
    set_kind("binary")
    add_files("src/Focused 5/*.cpp")

target("f6")
    set_kind("binary")
    add_files("src/Focused 6/*.cpp")

target("f7")
    set_kind("binary")
    add_files("src/Focused 7/*.cpp")

target("f8")
    set_kind("binary")
    add_files("src/Focused 8/*.cpp")

target("m1")
    set_kind("binary")
    add_files("src/Major 1/*.cpp")

target("m2")
    set_kind("binary")
    add_files("src/Major 2/*.cpp")

target("m3")
    set_kind("binary")
    add_files("src/Major 3/*.cpp")
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

