# MAKEFILE for linux GCC
#
# Tom St Denis
# Modified by Clay Culver

# The version
VERSION=1.05


srcdir=.

# Compiler and Linker Names
#CC=gcc
#LD=ld

# Archiver [makes .a files]
#AR=ar
#ARFLAGS=r

# Compilation flags. Note the += does not write over the user's CFLAGS!
# The rest of the flags come from the parent Dropbear makefile
# BRCM Begin
CFLAGS += -c -I$(srcdir)/src/headers/ -I$(srcdir)/../  \
-s -Os -fomit-frame-pointer -W -I.  -DDROPBEAR_SERVER
# BRCM End

# additional warnings (newer GCC 3.4 and higher)
#CFLAGS += -Wsystem-headers -Wdeclaration-after-statement -Wbad-function-cast -Wcast-align -Wstrict-prototypes -Wmissing-prototypes \
#		  -Wmissing-declarations -Wpointer-arith 

# optimize for SPEED
#CFLAGS += -O3 -funroll-loops

# add -fomit-frame-pointer.  hinders debugging!
#CFLAGS += -fomit-frame-pointer

# optimize for SIZE
#CFLAGS += -Os -DLTC_SMALL_CODE

# older GCCs can't handle the "rotate with immediate" ROLc/RORc/etc macros
# define this to help
#CFLAGS += -DLTC_NO_ROLC

# compile for DEBUGING (required for ccmalloc checking!!!)
#CFLAGS += -g3 -DLTC_NO_ASM

#Output filenames for various targets.
LIBNAME=libtomcrypt.a
LIBTEST=testprof/libtomcrypt_prof.a
HASH=hashsum
CRYPT=encrypt
SMALL=small
PROF=x86_prof
TV=tv_gen
MULTI=multi
TIMING=timing
TEST=test

#LIBPATH-The directory for libtomcrypt to be installed to.
#INCPATH-The directory to install the header files for libtomcrypt.
#DATAPATH-The directory to install the pdf docs.
DESTDIR=
LIBPATH=/usr/lib
INCPATH=/usr/include
DATAPATH=/usr/share/doc/libtomcrypt/pdf

#Who do we install as?
ifdef INSTALL_USER
USER=$(INSTALL_USER)
else
USER=root
endif

ifdef INSTALL_GROUP
GROUP=$(INSTALL_GROUP)
else
GROUP=wheel
endif

#List of objects to compile.

#Leave MPI built-in or force developer to link against libtommath?
#MPIOBJECT=src/misc/mpi/mpi.o
#Dropbear uses libtommath
MPIOBJECT=

