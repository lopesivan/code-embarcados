
# hp50g.h:      configure.h
# except.h:     util.h hp50g.h
# datatype.h:   integer.h real.h
# narray.h:     except.h datatype.h
# karray.h:     narray.h
# kmatrix.h:    karray.h
# array.h:      karray.h
# matrix.h:     array.h kmatrix.h
# pythagoras.h: except.h datatype.h
# help.h:       configure.h
# complex.h:    matrix.h pythagoras.h
# polynomial.h: list.h karray.h
# ltype.h:      narray.h except.h datatype.h
# ulist.h:      list.h ltype.h
