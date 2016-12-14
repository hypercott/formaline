#!/usr/bin/env python 

import os
import sys
import fnmatch
import glob
import h5py
import numpy as np

table_name = "table.h5"
tarfile = "code_src.tar.gz"

# creating output directory
print "Creating output directory saved_code"
os.system("mkdir saved_code")

# open HDF5 file
h5file = h5py.File(table_name,"r")

# check to see if the code dataset is there
try:
  # if so, get the source binary data (super easy!)
    indata = h5file['Code Source'][()]
except:
    print "Sorry, no source availabe in this HDF5 file."
    h5file.close()
    sys.exit()
# close the file
h5file.close()
# now write source binary data to tar.gz file (super easy!)
outfile = open("saved_code/"+tarfile,"wb")
outfile.write(indata)
outfile.close()
# done!