OBJECTS=src/ciphers/aes/aes_enc.o $(MPIOBJECT) src/ciphers/aes/aes.o src/ciphers/anubis.o \
src/ciphers/blowfish.o src/ciphers/cast5.o src/ciphers/des.o src/ciphers/khazad.o src/ciphers/noekeon.o \
src/ciphers/rc2.o src/ciphers/rc5.o src/ciphers/rc6.o src/ciphers/safer/safer.o \
src/ciphers/safer/safer_tab.o src/ciphers/safer/saferp.o src/ciphers/skipjack.o \
src/ciphers/twofish/twofish.o src/ciphers/xtea.o src/encauth/ccm/ccm_memory.o \
src/encauth/ccm/ccm_test.o src/encauth/eax/eax_addheader.o src/encauth/eax/eax_decrypt.o \
src/encauth/eax/eax_decrypt_verify_memory.o src/encauth/eax/eax_done.o src/encauth/eax/eax_encrypt.o \
src/encauth/eax/eax_encrypt_authenticate_memory.o src/encauth/eax/eax_init.o \
src/encauth/eax/eax_test.o src/encauth/gcm/gcm_add_aad.o src/encauth/gcm/gcm_add_iv.o \
src/encauth/gcm/gcm_done.o src/encauth/gcm/gcm_gf_mult.o src/encauth/gcm/gcm_init.o \
src/encauth/gcm/gcm_memory.o src/encauth/gcm/gcm_process.o src/encauth/gcm/gcm_reset.o \
src/encauth/gcm/gcm_test.o src/encauth/ocb/ocb_decrypt.o src/encauth/ocb/ocb_decrypt_verify_memory.o \
src/encauth/ocb/ocb_done_decrypt.o src/encauth/ocb/ocb_done_encrypt.o src/encauth/ocb/ocb_encrypt.o \
src/encauth/ocb/ocb_encrypt_authenticate_memory.o src/encauth/ocb/ocb_init.o src/encauth/ocb/ocb_ntz.o \
src/encauth/ocb/ocb_shift_xor.o src/encauth/ocb/ocb_test.o src/encauth/ocb/s_ocb_done.o \
src/hashes/chc/chc.o src/hashes/helper/hash_file.o src/hashes/helper/hash_filehandle.o \
src/hashes/helper/hash_memory.o src/hashes/helper/hash_memory_multi.o src/hashes/md2.o src/hashes/md4.o \
src/hashes/md5.o src/hashes/rmd128.o src/hashes/rmd160.o src/hashes/sha1.o src/hashes/sha2/sha256.o \
src/hashes/sha2/sha512.o src/hashes/tiger.o src/hashes/whirl/whirl.o src/mac/hmac/hmac_done.o \
src/mac/hmac/hmac_file.o src/mac/hmac/hmac_init.o src/mac/hmac/hmac_memory.o \
src/mac/hmac/hmac_memory_multi.o src/mac/hmac/hmac_process.o src/mac/hmac/hmac_test.o \
src/mac/omac/omac_done.o src/mac/omac/omac_file.o src/mac/omac/omac_init.o src/mac/omac/omac_memory.o \
src/mac/omac/omac_memory_multi.o src/mac/omac/omac_process.o src/mac/omac/omac_test.o \
src/mac/pelican/pelican.o src/mac/pelican/pelican_memory.o src/mac/pelican/pelican_test.o \
src/mac/pmac/pmac_done.o src/mac/pmac/pmac_file.o src/mac/pmac/pmac_init.o src/mac/pmac/pmac_memory.o \
src/mac/pmac/pmac_memory_multi.o src/mac/pmac/pmac_ntz.o src/mac/pmac/pmac_process.o \
src/mac/pmac/pmac_shift_xor.o src/mac/pmac/pmac_test.o src/misc/base64/base64_decode.o \
src/misc/base64/base64_encode.o src/misc/burn_stack.o src/misc/crypt/crypt.o \
src/misc/crypt/crypt_argchk.o src/misc/crypt/crypt_cipher_descriptor.o \
src/misc/crypt/crypt_cipher_is_valid.o src/misc/crypt/crypt_find_cipher.o \
src/misc/crypt/crypt_find_cipher_any.o src/misc/crypt/crypt_find_cipher_id.o \
src/misc/crypt/crypt_find_hash.o src/misc/crypt/crypt_find_hash_any.o \
src/misc/crypt/crypt_find_hash_id.o src/misc/crypt/crypt_find_prng.o \
src/misc/crypt/crypt_hash_descriptor.o src/misc/crypt/crypt_hash_is_valid.o \
src/misc/crypt/crypt_prng_descriptor.o src/misc/crypt/crypt_prng_is_valid.o \
src/misc/crypt/crypt_register_cipher.o src/misc/crypt/crypt_register_hash.o \
src/misc/crypt/crypt_register_prng.o src/misc/crypt/crypt_unregister_cipher.o \
src/misc/crypt/crypt_unregister_hash.o src/misc/crypt/crypt_unregister_prng.o \
src/misc/error_to_string.o src/misc/mpi/is_prime.o src/misc/mpi/mpi_to_ltc_error.o \
src/misc/mpi/rand_prime.o src/misc/pkcs5/pkcs_5_1.o src/misc/pkcs5/pkcs_5_2.o src/misc/zeromem.o \
src/modes/cbc/cbc_decrypt.o src/modes/cbc/cbc_done.o src/modes/cbc/cbc_encrypt.o \
src/modes/cbc/cbc_getiv.o src/modes/cbc/cbc_setiv.o src/modes/cbc/cbc_start.o \
src/modes/cfb/cfb_decrypt.o src/modes/cfb/cfb_done.o src/modes/cfb/cfb_encrypt.o \
src/modes/cfb/cfb_getiv.o src/modes/cfb/cfb_setiv.o src/modes/cfb/cfb_start.o \
src/modes/ctr/ctr_decrypt.o src/modes/ctr/ctr_done.o src/modes/ctr/ctr_encrypt.o \
src/modes/ctr/ctr_getiv.o src/modes/ctr/ctr_setiv.o src/modes/ctr/ctr_start.o \
src/modes/ecb/ecb_decrypt.o src/modes/ecb/ecb_done.o src/modes/ecb/ecb_encrypt.o \
src/modes/ecb/ecb_start.o src/modes/ofb/ofb_decrypt.o src/modes/ofb/ofb_done.o \
src/modes/ofb/ofb_encrypt.o src/modes/ofb/ofb_getiv.o src/modes/ofb/ofb_setiv.o \
src/modes/ofb/ofb_start.o 

