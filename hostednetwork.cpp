/*
Program used to restart Virtual Hosted Network NETSH command.
Current Hotspot behavior times out after 5minutes of inactivity.
Customer requires Hotspot to always be on.

Miguel Pulido
Software Architect
*/


#include <windows.h>    //Include Windows.h file to run within Windows Environment
#include <process.h>    //Declarations and macros used with threads and processes
#include <stdio.h>      //Standard Input / Output header file
#include <time.h>       //Used to get and manipulate date and time information
#include <iostream>

#include <shlobj.h>     // used for ShellExecuteEx
#include <shlwapi.h>    // used for ShellExecuteEx
#include <objbase.h>    // used for ShellExecuteEx


using namespace std;


// Function to start Virtual Hosted Network

void start_hostednetwork()

{
    //Standard time capture function
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    /* Convert to local time format */
    c_time_string = ctime(&current_time);


    cout << " Test output time duration of start_hostednetwork\n";
    cout << "Current time is " << c_time_string;


    //Try to spawn process from an already approved cmd prompt.

 /*
    if(0 == CreateProcess("cmd.exe", "/k netsh wlan show drivers", NULL, NULL, false, 0, NULL, NULL, &si, &pi)) {
        //runas word is a hack to require UAC elevation
        ShellExecute(NULL, "runas", "cmd.exe", "/k netsh wlan show drivers", NULL, SW_SHOWNORMAL);
}

*/


    //runas.exe /savecred /user:domain\username "cmd /c start mmc c:\"

    /*This one runs the typical system function from windows.h API to launch but does not work for elevated privileges  */
    //system("netsh wlan start hostednetwork");

    /*This should run netsh with admin elevated rights but asks you to confirm */

    ShellExecute(NULL, "runas","cmd.exe", "/k ipconfig", NULL, SW_SHOWNORMAL); // Keeps CMD Window Open
    //ShellExecute(NULL, "runas","ipconfig", NULL, NULL, SW_SHOWNORMAL); // Closes CMD window after
    ShellExecute(NULL, "runas","cmd.exe", "/k netsh wlan show drivers", NULL, SW_SHOWNORMAL); // Keeps CMD Window Open
    //ShellExecute(NULL, "runas", "netsh wlan show drivers", NULL, NULL, SW_SHOWNORMAL); // Closes CMD window after
    //ShellExecute(NULL, "runas", "netsh wlan start hostednetwork", 0, 0, SW_SHOWNORMAL); // Closes CMD window after

    cout << "ShellExecute has taken place";
}


int main()

{
    system("color 02"); // change the background color of terminal
    system("cls"); // Clear the screen
    //system("ipconfig"); //list IP connections

while(1)
{
    start_hostednetwork();  // Call start_hostednetwork() function from above
    Sleep(300000);  // Sleep is in milliseconds, set to 5 minutes
    //system("cls");
}


}


