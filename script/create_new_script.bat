@echo off
:: authorized by saltyzero@foxmail.com
:: VS141 RelWithDebInfo Win32

echo "please input a script name:"
set /p name=

:: create folders
if exist %name% del /s /q %name% & rd /s /q %name%
if not exist %name% md %name% & md %name%\src

:: create .h and .cpp
echo=> %name%\src\%name%.h & echo=#include ^"%name%.h^"> %name%\src\%name%.cpp & ^
echo,>> %name%\src\%name%.cpp & ^
echo _module void AddSC_%name%^(^) { new %name%^(^); }>> %name%\src\%name%.cpp

:: create .vcxproj for compiling
(echo ^<?xml version=^"1.0^" encoding=^"utf-8^"?^> & ^
echo ^<Project DefaultTargets=^"Build^" ToolsVersion=^"15.0^" xmlns=^"http:^/^/schemas.microsoft.com^/developer^/msbuild^/2003^"^> & ^
echo  ^<ItemGroup Label=^"ProjectConfigurations^"^> & ^
echo    ^<ProjectConfiguration Include=^"RelWithDebInfo^|Win32^"^> & ^
echo      ^<Configuration^>RelWithDebInfo^<^/Configuration^> & ^
echo      ^<Platform^>Win32^<^/Platform^> & ^
echo    ^<^/ProjectConfiguration^> & ^
echo  ^<^/ItemGroup^> & ^
echo  ^<PropertyGroup Label=^"Globals^"^> & ^
echo  ^<Platform^>Win32^<^/Platform^> & ^
echo    ^<WindowsTargetPlatformVersion^>10.0.17134.0^<^/WindowsTargetPlatformVersion^> & ^
echo  ^<^/PropertyGroup^> & ^
echo  ^<Import Project=^"$^(VCTargetsPath^)\Microsoft.Cpp.Default.props^" ^/^> & ^
echo  ^<PropertyGroup Condition=^"^'$^(Configuration^)^|$^(Platform^)^'==^'RelWithDebInfo^|Win32^'^" Label=^"Configuration^"^> & ^
echo    ^<ConfigurationType^>DynamicLibrary^<^/ConfigurationType^> & ^
echo    ^<UseDebugLibraries^>true^<^/UseDebugLibraries^> & ^
echo    ^<PlatformToolset^>v141^<^/PlatformToolset^> & ^
echo    ^<CharacterSet^>MultiByte^<^/CharacterSet^> & ^
echo  ^<^/PropertyGroup^> & ^
echo  ^<Import Project=^"$^(VCTargetsPath^)\Microsoft.Cpp.props^" ^/^> & ^
echo  ^<ImportGroup Label=^"ExtensionSettings^"^> & ^
echo  ^<^/ImportGroup^> & ^
echo  ^<ImportGroup Label=^"Shared^"^> & ^
echo  ^<^/ImportGroup^> & ^
echo  ^<ImportGroup Condition=^"^'$^(Configuration^)^|$^(Platform^)^'==^'RelWithDebInfo^|Win32^'^" Label=^"PropertySheets^"^> & ^
echo    ^<Import Project=^"$^(UserRootDir^)\Microsoft.Cpp.$^(Platform^).user.props^" Condition=^"exists^(^'$^(UserRootDir^)\Microsoft.Cpp.$^(Platform^).user.props^'^)^" Label=^"LocalAppDataPlatform^" ^/^> & ^
echo  ^<^/ImportGroup^> & ^
echo  ^<PropertyGroup Label=^"UserMacros^" ^/^> & ^
echo  ^<PropertyGroup Condition=^"^'$^(Configuration^)^|$^(Platform^)^'==^'RelWithDebInfo^|Win32^'^"^> & ^
echo    ^<LibraryPath^>$^(ProjectDir^)..\_lib\;$^(LibraryPath^)^<^/LibraryPath^> & ^
echo  ^<^/PropertyGroup^> & ^
echo  ^<ItemDefinitionGroup Condition=^"^'$^(Configuration^)^|$^(Platform^)^'==^'RelWithDebInfo^|Win32^'^"^> & ^
echo    ^<ClCompile^> & ^
echo      ^<WarningLevel^>Level3^<^/WarningLevel^> & ^
echo      ^<Optimization^>MaxSpeed^<^/Optimization^> & ^
echo      ^<SDLCheck^> & ^
echo      ^<^/SDLCheck^> & ^
echo      ^<DebugInformationFormat^>ProgramDatabase^<^/DebugInformationFormat^> & ^
echo      ^<MultiProcessorCompilation^>true^<^/MultiProcessorCompilation^> & ^
echo      ^<InlineFunctionExpansion^>OnlyExplicitInline^<^/InlineFunctionExpansion^> & ^
echo      ^<BasicRuntimeChecks^>Default^<^/BasicRuntimeChecks^> & ^
echo      ^<RuntimeLibrary^>MultiThreadedDLL^<^/RuntimeLibrary^> & ^
echo      ^<EnableEnhancedInstructionSet^>StreamingSIMDExtensions2^<^/EnableEnhancedInstructionSet^> & ^
echo      ^<RuntimeTypeInfo^>true^<^/RuntimeTypeInfo^> & ^
echo      ^<CompileAs^>CompileAsCpp^<^/CompileAs^> & ^
echo      ^<DisableSpecificWarnings^>4996;4355;4244;4985;4267;4619^<^/DisableSpecificWarnings^> & ^
echo      ^<TreatSpecificWarningsAsErrors^>4263;4264^<^/TreatSpecificWarningsAsErrors^> & ^
echo      ^<AdditionalIncludeDirectories^>$^(ProjectDir^)..\..\script\_include;$^(ProjectDir^)..\..\script\_include\common;$^(ProjectDir^)..\..\script\_include\common\Collision;$^(ProjectDir^)..\..\script\_include\common\Database;$^(ProjectDir^)..\..\script\_include\common\DataStores;$^(ProjectDir^)..\..\script\_include\common\Dynamic;$^(ProjectDir^)..\..\script\_include\common\Packets;$^(ProjectDir^)..\..\script\_include\common\Threading;$^(ProjectDir^)..\..\script\_include\common\Utilities;$^(ProjectDir^)..\..\script\_include\Detour;$^(ProjectDir^)..\..\script\_include\Recast;$^(ProjectDir^)..\..\script\_include\mysql;%%^(AdditionalIncludeDirectories^)^<^/AdditionalIncludeDirectories^> & ^
echo      ^<AdditionalOptions^>%%^(AdditionalOptions^) ^/Zm500 ^/utf-8^<^/AdditionalOptions^> & ^
echo      ^<PreprocessorDefinitions^>WIN32;_WINDOWS;NDEBUG;_module=extern ^"C^" _declspec^(dllexport^);%%^(PreprocessorDefinitions^)^<^/PreprocessorDefinitions^> & ^
echo    ^<^/ClCompile^> & ^
echo    ^<Link^> & ^
echo      ^<AdditionalLibraryDirectories^>%%^(AdditionalLibraryDirectories^)^<^/AdditionalLibraryDirectories^> & ^
echo      ^<AdditionalDependencies^>kernel32.lib;user32.lib;gdi32.lib;winspool.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;comdlg32.lib;advapi32.lib;ace.dll;worldserver.dll^<^/AdditionalDependencies^> & ^
echo      ^<IgnoreSpecificDefaultLibraries^>%%^(IgnoreSpecificDefaultLibraries^)^<^/IgnoreSpecificDefaultLibraries^> & ^
echo      ^<GenerateDebugInformation^>true^<^/GenerateDebugInformation^> & ^
echo      ^<SubSystem^>Console^<^/SubSystem^> & ^
echo      ^<ImageHasSafeExceptionHandlers^>true^<^/ImageHasSafeExceptionHandlers^> & ^
echo    ^<^/Link^> & ^
echo    ^<ProjectReference^> & ^
echo      ^<LinkLibraryDependencies^>false^<^/LinkLibraryDependencies^> & ^
echo    ^<^/ProjectReference^> & ^
echo    ^<PostBuildEvent^> & ^
echo      ^<Command^>xcopy ^/Y ^"$^(OutDir^)$^(TargetFileName^)^" ^"$^(ProjectDir^)..\^"^<^/Command^> & ^
echo    ^<^/PostBuildEvent^> & ^
echo  ^<^/ItemDefinitionGroup^> & ^
echo  ^<ItemGroup^> & ^
echo    ^<ClInclude Include=^"src\*.h^" ^/^> & ^
echo  ^<^/ItemGroup^> & ^
echo  ^<ItemGroup^> & ^
echo    ^<ClCompile Include=^"src\*.cpp^" ^/^> & ^
echo  ^<^/ItemGroup^> & ^
echo  ^<Import Project=^"$^(VCTargetsPath^)\Microsoft.Cpp.targets^" ^/^> & ^
echo  ^<ImportGroup Label=^"ExtensionTargets^"^> & ^
echo  ^<^/ImportGroup^> & ^
echo ^<^/Project^>)> "%name%\%name%.vcxproj"

:: create .vcxproj.user only for debugging
(echo ^<?xml version=^"1.0^" encoding=^"utf-8^"?^> & ^
echo ^<Project ToolsVersion=^"14.0^" xmlns=^"http:^/^/schemas.microsoft.com^/developer^/msbuild^/2003^"^> & ^
echo  ^<PropertyGroup Condition=^"^'$^(Configuration^)^|$^(Platform^)^'==^'RelWithDebInfo^|Win32^'^"^> & ^
echo    ^<LocalDebuggerCommand^>$^(LocalDebuggerWorkingDirectory^)\worldserver.exe^<^/LocalDebuggerCommand^> & ^
echo    ^<DebuggerFlavor^>WindowsLocalDebugger^<^/DebuggerFlavor^> & ^
echo    ^<LocalDebuggerWorkingDirectory^>..\..\build\az2.0\bin\RelWithDebInfo^<^/LocalDebuggerWorkingDirectory^> & ^
echo    ^<LocalDebuggerAttach^>false^<^/LocalDebuggerAttach^> & ^
echo  ^<^/PropertyGroup^> & ^
echo ^<^/Project^>)> "%name%\%name%.vcxproj.user"

start %name%