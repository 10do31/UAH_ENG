# Dan Otieno.
# CPE 449.
# Geolocation.
# 11/04/2023.

import os
import sys
import pygeoip

geoFile = "./inFolder/GeoIP.dat"
fLogins = "./inFolder/logins.txt"
ipAddrs = {}
countries = {}

def openLogins():
    try:
        #Open and parse logins.txt file.
        with open(fLogins, 'r') as f:
            for line in f:
                ipAddress = line.split()[2]

                #Add IP addresses to dictionary.
                if ipAddress in ipAddrs:
                    ipAddrs[ipAddress] += 1
                else:
                    ipAddrs[ipAddress] = 1
    except:
        sys.exit("Error: Logins File Not Found!!" + fLogins)

def openIPFile():
    try:
        #Parse Geo IP File.
        geoIp = pygeoip.GeoIP(geoFile)
        for item in ipAddrs:
            country = geoIp.country_name_by_addr(item)
            print("IP Address: %s-------%s--------Found %d times." % (item, country, ipAddrs[item]))

            #Add country names to dictionary.
            if country in countries:
                countries[country] += 1
            else:
                countries[country] = 1

        print("\nTotal unique IP addresses found = ", (len(ipAddrs)), ".\n")
        print("Number of IP addresses Per Country.")
        print("------------------------------------")
        for item in countries: 
            print(item,":",countries[item])
    except:
        sys.exit("Error: IP File Not Found!!" + geoFile)

openLogins()
openIPFile()