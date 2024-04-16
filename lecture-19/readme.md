please look at the handouts


The example below describes how we can compute the maximum size of a file if the inode contains
  - 12 direct pointers to file blocks
  - 1 single indirect
  - 1 double indirect
  - 1 triple indirect
  - Assume that the blocks are 4096 bytes i.e. 4 KB. Also the address of each data block can be stored in 4 bytes
- Then, 
  - A direct pointer alone can address 4096 bytes
  - Thus, 12 direct pointers can address 12 * 4096 bytes = 49152 bytes
  - The single indirect can address a datablock that contains the addresses of 4k / 4 = 1024 other datablocks. Thus total it can address 1024 (indirect data blocks) *4096 bytes = 4194304 bytes
  - The double indirect can address 1024 single indirect, so we have 1024 * 4194304 bytes = 4294967296 (based on the single indirect)
  - The triple indirect can address 1024 double indirect, so we have 1024 * 4294967296 = 4398046511104 (approximately 4TB)
  - Thus the total maximum file size is 4398046511104+4294967296+4194304+49152= 4.402345721856e+12 bytes
