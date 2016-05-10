AVL Medziai, versija 0.3.

Sukompailinkit pasinoudodami meikfailu.

Targetai:

 lib - sukurti biblioteka.

 exe_c - sukurti testavimo programa pasinaudojus c kalba (failai test/c_main.c ir include/c_avltree.h)

 exe_cpp - sukurti c++ stiliaus programa pasinaudojus kitais failais.

Bibliotekos naudojimas: 
Savo kode #include'inkit faila "include/c_avltrees.h", ir prie programos prijunkite biblioteka "lib/libAVLTreeTest.a" . Ta darykite per CodeBlocks Linker options, arba gcc -L"kelias-i-biblioteka"