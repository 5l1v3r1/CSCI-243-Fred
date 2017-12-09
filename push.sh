#!/bin/bash
git log > revisions.txt
scp -i ~/sshkey *.c *.h revisions.txt *.sh sym.* prog* ddp3945@berry.cs.rit.edu:~/Courses/csci243/Projects/03/
