#!/usr/bin/env python 
import os
import sys
import fnmatch
import glob
import h5py
import numpy as np

table_name = "table.h5"

# make file list
filelist = []
filelist.append("Makefile")
filelist.append("make.inc")
filelist.append("parameters")
filelist.append("README")

# collect files, include README files, include files
# and other custom stuff -- end user should change this, also, of course
# change file extensions to include all relevant source files
matches = []
for root, dirnames, filenames in os.walk('src'):
    for filename in fnmatch.filter(filenames, '*.F90') + \
        fnmatch.filter(filenames, '*.f') + fnmatch.filter(filenames, 'Makefile') +\
        fnmatch.filter(filenames, 'README') + fnmatch.filter(filenames, '*.inc'):
    
        matches.append(os.path.join(root, filename))

filelist = filelist + matches

# create tar.gz ball
tarfile = "code_src.tar.gz"
tarstring = "tar -czvf " + tarfile + " "
for xfile in filelist:
    tarstring = tarstring + xfile + " "

print tarstring
os.system(tarstring)

# read source tarfile as binary data
infile = open(tarfile,"rb")
data = infile.read()
infile.close()

# wrap data in a numpy void datatype for subsequent
# hdf5 storage -- this is essential!
wrapdata = np.void(data)

# open hdf5 file
h5file = h5py.File(table_name,"r+")
# create data set, name can be changed
dset = h5file.create_dataset("Code Source", data=wrapdata)
# close hdf5 file
h5file.close()
