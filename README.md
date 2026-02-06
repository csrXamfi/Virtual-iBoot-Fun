# Virtual-iBoot-Fun
For fun
## Credits
Thanks [Nyan Satan](https://github.com/NyanSatan)! 
## Builds:
```term
cd Virtual-iBoot-Fun/virtualization_test
make
make sign
```
## Test run (check the folder run)
### terminal window 1
```term
iBootVirt -r AVPBooter.vmapple2.patch.bin
```
### terminal window 2
```term
irecovery -f iBSS.vma2.RELEASE.patched.img4     # send iBootStage1
irecovery -f localpolicy.img4   # send LocalPolicy, sample is available in the repo as well
irecovery -c lpolrestore        # apply it
irecovery -f iBEC.vma2.RELEASE.patched.img4     # send iBootStage2
irecovery -c go  
```

## Patches 
For patches via bspatch, use img4tool

Use these two simple commands: 
```term
img4tool -e -o example.vma2.RELEASE.patched.bin example.vma2.RELEASE.patched.im4p # im4p -> bin <- this bin patch
img4tool -c example.vma2.RELEASE.patched.im4p -t ibss/ibec -d "iBoot-7429.41.5" example.vma2.RELEASE.patched.bin # create im4p
img4tool -c example.vma2.RELEASE.patched.img4 -p example.vma2.RELEASE.patched.im4p -m vma2_ticket.der # sign 
```

Apply patches: 
```term
./bspatch example.vma2.RELEASE.bin example.vma2.RELEASE.patched.bin example.bspatch43
```