HEADERS=src/headers/tommath_superclass.h src/headers/tomcrypt_cfg.h src/headers/tomcrypt_mac.h \
src/headers/tomcrypt_macros.h src/headers/tomcrypt_custom.h src/headers/tomcrypt_argchk.h \
src/headers/tomcrypt_cipher.h src/headers/tomcrypt_pk.h src/headers/tommath_class.h \
src/headers/ltc_tommath.h src/headers/tomcrypt_hash.h src/headers/tomcrypt_misc.h \
src/headers/tomcrypt.h src/headers/tomcrypt_pkcs.h src/headers/tomcrypt_prng.h testprof/tomcrypt_test.h

TESTOBJECTS=demos/test.o
HASHOBJECTS=demos/hashsum.o
CRYPTOBJECTS=demos/encrypt.o
SMALLOBJECTS=demos/small.o
TVS=demos/tv_gen.o
MULTIS=demos/multi.o
TIMINGS=demos/timing.o
TESTS=demos/test.o

#Files left over from making the crypt.pdf.
LEFTOVERS=*.dvi *.log *.aux *.toc *.idx *.ilg *.ind *.out

#Compressed filenames
COMPRESSED=crypt-$(VERSION).tar.bz2 crypt-$(VERSION).zip

#The default rule for make builds the libtomcrypt library.
default:library

#ciphers come in two flavours... enc+dec and enc 
src/ciphers/aes/aes_enc.o: src/ciphers/aes/aes.c src/ciphers/aes/aes_tab.c
	$(CC) $(CFLAGS) -DENCRYPT_ONLY -c src/ciphers/aes/aes.c -o src/ciphers/aes/aes_enc.o

#These are the rules to make certain object files.
src/ciphers/aes/aes.o: src/ciphers/aes/aes.c src/ciphers/aes/aes_tab.c
src/ciphers/twofish/twofish.o: src/ciphers/twofish/twofish.c src/ciphers/twofish/twofish_tab.c
src/hashes/whirl/whirl.o: src/hashes/whirl/whirl.c src/hashes/whirl/whirltab.c
src/pk/ecc/ecc.o: src/pk/ecc/ecc.c src/pk/ecc/ecc_sys.c
src/pk/dh/dh.o: src/pk/dh/dh.c src/pk/dh/dh_sys.c
src/hashes/sha2/sha512.o: src/hashes/sha2/sha512.c src/hashes/sha2/sha384.c
src/hashes/sha2/sha256.o: src/hashes/sha2/sha256.c src/hashes/sha2/sha224.c

#This rule makes the libtomcrypt library.
library: $(LIBNAME)

$(LIBTEST): 
	cd testprof ; CFLAGS="$(CFLAGS)" make 

$(LIBNAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS) 
	$(RANLIB) $(LIBNAME)

#This rule makes the hash program included with libtomcrypt
hashsum: library $(HASHOBJECTS)
	$(CC) $(HASHOBJECTS) $(LIBNAME) -o $(HASH) $(WARN)

#makes the crypt program
crypt: library $(CRYPTOBJECTS)
	$(CC) $(CRYPTOBJECTS) $(LIBNAME) -o $(CRYPT) $(WARN)

#makes the small program
small: library $(SMALLOBJECTS)
	$(CC) $(SMALLOBJECTS) $(LIBNAME) -o $(SMALL) $(WARN)
	
tv_gen: library $(TVS)
	$(CC) $(TVS) $(LIBNAME) -o $(TV)

multi: library $(MULTIS)
	$(CC) $(MULTIS) $(LIBNAME) -o $(MULTI)

timing: library $(LIBTEST) $(TIMINGS)
	$(CC) $(TIMINGS) $(LIBTEST) $(LIBNAME) $(EXTRALIBS) -o $(TIMING)

test: library $(LIBTEST) $(TESTS)
	$(CC) $(TESTS) $(LIBTEST) $(LIBNAME) -o $(TEST)


#This rule installs the library and the header files. This must be run
#as root in order to have a high enough permission to write to the correct
#directories and to set the owner and group to root.
install: library docs
	install -d -g $(GROUP) -o $(USER) $(DESTDIR)$(LIBPATH)
	install -d -g $(GROUP) -o $(USER) $(DESTDIR)$(INCPATH)
	install -d -g $(GROUP) -o $(USER) $(DESTDIR)$(DATAPATH)
	install -g $(GROUP) -o $(USER) $(LIBNAME) $(DESTDIR)$(LIBPATH)
	install -g $(GROUP) -o $(USER) $(HEADERS) $(DESTDIR)$(INCPATH)
	install -g $(GROUP) -o $(USER) doc/crypt.pdf $(DESTDIR)$(DATAPATH)

