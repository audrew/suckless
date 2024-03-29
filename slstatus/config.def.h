/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {

/*	I'm using scripts from my personal-dot-files repo
	just download them, make them executable and put them in /usr/local bin		*/

	/* function format          argument */
	{ run_command,	"^c#cc6666^ %2s", "~/.config/suckless/slstatus/cpuicon.sh " },
	{ cpu_perc,	"^c#c5c8c6^ %s%% ", NULL },

   	{ run_command,	"^c#b5bd68^ %2s ", "~/.config/suckless/slstatus/memicon.sh"  },
	{ ram_perc,	"^c#c8c5c6^ %s%% ", NULL },

   	{ run_command,	"^c#f0c674^ %2s ", "~/.config/suckless/slstatus/homeicon.sh" },
/*  { run_command,	"^c#c5c8c6^ %2s ", "hdd.sh" },   */
	{ disk_perc,	"^c#c5c8c6^ %s%% ", "/home/audrew/" },

	{ run_command,	"^c#81a2be^ %2s ", "~/.config/suckless/slstatus/neticon.sh" },
	{ run_command,	"^c#c5c8c6^ %2s ", "~/.config/suckless/slstatus/ip.sh" },
	{ run_command,	"^c#cc6666^ %2s ", "~/.config/suckless/slstatus/vpnicon.sh" },

    { run_command,	"^c#85678f^ %s ", "~/.config/suckless/slstatus/volicon.sh " },
	{ run_command,	"^c#c5c8c6^ %s ", "~/.config/suckless/slstatus/vol.sh " },

/*	{ run_command,	"^c#c5c8c6^ %2s ", "./forecast.sh " }, */
/*	{ run_command,	"^c#cc6666^ %2s ", "./tempicon.sh " }, */
/*	{ run_command,	"^c#c5c8c6^ %2s ", "./temp.sh " }, */


	{ run_command,	"^c#c5c8c6^ %2s ", "~/.config/suckless/slstatus/clock.sh" },

};
