#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Configuring macOS Firewall...\n");

    // Turn on the firewall
    printf("Enabling the firewall...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setglobalstate on");

    // Turn on Stealth Mode
    printf("Enabling Stealth Mode...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setstealthmode on");

    // Turn on Logging Mode
    printf("Enabling Logging Mode...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setloggingmode on");

    // Block all incoming unnecessary connections
    printf("Blocking all unnecessary incoming connections...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setblockall on");

    // Disallow automatically built-in apps from receiving connections
    printf("Disallowing built-in apps from receiving connections automatically...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setallowsignedapp off");

    // Disallow automatically downloaded signed applications from receiving connections
    printf("Disallowing downloaded signed applications from receiving connections automatically...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --setallowsigned off");

    // List all apps which the firewall is currently blocking or allowing
    printf("Listing all applications with firewall rules...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --listapps");

    // Block a specific application
    printf("Blocking a specific application...\n");
    system("sudo /usr/libexec/ApplicationFirewall/socketfilterfw --blockapp /usr/libexec/remoted");

    // Restart the firewall to apply changes
    printf("Restarting the firewall to apply changes...\n");
    system("sudo pkill -HUP socketfilterfw");

    printf("macOS Firewall configuration completed.\n");

    return 0;
}