install_test: $(LIBTEST)
	install -d -g $(GROUP) -o $(USER) $(DESTDIR)$(LIBPATH)
	install -d -g $(GROUP) -o $(USER) $(DESTDIR)$(INCPATH)
	install -g $(GROUP) -o $(USER) $(LIBTEST) $(DESTDIR)$(LIBPATH)

profile:
	CFLAGS="$(CFLAGS) -fprofile-generate" make timing EXTRALIBS=-lgcov
	./timing
	rm -f timing `find . -type f | grep [.][ao] | xargs`
	CFLAGS="$(CFLAGS) -fprofile-use" make timing EXTRALIBS=-lgcov


#This rule cleans the source tree of all compiled code, not including the pdf
#documentation.
clean:
	rm -f `find . -type f | grep "[.]o" | xargs`
	rm -f `find . -type f | grep "[.]lo"  | xargs`
	rm -f `find . -type f | grep "[.]a" | xargs`
	rm -f `find . -type f | grep "[.]la"  | xargs`
	rm -f `find . -type f | grep "[.]obj" | xargs`
	rm -f `find . -type f | grep "[.]lib" | xargs`
	rm -f `find . -type f | grep "[.]exe" | xargs`
	rm -f `find . -type f | grep "[.]gcda" | xargs`
	rm -f `find . -type f | grep "[.]gcno" | xargs`
	rm -f `find . -type f | grep "[.]il" | xargs`
	rm -f `find . -type f | grep "[.]dyn" | xargs`
	rm -f `find . -type f | grep "[.]dpi" | xargs`
	rm -rf `find . -type d | grep "[.]libs" | xargs`
	rm -f crypt.aux  crypt.dvi  crypt.idx  crypt.ilg  crypt.ind  crypt.log crypt.toc
	rm -f $(TV) $(PROF) $(SMALL) $(CRYPT) $(HASHSUM) $(MULTI) $(TIMING) $(TEST)
	rm -rf doc/doxygen
	rm -f doc/*.pdf
	rm -f *.txt

#build the doxy files (requires Doxygen, tetex and patience)
doxy:
	doxygen
	cd doc/doxygen/latex ; make ; mv -f refman.pdf ../../.
	echo The huge doxygen PDF should be available as doc/refman.pdf
	
#This builds the crypt.pdf file. Note that the rm -f *.pdf has been removed
#from the clean command! This is because most people would like to keep the
#nice pre-compiled crypt.pdf that comes with libtomcrypt! We only need to
#delete it if we are rebuilding it.
docs: crypt.tex
	rm -f doc/crypt.pdf $(LEFTOVERS)
	echo "hello" > crypt.ind
	latex crypt > /dev/null
	latex crypt > /dev/null
	makeindex crypt.idx > /dev/null
	latex crypt > /dev/null
	dvipdf crypt
	mv -ivf crypt.pdf doc/crypt.pdf
	rm -f $(LEFTOVERS)

docdvi: crypt.tex
	echo hello > crypt.ind
	latex crypt > /dev/null
	latex crypt > /dev/null
	makeindex crypt.idx
	latex crypt > /dev/null

#zipup the project (take that!)
no_oops: clean
	cd .. ; cvs commit 
	echo Scanning for scratch/dirty files
	find . -type f | grep -v CVS | xargs -n 1 bash mess.sh

zipup: no_oops docs
	cd .. ; rm -rf crypt* libtomcrypt-$(VERSION) ; mkdir libtomcrypt-$(VERSION) ; \
	cp -R ./libtomcrypt/* ./libtomcrypt-$(VERSION)/ ; \
	cd libtomcrypt-$(VERSION) ; rm -rf `find . -type d | grep CVS | xargs` ; cd .. ; \
	tar -cjvf crypt-$(VERSION).tar.bz2 libtomcrypt-$(VERSION) ; \
	zip -9r crypt-$(VERSION).zip libtomcrypt-$(VERSION) ; \
	gpg -b -a crypt-$(VERSION).tar.bz2 ; gpg -b -a crypt-$(VERSION).zip ; \
	mv -fv crypt* ~ ; rm -rf libtomcrypt-$(VERSION)


# $Source: /cvs/libtom/libtomcrypt/makefile,v $ 
# $Revision: 1.70 $ 
# $Date: 2005/06/19 18:03:24 $ 
