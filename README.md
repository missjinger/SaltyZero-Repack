# SaltyZero's Repack
Based on Azerothcore v2.0.0 and authorized by saltyzero@foxmail.com

Description:

I'm intended to build one high expansibility and performance server with easy game APIs. Now, it has supported for various scripts by using external dll.

Features:

1. Use game APIs with C++ rather than Eluna to override your own scripts just like it in demo project [transmog].

2. More brief file structure.

3. More APIs is coming....soon.

4. Use the cmd [create_new_script] to create a new scirpt project with the default configuration [RelWithDebInfo|Win32].

Requirements:

1. If you play at localhost just requiring [mysql] and one mysql database browser just like [navicat] or [heidisql].

2. If you open it on the internet and that will requirie one host tool just like [apache].

Steps:

1. Open the mysql service.

2. Import all sql within data folder and other script sql if you use it.

3. Set your server conf to connect to the mysql on it's port with default 3306.

4. Create a character and have fun.

Note:
1. Compile the script project with configuration [RelWithDefInfo]. 

2. The script name and the exported function name XXX matches the form of XXX.dll and AddSC_XXX() { new XXX(); } which will be filled in Database.

3. Game APIs are not complete but useful I'm trying to update.

4. You can debug your scripts in the debugger directly as long as you set your debugger configuration as the same as the demo script [transmog].

5. If you find any compiling error or any good suggestion just contact me.
