#!/usr/bin/env python

# split up a URL of the http://www.something.com
url = raw_input("Please enter the URL: ")
domain = url[11:-4]

print "Domain name: " + domain