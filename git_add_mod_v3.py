#!/usr/bin/env python

import subprocess

file_list = []

#take the output as string

#git_out = subprocess.Popen(('git','status'), stdout = subprocess.PIPE)
#result = subprocess.check_output(['grep','modified'], stdin = git_out.stdout)
#git_out.wait()

try:
    git_out = subprocess.Popen(('git','status'), stdout = subprocess.PIPE)
    result = subprocess.check_output(['grep','modified'], stdin = git_out.stdout)
    git_out.wait()
except subprocess.CalledProcessError as grepexc:
        #print "error code", grepexc.returncode, grepexc.output
        if(grepexc.returncode == 1):
            raise NameError("No modified files to add...")
            exit(0)



#parse this string to find the file paths and store it in a list
git_out.kill()

import os
for word in result.split():
    if word not in file_list:
        if os.path.isdir(word) or os.path.isfile(word):
            file_list.append(word)

#print file_list
print('\n')
print('MODIFIED FILES FOUND : ',len(file_list))
print('\n\n\n')

for i in file_list:
    print('Adding %s' %i.decode("utf-8"))
    git_add=subprocess.Popen(('git','add',i.decode("utf-8") ))
    git_add.wait()


print('\n\n\n')
print('============================================')
print('GIT STATUS \n\n')
git_out= subprocess.Popen(('git','status','-uno'))
